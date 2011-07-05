AM_CPPFLAGS=-I../include/
AM_CXXFLAGS=-std=c++0x

SRCDIR=../src

UTILDIR=$(SRCDIR)/mothutil
NETDIR=$(SRCDIR)/mothnet
LOGDIR=$(SRCDIR)/mothlog
THREADDIR=$(SRCDIR)/moththread

noinst_LTLIBRARIES=libmothutil.la libmothnet.la libmoththread.la libmothlog.la

bin_PROGRAMS=util

libmothutil_la_SOURCES=$(UTILDIR)/Tokenizer.cpp $(UTILDIR)/Properties.cpp $(UTILDIR)/MothException.cpp

libmothnet_la_SOURCES=$(NETDIR)/Socket.cpp

libmoththread_la_SOURCES=$(THREADDIR)/Thread.cpp

libmothlog_la_SOURCES=$(LOGDIR)/ConsoleLogger.cpp $(LOGDIR)/FileLogger.cpp $(LOGDIR)/FileRollerLogger.cpp $(LOGDIR)/LoggerFactory.cpp

util_SOURCES=$(SRCDIR)/test/Util.cpp
util_LDADD=libmothutil.la libmothnet.la libmoththread.la libmothlog.la