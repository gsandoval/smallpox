#include <moth/log/fileappender.h>

namespace moth {

FileAppender::FileAppender(std::vector<std::string> class_list, LogLevel log_level) :
    LogAppender(class_list, log_level) {
}

FileAppender::~FileAppender() {
}

void FileAppender::Write(LogMessage msg) {

}

}
