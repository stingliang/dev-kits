//
// Created by stingliang on 2021/9/29 14:30.
//

#include "logger.h"

logger::Ptr logger::m_logger = nullptr;
std::mutex logger::m_mutex;
std::map<int, std::string> logger::m_severity{
    std::make_pair<int, std::string>(0, "\033[36mTRACE\033[0m"),
    std::make_pair<int, std::string>(1, "\033[33mDEBUG\033[0m"),
    std::make_pair<int, std::string>(2, "\033[32mINFO\033[0m"),
    std::make_pair<int, std::string>(3, "\033[35mWARN\033[0m"),
    std::make_pair<int, std::string>(4, "\033[31mERROR\033[0m")
};
std::stringstream logger::m_ss;

Severity logger::m_severity_level(INFO);

logger::Ptr logger::getInstance() {
    if (m_logger) {
        return m_logger;
    } else {
        m_logger = Ptr(new logger);
        return m_logger;
    }
}

logger::Ptr logger::getInstance(const std::string &log_path) {
    if (m_logger) {
        return m_logger;
    } else {
        return Ptr(new logger);
    }
}

void logger::setSeverity(Severity severity) {
    m_severity_level = severity;
}

void logger::log(const Severity &severity) {
    // for thread safe
    if (severity >= m_severity_level) {
        m_mutex.lock();
        std::cout << "[" << m_severity.at(severity) << "] " << m_ss.str() << std::endl;
        m_mutex.unlock();
    }
}