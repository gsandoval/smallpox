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

#include <moth/util/mothexception.h>
#include <moth/thread/mutex.h>
#include <moth/thread/runnable.h>

namespace moth {

class Logger {
private:
    class LogDequeuer : public Runnable {
    public:
        void Run();
    private:
        bool running;
    };
public:
    Logger(std::string classname);
    virtual ~Logger();
    virtual void Info(std::string msg);
    virtual void Info(std::string msg, MothException e);
    virtual void Debug(std::string msg);
    virtual void Debug(std::string msg, MothException e);
    virtual void Warn(std::string msg);
    virtual void Warn(std::string msg, MothException e);
    virtual void Error(std::string msg);
    virtual void Error(std::string msg, MothException e);
protected:
    std::string classname;

    virtual std::string DateTime();
    virtual void Write(std::string message) = 0;
private:
    static std::vector<std::string> message_queue;
    static Mutex message_queue_mutex;

    void Queue(std::string message);
};

} /* namespace moth */
#endif /* LOGGER_H_ */
