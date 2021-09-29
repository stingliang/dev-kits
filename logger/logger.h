//
// Created by stingliang on 2021/9/29 14:30.
//
#ifndef DEV_UTILITY_LOGGER_H
#define DEV_UTILITY_LOGGER_H


#include <common.h>

#define LOGGER_LEVEL(SEVERITY) logger::getInstance()->setSeverity(SEVERITY);
#define LOG(SEVERITY, MESSAGE) logger::getInstance()->m_ss.str(""); \
                               logger::getInstance()->m_ss << MESSAGE; \
                               logger::getInstance()->log(SEVERITY);

enum Severity {
    TRACE = 0,
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class logger {
public:
    using Ptr = std::shared_ptr<logger>;
    static Ptr getInstance();
    static Ptr getInstance(const std::string& log_path);
    static void setSeverity(Severity);
    static void log(const Severity& severity);

    static std::stringstream m_ss;
private:
    logger() = default;
    static Severity m_severity_level;
    static Ptr m_logger;
    static std::mutex m_mutex;
    static std::map<int, std::string> m_severity;
};


#endif //DEV_UTILITY_LOGGER_H
