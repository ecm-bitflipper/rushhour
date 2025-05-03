// -*- Mode: C++ -*-

#include "liberror.h"
#include "internal.h"
#include "failure.h"

#define ERR_COUNT_SEPARATELY 1

/* This is only internally used in order to prevent the user from
 * hiding error numbers from the error_codes script. */
#define ERR_COUNT_TYPE_TAG               (1 << 0)
/* #define ERR_COUNT_TYPE_TAG_OF            (1 << 1)*/
#define ERR_COUNT_TYPE_TAG_OF_SUBSYSTEM  (1 << 2)
#define ERR_COUNT_TYPE_TAG_OF_GROUP      (1 << 3)

#if ERR_COUNT_SEPARATELY
#define ERR_COUNT_TYPE_SUBSYSTEM         (1 << 4)
#define ERR_COUNT_TYPE_GROUP             (1 << 5)
#endif

#define ERR_COUNT_TYPE_MESSAGE           (1 << 6)

#define ERR_COUNT_TYPE_ALL (~0)

typedef int err_count_type_t;

struct ErrCountersForType {
    ErrMapIntInt received;
    ErrMapIntInt issued;
    ErrMapIntInt buffered;
    ErrMapIntInt distributed;
    ErrMapIntInt shown;
    ErrMapIntInt printed;

    ErrCountersForType()
    {}

    void clear ()
    {
        received.clear();
        issued.clear();
        buffered.clear();
        distributed.clear();
        shown.clear();
        printed.clear();
    }
};

struct ErrCounters {
    ErrCountersForType tag;
    ErrCountersForType tag_of_subsystem;
    ErrCountersForType tag_of_group;
    ErrCountersForType message;
#if ERR_COUNT_SEPARATELY
    ErrCountersForType subsystem;
    ErrCountersForType group;
#endif
    ErrCounters()
    {}

    void clear ()
    {
        tag.clear();
        tag_of_subsystem.clear();
        tag_of_group.clear();
        message.clear();
#if ERR_COUNT_SEPARATELY
        subsystem.clear();
        group.clear();
#endif
    }

};

ErrCounters counters;
ErrCountersForType fatal_counters;
ErrCountersForType fatal_message_counters;

/* ********************************************************************** */

void err_count_init ()
{
#if ERR_REINIT
        counters.clear();
        fatal_counters.clear();
        fatal_message_counters.clear();
#endif
}

/* ********************************************************************** */

#if ERR_COUNT_SEPARATELY
#  define ERR_IF_COUNT_SEPARATELY(X) X
#else
#  define ERR_IF_COUNT_SEPARATELY(X)
#endif

#define ERR_FOR_SOME_TYPES(types, invocation)                                         \
        do {                                                                          \
            int type;                                                                 \
            type= types & ERR_COUNT_TYPE_TAG;              if (type) { invocation; } \
            type= types & ERR_COUNT_TYPE_TAG_OF_SUBSYSTEM; if (type) { invocation; } \
            type= types & ERR_COUNT_TYPE_TAG_OF_GROUP;     if (type) { invocation; } \
            type= types & ERR_COUNT_TYPE_MESSAGE;          if (type) { invocation; } \
            ERR_IF_COUNT_SEPARATELY(                                                  \
            type= types & ERR_COUNT_TYPE_SUBSYSTEM;        if (type) { invocation; } \
            type= types & ERR_COUNT_TYPE_GROUP;            if (type) { invocation; } \
            );                                                                        \
        } while (0)

#define ERR_FOR_SOME_COUNTERS(number, null_means_all, invocation, return_command) \
        do {                                                                      \
            int tags= number & C_TAG_MASK;                                        \
            if (null_means_all && tags == 0)                                      \
                tags= C_TAG_ALL;                                                  \
                                                                                  \
            int subsystem= number & C_TAG_SUBSYSTEM_MASK;                         \
            int group=     number & C_TAG_GROUP_MASK;                             \
            int type;                                                             \
                                                                                  \
            if (group != 0) {                                                     \
                nothing_if_fail (subsystem == 0);                                 \
                ERR_IF_COUNT_SEPARATELY (                                         \
                    if (tags == C_TAG_ALL) {                                      \
                        type= ERR_COUNT_TYPE_GROUP;                               \
                        int const tag=  0;                                        \
                        invocation;                                               \
                        return_command;                                           \
                    }                                                             \
                );                                                                \
                type= ERR_COUNT_TYPE_TAG_OF_GROUP;                                \
            }                                                                     \
            else                                                                  \
            if (subsystem != 0) {                                                 \
                nothing_if_fail (group == 0);                                     \
                ERR_IF_COUNT_SEPARATELY (                                         \
                    if (tags == C_TAG_ALL) {                                      \
                        type= ERR_COUNT_TYPE_SUBSYSTEM;                           \
                        int const tag=  0;                                        \
                        invocation;                                               \
                        return_command;                                           \
                    }                                                             \
                );                                                                \
                type= ERR_COUNT_TYPE_TAG_OF_SUBSYSTEM;                            \
            }                                                                     \
            else                                                                  \
                type= ERR_COUNT_TYPE_TAG;                                         \
                                                                                  \
            ERR_FOR_SOME_TAGS (number, invocation);                               \
            return_command;                                                       \
       } while(0)

static ErrMapIntInt *err_count_map (ErrCountersForType &ctrs, err_status_t status)
{
    switch (status) {
    case ERR_STATUS_RECEIVED:    return &ctrs.received;
    case ERR_STATUS_ISSUED:      return &ctrs.issued;
    case ERR_STATUS_BUFFERED:    return &ctrs.buffered;
    case 0:
    case ERR_STATUS_DISTRIBUTED: return &ctrs.distributed;
    case ERR_STATUS_SHOWN:       return &ctrs.shown;
    case ERR_STATUS_PRINTED:     return &ctrs.printed;
    }
    return0_if_reached_px (status);
    return NULL;
}


static ErrMapIntInt *err_count_map (
    ErrCounters &ctrs, err_status_t status, err_count_type_t type)
{
    switch (type) {
    case ERR_COUNT_TYPE_TAG:
        return err_count_map (ctrs.tag, status);
    case ERR_COUNT_TYPE_TAG_OF_SUBSYSTEM:
        return err_count_map (ctrs.tag_of_subsystem, status);
    case ERR_COUNT_TYPE_TAG_OF_GROUP:
        return err_count_map (ctrs.tag_of_group, status);
    case ERR_COUNT_TYPE_MESSAGE:
        return err_count_map (ctrs.message, status);
#if ERR_COUNT_SEPARATELY
    case ERR_COUNT_TYPE_GROUP:
        return err_count_map (ctrs.group, status);
    case ERR_COUNT_TYPE_SUBSYSTEM:
        return err_count_map (ctrs.subsystem, status);
#endif
    }
    return0_if_reached_px (type);
    return NULL;
}

static int *err_count_ptr (
    ErrCounters &ctrs, err_status_t status, err_count_type_t type, int number, bool alloc)
{
    ErrMapIntInt *map= err_count_map (ctrs, status, type);
    return0_if_null (map);
    if (alloc)
        return &(*map)[number];
    else
        return map->find_ptr (number);
}

static int err_count_single (err_status_t status, err_count_type_t type, int number)
{
    int *ptr= err_count_ptr (counters, status, type, number, true);
    return0_if_null(ptr);
    return *ptr;
}

static void err_set_count_single (err_status_t status, err_count_type_t type, int number, int val)
{
    if (val == 0) {
        ErrMapIntInt *m= err_count_map (counters, status, type);
        return_if_null (m);
        m->erase (number);
    }
    else {
        int *ptr= err_count_ptr (counters, status, type, number, true);
        return_if_null(ptr);
        *ptr= val;
    }
}

static void err_add_count_single (err_status_t status, err_count_type_t type, int number, int val)
{
    int *ptr= err_count_ptr (counters, status, type, number, true);
    return_if_null(ptr);
    *ptr+= val;
}

int err_count (err_status_t status, int number)
{
    int result= 0;
    bool no_tags= false;

    if ((number & C_TAG_MASK) == 0) {
        no_tags= true;
        number|= C_TAG_ERRORS;
    }

    int tags=      number & C_TAG_MASK;
    int subsystem= number & C_TAG_SUBSYSTEM_MASK;
    int group=     number & C_TAG_GROUP_MASK;
    int type;

    if (group != 0) {
        nothing_if_fail (subsystem == 0);
        ERR_IF_COUNT_SEPARATELY (
            if (no_tags)
                return err_count_single (status, ERR_COUNT_TYPE_GROUP, group);
        );
        type= ERR_COUNT_TYPE_TAG_OF_GROUP;
    }
    else
    if (subsystem != 0) {
        nothing_if_fail (group == 0);
        ERR_IF_COUNT_SEPARATELY (
            if (tags == C_TAG_ALL)
                return err_count_single (status, ERR_COUNT_TYPE_SUBSYSTEM, subsystem);
        );
        type= ERR_COUNT_TYPE_TAG_OF_SUBSYSTEM;
    }
    else
        type= ERR_COUNT_TYPE_TAG;

    ERR_FOR_SOME_TAGS (number,
        result+= err_count_single (status, type, tag | group | subsystem));

    return result;
}

static void err_set_count_aux (err_status_t status, int number, int val)
{
    int tags=      number & C_TAG_MASK;
    int subsystem= number & C_TAG_SUBSYSTEM_MASK;
    int group=     number & C_TAG_GROUP_MASK;
    int type;

    if (group != 0) {
        nothing_if_fail (subsystem == 0);
        ERR_IF_COUNT_SEPARATELY (
            if (tags == C_TAG_ALL) {
                int total= 0;
                for (int i= tags; i; i >>= 1)
                   total+= val;
                err_set_count_single (status, ERR_COUNT_TYPE_GROUP, group, total);
            }
        );
        type= ERR_COUNT_TYPE_TAG_OF_GROUP;
    }
    else
    if (subsystem != 0) {
        nothing_if_fail (group == 0);
        ERR_IF_COUNT_SEPARATELY (
            if (tags == C_TAG_ALL) {
                int total= 0;
                for (int i= tags; i; i >>= 1)
                   total+= val;
                err_set_count_single (status, ERR_COUNT_TYPE_SUBSYSTEM, subsystem, total);
            }
        );
        type= ERR_COUNT_TYPE_TAG_OF_SUBSYSTEM;
    }
    else
        type= ERR_COUNT_TYPE_TAG;

    ERR_FOR_SOME_TAGS (number,
        err_set_count_single (status, type, tag | group | subsystem, val));
}

void err_set_count (err_status_t statuses, int number, int val)
{
    ERR_FOR_SOME_STATUSES (statuses, err_set_count_aux (status, number, val));
}

static void err_add_count_aux (err_status_t status, int number, int val)
{
    int tags=      number & C_TAG_MASK;
    int subsystem= number & C_TAG_SUBSYSTEM_MASK;
    int group=     number & C_TAG_GROUP_MASK;

    if (group != 0) {
        ERR_IF_COUNT_SEPARATELY (
            if (tags == C_TAG_ALL) {
                int total= 0;
                for (int i= tags; i; i >>= 1)
                   total+= val;
                err_add_count_single (status, ERR_COUNT_TYPE_GROUP, group, total);
            }
        );
        ERR_FOR_SOME_TAGS (number,
            err_add_count_single (status, ERR_COUNT_TYPE_TAG_OF_GROUP, tag | group, val));
    }

    if (subsystem != 0) {
        ERR_IF_COUNT_SEPARATELY (
            if (tags == C_TAG_ALL) {
                int total= 0;
                for (int i= tags; i; i >>= 1)
                   total+= val;
                err_add_count_single (status, ERR_COUNT_TYPE_SUBSYSTEM, subsystem, total);
            }
        );
        ERR_FOR_SOME_TAGS (number,
            err_add_count_single (status, ERR_COUNT_TYPE_TAG_OF_SUBSYSTEM, tag | subsystem, val));
    }

    ERR_FOR_SOME_TAGS (number,
        err_add_count_single (status, ERR_COUNT_TYPE_TAG, tag, val));
}

void /*err-skip*/err_add_count (err_status_t statuses, int number, int val)
{
    ERR_FOR_SOME_STATUSES (statuses, err_add_count_aux (status, number, val));
}

void err_clear_all_count (err_status_t statuses)
{
    ERR_FOR_SOME_STATUSES (statuses,
        ERR_FOR_SOME_TYPES (ERR_COUNT_TYPE_ALL,
            err_count_map (counters, status, type)->clear ()));
}

void /*err-skip*/err_clear_count (err_status_t statuses, int number)
{
    err_set_count (statuses, number, 0);
}

int /*err-skip*/err_message_count (err_status_t status, int number)
{
    return err_count_single (status, ERR_COUNT_TYPE_MESSAGE, number);
}

static inline int *err_message_count_ptr (err_status_t status, int number)
{
    return err_count_ptr (counters, status, ERR_COUNT_TYPE_MESSAGE, number, true);
}

void /*err-skip*/err_set_message_count (err_status_t statuses, int number, int val)
{
    ERR_FOR_SOME_STATUSES (statuses,
        err_set_count_single (status, ERR_COUNT_TYPE_MESSAGE, number, val));
}

void /*err-skip*/err_add_message_count (err_status_t statuses, int number, int val)
{
    ERR_FOR_SOME_STATUSES (statuses,
        err_add_count_single (status, ERR_COUNT_TYPE_MESSAGE, number, val));
}

void /*err-skip*/err_clear_message_count (err_status_t status, int number)
{
    /*err-skip*/err_set_message_count (status, number, 0);
}

/* ********************************************************************** */
/* fatal counts */

void err_set_fatal_count (err_status_t statuses, int tag, int cnt)
{
    return_if_fail (cnt > 0);
    ERR_FOR_SOME_STATUSES (statuses,
        err_count_map (fatal_counters, status)->set (tag, cnt));
}

void err_unset_fatal_count (err_status_t statuses, int tag)
{
    ERR_FOR_SOME_STATUSES (statuses,
        err_count_map (fatal_counters, status)->erase (tag));
}

void err_unset_all_fatal_count (err_status_t statuses)
{
    ERR_FOR_SOME_STATUSES (statuses,
        err_count_map (fatal_counters, status)->clear());
}

void /*err-skip*/err_set_fatal_message_count (err_status_t statuses, int num, int cnt)
{
    return_if_fail (cnt > 0);
    ERR_FOR_SOME_STATUSES (statuses,
        err_count_map (fatal_message_counters, status)->set (num, cnt));
}

void /*err-skip*/err_unset_fatal_message_count (err_status_t statuses, int num)
{
    ERR_FOR_SOME_STATUSES (statuses,
        err_count_map (fatal_message_counters, status)->erase (num));
}

void /*err-skip*/err_unset_all_fatal_message_count (err_status_t statuses)
{
    ERR_FOR_SOME_STATUSES (statuses,
        err_count_map (fatal_message_counters, status)->clear());
}

static int err_fatal_count_min (int result, int count)
{
    if (count == -2) // uninitialised
        return result;
    if (result == -2) // uninitialised
        return count;
    if (count == -1 || result == -1) // unset
        return -1;
    return count < result ? count : result; // real minimum
}

static int err_fatal_count_single (err_status_t status, int number)
{
    int *countp= err_count_map (fatal_counters, status)->find_ptr (number);
    if (countp == NULL)
        return -1;
    return *countp;
}

int err_fatal_count (err_status_t statuses, int number)
{
    int result= -2;
    ERR_FOR_SOME_STATUSES (statuses,
        result= err_fatal_count_min (result, err_fatal_count_single (status, number));
        if (result == -1)
            return -1;
    );
    return result < 0 ? -1 : result;
}

int /*err-skip*/err_fatal_message_count_single (err_status_t status, int number)
{
    int *countp= err_count_map (fatal_message_counters, status)->find_ptr (number);
    if (countp == NULL)
        return -1;
    return *countp;
}

int /*err-skip*/err_fatal_message_count (err_status_t statuses, int number)
{
    int result= -2;
    ERR_FOR_SOME_STATUSES (statuses,
        result= err_fatal_count_min (result, err_fatal_message_count_single (status, number));
        if (result == -1)
            return -1;
    );
    return result < 0 ? -1 : result;
}

/* ********************************************************************** */
/* counting and possibly fatal exit */

static char const *err_status_description (err_status_t status)
{
    switch (status) {
    case ERR_STATUS_RECEIVED:    return "received";
    case ERR_STATUS_ISSUED:      return "issued";
    case ERR_STATUS_BUFFERED:    return "buffered";
    case ERR_STATUS_DISTRIBUTED: return "distributed";
    case ERR_STATUS_SHOWN:       return "shown";
    case ERR_STATUS_PRINTED:     return "printed";
    }
    nothing_if_reached();
    return "";
}

static void err_too_many (
    err_status_t status,
    int key,
    int /*cnt*/,
    int /*max*/)
{
    /* these variables define the style. */
    bool plural=  true /*cnt != 1*/;
    bool verb= true;
    bool occured= status == ERR_STATUS_DISTRIBUTED;

    if (key == C_TAG_ALL)
        key= 0;

    ErrVChar tag_name;
    ERR_FOR_SOME_TAGS (key,
        tag_name.format ("%s%s",
            tag_name.empty() ? "" : plural ? " and " : " or ",
               err_tag_description (NULL, tag, plural)));

    if (tag_name.nentries() > 40)
        tag_name.clear().format ("message%s", plural ? "s" : "");
    else
    if (tag_name.empty())
        tag_name.format ("message%s", plural ? "s" : "");

    ErrVChar suffix;
#if 0
    /* group names should not be shown to the user */
    int group= key & C_TAG_GROUP_MASK;
    if (group != 0) {
        char const *name= group_names.find (group);
        if (name == NULL)
            suffix.format (" from unknown group %d", group);
        else
            suffix.format (" from group %s", name);
    }
#endif

    int subsystem= key & C_TAG_SUBSYSTEM_MASK;
    if (subsystem != 0) {
        char const *name= err_subsystem_names.find (subsystem);
        if (name == NULL)
            suffix.format (" from unknown subsystem %d", subsystem);
        else
            suffix.format (" from subsystem %s", name);
    }

    char const *status_name= !verb || occured ? "" : err_status_description (status);

    eprintf (C_TAG_FATAL, 0,
        "Too many %s%s%s%s.",
        /*cnt,*/
        tag_name.as_array(),
        !verb ? "" : occured ? " occured" : plural ? " were " : " was ",
        status_name, suffix.as_array());

    /* If this is reached, the user has deleted the exit() callback.  Oh, well,
     * *we* can handle that simply by continuing... */
}

static void err_too_many_message (
    int tag,
    int number,
    err_status_t status,
    int /*cnt*/,
    int /*max*/)
{
    /* these variables define the style. */
    bool plural=  true /*cnt != 1*/;
    bool verb=    true;
    bool occured= (status == ERR_STATUS_DISTRIBUTED);

    char const *tag_name=     err_tag_description (NULL, ERR_PURE_TAG (tag), plural);
    char const *status_name=  !verb || occured ? "" : err_status_description (status);

    eprintf (C_TAG_FATAL, 0,
        "Too many %s %05d%s%s.",
        /*cnt,*/
        tag_name, number,
        !verb ? "" : occured ? " occured" : plural ? " were " : " was ", status_name);

    /* If this is reached, the user has deleted the exit() callback.  Oh, well,
     * *we* can handle that simply by continuing... */
}

static void err_check_too_many_aux (int tag, int number, err_status_t stat)
{
    if (tag != C_TAG_MORE) {
        int key, max;

        err_map_forall (err_count_map (fatal_counters, stat), key, max) {
            int cnt= err_count (stat, key);
            if (cnt >= max)
                err_too_many (stat, key, cnt, max);
        }

        err_map_forall (err_count_map (fatal_message_counters, stat), key, max) {
            int cnt= /*err-skip*/err_message_count (stat, key);
            if (cnt >= max)
                err_too_many_message (tag, number, stat, cnt, max);
        }
    }
}

void err_check_too_many (int tag, int number)
{
    if (tag != C_TAG_MORE) {
        int statuses= ERR_STATUS_ALL;
        ERR_FOR_SOME_STATUSES (statuses, err_check_too_many_aux (tag, number, status));
    }
}

