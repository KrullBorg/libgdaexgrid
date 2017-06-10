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

gir_include = \
                               grid.h \
                               gridcolumn.h

libgdaexgrid_include_HEADERS = libgdaexgrid.h \
                               $(gir_include)

libgdaexgrid_includedir = $(includedir)/libgdaexgrid

CLEANFILES =

-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir) --warn-all --accept-unprefixed --identifier-prefix=""
INTROSPECTION_COMPILER_ARGS = --includedir=$(srcdir)

if HAVE_INTROSPECTION
introspection_sources = $(libgdaexgrid_la_SOURCES) $(gir_include)

GdaexGrid-1.0.gir: libgdaexgrid.la
GdaexGrid_1_0_gir_INCLUDES = GObject-2.0 GLib-2.0 Gda-5.0 Gdaex-1.0
GdaexGrid_1_0_gir_CFLAGS = $(AM_CPPFLAGS)
GdaexGrid_1_0_gir_LIBS = libgdaexgrid.la
GdaexGrid_1_0_gir_FILES = $(introspection_sources)
INTROSPECTION_GIRS += GdaexGrid-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif
