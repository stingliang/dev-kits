//
// Created by stingliang on 2021/9/29 14:30.
//
#ifndef DEV_UTILITY_LOGGER_H
#define DEV_UTILITY_LOGGER_H


#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <map>

#define LOG(SEVERITY, MESSAGE) Logger::getInstance()->log(SEVERITY, MESSAGE);

enum Severity {
    TRACE = 0,
    DEBUG,
    INFO,
    WARN,
    ERROR
};

class Logger {
public:
    using Ptr = std::shared_ptr<Logger>;
    static Ptr getInstance();
    static Ptr getInstance(const std::string& log_path);
    static void log(const Severity& severity, const std::string& message);

private:
    Logger() = default;
    static Severity m_severity_level;
    static Ptr m_logger;
    static std::mutex m_mutex;
    static std::map<int, std::string> m_severity;
};


#endif //DEV_UTILITY_LOGGER_H
