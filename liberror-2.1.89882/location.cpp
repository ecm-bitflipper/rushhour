// -*- Mode: C++ -*-

#include "liberror.h"
#include "internal.h"
#include "failure.h"

void err_ext_address_init (err_ext_address_t *s, err_ext_address_class_t const *c)
{
    s->klass= c;
}

/* ********************************************************************** */
/* ext_address_t */

void err_normal_address_destruct (err_ext_address_t *x)
{
    delete x;
}

err_ext_address_t *err_normal_address_clone (err_ext_address_t const *s)
{
    err_normal_address_t const *self= (err_normal_address_t const *)s;
    return0_if_null (self);
    return (err_ext_address_t *)new ErrNormalAddress (self->address);
}

void err_normal_address_format_preposition (err_v_char_t *target, err_preposition_t prep)
{
    switch (prep) {
    case ERR_PREP_NONE: break;

    case ERR_PREP_CAPITAL_AT:   err_v_char_append_string (target, "At ");   break;
    case ERR_PREP_CAPITAL_FROM: err_v_char_append_string (target, "From "); break;
    case ERR_PREP_CAPITAL_TO:   err_v_char_append_string (target, "To ");   break;

    case ERR_PREP_LOWER_AT:     err_v_char_append_string (target, "at ");   break;
    case ERR_PREP_LOWER_FROM:   err_v_char_append_string (target, "from "); break;
    case ERR_PREP_LOWER_TO:     err_v_char_append_string (target, "to ");   break;
    }
}

void err_normal_address_format (
    err_v_char_t *target, err_ext_address_t const *s, err_preposition_t prep)
{
    err_normal_address_t const *self= (err_normal_address_t const *)s;
    return_if_null (self);
    err_normal_address_format_preposition (target, prep);
    err_v_char_format (target, "address "ERR_FORMAT_ADDRESS, self->address);
}

void err_normal_address_format_ext (
    err_v_char_t *target, err_ext_address_t const *s,
    err_preposition_t prep, err_format_style_t st)
{
    err_normal_address_t const *self= (err_normal_address_t const *)s;
    return_if_null (self);
    err_normal_address_format_preposition (target, prep);
    switch (st) {
    case ERR_FS_HUMAN:
        err_v_char_format (target, "address "ERR_FORMAT_ADDRESS, self->address);
        break;
    case ERR_FS_ADDRESS:
        err_v_char_format (target, ERR_FORMAT_ADDRESS, self->address);
        break;
    case ERR_FS_ROUTINE:
    case ERR_FS_ROUTINE_ID:
    case ERR_FS_LOCATION_ID:
        break;
    }
}

err_address_t err_normal_address_to_linear (err_ext_address_t const *s)
{
    err_normal_address_t const *self= (err_normal_address_t const *)s;
    return0_if_null (self);
    return self->address;
}

err_ext_address_class_t const err_normal_address_class_s= {
    err_normal_address_destruct,
    err_normal_address_clone,
    err_normal_address_format,
    err_normal_address_to_linear,
    NULL,
    err_normal_address_format_ext
};

/* ********************************************************************** */
/** Locations **/

/* err_position_t */
void err_position_t::release ()
{
    return_if_null (refcount);
    return_if_fail (*refcount > 0);
    if (--*refcount == 0) {
        /* last copy, so free on heap */
        delete refcount;
        refcount= NULL;
        err_string_free (file);
        if (address) {
            address->destruct();
            address= NULL;
        }
    }
}

void err_position_t::import (char const *a, int b, int c, ErrExtAddress *d)
{
    refcount=  new int;
    *refcount= 1;
    return_if_null (refcount);
    return_if_fail (*refcount > 0);

    file=      err_string_dup (a);
    line=      b;
    pos=       c;
    address=   d;
}

void err_position_t::import (int *r, char *a, int b, int c, ErrExtAddress *d)
{
    refcount=  r;
    (*refcount)++;
    return_if_null (refcount);
    return_if_fail (*refcount > 0);

    file=      a;
    line=      b;
    pos=       c;
    address=   d;

}

static err_ext_address_t *clone(err_ext_address_t const *d)
{
    return d ? d->clone() : NULL;
}

/* always makes a new copy */
err_position_t::err_position_t (char const *a, int b, int c)
{
    import (a, b, c, NULL);
}

/* always makes a new copy */
err_position_t::err_position_t (err_address_t a)
{
    import (NULL, 0, 0, (err_ext_address_t *)new ErrNormalAddress(a));
}

/* always makes a new copy */
err_position_t::err_position_t (err_ext_address_t const &a)
{
    import (NULL, 0, 0, clone(&a));
}

/* always makes a new copy */
err_position_t::err_position_t (err_ext_address_t const *a)
{
    import (NULL, 0, 0, clone(a));
}

/* makes a shared object without copying */
err_position_t::err_position_t (err_position_t const &a)
{
    import (a.refcount, a.file, a.line, a.pos, a.address);
}

/* makes a shared object without copying */
void err_position_t::operator= (err_position_t const &a)
{
    if (this != &a && refcount != a.refcount) {
        release ();
        import (a.refcount, a.file, a.line, a.pos, a.address);
    }
}

/* makes a shared object without copying */
void err_position_t::operator= (err_area_t const &a)
{
    *this= a.first;
}

/* makes a shared object without copying */
void err_position_t::operator= (err_location_t const &a)
{
    *this= a.here.first;
}

err_position_t::~err_position_t ()
{
    release ();
}

/* always makes a new copy */
void err_position_t::set_position (char const *a, int b, int c)
{
    err_position_t old= *this;             /* copy (we need old.address) */
    release();                             /* release this */
    import (a, b, c, clone(old.address));  /* init with new and old data */
                                           /* autodelete copy */
}

err_position_t::operator err_area_t const *() const
{
    static ErrArea loc;
    loc= ErrArea (*this);
    return &loc;
}

err_position_t::operator err_area_t () const
{
    return ErrArea (*this);
}

err_position_t::operator err_location_t const *() const
{
    static ErrLocation loc;
    loc= ErrLocation (*this);
    return &loc;
}

err_position_t::operator err_location_t () const
{
    return ErrLocation (*this);
}

/* err_area_t */
err_area_t::err_area_t (char const *a, int b, int c):
    first (a, b, c)
{
}

err_area_t::err_area_t (err_address_t a):
    first (a)
{
}

err_area_t::err_area_t (err_ext_address_t const *a):
    first (a)
{
}

err_area_t::err_area_t (err_ext_address_t const &a):
    first (a)
{
}

err_area_t::err_area_t (err_position_t const &a):
    first (a)
{
}

err_area_t::err_area_t (err_position_t const &a, err_position_t const &b):
    first (a),
    last  (b)
{
}

err_area_t::err_area_t (err_area_t const &a):
    first (a.first),
    last  (a.last)
{
}

void err_area_t::operator= (err_position_t const &a)
{
    first= a;
    last=  ErrPosition();
}

void err_area_t::operator= (err_area_t const &a)
{
    first= a.first;
    last=  a.last;
}

void err_area_t::operator= (err_location_t const &a)
{
    first= a.here.first;
    last=  a.here.last;
}

err_area_t::~err_area_t ()
{
}

err_area_t::operator err_location_t const *() const
{
    static ErrLocation loc;
    loc= ErrLocation (*this);
    return &loc;
}

err_area_t::operator err_location_t () const
{
    return ErrLocation (*this);
}

/* err_location_t */
err_location_t::err_location_t (char const *a, int b, int c):
    here (a, b, c),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_address_t a):
    here (a),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_ext_address_t const &a):
    here (a),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_ext_address_t const *a):
    here (a),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_position_t const &a):
    here (a),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_position_t const &a, err_position_t const &b):
    here (a, b),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_area_t const &a):
    here (a),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_area_t const &a, err_area_t const &b):
    here (a),
    orig (b),
    next_loc (NULL),
    print_next (NULL)
{
}

err_location_t::err_location_t (err_location_t const &a):
    here (a.here),
    orig (a.orig),
    next_loc (NULL),
    print_next (NULL)
{
}

void err_location_t::operator= (err_position_t const &a)
{
    if (next_loc)
        delete next_loc;
    here= ErrArea (a);
    orig= ErrArea ();
}

void err_location_t::operator= (err_area_t const &a)
{
    if (next_loc)
        delete next_loc;
    here= a;
    orig= ErrArea();
}

void err_location_t::operator= (err_location_t const &a)
{
    if (next_loc)
        delete next_loc;
    next_loc= a.next_loc ? new err_location_t (*a.next_loc) : NULL;

    print_next= a.print_next;

    here= a.here;
    orig= a.orig;
}

err_location_t::~err_location_t ()
{
    if (next_loc)
        delete next_loc;
}

err_location_t &err_location_t::set_next (
    err_location_t const *loc,
    void (*print) (err_v_char_t *, err_location_t const *))
{
    if (loc != NULL) {
        return_val_if_fail (loc == NULL || print != NULL, *this);
    
        if (next_loc)
            delete next_loc;
        next_loc=   new err_location_t (*loc);
        print_next= print;
    }

    return *next_loc;
}

/* C interface */

err_location_t *err_in_file (char const *f)
{
    static ErrLocation loc;
    loc= ErrLocation (f);
    return &loc;
}

err_location_t *err_in_line (char const *f, int l)
{
    static ErrLocation loc;
    loc= ErrLocation (f, l);
    return &loc;
}

err_location_t *err_at_position (char const *f, int l, int p)
{
    static ErrLocation loc;
    loc= ErrLocation (f, l, p);
    return &loc;
}

err_location_t *err_at_address  (err_address_t a)
{
    static ErrLocation loc;
    loc= ErrLocation (a);
    return &loc;
}

err_location_t *err_at_ext_address  (err_ext_address_t const *a)
{
    static ErrLocation loc;
    loc= ErrLocation (a);
    return &loc;
}

/* C copying/deletion */
err_location_t *err_location_copy (err_location_t const *x)
{
    return new ErrLocation (*x);
}

void err_location_delete (err_location_t *x)
{
    delete x;
}


/* upto */
err_location_t *err_upto_file (err_location_t *l, char const *a)
{
    l->free_upto().last= ErrPosition (a);
    return l;
}

err_location_t *err_upto_line (err_location_t *l, char const *a, int b)
{
    l->free_upto().last= ErrPosition (a, b);
    return l;
}

err_location_t *err_upto_position (err_location_t *l, char const *a, int b, int c)
{
    l->free_upto().last= ErrPosition (a, b, c);
    return l;
}

err_location_t *err_upto_address (err_location_t *l, err_address_t a)
{
    l->free_upto().last= ErrPosition (a);
    return l;
}

err_location_t *err_upto_ext_address (err_location_t *l, err_ext_address_t const *a)
{
    l->free_upto().last= ErrPosition (a);
    return l;
}

/* originally */
err_location_t *err_originally_in_file (err_location_t *l, char const *a)
{
    l->free_orig()= ErrPosition (a);
    return l;
}

err_location_t *err_originally_in_line (err_location_t *l, char const *a, int b)
{
    l->free_orig()= ErrPosition (a, b);
    return l;
}

err_location_t *err_originally_at_position (err_location_t *l, char const *a, int b, int c)
{
    l->free_orig()= ErrPosition (a, b, c);
    return l;
}

err_location_t *err_originally_at_address (err_location_t *l, err_address_t a)
{
    l->free_orig()= ErrPosition (a);
    return l;
}

err_location_t *err_originally_at_ext_address (err_location_t *l, err_ext_address_t const *a)
{
    l->free_orig()= ErrPosition (a);
    return l;
}

err_location_t *err_set_next_loc (
    err_location_t *l,
    err_location_t const *n,
    void (*p)(err_v_char_t *, err_location_t const *))
{
    return &l->set_next (n, p);
}
