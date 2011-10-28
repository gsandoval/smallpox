#include <moth/log/filerollerappender.h>

namespace moth {

FileRollerAppender::FileRollerAppender(std::vector<std::string> class_list, LogLevel log_level) :
    LogAppender(class_list, log_level) {
}

FileRollerAppender::~FileRollerAppender() {
}

void FileRollerAppender::Write(LogMessage msg) {

}

}
