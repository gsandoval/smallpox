AM_CPPFLAGS=-I../include/
AM_CXXFLAGS=-std=c++0x

SRCDIR=../src

UTILDIR=$(SRCDIR)/mothutil
NETDIR=$(SRCDIR)/mothnet
LOGDIR=$(SRCDIR)/mothlog
THREADDIR=$(SRCDIR)/moththread

noinst_LTLIBRARIES=libmothutil.la libmothnet.la libmoththread.la libmothlog.la

bin_PROGRAMS=util log

libmothutil_la_SOURCES=$(UTILDIR)/tokenizer.cpp $(UTILDIR)/properties.cpp $(UTILDIR)/mothexception.cpp

libmothnet_la_SOURCES=$(NETDIR)/socket.cpp

libmoththread_la_SOURCES=$(THREADDIR)/thread.cpp

libmothlog_la_SOURCES=$(LOGDIR)/logger.cpp $(LOGDIR)/consolelogger.cpp $(LOGDIR)/filelogger.cpp $(LOGDIR)/filerollerlogger.cpp $(LOGDIR)/loggerfactory.cpp
libmothlog_la_LIBADD=libmothutil.la

util_SOURCES=$(SRCDIR)/test/util.cpp
util_LDADD=libmothutil.la libmothnet.la libmoththread.la libmothlog.la

log_SOURCES=$(SRCDIR)/test/log.cpp
log_LDADD=libmothutil.la libmothnet.la libmoththread.la libmothlog.la