LIBS = $(GDAEX_LIBS) \
       -export-dynamic

AM_CPPFLAGS = $(GDAEX_CFLAGS) \
              -I$(top_srcdir)/src \
              -DTESTSDIR="\"@abs_builddir@\""

if LIBSOLIPA_FOUND
AM_CPPFLAGS += \
               $(SOLIPA_CFLAGS) \
               -DSOLIPA_FOUND=1

LIBS += \
        $(SOLIPA_LIBS)
endif

noinst_PROGRAMS = \
                  grid \
                  grid_tree

LDADD = $(top_builddir)/src/libgdaexgrid.la

EXTRA_DIST = grid.db
