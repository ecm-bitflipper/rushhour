# @MODE_FUNDAMENTAL@ -*- Mode: Makefile -*-
######################################################################

srcdir    = .
top_srcdir= .

include $(top_srcdir)/make/Defs
include $(top_srcdir)/make/ht/Config

######################################################################

EXTRA_FILES= README

# Either a program or a library
PROG       = rush_hour
USE_ERWIN  = 1
USE_SYMBOL = 1

######################################################################

# Parameters and options:

EXTRA_FILES= level32.txt \
             README \
             TODO \
             Changes

CPPMODULES = $(PROG)

HHEADERS   = settings \
             decls

EXTRA_GENCPPMODULES=

EXTRA_SOURCES=

######################################################################

do-it-all: $(PROG)
    # default target

run: # e.g.: run-top

# For more installations (e.g. links, etc.,) you can use the following targets:
install-local:
uninstall-local:

# For invoking 'install' and 'uninstall' actions for subdirs, use the following
# targets.  Note that the Makefile does not automatically recurse to subdirs
# for installation -- you have to invoke each subdir that wants to install
# something manually:
install-subdirs:
uninstall-subdirs:

# Misc: (use 'make help' to find out the meaning of the target)
clean-local:
distclean-local:
develclean-local:
sweep-local:      # removes all back-up files (X.bak and X~, for instance)
run-local:        # runs programs (e.g. diagnostics)
test-loca:        # runs test programs
depend-local:     # generates dependence info for make (for C/C++, this is
                  # automatically handled with gcc):

# For sub-directories: if you need the things from the parent directory before
# being built yourself, use 'do-it-all: all-top' and 'all-post'.
all-post:

copy-doc: README.html
	cp README.html ../../../www/theiling/raw/projects/rush_hour_README.html

README.html: README
	erwin-cgen --text2html $< > $@

include $(top_srcdir)/make/Rules
