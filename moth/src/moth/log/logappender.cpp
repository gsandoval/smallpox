#include <moth/log/logappender.h>

namespace moth {

LogAppender(std::vector<std::string> _class_list, LogLevel _log_level) {
    for (auto it = _class_list; it != _class_list.end(); ++it) {
        class_list.insert(it);
    }
    log_level = _log_level;
}

LogAppender::LogMessage::LogMessage(std::string _time, std::string _message, std::string _thread_name, std::string _class_name, LogLevel _level) :
    time_str(_time), message(_message), thread_name(_thread_name), class_name(_class_name), level(_level) {
}

std::string LogAppender::LogMessage::Time() {
    return time_str;
}
std::string LogAppender::LogMessage::Message() {
    return message;
}
std::string LogAppender::LogMessage::ThreadName() {
    return thread_name;
}
std::string LogAppender::LogMessage::ClassName() {
    return class_name;
}
LogLevel LogAppender::LogMessage::Level() {
    return level;
}
std::string LogAppender::LogMessage::LevelString() {
    string level_str;
    switch (msg.level) {
    case DEBUG_LEVEL:
        level_str = "DEBUG";
        break;
    case INFO_LEVEL:
        level_str = "INFO";
        break;
    case WARN_LEVEL:
        level_str = "WARN";
        break;
    case ERROR_LEVEL:
        level_str = "ERROR";
        break;
    }
    return level_str;
}

}
