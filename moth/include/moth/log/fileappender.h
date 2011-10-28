#ifndef FILEAPPENDER_H
#define FILEAPPENDER_H

#include <moth/log/logappender.h>

namespace moth {

class FileAppender : public LogAppender {
public:
    void Write(LogMessage);
};

} /* namespace moth */
#endif // FILEAPPENDER_H
