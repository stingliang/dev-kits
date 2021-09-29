//
// Created by Liang on 2021/9/29.
//

#ifndef DEV_UTILITY_LIBRARY_UTILITY_SAMPLE_H
#define DEV_UTILITY_LIBRARY_UTILITY_SAMPLE_H

#include "utility/utility.h"
#include "logger/logger.h"

void utility_sample() {
    std::map<int, std::string> _map {
        {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}
    };
    LOG(INFO, "map: " << printStl(_map).str())

    std::vector<int> _vector { 1, 2, 3, 4, 5 };
    LOG(INFO, "vector: " << printStl(_vector).str())
}

#endif //DEV_UTILITY_LIBRARY_UTILITY_SAMPLE_H
