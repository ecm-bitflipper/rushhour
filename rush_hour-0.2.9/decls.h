typedef char const *symbol_t;
struct Car;
typedef int Colour;

typedef int Colour;
typedef int Move;

struct RGBColour;

#define FREE    0
#define WALL   -1

#define CARGO1   19
#define CARGO2   20

#define MYSELF1  24
#define MYSELF2  25
#define MYSELF3  26
  /* if you change this, change rush_hour.cpp, too, especially rgb_colour. */

#define FORWARD  0
#define BACKWARD 1
#define DOWN     2
#define UP       3

struct Board;
struct Edge;
struct Node;

extern hashval_t board_hash (Board const *);
extern int       board_cmp  (Board const *, Board const *);
