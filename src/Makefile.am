LIBS = $(GDAEXGRID_LIBS)

AM_CPPFLAGS = $(GDAEXGRID_CFLAGS) \
              -DLOCALEDIR=\"$(localedir)\" \
              -DG_LOG_DOMAIN=\"GdaExGrid\"

if LIBREPTOOL_FOUND
AM_CPPFLAGS += \
               $(REPTOOL_CFLAGS) \
               -DREPTOOL_FOUND=1

LIBS += \
        $(REPTOOL_LIBS)
endif

if LIBSOLIPA_FOUND
AM_CPPFLAGS += \
               $(SOLIPA_CFLAGS) \
               -DSOLIPA_FOUND=1

LIBS += \
        $(SOLIPA_LIBS)
endif

lib_LTLIBRARIES = libgdaexgrid.la

libgdaexgrid_la_SOURCES = grid.c \
                          gridcolumn.c

libgdaexgrid_la_LDFLAGS = -no-undefined

libgdaexgrid_include_HEADERS = libgdaexgrid.h \
                               grid.h \
                               gridcolumn.h

libgdaexgrid_includedir = $(includedir)/libgdaexgrid
