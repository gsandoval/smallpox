#include <string>

#include <moth/log/logappender.h>

namespace moth {

using namespace std;

LogAppender::LogAppender(vector<string> _class_list, LogLevel _log_level) {
    for (auto it = _class_list.begin(); it != _class_list.end(); ++it) {
        class_list.insert(*it);
    }
    log_level = _log_level;
}

LogAppender::LogMessage::LogMessage(string _time, string _message, string _thread_name, string _class_name, LogLevel _level) :
    time_str(_time), message(_message), thread_name(_thread_name), class_name(_class_name), level(_level) {
}

LogAppender::LogMessage::~LogMessage() {
}

string LogAppender::LogMessage::Time() {
    return time_str;
}

string LogAppender::LogMessage::Message() {
    return message;
}

string LogAppender::LogMessage::ThreadName() {
    return thread_name;
}

string LogAppender::LogMessage::ClassName() {
    return class_name;
}

LogLevel LogAppender::LogMessage::Level() {
    return level;
}

string LogAppender::LogMessage::LevelString() {
    string level_str;
    switch (level) {
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
