AM_CPPFLAGS=-I../include/

SRCDIR=../src

IODIR=$(SRCDIR)/mothio
NETDIR=$(SRCDIR)/mothnet
LOGDIR=$(SRCDIR)/mothlog
THREADDIR=$(SRCDIR)/moththread

noinst_LTLIBRARIES=libmothio.la libmothnet.la libmoththread.la libmothlog.la

libmothio_la_SOURCES=$(IODIR)/File.cpp

libmothnet_la_SOURCES=$(NETDIR)/Socket.cpp

libmoththread_la_SOURCES=$(THREADDIR)/Thread.cpp

libmothlog_la_SOURCES=$(LOGDIR)/Logger.cpp