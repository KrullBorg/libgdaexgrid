#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.65)
AC_INIT([libgdaexgrid], [0.0.1], [azagli@libero.it])
AC_CONFIG_SRCDIR([src/grid.c])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE(-Wall)

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_MAINTAINER_MODE

AC_CONFIG_MACRO_DIR([m4])

AC_CANONICAL_SYSTEM

LT_INIT

AC_LIBTOOL_WIN32_DLL

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AC_PROG_RANLIB

GTK_DOC_CHECK(1.0)
IT_PROG_INTLTOOL

dnl ******************************
dnl Translations
dnl ******************************
GETTEXT_PACKAGE=libgdaexgrid
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE",
                   [The prefix for our gettext translation domains.])
AM_GLIB_GNU_GETTEXT

# Checks for libraries.
PKG_CHECK_MODULES(GDAEXGRID, [libgdaex >= 0.5.0])

AC_SUBST(GDAEXGRID_CFLAGS)
AC_SUBST(GDAEXGRID_LIBS)

PKG_CHECK_EXISTS(libreptool >= 0.2.2, [LIBREPTOOL_FOUND=yes], [LIBREPTOOL_FOUND=no])

AM_CONDITIONAL(LIBREPTOOL_FOUND, test $LIBREPTOOL_FOUND = yes)

if test $LIBREPTOOL_FOUND = yes; then
PKG_CHECK_MODULES(REPTOOL, libreptool >= 0.2.2)

AC_SUBST(REPTOOL_CFLAGS)
AC_SUBST(REPTOOL_LIBS)
fi

PKG_CHECK_EXISTS(libsolipa >= 0.4.0, [LIBSOLIPA_FOUND=yes], [LIBSOLIPA_FOUND=no])

AM_CONDITIONAL(LIBSOLIPA_FOUND, test $LIBSOLIPA_FOUND = yes)

if test $LIBSOLIPA_FOUND = yes; then
PKG_CHECK_MODULES(SOLIPA, libsolipa >= 0.4.0)

AC_SUBST(SOLIPA_CFLAGS)
AC_SUBST(SOLIPA_LIBS)
fi

# Checks for header files.
AC_HEADER_STDC

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# Checks for library functions.

# Checks for library functions.

dnl ******************************
dnl Check for Operating System
dnl ******************************

platform_win32=no

case "$host" in
*-mingw*)
    platform_win32=yes
    ;;
esac

AM_CONDITIONAL(PLATFORM_WIN32, [test $platform_win32 = yes])

# Output files
AC_CONFIG_FILES([
	libgdaexgrid.pc
	Makefile
	po/Makefile.in
	src/Makefile
	tests/Makefile
])
AC_OUTPUT
