# -*- Mode: Makefile -*-
#
# We do not want to be very sophisticated -- we just want to be able
# to produce Latex and HTML using a well-structured method.

srcdir    = .
top_srcdir= ..

include $(top_srcdir)/make/Defs
include $(top_srcdir)/make/ht+absint/Config

MAGIC_SHELL := $(shell mkdir html > /dev/null 2>&1 ; \
                       echo > html/dummy.html ;      \
                       echo > html/dummy.css ;       \
                       true                          \
                )
   # generate at least one .html and one .css file in html subdir,
   # otherwise 'make install' will fail when trying to install

TARGETS=html/index.html

do-it-all: $(TARGETS)
.PHONY: all

.PHONY: all-post
all-post:

clean-local:
	rm -f $(TARGETS)

develclean-local:

HEADERS= liberror.h \
         error/style.h \
         error/tags.h \
         error/printf.h \
         error/printf-gen.h \
         error/style-plain.h \
         error/style-colon.h \
         error/style-quotes.h \
         error/style-qt.h \
         error/style-qt3.h

HTML_TEMPLATE=/doesnotexist-use-default

html/index.html: $(addprefix ../include/, $(HEADERS)) \
                 Makefile.in                          \
                 ../README ../COPYING ../Changes      \
                 options.txt errcodes.txt mails.txt
	cd .. &&                                                                 \
	    erwin-cgen --global-prefix=err $(addprefix include/, $(HEADERS))     \
	        -html-template=$(HTML_TEMPLATE)                                  \
	        -html-link-prefix=../../                                         \
	        -name='Message Library'                                          \
	        -text-section:-1:"Read Me"=README                                \
	        -text-section:1:"Two Introductory Mails"=doc/mails.txt           \
	        -text-section:2:"Command Line Options"=doc/options.txt           \
	        -text-section:3:"Error Code Assignment"=doc/errcodes.txt         \
	        -text-section:4:"Change Log"=Changes                             \
	        -text-section:5:"Copyright"=COPYING                              \
	        -copyright-html='$(VENDOR_HTML)'                                 \
	        --write-html doc/html

Makefile: Makefile.in
	cd .. && CONFIG_FILES=doc/Makefile CONFIG_HEADERS= ./config.status

.PHONY: upload
upload: html/index.html
	test -n "$(UPLOAD_ROOT)"
	$(RCP) html/* $(UPLOAD_ROOT)/refman/liberror/

.PHONY: dummy
dummy:
