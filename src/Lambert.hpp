#ifndef LAMBERTSPROBLEM_LIBRARY_H
#define LAMBERTSPROBLEM_LIBRARY_H

#include "Vector3D.hpp"
#include "StumpffFunc.hpp"
#include <vector>
#include <string>
#include <map>


template <typename T>
T y(const T z, const T r0, const T rf, const T A) {
    T dum = r0 + rf + A * (z * stumpS(z) - 1) / std::sqrt(stumpC(z));
    return dum;
}

template <typename T>
T F(const T z, const T r0, const T rf, const double &time,
    const double &GM, const T A) {
    T tmp = y(z, r0, rf, A);
    T p = std::pow(tmp / stumpC(z), 1.5) * stumpS(z) + A * std::sqrt(tmp) - std::sqrt(GM) * time;
    return p;
}

template <typename T>
T dFdz(const T z, const T r0, const T rf, const T A) {
    T tmp = y(z, r0, rf, A);
    T temp = y(0., r0, rf, A);
    T tmp1 = stumpC(z);
    T tmp2 = stumpS(z);
    T dum;
    if (z == 0)
         dum = sqrt(2) / 40 * std::pow(temp, 1.5) + A / 8 * (sqrt(temp) + A * sqrt(0.5 / temp));
    else
         dum = std::pow(tmp / tmp1, 1.5) * (0.5 / z * (tmp1 - 1.5 * tmp2 / tmp1) +
            3 / 4 * pow(tmp2, 2) / tmp1) + A / 8 * (3 * tmp2 / tmp1 * sqrt(tmp) + A * sqrt(tmp1 / tmp));
    return dum;
}

/*!
    \brief The function of finding velocities from two given vectors of the initial and target orbits

    \param[in] R0 -initial position vector (km)
    \param[in] Rf - final position vector (km)
    \param[in] time - desired space maneuver time (sec)
    \param[in] GM - gravitational parameter (kmˆ3/sˆ2)

*/
template <typename T>
std::pair<Vector3D, Vector3D> LambertsProblem(const Vector3D &R0, const Vector3D &Rf, const double &time,
                               const double &GM, const std::string &str) {
    std::map <std::string, int> mapping;
    const int pro = 1;
    const int retro = 2;
    mapping["pro"] = pro;
    mapping["retro"] = retro;

    double tol = 1.e-6;
    unsigned int nmax = 0;
    unsigned int n = 0;
    double z = 1.5;
    T r0 = EuclidNorm(R0);
    T rf = EuclidNorm(Rf);
    T c12 = VecMult(R0, Rf).z;
    T s12 = ScalarMult(R0, Rf);
    T A, coefF, tmp;
    T f, g ,gdot;
    Vector3D V1{0. , 0. ,0.};
    Vector3D V2{0. , 0. ,0.};
    T ratio = 1.;


    T theta = std::acos(s12 / (r0 * rf));
    switch (mapping[str]) {
        case pro:
            if (c12 <= 0.)
                theta = 2 * atan(1) * 4 - theta;
            break;

        case retro:
            if (c12 >= 0.)
                theta = 2 * atan(1) * 4 - theta;
            break;
        default:
            theta = 2 * atan(1) * 4 - theta;
            //Prograde trajectory assumed
    }

    A = std::sin(theta) * sqrt(r0 * rf / (1 - std::cos(theta)));
    coefF = F(z, r0, rf, time, GM, A);
    while (coefF < 0) {
        z += 0.1;
        coefF = F(z, r0, rf, time, GM, A);
    }

    //Newton's procedure
    while (std::abs(ratio) > tol && n <= nmax) {
        n += 1;
        ratio = F(z, r0, rf, time, GM, A) / dFdz(z, r0, rf, A);
        //std::cout << n << ' ' << ratio << '\n';
        z -= ratio;
    }

    if (n >= nmax)
        std::cout << "Number of iterations exceeds" << std::endl;

    tmp = y(z, r0, rf, A);
    //param f & g - Lagrange coefficients
    f = 1 - tmp / r0;
    g = A * sqrt(tmp / GM);
    gdot = 1 - tmp / rf;
    V1 = 1 / g * (Rf - f * R0);
    V2 = 1 / g * (gdot * Rf - R0);
    std::pair<Vector3D, Vector3D> pair = {V1, V2};
    return pair;
}

#endif //LAMBERTSPROBLEM_LIBRARY_H
