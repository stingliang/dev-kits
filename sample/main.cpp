//
// Created by Liang on 2021/9/29.
//

#include "sample/logger_sample.h"
#include "sample/utility_sample.h"

#define CROSS_LINE(MODULE_NAME) \
std::cout << "====================[" << MODULE_NAME << "]====================" << std::endl;

int main() {
    CROSS_LINE("logger")
    logger_sample();

    CROSS_LINE("utility")
    utility_sample();

    return 0;
}
