//
// Created by Liang on 2021/9/29.
//

#ifndef DEV_UTILITY_LIBRARY_LOGGER_SAMPLE_H
#define DEV_UTILITY_LIBRARY_LOGGER_SAMPLE_H

#include "logger/logger.h"

void logger_sample() {
    LOGGER_LEVEL(TRACE)
    LOG(TRACE, "Hello, World!")
    LOG(DEBUG, "Hello, World!")
    LOG(INFO, "Hello, World!")
    LOG(WARN, "Hello, World!")
    LOG(ERROR, "Hello, World!")
}

#endif //DEV_UTILITY_LIBRARY_LOGGER_SAMPLE_H
