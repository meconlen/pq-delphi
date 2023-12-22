AM_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include/ -I$(top_srcdir)/googletest/googlemock/include
AM_LDFLAGS = -L$(top_srcdir)/googletest/googletest/lib/.libs/ -L$(top_srcdir)/googletest/googlemock/lib/.libs/
LDADD = -lpthread -lgtest

check_LTLIBRARIES = libgtest.la
libgtest_la_SOURCES = ../googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest
libgtest_la_LDFLAGS = -pthread

bin_PROGRAMS = test find
test_SOURCES = test.cpp lcg.cpp

test_CPPFLAGS = -I ${top_srcdir}/googletest/googletest/include/
test_LDFLAGS = -pthread -lm

find_SOURCES = find.cpp lcg.cpp

find_CPPFLAGS = -I ${top_srcdir}/googletest/googletest/include/
find_LDFLAGS = -pthread -lm
