#include <iostream>
#include <string>

#include <moth/log/consoleappender.h>

namespace moth {

using namespace std;

ConsoleAppender::ConsoleAppender(std::vector<std::string> class_list, LogLevel log_level) :
    LogAppender(class_list, log_level) {
}

ConsoleAppender::~ConsoleAppender() {
}

void ConsoleAppender::Write(LogMessage msg) {
    if (msg.Level() >= log_level) {
        cout << msg.Time() << " [" << msg.ThreadName() << "] " << msg.LevelString() << " " << msg.ClassName() << " - " << msg.Message() << endl;
    }
}

}
