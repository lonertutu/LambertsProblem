//
// Created by lonertutu on 01.04.23.
//

#ifndef LAMBERTSPROBLEM_VECTOR3D_HPP
#define LAMBERTSPROBLEM_VECTOR3D_HPP

#include <iostream>
#include <cmath>

struct Vector3D {
    double x;
    double y;
    double z;
};

Vector3D operator+(const Vector3D &a, const Vector3D &b) {
    Vector3D sol_vec{};
        sol_vec.x = a.x + b.x;
        sol_vec.y = a.y + b.y;
        sol_vec.z = a.z + b.z;
    return sol_vec;
}

Vector3D operator-(const Vector3D &a, const Vector3D &b) {
    Vector3D sol_vec{};
        sol_vec.x = a.x - b.x;
        sol_vec.y = a.y - b.y;
        sol_vec.z = a.z - b.z;
    return sol_vec;
}

Vector3D operator*(const Vector3D &a, const Vector3D &b) {
    Vector3D sol_vec{};
        sol_vec.x = a.x * b.x;
        sol_vec.y = a.y * b.y;
        sol_vec.z = a.z * b.z;
    return sol_vec;
}

Vector3D operator*(const double scalar, const Vector3D &a) {
    Vector3D sol_vec{};
        sol_vec.x = a.x * scalar;
        sol_vec.y = a.y * scalar;
        sol_vec.z = a.z * scalar;
    return sol_vec;
}
Vector3D operator*(const Vector3D &a, const double scalar) {
    Vector3D sol_vec{};
    sol_vec.x = a.x * scalar;
    sol_vec.y = a.y * scalar;
    sol_vec.z = a.z * scalar;
    return sol_vec;
}

double EuclidNorm(const Vector3D &a) {
    return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

double ScalarMult(const Vector3D &a, const Vector3D &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D VecMult(const Vector3D &a, const Vector3D &b) {
    Vector3D sol_vec{};
        sol_vec.x = a.y * b.z - a.z * b.y;
        sol_vec.y = a.z * b.x - a.x * b.z;
        sol_vec.z = a.x * b.y - a.y * b.x;
    return sol_vec;
}

#endif //LAMBERTSPROBLEM_VECTOR3D_HPP

