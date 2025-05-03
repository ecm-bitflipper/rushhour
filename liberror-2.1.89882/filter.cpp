// -*- Mode: C++ -*-

#include "liberror.h"
#include "internal.h"
#include "failure.h"

err_filter_t::err_filter_t():
    last (0),
    last_decided (false)
{}

void err_filter_t::clear ()
{
    tag.clear();
    message.clear();
    last= 0;
}

static ErrFilter filter_show;
static ErrFilter filter_issue;

#define TRUE_P ((ErrFilterElement)&filter_show)
   /* This is != NULL and thus represents true instead of false.  That's all we
    * need here.  Other modules really store something. */

#if ERR_REINIT
void err_filter_init()
{
    filter_show.clear ();
    filter_issue.clear ();
}
#endif

char const *err_decision_to_char_p(err_decision_t allow)
{
    switch (allow) {
    case ERR_NO:       return "no";
    case ERR_YES:      return "yes";
    case ERR_WEAK_NO:  return "weak no";
    case ERR_WEAK_YES: return "weak yes";
    case ERR_DEFAULT:  return "default";
    }
    nothing_if_reached ();
    return "unknown!";
}

char const *err_subsystem_name (int tag)
{
    if (int i= tag & C_TAG_SUBSYSTEM_MASK)
        return err_subsystem_names.find (i);
    return NULL;
}

char const *err_group_name (int tag)
{
    if (int i= tag & C_TAG_GROUP_MASK)
        return err_group_names.find (i);
    return NULL;
}

ErrVChar err_tag_full_description (int x)
{
    ErrVChar result;
    switch (x) {
    case 0:
        result.append ("no tag");
        break;
    case C_TAG_MORE:
        result.append ("more");
        break;
    case C_TAG_PREFIX:
        result.append ("prefix");
        break;
    case C_TAG_SUFFIX:
        result.append ("suffix");
        break;
    default:
        ERR_FOR_SOME_TAGS (x,
            if (result.non_empty()) result.append (", ");
            result.append (err_tag_description (NULL, tag, 0)));

        if (x & C_TAG_VARIANT)
            result.append (" (variant)");

        if (x & C_TAG_GROUP_MASK)
            result.format ("; group %s",
                err_group_names.find (x & C_TAG_GROUP_MASK));

        if (x & C_TAG_SUBSYSTEM_MASK)
            result.format ("; subsystem %s",
                err_subsystem_names.find (x & C_TAG_SUBSYSTEM_MASK));
        break;
    }

    return result;
}

/* ********************************************************************** */
/* Filtering */

static bool err_filter_aux (
    ErrFilterMap &filter, int val, err_decision_t allow, ErrFilterElement truep)
{
    switch (allow) {
    case ERR_NO:       filter.set    (val, 0);     break;
    case ERR_YES:      filter.set    (val, truep); break;
    case ERR_WEAK_NO:  filter.insert (val, 0);     break;
    case ERR_WEAK_YES: filter.insert (val, truep); break;
    case ERR_DEFAULT:  filter.erase  (val);        break;
    }
    return err_map_errno == ERR_MAP_OK;
}

bool err_filter (
    ErrFilter &filter, int tags, ErrDevel devel, err_decision_t allow, ErrFilterElement truep)
{
    if ((tags & C_TAG_MASK) == 0)
        tags|= C_TAG_ALL;

    ERR_IF_DEBUG_SHOW2 (
        fprintf (stderr, "DEBUG: setting filter %p to %d (=%s) for %s\n",
            &filter,
            allow,
            err_decision_to_char_p (allow),
            err_tag_full_description (tags).as_array()));

    bool result= false;
    if (devel & ERR_DEVEL_ONLY) {
        ERR_FOR_SOME_TAGS (tags & ~C_TAG_DEBUG,
            result|= err_filter_aux (
                filter.tag,
                tag | C_TAG_DEBUG | (tags & (C_TAG_GROUP_MASK | C_TAG_SUBSYSTEM_MASK)),
                allow,
                truep));
    }
    if (devel & ERR_RELEASE_ONLY) {
        ERR_FOR_SOME_TAGS (tags,
            result|= err_filter_aux (
                filter.tag,
                tag | (tags & (C_TAG_GROUP_MASK | C_TAG_SUBSYSTEM_MASK)),
                allow,
                truep));
    }
    return result;
}

bool err_filter_message (
    ErrFilter &filter, int number, err_decision_t allow, ErrFilterElement truep)
{
    ERR_IF_DEBUG_SHOW2 (
        fprintf (stderr, "DEBUG: setting filter %p to %d (=%s) for message no %d\n",
            &filter,
            allow,
            err_decision_to_char_p (allow),
            number));

    return err_filter_aux (filter.message, number, allow, truep);
}

void err_merge_filter (ErrFilter &target, ErrFilter &source, int specialise)
{
    int key;
    ErrFilterElement value;

    err_map_forall (source.tag, key, value) {
        ERR_IF_DEBUG_SHOW2 (
            fprintf (stderr, "DEBUG: overwriting filter %p to %d for %s\n",
                &target.tag,
                value ? 1 : 0,
                err_tag_full_description (key | specialise).as_array()));
        target.tag.set (key | specialise, value);
    }

    err_map_forall (source.message, key, value) {
        ERR_IF_DEBUG_SHOW2 (
            fprintf (stderr, "DEBUG: setting filter %p to %d for message no %d\n",
                &target.message,
                value ? 1 : 0,
                key));
        target.message.set (key, value);
    }
}

ErrFilterElement err_lookup_filter (
    bool &decided, ErrFilter const &filter, int tag, int number, ErrFilterElement truep)
{
    ErrFilterElement do_allow= filter.last;

    decided= false;
    ERR_FOR_DEBUG_SHOW2(char const *reason= "default";)

    if (tag == C_TAG_MORE) {
        decided= filter.last_decided;
        ERR_IF_DEBUG_SHOW2(reason= "last");
        if (do_allow && number != 0) {
            // Filter by additional number given for C_TAG_MORE, but only if the
            // main message was issued.
            ErrFilterElement a= filter.message.find (number);
            if (err_map_errno == ERR_MAP_OK) {
                do_allow= a;
                decided= true;
                ERR_IF_DEBUG_SHOW2(reason= "last & more");
            }
        }
    }
    else {
        return0_if_fail_pxx (ERR_SINGLE_TAG (tag), tag, ERR_PURE_TAG (tag));

        // errors that cannot be filtered:
        int pure_tag= ERR_PURE_TAG (tag);

        // filter by message number
        if (err_tag_string (pure_tag) == NULL) {
            do_allow= truep;  // These have no number, so we will normally show them unless
                              // other filtering is done.
            decided= false;   // This is the default that may be overridden by tag filtering
            ERR_IF_DEBUG_SHOW2(reason= "no number");
        }
        else {
            do_allow= filter.message.find (number);
            decided= (err_map_errno == ERR_MAP_OK);
            ERR_IF_DEBUG_SHOW2(reason= "number");
        }

        // filter by exactly this tag
        if (!decided) {
            do_allow= filter.tag.find (tag);
            decided= (err_map_errno == ERR_MAP_OK);
            ERR_IF_DEBUG_SHOW2(reason= "full tag");
        }

        // filter by tag & group & subsystem
        if (!decided &&
            (tag & C_TAG_GROUP_MASK) != 0 &&
            (tag & C_TAG_SUBSYSTEM_MASK) != 0)
        {
            int test_tag= pure_tag | (tag & (C_TAG_GROUP_MASK | C_TAG_SUBSYSTEM_MASK));
            if (ERR_IS_DEVEL(tag)) {
                do_allow= filter.tag.find (test_tag | C_TAG_DEBUG);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag+group+subsystem+devel");
            }
            if (!decided) {
                do_allow= filter.tag.find (test_tag);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag+group+subsystem");
            }
        }

        // filter by tag & group
        if (!decided && (tag & C_TAG_GROUP_MASK) != 0) {
            int test_tag= pure_tag | (tag & C_TAG_GROUP_MASK);
            if (ERR_IS_DEVEL(tag)) {
                do_allow= filter.tag.find (test_tag | C_TAG_DEBUG);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag+group+devel");
            }
            if (!decided) {
                do_allow= filter.tag.find (test_tag);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag+group");
            }
        }

        // filter by tag & subsystem
        if (!decided && (tag & C_TAG_SUBSYSTEM_MASK) != 0) {
            int test_tag= pure_tag | (tag & C_TAG_SUBSYSTEM_MASK);
            if (ERR_IS_DEVEL(tag)) {
                do_allow= filter.tag.find (test_tag | C_TAG_DEBUG);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag+subsystem+devel");
            }
            if (!decided) {
                do_allow= filter.tag.find (test_tag);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag+subsystem");
            }
        }

        // filter by tag
        if (!decided) {
            if (ERR_IS_DEVEL (tag)) {
                do_allow= filter.tag.find (pure_tag | C_TAG_DEBUG);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag+devel");
            }
            if (!decided) {
                do_allow= filter.tag.find (pure_tag);
                decided= (err_map_errno == ERR_MAP_OK);
                ERR_IF_DEBUG_SHOW2(reason= "tag");
            }
        }

        if (!decided) {
            // use default for this tag
#ifdef NDEBUG
            do_allow= (tag & C_TAG_DEBUG) ? (ErrFilterElement)0 : truep;
#else
            do_allow= truep;
#endif
        }
    }

    ERR_IF_DEBUG_SHOW2(
        fprintf (stderr, "DEBUG:ERR: by %s: filter %p: allow=%d, decided=%d\n",
            reason,
            &filter,
            do_allow ? 1 : 0,
            decided));

    return do_allow;
}

/* show/hide */
void err_show (int x, err_decision_t show)
{
    err_filter (filter_show, x, ERR_RELEASE_ONLY, show, TRUE_P);
}

void err_show_devel (int x, err_decision_t show)
{
    err_filter (filter_show, x, ERR_DEVEL_ONLY, show, TRUE_P);
}

void /*err-skip*/err_show_message (int x, err_decision_t show)
{
    err_filter_message (filter_show, x, show, TRUE_P);
}

static ERR_BOOL /*err-skip*/err_is_shown (bool &decided, int tag, int number)
{
    decided= true;
    return err_flushing ||  /* During flushing, all show-filters are switched off. */
           (bool)err_lookup_filter (decided, filter_show, tag, number, TRUE_P);
}

ERR_BOOL /*err-skip*/err_is_shown (int tag, int number)
{
    bool decided;
    return err_is_shown (decided, tag, number);
}

bool err_is_shown_set_last  (int tag, int number)
{
    bool decided;
    filter_show.last=
        /*err-skip*/err_is_shown (decided, tag, number) ? TRUE_P : (ErrFilterElement)0;
    filter_show.last_decided= true;
    return (bool)filter_show.last;
}

void err_set_quiet_level (int quiet)
{
    if (quiet > 0)
    switch (quiet) {
        default:
        case 6:
            err_show (C_TAG_FATAL,    ERR_WEAK_NO);
            err_show (C_TAG_ASSERT,   ERR_WEAK_NO);
        case 5:
            err_show (C_TAG_INTERNAL, ERR_WEAK_NO);
            err_show (C_TAG_ERROR,    ERR_WEAK_NO);
        case 4:
            err_show (C_TAG_WARN,     ERR_WEAK_NO);
        case 3:
            err_show (C_TAG_INFO,     ERR_WEAK_NO);
        case 2:
            err_show (C_TAG_NOTE,     ERR_WEAK_NO);
        case 1:
            err_show (C_TAG_PROGRESS, ERR_WEAK_NO);
            err_show (C_TAG_BANNER,   ERR_WEAK_NO);
        break;
    }
}

void err_set_quiet_level_devel (int quiet)
{
    if (quiet > 0)
    switch (quiet) {
        default:
        case 6:
            err_show_devel (C_TAG_FATAL,    ERR_WEAK_NO);
            err_show_devel (C_TAG_ASSERT,   ERR_WEAK_NO);
        case 5:
            err_show_devel (C_TAG_INTERNAL, ERR_WEAK_NO);
            err_show_devel (C_TAG_ERROR,    ERR_WEAK_NO);
        case 4:
            err_show_devel (C_TAG_WARN,     ERR_WEAK_NO);
        case 3:
            err_show_devel (C_TAG_INFO,     ERR_WEAK_NO);
        case 2:
            err_show_devel (C_TAG_NOTE,     ERR_WEAK_NO);
        case 1:
            err_show_devel (C_TAG_PROGRESS, ERR_WEAK_NO);
            err_show_devel (C_TAG_BANNER,   ERR_WEAK_NO);
        break;
    }
}

void err_stream_set_quiet_level_aux (ErrFormattedStream *stream, int quiet, ErrDevel devel)
{
    return_if_null (stream);
    if (quiet > 0)
    switch (quiet) {
        default:
        case 6:
            err_print_aux (stream, C_TAG_FATAL,    devel, ERR_WEAK_NO);
            err_print_aux (stream, C_TAG_ASSERT,   devel, ERR_WEAK_NO);
        case 5:
            err_print_aux (stream, C_TAG_INTERNAL, devel, ERR_WEAK_NO);
            err_print_aux (stream, C_TAG_ERROR,    devel, ERR_WEAK_NO);
        case 4:
            err_print_aux (stream, C_TAG_WARN,     devel, ERR_WEAK_NO);
        case 3:
            err_print_aux (stream, C_TAG_INFO,     devel, ERR_WEAK_NO);
        case 2:
            err_print_aux (stream, C_TAG_NOTE,     devel, ERR_WEAK_NO);
        case 1:
            err_print_aux (stream, C_TAG_PROGRESS, devel, ERR_WEAK_NO);
            err_print_aux (stream, C_TAG_BANNER,   devel, ERR_WEAK_NO);
        break;
    }
}

void err_stream_set_quiet_level (FILE *file, int quiet)
{
    err_stream_set_quiet_level_aux (err_get_stream (file), quiet, ERR_RELEASE_ONLY);
}

void err_stream_set_quiet_level_devel (FILE *file, int quiet)
{
    err_stream_set_quiet_level_aux (err_get_stream (file), quiet, ERR_DEVEL_ONLY);
}

/* issue/suppress */
void err_issue (int x, err_decision_t issue)
{
    err_filter (filter_issue, x, ERR_RELEASE_ONLY, issue, TRUE_P);
}

void err_issue_devel (int x, err_decision_t issue)
{
    err_filter (filter_issue, x, ERR_DEVEL_ONLY, issue, TRUE_P);
}

void /*err-skip*/err_issue_message (int x, err_decision_t issue)
{
    err_filter_message (filter_issue, x, issue, TRUE_P);
}

ERR_BOOL /*err-skip*/err_is_issued (bool &decided, int tag, int number)
{
    decided= true;
    int pure_tag= ERR_PURE_TAG (tag);
    if (pure_tag == C_TAG_FATAL || pure_tag == C_TAG_ASSERT)
        return true;
    return (bool)err_lookup_filter (decided, filter_issue, tag, number, TRUE_P);
}

ERR_BOOL /*err-skip*/err_is_issued (int tag, int number)
{
    bool decided;
    return err_is_issued (decided, tag, number);
}

bool err_is_issued_set_last (bool &user_wants_filter, int tag, int number)
{
    bool decided;
    filter_issue.last=
        /*err-skip*/err_is_issued (decided, tag, number) ? TRUE_P : (ErrFilterElement)0;
    filter_issue.last_decided= decided;
    user_wants_filter= (bool)err_lookup_filter (decided, filter_issue, tag, number, TRUE_P);
    return (bool)filter_issue.last;
}

void /*err-skip*/err_do_count (int tag, int number, err_status_t stat)
{
    if (tag != C_TAG_MORE && !ERR_IS_DEVEL (tag)) {
        return_if_fail_pxx (ERR_SINGLE_TAG (tag), tag, ERR_PURE_TAG (tag));
        int pure_tag= ERR_PURE_TAG (tag);
        err_add_count (stat, pure_tag | (tag & (C_TAG_SUBSYSTEM_MASK | C_TAG_GROUP_MASK)), 1);
        /*err-skip*/err_add_message_count (stat, number, 1);
    }
}

