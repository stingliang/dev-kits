//
// Created by Liang on 2021/9/29.
//

#include "Logger/Logger.h"

int main() {
    LOG(TRACE, "Hello, World!")
    LOG(DEBUG, "Hello, World!")
    LOG(INFO, "Hello, World!")
    LOG(WARN, "Hello, World!")
    LOG(ERROR, "Hello, World!")

    return 0;
}
