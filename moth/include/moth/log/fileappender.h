#ifndef FILEAPPENDER_H
#define FILEAPPENDER_H

#include <moth/log/logappender.h>

namespace moth {

class FileAppender : public LogAppender {
public:
    FileAppender(std::vector<std::string> class_list, LogLevel log_level);
    virtual ~FileAppender();

    void Write(LogMessage);
};

} /* namespace moth */
#endif // FILEAPPENDER_H
