//
// Created by lonertutu on 14.05.23.
//

#ifndef UNTITLED_STUMPFFFUNC_HPP
#define UNTITLED_STUMPFFFUNC_HPP
#include <cmath>


template<typename T>
T stumpC(const T z) {
    T c;
    if (z > 0)
        c = (1 - std::cos(std::sqrt(z))) / z;
    else if (z < 0)
        c = (std::cosh(std::sqrt(-z)) - 1) / (-z);
    else c = 0.5;
    return c;
}

template<typename T>
T stumpS(const T z) {
    T s;
    T tmp;
    if (z > 0) {
        tmp = std::sqrt(z);
        s = std::pow((tmp - std::sin(tmp)) / tmp, 3);
    }
    else if (z < 0) {
        tmp = std::sqrt(-z);
        s = std::pow((std::sinh(tmp) - tmp) / (tmp), 3);
    }
    else s = 1./6;
    return s;
}
#endif //UNTITLED_STUMPFFFUNC_HPP
