/* -*- Mode: C++ -*- */

/* Rush Hour solver
 * ================
 * (c) Henrik Theiling
 *
 *    - Linux (hopefully many Unices)
 *    - Windows
 *    - hopefully MacOS
 */

// Another solver is here:
// http://www.cz.j.th.schule.de/spezi/projekte/informatik/rushhour/
//    But it's for Windows only, it seems, and not open source.

#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <list>
#include <liberror.h>

#include <erwin/erwin.h>
#include "failure.h"

#ifdef HAVE_UNISTD_H
#  include <unistd.h>
#else
#  define getpid() 0
#endif

#define forever    for(;;)
#define unless(X)  if(!(X))
#define until(X)   while(!(X))

#define WIDTH_HEIGHT 7
#define MULTIPLE 1

#define MOVE(no,d,cnt) (((no) << 2) | ((d) & 3) | ((cnt) << 16))
#define MOVE_NO(x)     (((x) >> 2) & 16383)
#define MOVE_BACK(x)   ((x) & 3)
#define MOVE_CNT(x)    ((x) >> 16)

#define MOVE_MAX 64 
   // 16 cars, two directions each= 32 moves maximally.

static bool plain_colours= false;
static bool use_pylons= false;
static bool safari_mode= false;

static int char2colour (char c)
{
    switch (c) {
    case '.': return FREE;    // == 0

    // width 2 (must be 3 * 4 = 12 ones.  Using one more in case j is not used, so 13).
    case 'a': return 2;
    case 'b': return 3;
    case 'c': return 4;
    case 'd': return 5;
    case 'e': return 6;
    case 'f': return 7;
    case 'g': return 8;
    case 'h': return 9;
    case 'i': return 10;
    case 'j': return 11;
    case 'k': return 12;
    case 'l': return 13;
    case 'm': return 14;
    case 'n': return 15;
    // width 3 (4 ones)
    case 'o': return 16;
    case 'p': return 17;
    case 'q': return 18;
    case 'r': return 19;
    case 's': return 20;
    //cargo
    case 't': return 21;
    case 'u': return 22;
    case 'v': return 23;

    case 'x': return MYSELF1;
    case 'y': return MYSELF2;
    case 'z': return MYSELF3;

    default:
        eprintf (C_TAG_FATAL, 0, "Unknown colour: '%c'\n", c);
    }
    return WALL;
}

static char colour2char (int i)
{
    switch (i) {
    case FREE:    return '.';

    case MYSELF1: return 'x';
    case MYSELF2: return 'y';
    case MYSELF3: return 'z';

    case  2:      return 'a';
    case  3:      return 'b';
    case  4:      return 'c';
    case  5:      return 'd';
    case  6:      return 'e';
    case  7:      return 'f';
    case  8:      return 'g';
    case  9:      return 'h';
    case 10:      return 'i';
    case 11:      return 'j';
    case 12:      return 'k';
    case 13:      return 'l';
    case 14:      return 'm';
    case 15:      return 'n';
    case 16:      return 'o';
    case 17:      return 'p';
    case 18:      return 'q';
    case 19:      return 'r';
    case 20:      return 's';
    case 21:      return 't';
    case 22:      return 'u';
    case 23:      return 'v';
    }
    return '?';
}

struct RGBColour {
    double r, g, b;

    void import (double _r, double _g, double _b)
    {
       r= _r;
       g= _g;
       b= _b;
       return_if_fail (r >= 0.0);
       return_if_fail (r <= 1.0);
       return_if_fail (g >= 0.0);
       return_if_fail (g <= 1.0);
       return_if_fail (b >= 0.0);
       return_if_fail (b <= 1.0);
    }

    RGBColour (double _gr = 0.0)
    {
       import (_gr, _gr, _gr);
    }

    RGBColour (int _gr)
    {
       import (_gr / 255.0, _gr / 255.0, _gr / 255.0);
    }

    RGBColour (int _r, int _g, int _b)
    {
       import (_r / 255.0, _g / 255.0, _b / 255.0);
    }

    RGBColour (double _r, double _g, double _b)
    {
       import (_r, _g, _b);
    }
};

static const RGBColour rgb_white (1.0);
static const RGBColour rgb_black (0.0);

static const RGBColour rgb_colour[]= {
    RGBColour (0.0),           // 0: not used.
    RGBColour (0.0),           // 1: not used.

    RGBColour (178, 243, 209), // a = 2
    RGBColour (255, 149,  93), // b
    RGBColour (152, 218, 252), // c

    RGBColour (255, 176, 208), // d = 5
    RGBColour (169, 136, 249), // e
    RGBColour ( 24, 190, 140), // f
    RGBColour ( 75,  74,  90), // g

    RGBColour (227, 204, 188), // h = 9
    RGBColour (232, 237, 171), // i
    RGBColour (177, 113, 113), // j
    RGBColour (100, 109,  54), // k = 12

    RGBColour (255, 211,  63), // o = 13
    RGBColour (231, 190, 255), // p
    RGBColour (119, 168, 255), // q
    RGBColour (126, 248, 237), // r = 16
    RGBColour (164, 128, 184),
    RGBColour (122, 141, 242),
    RGBColour (30, 30, 60),
    RGBColour (120, 120, 120),
    RGBColour (180, 180, 180),
    RGBColour (220, 220, 220),
    RGBColour (200, 200, 200),
    RGBColour (255,  22,  53), // x: MYSELF1 = 19
    RGBColour (255, 255, 255), // y: MYSELF2 = 20
    RGBColour (255,  22,  53)  // z: MYSELF3 = 21
};

static int rand_int_min (int minimum, int cnt)
{
    int v = rand();
    int v1 = v % (cnt - minimum);
    int v2 = v1 + minimum;

    return v2;
} 

static int rand_int (int cnt)
{
    int v = rand();
    int v1 = ((v % cnt));

    return v1;
//    return (int) ((rand() * (double)cnt) / (RAND_MAX + 1.0));
}

//////////////////////////////////////////////////////////////////////

struct Car {
    int x, y, w, h, colour;
    int w1, h1;

    Car (int a, int b, int c, int d, int e): x(a), y(b), w(c), h(d), colour (e)
    {
        if (w == 2 && h == 2) {
            w1= 1;
            h1= 1;
        } else if (w == 0) { // vertical
            w1= 0;
            h1= 1;
        }
        else { // horizontal
            return_if_fail (h == 0);
            w1= 1;
            h1= 0;
        }
    }

    Car *clone() const
    {
         return new Car (x, y, w, h, colour);
    }

    char direction (bool back) const
    {
         return back ?
                   (w == 0 ? 'u' : 'l')
                 : (w == 0 ? 'd' : 'r');
    }
};

long dkcount;

#define DOOR_Y 2

struct Board {
    int width;
    int height;
    Colour *cells;
    Colour door;
    VectorCarP cars;
    Board const *previous_board;
    Move previous_move; /* valid only if previous_board != NULL */
    int previous_cnt;   /* valid only if previous_board != NULL */
    Colour myself;
    Node *node;
    int red_car_x;
    int pylons;
    int px[2];
    int py[2];
    int cargo;

    int board_max() const { return width * height; }

private:
    Colour * cells_dup (Colour const *c)
    {
        if (c == NULL)
            return NULL;
        int size= sizeof (Colour) * board_max();
        return (Colour *)memcpy (malloc (size), c, size);
    }

    void clear_cells ()
    {
        for (int i=0; i < board_max(); i++) cells[i]= FREE;
        door= FREE;
    }

    void clear_cars()
    {
        Car *car;
        vector_forall_values (cars, car) delete car;
        cars.clear();
    }

    void append_cars (VectorCarP const &other)
    {
        Car *car;
        vector_forall_values (other, car) {
            cars.append (car->clone());
        }
    }

public:
    void clear()
    {
        clear_cells ();
        clear_cars ();
    }

    Board (int w = WIDTH_HEIGHT, int h = WIDTH_HEIGHT):
        width (w),
        height (h)
    {
        cells= (Colour *)malloc (sizeof (Colour) * board_max());
        clear_cells ();
        previous_board= NULL;
        previous_move= 0;
        previous_cnt= 0;
        pylons= 0;
        cargo= 0;
        myself= -1;
        node= NULL;
    }

    ~Board()
    {
        free (cells);
        clear_cars();
    }

    Board (Board const &other)
    {
        width=  other.width;
        height= other.height;
        cells= cells_dup (other.cells);
        door= other.door;
        myself= other.myself;
        append_cars (other.cars);
        previous_board= NULL;
        previous_move= 0;
        previous_cnt= 0;
        pylons = other.pylons;
        px[0] = other.px[0];
        px[1] = other.px[1];
        py[0] = other.py[0];
        py[1] = other.py[1];
        cargo= other.cargo;
    }

    Board (Board const &other, Move move)
    {
        width=  other.width;
        height= other.height;
        cells= cells_dup (other.cells);
        door= other.door;
        myself= other.myself;
        node= NULL;
        pylons = other.pylons;
        px[0] = other.px[0];
        px[1] = other.px[1];
        py[0] = other.py[0];
        py[1] = other.py[1];
        cargo = other.cargo;

        append_cars (other.cars);
        do_move (move, false);
        previous_board= &other;
        previous_move=  move;
        if (MULTIPLE)
            previous_cnt= MOVE_CNT (move);
        else
        if (other.previous_board && other.previous_move == move) {
            previous_board= other.previous_board;
            previous_cnt=   other.previous_cnt + 1;
        }
        else
            previous_cnt= 1;
    }

private:
    void operator= (Board const &other)
    {
        free (cells);
        clear_cars ();

        width=  other.width;
        height= other.height;
        cells= cells_dup (other.cells);
        door= other.door;
        append_cars (other.cars);
        pylons = other.pylons;
        px[0] = other.px[0];
        px[1] = other.px[1];
        py[0] = other.py[0];
        py[1] = other.py[1];
        cargo = other.cargo;
    }

    Board *clone () const { return new Board (*this); }

public:
    Colour operator() (int x, int y) const
    {
        if (x == width && y == DOOR_Y)
            return door;
        return
            x < 0 || x >= width || y < 0 || y >= height ?
                WALL
              : cells[y * width + x];
    }

    Colour get (int x, int y) const { return operator() (x, y); }

    void set (int x, int y, Colour c)
    {
        if (x == width && y == DOOR_Y) {
            door= c;
            return;
        }
        return_if_fail (!(x < 0 || x >= width || y < 0 || y >= height));
        cells[y * width + x]= c;
    }

    VChar name() const
    {
        VChar result;
        for (int y=0; y < height; y++)
            for (int x=0; x < width; x++)
                result.append (colour2char (get (x, y)));
        return result;
    }

    int xy_idx(int x, int y)
    {
        return x + y * width;
    }

    void learn_cars()
    {
        return_if_fail (FREE == 0); /* 'schon' map relies on this */

        cars.clear ();

        MapIntInt schon_xy;
        MapIntInt schon_c;
        myself= -1;
        for (int y=0; y < height; y++) {
            for (int x=0; x < width; x++) {
                Colour c= get (x, y);
                if (c != FREE && c != WALL) {
                    if (!schon_c.find (c)) {
                        schon_xy.insert (xy_idx(x, y), c);
                        schon_c.insert (c, 1);

                        int len= 1;
                        int horiz;

                        if (get (x+1, y+1) == c) { // cargo

                            while (get (x+len, y) == c) {
                                schon_xy.insert (xy_idx(x + len, y), c);
                                len++;
                            }
                            while (get (x, y+len) == c) {
                                schon_xy.insert (xy_idx(x, y + len), c);
                                len++;
                            }
                            cars.append (new Car (x, y, len, len, c));
                            horiz= -1;
                        } else if (get (x+1, y) == c) { // horizontal car
                            while (get (x+len, y) == c) {
                                schon_xy.insert (xy_idx(x + len, y), c);
                                len++;
                            }
                            cars.append (new Car (x, y, len, 0, c));
                            horiz= true;
                        } else if (c == WALL) {}
                        else
                        if (get (x, y+1) == c) { // vertical car
                            while (get (x, y+len) == c) {
                                schon_xy.insert (xy_idx(x, y + len), c);
                                len++;
                            }
                            cars.append (new Car (x, y, 0, len, c));
                            horiz= false;
                        }
                        else {
                            eprintf (C_TAG_ERROR, 0, "Unrecognised car at pos. %d,%d\n", x, y);
                            exit (1);
                        }
/*                        if (y == DOOR_Y && horiz) {
                            if (c == MYSELF3) myself= MYSELF3;
                            else
                            if (c == MYSELF2) myself= MYSELF2;
                            else
                            if (c == MYSELF1) myself= MYSELF1;
                        } */
myself = MYSELF1;

                    }
                    else
                    if (schon_xy.find (xy_idx(x, y)) == FREE && c != WALL) {
                        /* The colour was already used, but the field was not
                         * used -> car was used twice */
                        // eprintf (C_TAG_ERROR, 0,
                        //    "Car at pos. %d,%d already used somewhere else.\n",
                        //    x, y);
                        // exit (1);
                    }
                }
            }
        }
        if (myself == -1 && (!safari_mode)) {
            eprintf (C_TAG_ERROR, 0, "No car x, y or z found horizontally in row %d.\n", DOOR_Y);
            show (stderr);
            exit (1);
        }
    }

    bool final () const
    {
        int redx = -1;
        int redy = -1;
        int red_height = 0;
        bool found_first_x = false;
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                if (get(x,y) == MYSELF1) {
                    redx = x;
                    redy = y;
                    if (redx < width - 1 && redy < height - 1) {
                        if (get(redx, redy) == get(redx+1, redy+1)) {
                            red_height=1;
                        }
                    }
                    found_first_x = true;
                    break;
                }
            }
            if (found_first_x) break;
        }
        if (redy == DOOR_Y) {
            bool clear_path = true;
            for (int x = redx+2; x < width; ++x) {
                for (int y = redy; y <= redy + red_height; ++y) {
                    if (get(x,y) != FREE) clear_path = false;
                }
                if (!clear_path) break;
            }
            if (clear_path) {
//printf("Found clear_path!  +1 move\n");
                return true;
            }
        }

        return door == myself;
    }

    int find_moves (Move *moves) const
    {
        int move_cnt= 0;
        int i;
        Car *car;
        vector_forall (cars, i, car) {
            if (MULTIPLE) {
            if (get(car->x, car->y) == get(car->x+1, car->y+1)) {
                //cargo
                int cnt;

                cnt= 1;
                while (get (car->x + 1 + cnt,
                            car->y) == FREE
                       && get(car->x + 1 + cnt,
                            car->y+1) == FREE)
                {
                    cnt++;
                    moves[move_cnt++]= MOVE (i, FORWARD, cnt);
                }

                cnt= 1;
                while (get (car->x - cnt, car->y) == FREE
                       && get (car->x - cnt, car->y+1) == FREE) {
                    moves[move_cnt++]= MOVE (i, BACKWARD, cnt);
                    cnt++;
                }

                cnt= 1;
                while (get (car->x,
                            car->y + 1 + cnt) == FREE
                       && get (car->x+1,
                            car->y + 1 + cnt) == FREE)
                {
                    cnt++;
                    moves[move_cnt++]= MOVE (i, DOWN, cnt);
                }

                cnt= 1;
                while (get (car->x, car->y - cnt) == FREE
                       && get (car->x-1, car->y - cnt) == FREE) {
                    moves[move_cnt++]= MOVE (i, UP, cnt);
                    cnt++;
                }

            } else {

                int cnt;

                cnt= 0;
                while (get (car->x + car->w + car->w1 * cnt,
                            car->y + car->h + car->h1 * cnt) == FREE)
                {
                    cnt++;
                    if (car->y==DOOR_Y && car->w >= 2) {
                        if ((car->w == 2 && car->x+cnt < 6) || (car->w == 3 && car->x+cnt < 5)) {
                            moves[move_cnt++]= MOVE (i, FORWARD, cnt);
                        }
                    } else {
                        moves[move_cnt++]= MOVE (i, FORWARD, cnt);
                    }
                }

                cnt= 1;
                while (get (car->x - car->w1 * cnt, car->y - car->h1 * cnt) == FREE) {
                    moves[move_cnt++]= MOVE (i, BACKWARD, cnt);
                    cnt++;
                }
            }
            }
            else {
                if (get (car->x + car->w, car->y + car->h) == FREE)
                    moves[move_cnt++]= MOVE (i, FORWARD, 1);
                if (get (car->x - car->w1, car->y - car->h1) == FREE)
                    moves[move_cnt++]= MOVE (i, BACKWARD, 1);
            }
        }
        return0_if_fail (move_cnt < MOVE_MAX);
        return move_cnt;
    }

private:
    void do_move_aux (Car *car, int back)
    {
        return_if_fail_pi4C (get (car->x, car->y) == car->colour,
            car->x, car->y, car->colour, get(car->x, car->y),
            show(stderr));
        if (get(car->x, car->y) == get(car->x+1, car->y+1)) {
            //cargo
            if (car->x < WIDTH_HEIGHT - 1 && back == FORWARD
               && get(car->x+2, car->y) == FREE
               && get(car->x+2, car->y+1) == FREE) {
//fprintf(stdout, "Cargo FORWARD\n");
                set (car->x + 2, car->y, get (car->x, car->y));
                set (car->x + 2, car->y+1, get(car->x, car->y));
                car->x+= 1;
                set (car->x - 1, car->y, FREE);
                set (car->x - 1, car->y+1, FREE);
            } else if (car->x > 0 && back == BACKWARD
                      && get(car->x-1, car->y) == FREE
                      && get(car->x-1, car->y+1) ==FREE) {
//fprintf(stdout, "Cargo BACKWARD\n");
                set (car->x - 1, car->y, get (car->x, car->y));
                set (car->x - 1, car->y+1, get(car->x, car->y));
                car->x-= 1;
                set (car->x + 2, car->y, FREE);
                set (car->x + 2, car->y+1, FREE);
            } else if (car->y < WIDTH_HEIGHT - 1 && back == DOWN
                      && get(car->x, car->y+2) == FREE
                      && get(car->x+1, car->y+2) == FREE) {
//fprintf(stdout, "Cargo DOWN\n");
                 set (car->x, car->y+2, get (car->x, car->y));
                 set (car->x + 1, car->y+2, get(car->x, car->y));
                 car->y+= 1;
                 set (car->x, car->y - 1, FREE);
                 set (car->x + 1, car->y -1, FREE);
            } else if (car->y > 0 && back == UP
                      && get(car->x, car->y-1) == FREE
                      && get(car->x+1, car->y-1) == FREE) {
//fprintf(stdout, "Cargo UP \n");
                set (car->x, car->y-1, get (car->x, car->y));
                set (car->x+1, car->y-1, get(car->x, car->y));
                car->y-= 1;
                set (car->x, car->y+2, FREE);
                set (car->x + 1, car->y+2, FREE);
            }
        } else {
//fprintf(stdout, "NOT CARGO!\n");
            if (back) {
                set (car->x - car->w1, car->y - car->h1, get (car->x, car->y));
                car->x-= car->w1;
                car->y-= car->h1;
                set (car->x + car->w, car->y + car->h, FREE);
            } else {
                set (car->x + car->w, car->y + car->h, get (car->x, car->y));
                car->x+= car->w1;
                car->y+= car->h1;
                set (car->x - car->w1, car->y - car->h1, FREE);
            }
        }
    }

public:
    void do_move (Move move, bool invert)
    {
        int  nr=   MOVE_NO   (move);
        Car *car= cars.nth(nr);
        if (get(car->x, car->y) == get(car->x+1, car->y+1)) {
        //cargo
        int back= MOVE_BACK (move);
        int  cnt=  MOVE_CNT  (move);
        for (int i=0; i < cnt; i++)
            do_move_aux (car, back);
        } else {
        bool back= MOVE_BACK (move) ^ invert;
        int  cnt=  MOVE_CNT  (move);
        Car *car= cars.nth(nr);
        for (int i=0; i < cnt; i++)
            do_move_aux (car, back);
        }
//show(stdout);
    }

    static void no_color (FILE *f)
    {
#ifdef ERWIN_UNIX
        fputs ("\033[0m", f);
#endif
    }

#ifdef ERWIN_UNIX
    static void set_color (FILE *f, int fore, int back)
    {
        if (fore >= 0)
            if (back >= 0)
                fprintf (f, "\033[1;3%d;4%dm", fore, back);
            else
                fprintf (f, "\033[1;3%dm", 30+fore);
        else
            if (back >= 0)
                fprintf (f, "\033[1;4%dm", 40+fore);
    }
#endif

    static void set_color (FILE *f, char c)
    {
#ifdef ERWIN_UNIX
        switch (c) {
        // width 2 (must be 3 * 4 = 12.  Using one more in case j is not used, so 13).
        case WALL:   set_color (f,  0,  0); break;
        case FREE:   set_color (f, -1, -1); break;

        case  2:     set_color (f,  0,  2); break;
        case  3:     set_color (f,  7,  2); break;
        case  4:     set_color (f,  6,  2); break;
        case  5:     set_color (f,  5,  2); break;
        case  6:     set_color (f,  4,  2); break;
        case  7:     set_color (f,  1,  2); break;
        case  8:     set_color (f,  0,  4); break;
        case  9:     set_color (f,  7,  4); break;
        case 10:     set_color (f,  2,  4); break;
        case 11:     set_color (f,  1,  4); break;
        case 12:     set_color (f,  6,  4); break;
        case 13:     set_color (f,  5,  4); break;
        case 14:     set_color (f,  0,  7); break;
        case 15:     set_color (f,  1,  7); break;
        case 16:     set_color (f,  2,  7); break;
        case 17:     set_color (f,  4,  6); break;
        case 18:     set_color (f,  5,  7); break;
        case 19:     set_color (f,  3,  7); break;
        case 20:     set_color (f,  3,  5); break;
        case 21:     set_color (f,  3,  6); break;
        case 22:     set_color (f,  3,  2); break;
        case 23:     set_color (f,  3,  1); break;

        case MYSELF1: set_color (f,  7,  1); break;
        case MYSELF2: set_color (f,  7,  1); break;
        case MYSELF3: set_color (f,  3,  0); break;
        default:
            eprintf (C_TAG_FATAL, 0, "Colour is unknown: %c\n", c);
        }
#endif
    }

    void show_gdl (FILE *f, Move highlight) const
    {
        Car *high= NULL;
        if (highlight)
            high= cars.nth (MOVE_NO (highlight));

        for (int y=0; y < height; y++) {
            if (y)
                fputc ('\n', f);
            for (int x=0; x < width; x++) {
                 Colour c= get(x,y);
                 bool h= false;
                 if (high && high->colour == c) {
                     fputs ("\\f33", f);
                     h= true;
                 }
                 fputc (colour2char (c), f);
                 if (h)
                     fputs ("\\f31", f);
            }
        }
    }

    void show (FILE *f, bool show_cars = false, bool show_moves = false) const
    {
        fputs ("Board:\n", f);
        for (int y=0; y < height; y++) {
            for (int x=0; x < width; x++) {
                 Colour c= get(x,y);
                 set_color (f, c);
                 switch (c) {
#ifdef ERWIN_UNIX
                 case FREE: fputs ("  ", f); break;
                 case WALL: fputs ("##", f); break;
                 default:   fputs ("[]", f); break;
#else
                 case FREE: fputs ("   ", f); break;
                 case WALL: fputs ("###", f); break;
                 default:   fprintf (f, "[%c]", colour2char (c)); break;
#endif
                 }
                 no_color (f);
            }
            fprintf (f, "\n");
        }
        if (show_cars) {
            fprintf (f, "Cars:\n");
            Car *car;
            vector_forall_values (cars, car)
                fprintf (f, "  %d %d %d %d\n", car->x, car->y, car->w, car->h);
        }
        if (show_moves) {
            Move moves[MOVE_MAX];
            int move_cnt= find_moves (moves);
            if (move_cnt == 0) fprintf (f, "No moves possible.\n");
            else {
                fprintf (f, "Possible moves:\n");
                for (int i=0; i < move_cnt; i++) {
                    int  nr=   MOVE_NO   (moves[i]);
                    bool back= MOVE_BACK (moves[i]);
                    int  cnt=  MOVE_CNT  (moves[i]);
                    fprintf (f, "  %d %d %s %d\n",
                        cars.nth(nr)->x,
                        cars.nth(nr)->y,
                        back ? "backward" : "forward",
                        cnt);
                }
            }
        }
        fprintf (f, "\n");
    }

private:
#   define UNIT_W  (72.0 / 2.54)
#   define UNIT_H  UNIT_W

#   define PAPER_W  21.0
#   define PAPER_H  29.7

#   define EDGE_W   1.5
#   define EDGE_H   2.5

#   define PER_UNIT_W 3.0
#   define PER_UNIT_H 3.0

#   define NORM_LINE  0.05
#   define THICK_LINE 0.1

    void show_move_ps (FILE *f, Move move) const
    {
        if (move == 0)
            return;

        int  no=   MOVE_NO   (move);
        bool back= MOVE_BACK (move);
        int  cnt=  MOVE_CNT  (move);
        Car *car= cars.nth (no);
        double x1, y1, x2, y2;
        if (back) {
            x1= car->x;
            y1= car->y;
            x2= car->x - car->w1 * cnt;
            y2= car->y - car->h1 * cnt;
        }
        else {
            x1= car->x + car->w - car->w1;
            y1= car->y + car->h - car->h1;
            x2= car->x + car->w + (car->w1 * (cnt - 1));
            y2= car->y + car->h + (car->h1 * (cnt - 1));
        }

        double const aw= 0.15;
        double const al= 0.4;
        double xa= 0.0;
        double ya= 0.0;
        double xb= 0.0;
        double yb= 0.0;
        switch (car->direction (back)) {
        case 'u': xa=-aw; xb=+aw; ya=yb=+al; break;
        case 'd': xa=-aw; xb=+aw; ya=yb=-al; break;
        case 'l': ya=-aw; yb=+aw; xa=xb=+al; break;
        case 'r': ya=-aw; yb=+aw; xa=xb=-al; break;
        default: return_if_reached_ptc ("Wrong direction!", car->direction(back));
        }

        fprintf (f, "0 0.7 0 setrgbcolor\n");

        fprintf (f, "%g setlinewidth\n", THICK_LINE);
        // arrow trunk
        fprintf (f, "newpath %g %g moveto %g %g lineto stroke\n", x1,y1,x2,y2);

        // arrow head
        fprintf (f, "newpath %g %g moveto %g %g rlineto stroke\n", x2, y2, xa, ya);
        fprintf (f, "newpath %g %g moveto %g %g rlineto stroke\n", x2, y2, xb, yb);

        fprintf (f, "%g setlinewidth\n", NORM_LINE);
    }

    void ps_colour (FILE *f, RGBColour const *rgb) const
    {
        if (rgb)
            fprintf (f, "%g %g %g setrgbcolor\n", rgb->r, rgb->g, rgb->b);
        else
            fprintf (f, "0 0 0 setrgbcolor\n");
    }

    void ps_box (
        FILE *f,
        double x1, double y1, double x2, double y2, RGBColour const *rgb, bool fill = false) const
    {
        fprintf (f,
           "newpath %g %g moveto %g %g lineto %g %g lineto %g %g lineto closepath\n",
           x1, y1, x2, y1, x2, y2, x1, y2);
        ps_colour (f, rgb);
        if (fill)
            fprintf (f, "fill\n");
        else
            fprintf (f, "stroke\n");
    }

    void ps_line (
        FILE *f,
        double x1, double y1, double x2, double y2, RGBColour const *rgb) const
    {                           
        fprintf (f,
           "newpath %g %g moveto %g %g lineto\n", x1, y1, x2, y2);
        ps_colour (f, rgb);
        fprintf (f, "stroke\n");
    }

    void ps_box_with_gap (
        FILE *f,
        double x1, double y1, double x2, double y2,
        double yg1, double yg2,
        double xu,
        RGBColour const *rgb) const
    {
        fprintf (f,
           "newpath %g %g moveto %g %g lineto %g %g lineto %g %g lineto"
                  " %g %g lineto %g %g lineto %g %g lineto %g %g lineto\n",
           x2+xu, yg1, x2, yg1, x2, y1, x1, y1, x1, y2, x2, y2, x2, yg2, x2+xu, yg2);
        ps_colour (f, rgb);
        fprintf (f, "stroke\n");
    }

    void ps_hline (
        FILE *f,
        double x, double y1, double y2, RGBColour const *rgb) const
    {
        ps_line (f, x, y1, x, y2, rgb);
    }

    void ps_car (FILE *f, double x1, double y1, double x2, double y2, Colour colour) const
    {
        RGBColour const *col= &rgb_colour[colour];
        if (plain_colours) {
            if (colour != myself)
                col= &rgb_white;
        }
        ps_box (f, x1, y1, x2, y2, col,  true);
        ps_box (f, x1, y1, x2, y2, NULL, false);
    }

    void show_car_ps (FILE *f, Car *car) const
    {
        double const wr= 0.4;
        ps_car (f,
            car->x - wr,
            car->y - wr,
            car->x + car->w - car->w1 + wr,
            car->y + car->h - car->h1 + wr,
            car->colour);
    }

public:
    void ps_write (FILE *f, double x, double y, double h, char const *text) const
    {
        fprintf (f,
            "save\n");
        fprintf (f,
            "%g %g moveto %g %g scale\n", x, y, 1.0, -1.0);
        fprintf (f,
            "/Helvetica %g selectfont\n"
            "0 0 0 setrgbcolor\n"
            "(%s) show\n", h, text);
        fprintf (f,
            "restore\n");
    }

    void ps_header (FILE *f) const
    {
        fprintf (f,
           "%%!PS-Adobe-2.0 EPSF-2.0\n"
           "save\n"
        );
        fprintf (f, "0 0 0 setrgbcolor\n");
        fprintf (f, "1 -1 scale\n");
        fprintf (f, "%g %g scale\n",     UNIT_W, UNIT_H);
        fprintf (f, "%g %g translate\n", 0.0, -PAPER_H);
        fprintf (f, "%g %g translate\n", EDGE_W, EDGE_H);
        fprintf (f, "%g %g scale\n",     1/PER_UNIT_W, 1/PER_UNIT_H);
        fprintf (f, "%g setlinewidth\n", NORM_LINE);
    }

    void ps_trailer (FILE *f) const
    {
        fprintf (f,
           "restore\n"
           "showpage\n"
        );
    }

    void show_ps (FILE *f, int cnt, bool show_moves = false, Move move = 0) const
    {
        double const pr= 0.01;
        double const br= 0.6;

        fprintf (f, "save\n");

        double total_w= width  + 2.0;
        double total_h= height + 2.0;
        int per_line= (int)floor ((PAPER_W - 2*EDGE_W) / (total_w * 1/PER_UNIT_W));
        int px= cnt % per_line;
        int py= cnt / per_line;

        fprintf (f, "%g %g translate\n", px * total_w, py * total_h);

        // show the parking:
        ps_box_with_gap (f,
            -br, -br,
            width-1+br, height-1+br,
            DOOR_Y-br,  DOOR_Y+br,
            +br/2,
            NULL);

        // mark each free sqare with a dot
        for (int y=0; y < height; y++)
            for (int x=0; x < height; x++)
                ps_box (f,
                    x-pr, y-pr,
                    x+pr, y+pr,
                    NULL, false);

        Car *car;
        vector_forall_values (cars, car)
            show_car_ps (f, car);

        show_move_ps (f, move);
        if (show_moves) {
            Move moves[MOVE_MAX];
            int move_cnt= find_moves (moves);
            for (int i=0; i < move_cnt; i++)
                show_move_ps (f, moves[i]);
        }

        fprintf (f, "restore\n");
    }

    hashval_t hash () const
    {                 
        if (this == NULL)
            return 0;
        hashval_t result= 1;
        for (int i=0; i < board_max(); i++)
            result= i+3 * cells[i] + result << 1;
        return result;
    }

    int cmp (Board const *other) const
    {
        if (this == NULL)
            return other == NULL ? 0 : -1;
        if (other == NULL)
            return +1;

        for (int i=0; i < board_max(); i++)
            if (cells[i] != other->cells[i])
                return cells[i] - other->cells[i];
        return 0;
    }

    int cmp (Board const &other) const
    {
        return cmp (&other);
    }

    int nentries() const
    {
        return this == NULL ? 0 : 1 + previous_board->nentries();
    }

    void show_way (FILE *f) const
    {
        if (previous_board)
            previous_board->show_way (f);
        show (f);
    }

private:
    void describe_way_aux (FILE *f, int &i) const
    {
        if (previous_board) {
            previous_board->describe_way_aux (f, i);
            switch (i++) {
            case 5:  fprintf (f, "\n"); i= 1; break;
            case 0:  break;
            default: fprintf (f, " "); break;
            }
            Car *car= cars.nth (MOVE_NO (previous_move));
            fprintf (f, "%c%c%d",
                colour2char (car->colour),
                car->direction (MOVE_BACK (previous_move)),
                previous_cnt);
        }
    }

public:
    void describe_way (FILE *f) const
    {
        int i=0;
        describe_way_aux (f, i);
        fprintf (f, "\n");
    }

private:
    void show_way_ps_aux (FILE *f, int &i, Move pm) const
    {
        if (previous_board)
            previous_board->show_way_ps_aux (f, i, previous_move);
        show_ps (f, i, false, pm);
        i++;
    }

public:
    void show_way_ps (FILE *f) const
    {
        int i=0;
        show_way_ps_aux (f, i, 0);
    }

    void put_car (int x, int y, int w, int h, Colour c)
    {
        for (int ww=0; ww < w; ww++)
            for (int hh=0; hh < h; hh++)
                set (x+ww, y+hh, c);
    }

    void clear_random_put_myself ()
    {
        clear();
        red_car_x = rand_int(width-2);
        if (safari_mode)
            put_car (red_car_x, rand_int(height-2), 2, 2, MYSELF1);
        else
            put_car (red_car_x, DOOR_Y, 2, 1, MYSELF1);
    }

    bool is_free (int x, int y, int w, int h)
    {
        for (int ww=0; ww < w; ww++)
            for (int hh=0; hh < h; hh++)
                if (get (x+ww, y+hh) != FREE)
                    return false;
        return true;
    }

    bool random_put_cargo(Colour col) {

int tries = 0;
        forever {
            int  x= rand_int (width);
            int  y= rand_int (height);
                if (is_free (x, y, 2, 2)) {
                    put_car (x, y, 2, 2, col);
                    return true;
                }

++tries;
if (tries >= 100) return false;
        }
    }

    bool random_put_car (int length, Colour col)
    {
        int  sx= rand_int (width);
        int  sy= rand_int (height);
        bool sv= rand_int (2);
        int  x=  sx;
        int  y=  sy;
        bool v=  sv;

int tries = 0;
        forever {
            if (y == DOOR_Y && x > red_car_x + 1 && !sv) {
                y++; // do not put horizontal cars in output line.
                x= 0;
            }
            if (sv) {
                if (is_free (x, y, 1, length)) {
                    put_car (x, y, 1, length, col);
                    return true;
                }
            }
            else {
                if (is_free (x, y, length, 1)) {
                    put_car (x, y, length, 1, col);
                    return true;
                }
            }

            x++;
            if (x >= width) {
                x= 0;
                y++;
                if (y >= height) {
                   y= 0;
                   sv= !sv;
                }
            }
            if (x == sx && y == sy && v == sv)
                return false;
++tries;
if (tries >= 100) return false;
        }
    }

    void randomize (int twos, int threes)
    {
        if (twos < 0)
            twos= rand_int_min (4, 13); // 0..11 two-block additional cars (excluding the red one)

        if (threes < 0)
            threes= rand_int (6); // 0..4 three-block additional cars

//        fprintf (stderr, "count:%d %d\n", twos, threes);
        forever {
            clear_random_put_myself ();

            pylons = 0;
            if (use_pylons) pylons = rand_int(3);
            for (int i = 0; i < pylons; ++i) {
                px[i] = rand_int(width);
                py[i] = rand_int(height);

                if (safari_mode  && (py[i] == DOOR_Y || py[i] == DOOR_Y + 1) && (px[i] >= 5)) { /* don't block the door! */ }
                else if (is_free(px[i], py[i], 1, 1)  && (safari_mode || py[i] != DOOR_Y || px[i] < red_car_x)) put_car(px[i], py[i],1,1,WALL);
                else --i; 
            }

        cargo= rand_int(3);
        if (cargo >= 1) random_put_cargo(CARGO1);
        if (cargo >= 2) random_put_cargo(CARGO2);

            for (int i=0; i < twos; i++) {
                unless (random_put_car (2, i + 2))
                    continue;
            }
            for (int i=0; i < threes; i++) {
                unless (random_put_car (3, i + 14))
                    continue;
            }
            break; // If we get to this, we have succeeded.
        }
        learn_cars ();
    }
};

hashval_t board_hash (Board const *x)
{
    return x->hash();
}

int board_cmp  (Board const *a, Board const *b)
{
    return a->cmp (b);
}

//////////////////////////////////////////////////////////////////////

static bool read_one_level (Board &board, FILE *f)
{
    board.clear();
    for (int y=0; y < board.height; y++) {
         VChar line;
         line.fgets (f).trim();
         for (int x=0; x < board.width; x++)
             board.set (x, y, char2colour (line[x]));
         if (line.empty())
             return false;
         if (line.nentries() < board.width)
             eprintf (C_TAG_FATAL, 0, "Line too short in level file:\n%s\n", +line);
    }                         

    VChar line;
    line.fgets (f).trim();

    // possibly read solution
    if (erwin_strequ (line, "-"))
        until (line.clear().fgets (f).trim().empty()) {}

    unless (line.empty())
        eprintf (C_TAG_FATAL, 0, "Expected empty line after level, but found:\n%s\n", +line);

    return true;
}

static bool read_level (Board &board, int level)
{
    bool result= false;
    FILE *f= fopen (VChar().format("level%d.txt", level), "rt"); // try special
    if (f == NULL)
        f= fopen ("level.txt", "rt"); // try generic
    if (f == NULL)
        eprintf (C_TAG_FATAL, 0, ERR_OPEN_READ, "level.txt");
    forever {
        int i;
        if (sscanf (VChar().fgets (f), "%i:", &i) < 1)
            eprintf (C_TAG_FATAL, 0, "Unrecognised token in level file.\n");
        if (!read_one_level (board, f))
            break;
        if (i == level) {
            board.learn_cars();
            result= true;
            break;
        }
    }
    fclose (f);
    return result;
}

//////////////////////////////////////////////////////////////////////

struct AgendaStack;
struct AgendaQueue;
typedef AgendaQueue Agenda;

struct AgendaStack {
    VectorBoardP store;

    void insert (Board *a)
    {
        store.append (a);
    }

    bool empty() const
    {
        return store.empty();
    }

    Board *next ()
    {
        return store.last_chop1();
    }
};

struct AgendaQueue {
    VectorBoardP front;
    VectorBoardP back;

    void insert (Board *a)
    {
        back.append (a);
    }

    bool empty () const
    {
        return front.empty() && back.empty();
    }

    Board *next()
    {
        if (front.empty()) {
            Board *board;
            vector_forall_values_reverse (back, board)
                front.append (board);
            back.clear();
        }
        return front.last_chop1();
    }
};

//////////////////////////////////////////////////////////////////////

struct Node {
    Node *parent;
    Board board;
    bool on_final_path;
    Move move;

    void set_on_final_path()
    {
        if (this) {
            on_final_path= true;
            parent->set_on_final_path();
        }
    }

    Node (Node *a, Board *b):
       parent (a),
       board  (*b),
       on_final_path (false),
       move (0)
    {
        return_if_null (b);
        return_if_fail (b->node == NULL);
        board.node= b->node= this;
        if (board.final())
            parent->set_on_final_path ();
    }
};

struct Edge {
    Node *from;
    Node *to;
    bool  first;
    Move  move;

    Edge (Node *a, Node *b, bool c, Move d):
        from  (a),
        to    (b),
        first (c),
        move  (d)
    {
        return_if_null (a);
        return_if_null (b);
        if (first)
            b->move= move;
    }
};

struct GDLWriter {
private:
    FILE *f;
    VectorNodeP nodes;
    VectorEdgeP edges;

public:
    GDLWriter (char const *filename = NULL):
        f (NULL)
    {
        if (filename) {
            f= fopen (filename, "wt");
            if (f == NULL)
                eprintf (C_TAG_FATAL, 0, ERR_OPEN_WRITE, filename);
            else {
                fprintf (f,
                    "graph: {\n"
                    "   amax: 0\n"
                    "   arrowmode: free\n"
                    "   scaling: maxspect\n");

                if (1)
                    fprintf (f,
                        "   layoutalgorithm: forcedir\n"
                        // Parameters for force-directed placement
                        "   attraction:      5050\n"    // Attractive force
                        "   repulsion:       80\n"    // Repulsive force
                        "   gravity:         0.0\n"   // Gravity force factor (float)
                        "   randomrounds:    0\n"     // Nr.rounds with rand.impulse
                        "   randomimpulse:   0\n"     // Force of the random impulse
                        "   fdmax:           120\n"   // Number Iterations
                        "   tempmax:         254\n"   // Maximal Temperature
                        "   tempmin:         0\n"     // Minimal Temperature
                        "   temptreshold:    3\n"     // > 0
                        "   tempscheme:      3\n"     // 1 - 8
                        "   tempfactor:      1.08\n"  // > 1 (float)
                        "   randomfactor:    100\n"   // 100 means: determ. schedule
                        "   magnetic_field1: top_to_bottom\n"
                        "   magnetic_field2: no\n"
                        "   magnetic_force1: 20\n"
                        "   magnetic_force2: 0\n"
                        // Parameters for simulated annealing
                        "   energetic:                no\n"      // yes = sim. annealing
                        "   energetic attraction:   2500.0\n"    // Attractive weight
                        "   energetic repulsion:    2500.0\n"    // Repulsive weight
                        "   energetic gravity:         0.0\n"    // Gravity weight
                        "   energetic crossing:     1000.0\n"    // Crossing weight
                        "   energetic overlapping:  1000.0\n"    // Overlapping weight
                        "   energetic border:      10000.000\n"  // Border weight
                        // And the border coordinates
                        "   border x:  5000\n"
                        "   border y:  5000\n");

                fprintf (f,
                    "   colorentry 33: 224   0   0\n"
                    "   colorentry 34:   0 255 255\n"
                    "   colorentry 35:   0 255   0\n"
                    "   classname 1: \"New Node\"\n"
                    "   classname 2: \"Old Node\"\n"
                    "   hidden: 2\n"
                );
            }
        }
    }

    void finalise()
    {
        if (this && f) {
            Node *node;
            vector_forall_values (nodes, node)
                print_node (node);

            Edge *edge;
            vector_forall_values (edges, edge)
                print_edge (edge);

            fprintf (f, "}\n");
            fclose (f);
            f= NULL;
        }
    }

    ~GDLWriter ()
    {
        finalise();
    }

    Node *new_node (Board *to)
    {
        Node *result= NULL;
        if (this && f && to)
            nodes.append (result= new Node (NULL, to));
        return result;
    }

    Node *new_node (Board *from, Board *to, Move move)
    {
        Node *result= NULL;
        if (this && f && to && from) {
            nodes.append (result= new Node (from->node, to));
            edges.append (new Edge (from->node, to->node, true, move));
        }
        return result;
    }

    Edge *new_edge (Board *from, Board *to, Move move)
    {
        Edge *result= NULL;
        if (this && f && from && to)
            edges.append (result= new Edge (from->node, to->node, false, move));
        return result;
    }

private:
    void print_node (Node *node)
    {
        return_if_null3 (this, f, node);

        fprintf (f,
            "node: {\n"
            "  title: \"%s\"\n", +node->board.name());

        fputs ("  label: \"", f);
        node->board.show_gdl (f, node->move);
        fputs ("\"\n", f);

        if (node->board.final())
            fputs ("  color: 34 bordercolor: 34\n", f);
        else
        if (node->on_final_path)
            fputs ("  color: 35 bordercolor: 35\n", f);

        fprintf (f, "}\n");
    }

    void print_edge (Edge *edge)
    {
        return_if_null5 (this, f, edge, edge->from, edge->to);
        fprintf (f,
            "edge: {\n"
            "  source: \"%s\"\n"
            "  target: \"%s\"\n",
            +edge->from->board.name(),
            +edge->to->board.name());

        if (edge->first)
            fprintf (f,
                "  class: 1\n"
                "  priority: 100\n");
        else
            fprintf (f,
                "  class: 2\n"
                "  priority: 1\n");

        if (edge->to->on_final_path || edge->to->board.final())
            fprintf (f,
                "  color: 35\n");

        fprintf (f,
            "}\n");
    }
};

//////////////////////////////////////////////////////////////////////

static FILE *fps;

static int print_solution (Board *board, bool first, int check_cnt)
{
    int n= board->nentries()-1;
    printf ("----------------------------------------------------------------------\n");
//    printf ("Found solution (%d step%s) after checking %d board configurations:\n",
      printf ("%d step%s, checked %d\n",
        n, n==1 ? "" : "s",
        check_cnt);
    board->describe_way (stdout);
    // board->show_way (stdout);
    if (first && fps) {
        board->ps_write (fps, 0, -3, 1.0,
            VChar().format("Solution has %d steps, found after %d tests.\n", n, check_cnt));
        board->show_way_ps (fps);
    }
    return n;
}

std::list<Board *> board_list;

static void try_board (GDLWriter *trace, MapBoardPNodeP &schon, Agenda *agenda, Board *board)
{
    Move moves[MOVE_MAX];
    int move_cnt= board->find_moves (moves);
    for (int i=0; i < move_cnt; i++) {
        Board *new_board= new Board (*board, moves[i]);

        Node **x= schon.find_ptr_ensure (new_board);
        if (map_errno == MAP_OK) {
delete new_board;
//new_board = 0;
//            new_board->node= *x;
            //trace->new_edge (board, new_board, moves[i]);
        }
        else {
            //*x= trace->new_node (board, new_board, moves[i]);
            agenda->insert (new_board);
board_list.push_back(new_board);
        }
    }
}

static int game_run (GDLWriter *trace, Board *board, bool is_no_pylons = false)
{
    MapBoardPNodeP schon;
    Agenda agenda;
    Board board_start(*board);
    Board board_no_pylons(*board);
    board_no_pylons.learn_cars();
    agenda.insert (board);
    schon.insert (board, trace->new_node (board));

    bool first= true;
    int check_cnt= 0;
    int steps = 0;

// board->show(stdout);

    forever {
dkcount = dkcount + 1;
        if (agenda.empty ()) {
            break; //!
        }
        Board *board= agenda.next ();
        check_cnt++;
        if (board->final()) {
            steps = board->nentries()-1;
            if (steps >= 30) {
                if (board->pylons > 0) {
                    for (int j = 0; j < board_no_pylons.pylons; ++ j) {
                        board_no_pylons.set(board_no_pylons.px[j], board_no_pylons.py[j], FREE);
                    }
                    board_no_pylons.pylons = 0;
                    printf("NO PYLONS:\n");
                    game_run(trace, &board_no_pylons);
                }
                board_start.show(stdout);
                steps = print_solution (board, first, check_cnt);
                first= false;
            } else {
                //print_solution(board, first, check_cnt);
            }
            break;
        }
        else {
            try_board (trace, schon, &agenda, board);
        }
if (dkcount > 1500000) break;
    }
    return steps;
}

void rush_hour_init (int *argc_p, char ***argv_p)
{
    erwin_init (argc_p, argv_p);
}

int main (int argc, char **argv)
{
    err_init (&argc, &argv);
    err_add_stream (C_TAG_ALL, stderr, NULL);
    rush_hour_init (&argc, &argv);

    srand (time (NULL)); //*7 ^ getpid ()*1391);

    int i;
    for (i = 2; i <= 26; ++i) {
        Board::no_color(stdout);
        fprintf(stdout, "%c : ", 95+i);
        Board::set_color(stdout, i);
        fprintf(stdout, "[]");
        Board::no_color(stdout);
        fprintf(stdout, "\n");
    }



    int  level= 32;
    int  rand_twos= -1;
    int  rand_threes= -1;
    bool random_level= false;
    bool gdl= false;

    for (int i=1; i < argc; i++) {
        char const *arg= argv[i];
        if (*arg == '-') {
            while (*arg == '-') arg++;
            if (erwin_strequ (arg, "random"))
                random_level= true;
            else
            if (erwin_strequ (arg, "gdl"))
                gdl= true;
            else
            if (erwin_strequ (arg, "plain-colours") || erwin_strequ (arg, "p"))
                plain_colours= true;
            else
            if (erwin_strequ (arg, "pylons"))
                use_pylons=true;
            else
            if (erwin_strequ (arg, "safari"))
                safari_mode= true;
            else
            if (erwin_strequ (arg, "h") || erwin_strequ (arg, "help")) {
                printf (
                    "usage: rush_hour [options] [level_nr]\n"
                    "options:\n"
                    "  --random\n"
                    "          Creates a random level and solves it.\n"
                    "  --gdl\n"
                    "          Generates a .gdl file illustrating the solving steps.\n"
                    "  --plain-colours, -p\n"
                    "          Makes all cars white except own red car.\n"
                    "  --pylons\n"
                    "          Adds up to 2 pylons when using --random\n"
                    "  --safari\n"
                    "          Uses cargo style exit car like Safari Rush Hour\n");
                exit (0);
            }
            else
                eprintf (C_TAG_FATAL, 0, "Unknown option: -%s", arg);
        }
        else
            level= erwin_strtol (arg);
    }

    GDLWriter *gdl_writer= NULL;
    if (gdl)
       gdl_writer= new GDLWriter (VChar().format ("solution%d.gdl", level));

    Board board;
    if (random_level) {
      while (1) {
        int steps = 0;
        while (steps <= 30) {
            dkcount = 0;
            board.randomize (rand_twos, rand_threes);
            steps = game_run (gdl_writer, &board);
            int clean_count = 0;
            while (!board_list.empty()) {
                Board *clean_board = board_list.back();
                delete clean_board;
                board_list.pop_back();
                ++clean_count;
            }
            //fprintf(stderr, "Cleaned %d boards\n", clean_count);
        }           
        fflush(stdout);
      }
    } else
    if (!read_level (board, level))
        eprintf (C_TAG_FATAL, 0, "Unable to read level.\n");

    VChar level_name;
    level_name.format ("solution%d.ps", level);
    fps= fopen (level_name, "wt");
    if (!fps)
        eprintf (C_TAG_WARNING, 0, ERR_OPEN_WRITE, +level_name);

    if (fps)
        board.ps_header (fps);

#if 0
    board.show_ps (fps, 0, true);
    board.show_ps (fps, 1, true);
    board.show_ps (fps, 2, true);
    board.show_ps (fps, 3, true);
    board.show_ps (fps, 4, true);
    board.show_ps (fps, 5, true);
    board.show_ps (fps, 6, true);
    board.show_ps (fps, 7, true);
    board.show_ps (fps, 8, true);
#endif

    if (!random_level) {
        board.show (stdout);
        game_run (gdl_writer, &board);
    }

    if (fps) {
        board.ps_trailer (fps);
        fclose (fps);
    }

    if (gdl_writer)
        delete gdl_writer;

    exit (err_count(0,C_TAG_ERRORS) > 0 ? EXIT_FAILURE : EXIT_SUCCESS);
}

/*
one_off()
{

board.clear();
board.put_car(0, 0, 3, 1, 14);
board.put_car(5, 0, 2, 2, CARGO1);
board.put_car(0, 1, 2, 1, 2);
board.put_car(4, 1, 1, 2, 3);
board.put_car(0, 2, 1, 3, 15);
board.put_car(1, 2, 1, 1, WALL);
board.put_car(2, 2, 2, 1, 4);
board.put_car(1, 3, 2, 1, 5);
board.put_car(3, 3, 2, 2, MYSELF1);
board.put_car(6, 3, 1, 2, 6);
board.put_car(1, 4, 2, 2, CARGO2);
board.put_car(5, 4, 1, 1, WALL);
board.put_car(3, 5, 2, 1, 7);
board.put_car(6, 5, 1, 2, 8);
board.put_car(0, 6, 2, 1, 9);
board.put_car(2, 6, 3, 1, 16); 
board.learn_cars();
}
*/
