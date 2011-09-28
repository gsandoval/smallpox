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
#include <moth/thread/thread.h>

namespace moth {

using namespace std;

Logger::LogDequeuer::LogDequeuer() : running(false) {

}

void Logger::LogDequeuer::Run() {
    running = true;
    while (running) {

    }
}

Logger::Logger(string _classname) : classname(_classname) {

}

Logger::~Logger() {
}

string Logger::DateTime() {
    time_t t = time(NULL);
    tm* timeinfo = localtime(&t);
    timeval tv;
    gettimeofday(&tv, NULL);

    ostringstream oss;
    oss << setfill('0');
    oss << timeinfo->tm_year + 1900 << "-" << setw(2) << timeinfo->tm_mon + 1 << "-" << setw(2) << timeinfo->tm_mday;
    oss << " " << setw(2) << timeinfo->tm_hour << ":" << setw(2) << timeinfo->tm_min << ":" << setw(2) << timeinfo->tm_sec;
    oss << "," << ((tv.tv_usec / 1000) % 1000);
    return oss.str();
}

void Logger::Queue(const string message) {
    message_queue_mutex.Lock();
    message_queue.push_back(message);
    message_queue_mutex.Unlock();
}

void Logger::Error(string msg) {
    Queue(DateTime() + " [" + Thread::CurrentThreadName() + "] ERROR " + classname + " - " + msg);
}

void Logger::Error(string msg, MothException e) {
    ostringstream oss;
    oss << DateTime() << " [" << Thread::CurrentThreadName() << "] ERROR " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(oss.str());
}

void Logger::Warn(string msg) {
    Queue(DateTime() + " [" + Thread::CurrentThreadName() + "] WARN " + classname + " - " + msg);
}

void Logger::Warn(string msg, MothException e) {
    ostringstream oss;
    oss << DateTime() << " [" << Thread::CurrentThreadName() << "] WARN " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(oss.str());
}

void Logger::Debug(string msg) {
    Queue(DateTime() + " [" + Thread::CurrentThreadName() + "] DEBUG " + classname + " - " + msg);
}

void Logger::Debug(string msg, MothException e) {
    ostringstream oss;
    oss << DateTime() << " [" << Thread::CurrentThreadName() << "] DEBUG " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(oss.str());
}

void Logger::Info(string msg) {
    Queue(DateTime() + " [" + Thread::CurrentThreadName() + "] INFO " + classname + " - " + msg);
}

void Logger::Info(string msg, MothException e) {
    ostringstream oss;
    oss << DateTime() << " [" << Thread::CurrentThreadName() << "] INFO " << classname << ":" << e.LineNumber() << " - " << msg << "(" << e.what() << ")";
    Queue(oss.str());
}

} /* namespace moth */
