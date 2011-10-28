#ifndef FILEROLLERAPPENDER_H
#define FILEROLLERAPPENDER_H

#include <moth/log/logappender.h>

namespace moth {

class FileRollerAppender : public LogAppender {
public:
    void Write(LogMessage);
};

} /* namespace moth */
#endif // FILEROLLERAPPENDER_H
