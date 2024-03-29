#ifndef FILEROLLERAPPENDER_H
#define FILEROLLERAPPENDER_H

#include <moth/log/logappender.h>

namespace moth {

class FileRollerAppender : public LogAppender {
public:
    FileRollerAppender(std::vector<std::string> class_list, LogLevel log_level, std::string file_name, long long kb_max_size);
    virtual ~FileRollerAppender();

    void Write(LogMessage);
};

} /* namespace moth */
#endif // FILEROLLERAPPENDER_H
