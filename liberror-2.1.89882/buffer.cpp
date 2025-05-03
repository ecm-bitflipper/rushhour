// -*- Mode: C++ -*-

#include "liberror.h"
#include "internal.h"
#include "failure.h"

static ErrVBuffer buffers;
bool err_flushing= false;

void err_flush_buffers(void)
{
    bool old_flushing= err_flushing;
    err_flushing= true;

    bool first= true;
    err_buffer_t *buffer;
    int level;
    err_vector_forall (buffers, level, buffer) {
        if (err_buffer_nentries (buffer) > 0) {
            if (first) {
                eprintf (ERR_TAG_DEBUG | ERR_TAG_WARNING, 0,
                    "Exiting prematurely, there are still unflushed error buffers.");
                first= false;
            }
            eprintf (ERR_TAG_DEBUG | ERR_TAG_MORE, 0,
                "Buffer on nesting level %d contains messages:", level);

            err_message_t *m;
            int i;
            err_buffer_forall (buffer, i, m) {
                ErrVChar text2;
                char const *tagstr= err_tag_string (m->tag);
                if (tagstr) {
                    text2.append (tagstr);
                    if (m->number > 0)
                        text2.format ("%05d", m->number);
                    text2.append (": ");
                }
                text2.append (m->text);
                leprintf (C_TAG_MORE, 0, &m->loc, "%s", text2.as_array());
                for (err_next_message_t *lauf= m->more; lauf; lauf= lauf->next)
                    leprintf (C_TAG_MORE, 0, &lauf->loc, "%s", lauf->text);
            }
        }
    }
    buffers.clear();

    err_flushing= old_flushing;
}

static void err_flush_buffers_perhaps(void)
{
    err_flushing= true;
#ifndef NDEBUG
    err_flush_buffers();
#endif
    buffers.clear();
}

void err_buffer_init()
{
#if ERR_REINIT
    buffers.clear (); // this is a potential memory leak, but the invocation of clear()
                      // is for sanity only and the underlying structure, buffers,
                      // assumed to be empty anyway.
    err_flushing= false;
#endif
    atexit (err_flush_buffers_perhaps);
}

/* ********************************************************************** */
/* Buffer handling */

void err_next_message_t::release ()
{
    err_string_free (text);
    if (next)
        delete next;
}

void err_next_message_t::import (
    int a, err_msg_info_t const &b, err_location_t const *c, char const *d, err_next_message_t *e)
{
    number= a;
    info= b;
    loc= *c;
    text= err_string_dup (d);
    next= err_next_message_copy (e);
}

err_next_message_t *err_next_message_copy (err_next_message_t const *orig)
{
    if (orig == NULL)
        return NULL;
    return new ErrNextMessage (*orig);
}

err_next_message_t::err_next_message_t (err_next_message_t const &x)
{
    import (x.number, x.info, x.loc, x.text, x.next);
}

err_next_message_t::err_next_message_t  (
    int a, err_msg_info_t const &b, err_location_t const *c, char const *d)
{
    import (a, b, c, d, NULL);
}

err_next_message_t::~err_next_message_t ()
{
    release ();
}

void err_next_message_t::operator = (err_next_message_t const &x)
{
    release ();
    import (x.number, x.info, x.loc, x.text, x.next);
}

/* **** */

void err_message_t::release ()
{
    err_string_free (text);
    if (more)
        delete more;
}

void err_message_t::import (
    int a, int b, err_msg_info_t const &c, err_location_t const *d, char const *e, err_next_message_t *f)
{
    tag= a;
    number= b;
    info= c;
    loc= *d;
    text= err_string_dup (e);
    more= err_next_message_copy (f);
    bottom= get_bottom ();
}

err_message_t::err_message_t (
    int a, int b, err_msg_info_t const &c, err_location_t const *d, char const *e)
{
    import (a, b, c, d, e, NULL);
}

err_message_t::err_message_t  (err_message_t const &x)
{
    import (x.tag, x.number, x.info, x.loc, x.text, x.more);
}

err_message_t::~err_message_t ()
{
    release ();
}

void err_message_t::operator= (err_message_t const &x)
{
    release ();
    import (x.tag, x.number, x.info, x.loc, x.text, x.more);
}

err_next_message_t **err_message_t::get_bottom()
{                                       
    err_next_message_t **lauf= &more;
    while (*lauf != NULL)
        lauf= &((*lauf)->next);
    return lauf;
}

void err_message_t::append (err_next_message_t *x)
{
    (*bottom)= x;
    while (*bottom != NULL)
        bottom= &((*bottom)->next);
}

err_message_t *err_message_copy (err_message_t const *orig, int *)
{
    if (orig == NULL)
        return NULL;
    return new ErrMessage (*orig);
}

void err_message_free (err_message_t *x)
{
    if (x != NULL)
        delete x;
}

static bool err_is_buffered_aux (err_buffer_t *&buffer, int tag, int orig_tag, int /*number*/)
{
    if (err_flushing)
        return false;

    int pure_orig_tag= (ERR_PURE_TAG (orig_tag));
    if (pure_orig_tag == C_TAG_FATAL ||      // these tags cannot be redirected into a buffer
        pure_orig_tag == C_TAG_ASSERTION)
        return false;

    if (buffers.empty ())
        return false;

    // select a buffer:
    buffer= buffers.last ();
    if (buffer != NULL && err_buffer_empty (buffer) && tag == C_TAG_MORE) {
        // it is impossible to append to the last error message, because
        // there is none, so we must output this error using the normal
        // mechanism.
        // FIXME: This should be propagated to the next level of buffering
        //        instead of not being buffered.
        return false;
    }

    return true;
}

ERR_BOOL err_is_buffered (int tag, int number)
{
    return0_if_fail (tag != C_TAG_MORE);
    err_buffer_t *buffer;
    return err_is_buffered_aux (buffer, tag, tag, number);
}

bool err_do_buffer (
    int tag, int orig_tag, int orig_number,
    err_msg_info_t const &info, err_location_t const *loc, char const *text)
{
    err_buffer_t *buffer;
    if (!err_is_buffered_aux (buffer, tag, orig_tag, orig_number))
        return false;

    if (buffer != NULL) {
        if (tag == C_TAG_MORE)
            err_buffer_last (buffer)
                ->append (new ErrNextMessage (orig_number, info, loc, text));
        else
            err_buffer_append (buffer,
                new ErrMessage (orig_tag, orig_number, info, loc, text));

        /*err-skip*/err_do_count (tag, orig_number, ERR_STATUS_BUFFERED);
    }
    return true;
}


/* ********************************************************************** */
/* Buffering */

void err_buffer_begin (err_buffer_t *buffer)
{
    buffers.append (buffer);
}

void err_buffer_end ()
{
    return_if_fail (!buffers.empty());
    buffers.chop ();
}

void err_re_issue (err_message_t *m)
{
    if (!m)
        return;
    // fprintf (stderr, "DEBUG:ERR: re-issue: m=%p\n", m);
    // fprintf (stderr, "DEBUG:ERR: re-issue: tag=%d, number=%d\n", m->tag, m->number);
    // fprintf (stderr, "DEBUG:ERR: re-issue: text='%s'\n", m->text);

    err_do_issue (m->tag, m->tag, m->number, m->number, m->info, &m->loc, m->text);
    for (err_next_message_t *lauf= m->more; lauf; lauf= lauf->next)
        err_do_issue (
            C_TAG_MORE, m->tag, lauf->number, m->number, m->info, &lauf->loc, lauf->text);
}

static void err_buffer_flush_internal (err_buffer_t *buffer, bool do_free)
{
    if (buffer == NULL)
        return;

    err_buffer_t *old_buffer= NULL;
    if (!buffers.empty() && buffers.last() == buffer) {
       // Pass the messages through to the next layer.
       old_buffer= buffers.last();
       err_buffer_end ();
    }

    int i;
    err_message_t *m;
    err_buffer_forall (buffer, i, m)
        err_re_issue (m);

    if (do_free)
        err_buffer_clear (buffer);

    // After passing the messages through, re-use old buffer.
    if (old_buffer)
        err_buffer_begin (old_buffer);
}

void err_buffer_re_issue (err_buffer_t *buffer)
{
    err_buffer_flush_internal (buffer, false);
}

void err_buffer_flush (err_buffer_t *buffer)
{
    err_buffer_flush_internal (buffer, true);
}
