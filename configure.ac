AC_PREREQ([2.71])
AC_INIT([pq-delphi],[0.1],[mike@conlen.org])
AC_CONFIG_SRCDIR([src/test.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])
AM_PROG_AR
LT_INIT
AC_PROG_CXX([g++])

AC_CHECK_INCLUDES_DEFAULT
AC_PROG_EGREP


CXXFLAGS="$CXXFLAGS --std=c++17"
LDFLAGS="$LDFLAGS"
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([malloc.h])
AC_CHECK_HEADERS([sys/malloc.h])
AC_CHECK_HEADERS([malloc/malloc.h])
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_CHECK_FUNCS([fstat])
AC_CONFIG_FILES([Makefile
	src/Makefile
])
# AC_CONFIG_SUBDIRS([
# 	googletest/googletest
# 	googletest/googlemock
# ])
AC_OUTPUT
