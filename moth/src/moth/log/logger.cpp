/*
 * logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <sys/time.h>

#include <iomanip>
#include <ctime>
#include <sstream>

#include <moth/log/logger.h>
#include <moth/log/loglevel.h>
#include <moth/thread/thread.h>
#include <moth/util/clock.h>

namespace moth {

using namespace std;

Logger::LogDequeuer::LogDequeuer() : running(false) {

}

void Logger::LogDequeuer::Run() {
    running = true;
    while (running) {

    }
}

void Logger::Setup(Properties properties) {

}

Logger::Logger(string _classname) : classname(_classname) {

}

Logger::~Logger() {
}

void Logger::Queue(const LogAppender::LogMessage &message) {
    message_queue_mutex.Lock();
    message_queue.push_back(message);
    message_queue_mutex.Unlock();
}

void Logger::Error(string msg) {
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), msg, Thread::CurrentThreadName(), classname, ERROR_LEVEL));
}

void Logger::Error(string msg, MothException e) {
    ostringstream oss;
    oss << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), oss.str(), Thread::CurrentThreadName(), classname, ERROR_LEVEL));
}

void Logger::Warn(string msg) {
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), msg, Thread::CurrentThreadName(), classname, WARN_LEVEL));
}

void Logger::Warn(string msg, MothException e) {
    ostringstream oss;
    oss << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), oss.str(), Thread::CurrentThreadName(), classname, WARN_LEVEL));
}

void Logger::Debug(string msg) {
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), msg, Thread::CurrentThreadName(), classname, DEBUG_LEVEL));
}

void Logger::Debug(string msg, MothException e) {
    ostringstream oss;
    oss << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), oss.str(), Thread::CurrentThreadName(), classname, DEBUG_LEVEL));
}

void Logger::Info(string msg) {
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), msg, Thread::CurrentThreadName(), classname, INFO_LEVEL));
}

void Logger::Info(string msg, MothException e) {
    ostringstream oss;
    oss << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(LogAppender::LogMessage(Clock::CurrentTimeString(), oss.str(), Thread::CurrentThreadName(), classname, INFO_LEVEL));
}

} /* namespace moth */
