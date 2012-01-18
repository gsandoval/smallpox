/*
 * logger.cpp
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#include <sys/time.h>

#include <ctime>
#include <cstdio>
#include <sstream>
#include <iostream>

#include <moth/log/logger.h>
#include <moth/util/tokenizer.h>
#include <moth/log/loglevel.h>
#include <moth/thread/thread.h>
#include <moth/util/clock.h>
#include <moth/log/consoleappender.h>
#include <moth/log/fileappender.h>
#include <moth/log/filerollerappender.h>

namespace moth {

using namespace std;

std::vector<LogAppender::LogMessage> Logger::message_queue;
Mutex Logger::message_queue_mutex;
Logger::LogDequeuer Logger::dequeuer;

Logger::LogDequeuer::LogDequeuer() : running(false) {

}

Logger::LogDequeuer::~LogDequeuer() {

}

void Logger::LogDequeuer::AddAppender(shared_ptr<LogAppender> appender) {
    appenders.push_back(appender);
}

void Logger::LogDequeuer::Run() {
    running = true;
    while (running) {

    }
}

void Logger::Setup(Properties properties) {
    string appender_list = properties.Get("logger.appenders");
    if (appender_list == "") {
        appender_list = "root";
    }
    Tokenizer tok(appender_list, ", ");
    for (auto it = tok.begin(); it != tok.end(); ++it) {
        string type_prop = "logger." + *it + ".type";
        string level_prop = "logger." + *it + ".level";
        string filter_prop = "logger." + *it + ".filter";
        string file_prop = "logger." + *it + ".file";
        string maxsize_prop = "logger." + *it + ".maxsize";

        string type_str = properties.Get(type_prop);
        if (type_str == "" || (type_str != "console" && type_str != "file" && type_str != "fileroller")) {
            clog << "Error configuring " << *it << " appender: Invalid type" << endl;
            continue;
        }

        string level_str = properties.Get(level_prop);
        LogLevel level = DEBUG_LEVEL;
        if (level_str == "DEBUG") level = DEBUG_LEVEL;
        else if (level_str == "INFO") level = INFO_LEVEL;
        else if (level_str == "WARN") level = WARN_LEVEL;
        else if (level_str == "ERROR") level = ERROR_LEVEL;

        string filter_str = properties.Get(filter_prop);
        vector<string> class_list;
        Tokenizer f_tok(filter_str, ", ");
        for (auto f_it = f_tok.begin(); f_it != f_tok.end(); ++f_it) {
            class_list.push_back(*f_it);
        }

        string file_str = properties.Get(file_prop);
        string maxsize_str = properties.Get(maxsize_prop);
        long long max_byte_size = -1;
        for (size_t i = 0; i < maxsize_str.size(); ++i) maxsize_str[i] = tolower(maxsize_str[i]);
        if (maxsize_str != "") {
            long long factor = 1;
            size_t index;
            if ((index = maxsize_str.find("kib")) != string::npos) {
                factor = 1024LL;
            } else if ((index = maxsize_str.find("kb")) != string::npos) {
                factor = 1000LL;
            } else if ((index = maxsize_str.find("mib")) != string::npos) {
                factor = 1024LL * 1024;
            } else if ((index = maxsize_str.find("mb")) != string::npos) {
                factor = 1000LL * 1000;
            } else if ((index = maxsize_str.find("gib")) != string::npos) {
                factor = 1024LL * 1024 * 1024;
            } else if ((index = maxsize_str.find("gb")) != string::npos) {
                factor = 1000LL * 1000 * 1000;
            }
            if (index != string::npos) {
                index = min(index, max(maxsize_str.find(" "), maxsize_str.size()));
                maxsize_str = maxsize_str.substr(0, index);
                max_byte_size = 0LL;
                stringstream(maxsize_str) >> max_byte_size;
                max_byte_size *= factor;
            }
        }

        if (type_str == "console") {
            shared_ptr<LogAppender> ca(new ConsoleAppender(class_list, level));
            dequeuer.AddAppender(ca);
        } else if (type_str == "file") {
            shared_ptr<LogAppender> fa(new FileAppender(class_list, level, file_str));
            dequeuer.AddAppender(fa);
        } else if (type_str == "fileroller") {
            if (max_byte_size == -1) {
                clog << "Error configuring " << *it << " appender: Invalid maxsize" << endl;
                continue;
            }
            shared_ptr<LogAppender> fra(new FileRollerAppender(class_list, level, file_str, max_byte_size));
            dequeuer.AddAppender(fra);
        }
    }
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
