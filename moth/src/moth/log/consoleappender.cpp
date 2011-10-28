#include <moth/log/consoleappender.h>

void ConsoleAppender::Write(LogMessage msg) {
    //Queue(DateTime() + " [" + Thread::CurrentThreadName() + "] WARN " + classname + " - " + msg);
}
