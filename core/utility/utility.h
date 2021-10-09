//
// Created by Liang on 2021/9/29.
//

#ifndef DEV_UTILITY_LIBRARY_UTILITY_H
#define DEV_UTILITY_LIBRARY_UTILITY_H

#include "common.h"

///
/// \tparam T1
/// \tparam T2
/// \param std::map
/// \return std::stringstream
/// \brief print stl map
template<typename T1, typename T2>
std::stringstream printStl(std::map<T1,T2>& m) {
    std::stringstream ss;
    for(auto const& elem : m) {
        ss << "[" << elem.first << ": " << elem.second << "]";
    }
    return ss;
}

///
/// \tparam T
/// \param stl/boost container
/// \return std::stringstream
/// \brief print stl set
template<typename T>
std::stringstream printStl(T& s) {
    std::stringstream ss;
    for(auto const& elem : s) {
        ss << "[" << elem << "]";
    }
    return ss;
}

#endif //DEV_UTILITY_LIBRARY_UTILITY_H
