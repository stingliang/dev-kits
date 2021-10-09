//
// Created by Liang on 2021/9/29.
//

#ifndef DEV_UTILITY_LIBRARY_LOGGER_SAMPLE_H
#define DEV_UTILITY_LIBRARY_LOGGER_SAMPLE_H

#include "logger/logger.h"

#define SAMPLE_LOG(SEVERITY) LOGGER("Sample", SEVERITY)

void logger_sample() {
    auto config = log_initializer::log_config();
#ifdef WIN32
    config.log_path = R"(C:\Users\liangrui\CLionProjects\dev-utility\output\log)";
#else
    config.log_path = R"(./log)";
#endif
    config.severity = boost::log::trivial::trace;
    log_initializer::init(config);

    SAMPLE_LOG(trace) << "A trace severity message";
    SAMPLE_LOG(debug) << "A debug severity message";
    SAMPLE_LOG(info) << "An informational severity message";
    SAMPLE_LOG(warning) << "A warning severity message";
    SAMPLE_LOG(error) << "An error severity message";
    SAMPLE_LOG(fatal) << "A fatal severity message";
}

#endif //DEV_UTILITY_LIBRARY_LOGGER_SAMPLE_H
