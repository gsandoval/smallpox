/*
 * Logger.h
 *
 *  Created on: 23/06/2011
 *      Author: Guillermo Sandoval [gsandoval@darchitect.org]
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <vector>
#include <memory>

#include <moth/util/mothexception.h>
#include <moth/thread/mutex.h>
#include <moth/thread/runnable.h>
#include <moth/util/properties.h>
#include <moth/log/logappender.h>

namespace moth {

class Logger {
private:
    class LogDequeuer : public Runnable {
    public:
        LogDequeuer();
        ~LogDequeuer();
        void Run();
        void AddAppender(std::shared_ptr<LogAppender>);
    private:
        bool running;
        std::vector<std::shared_ptr<LogAppender> > appenders;
    };
public:
    Logger(std::string classname);
    virtual ~Logger();
    void Info(std::string msg);
    void Info(std::string msg, MothException e);
    void Debug(std::string msg);
    void Debug(std::string msg, MothException e);
    void Warn(std::string msg);
    void Warn(std::string msg, MothException e);
    void Error(std::string msg);
    void Error(std::string msg, MothException e);

    static void Setup(Properties);
private:
    std::string classname;
    static std::vector<LogAppender::LogMessage> message_queue;
    static Mutex message_queue_mutex;
    static LogDequeuer dequeuer;

    void Queue(const LogAppender::LogMessage &);
};

} /* namespace moth */
#endif /* LOGGER_H_ */
