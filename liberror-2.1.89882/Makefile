# @MODE_FUNDAMENTAL@ -*- Mode: Makefile -*-
######################################################################

srcdir    = .
top_srcdir= .

include $(top_srcdir)/make/Defs
include $(top_srcdir)/make/ht+absint/Config

######################################################################

SUBDIRS= test eprintf

######################################################################

LIBRARY         = error
GLOBAL_PREFIX   = err_
USE_ERWIN       = 1
USE_SYMBOL      = 1
INSTALL_SYMBOL  = 1
ERROR_SUBSYSTEM = 1
   # used for composing ...err_subsystem for the assertions.

EXTRA_SCRIPT = errcodes \
               makeprintf.pl

EXTRA_FILES  = errcodes.in \
               makeprintf.pl \
               doc/mails.txt \
               doc/errcodes.txt \
               doc/options.txt

CPPMODULES_F = fast

CPPMODULES_L = init \
               error \
               count \
               location \
               buffer \
               filter \
               callback \
               parseargs \
               printf \
               printf-gen \
               style \
                   style-none \
                   style-simple \
                   style-plain \
                       style-colon \
                       style-quotes \
                   style-qt \
                   style-qt3 \
                   style-default

CPPMODULES=$(CPPMODULES_L)
EXTRA_SOURCES=$(addsuffix .cpp,$(CPPMODULES_F)) include/error/err-config.h.in

CMODULES   = check_compile

HHEADERS   = internal \
             include/liberror \
             include/error/assert \
             include/error/settings \
             include/error/decls \
             include/error/tags \
             include/error/printf \
             include/error/printf-gen \
             include/error/style \
             include/error/style-plain \
             include/error/style-colon \
             include/error/style-quotes \
             include/error/style-qt \
             include/error/style-qt3 

HOTFUNC_DEFS= include/liberror.h \
              include/error/decls.h \
              include/error/printf.h \
              include/error/printf-gen.h \
              $(EXTRA_SOURCES) \
              $(EXTRA_HEADERS)

TOP_DOC_FILES= README \
               Changes \
               COPYING

DOC_FILES    = errcodes.txt \
               mails.txt \
               options.txt

GEN_DOC_FILES= html/*.html \
               html/*.css

SHARE_FILES  = hotfuncs.default

######################################################################

do-it-all: all-top

all: errcodes.ok $(addprefix share/,$(SHARE_FILES)) documentation

.PHONY: documentation
documentation:
	-cd doc && $(MAKE)

ifneq ($(FORCE_DOC),)
doc: documentation
endif

ifneq ($(RELEASE_DOC),)
doc:
	wget -q -O doc/template.html 'http://www.theiling.de/empty.html.html'
	-cd doc && $(MAKE) clean-local && $(MAKE) HTML_TEMPLATE=`pwd`/template.html
endif

.PHONY: release-doc
release-doc:
	$(MAKE) doc RELEASE_DOC=1


run:

include/error/printf-gen.h: printf-gen.cpp

printf-gen.cpp: makeprintf.pl
	$(PERL) makeprintf.pl

Makefile: printf-gen.cpp

run-local:
	./test/testerror

errcodes: errcodes.in
	(cd ${top_srcdir} && CONFIG_FILES=errcodes CONFIG_HEADERS= ./config.status)

share/hotfuncs.default: errcodes $(HOTFUNC_DEFS)
	-mkdir share
	./errcodes -o $@ list-hotfuncs $(HOTFUNC_DEFS)

errcodes.ok: errcodes
	-rm -f errcodes.ok
	$(PERL) -c $<
	echo > errcodes.ok

clean-local:
	-rm -f errcodes.ok share/hotfuncs.default

distclean-local:
	-rm -f errcodes

install-subdirs:
	cd eprintf && $(MAKE) install-all-local

uninstall-subdirs:
	cd eprintf && $(MAKE) uninstall-all-local

include $(top_srcdir)/make/Rules

