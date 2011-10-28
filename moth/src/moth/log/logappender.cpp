#include <moth/log/logappender.h>

namespace moth {

LogAppender(std::vector<std::string> _class_list, LogLevel _log_level) {
    for (auto it = _class_list; it != _class_list.end(); ++it) {
        class_list.insert(it);
    }
    log_level = _log_level;
}

}
