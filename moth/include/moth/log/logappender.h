#ifndef LOGAPPENDER_H
#define LOGAPPENDER_H

#include <set>
#include <string>
#include <vector>

#include <moth/log/loglevel.h>

namespace moth {

class LogAppender {
public:
    class LogMessage {
    public:
        LogMessage(std::string time, std::string message, std::string thread_name, std::string class_name, LogLevel level);
        ~LogMessage();
        std::string Time();
        std::string Message();
        std::string ThreadName();
        std::string ClassName();
        LogLevel Level();
        std::string LevelString();
    private:
        std::string time_str;
        std::string message;
        std::string thread_name;
        std::string class_name;
        LogLevel level;
    };

    LogAppender(std::vector<std::string> class_list, LogLevel log_level);
    virtual void Write(LogMessage) = 0;
protected:
    std::set<std::string> class_list;
    LogLevel log_level;
};

} /* namespace moth */
#endif // LOGAPPENDER_H
