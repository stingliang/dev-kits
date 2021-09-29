//
// Created by stingliang on 2021/9/29 14:30.
//

#include "Logger.h"

Logger::Ptr Logger::m_logger = nullptr;
std::mutex Logger::m_mutex;
std::map<int, std::string> Logger::m_severity{
    std::make_pair<int, std::string>(0, "\033[36mTRACE\033[0m"),
    std::make_pair<int, std::string>(1, "\033[33mDEBUG\033[0m"),
    std::make_pair<int, std::string>(2, "\033[32mINFO\033[0m"),
    std::make_pair<int, std::string>(3, "\033[35mWARN\033[0m"),
    std::make_pair<int, std::string>(4, "\033[31mERROR\033[0m")
};

#ifdef LOGGER_LEVEL
Severity Logger::m_severity_level(LOGGER_LEVEL);
#else
Severity Logger::m_severity_level(INFO);
#endif

Logger::Ptr Logger::getInstance() {
    if (m_logger) {
        return m_logger;
    } else {
        return Ptr(new Logger);
    }
}

Logger::Ptr Logger::getInstance(const std::string &log_path) {
    if (m_logger) {
        return m_logger;
    } else {
        return Ptr(new Logger);
    }
}

void Logger::log(const Severity &severity, const std::string &message) {
    // for thread safe
    if (severity >= m_severity_level) {
        m_mutex.lock();
        std::cout << "[" << m_severity.at(severity) << "] " << message << std::endl;
        m_mutex.unlock();
    }
}
