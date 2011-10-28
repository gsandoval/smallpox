#ifndef CONSOLEAPPENDER_H
#define CONSOLEAPPENDER_H

#include <moth/log/logappender.h>

namespace moth {

class ConsoleAppender : public LogAppender {
public:
    ConsoleAppender(std::vector<std::string> class_list, LogLevel log_level);
    virtual ~ConsoleAppender();

    void Write(LogMessage);
};

} /* namespace moth */
#endif // CONSOLEAPPENDER_H
