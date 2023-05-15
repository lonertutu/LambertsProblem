//
// Created by lonertutu on 14.05.23.
//

#ifndef LAMBERTSPROBLEM_STUMFF_HPP
#define LAMBERTSPROBLEM_STUMFF_HPP

#include <cmath>

/* C provides the Stumpff functions c(n,x) for
   n = 0, 1, 2, 3, 4, or 5.
*/

double Stumff(double z, unsigned int n) {
double c, tmp;

/* Elliptical path: use circular function representation. */

if (z > 0.1) {
    tmp = std::sqrt(z);
switch(n) {
    case 0:
        c = std::cos(tmp);
        break;
    case 1:
        c = std::sin(tmp) / tmp;
        break;
    case 2:
        c = (1.0 - std::cos(tmp)) / z;
        break;
    case 3:
        c = (tmp - std::sin(tmp)) / (z * tmp);
        break;
    case 4:
        c = (std::cos(tmp) - (1.0 - 0.5 * z)) / z * z;
        break;
    case 5:
        c = (std::sin(tmp) - (tmp - 0.16666666667 * z * tmp)) /
                 (z * z * tmp);
        break;
    default  : { }
    }
}

/* Near-parabolic or parabolic path: use series representation. */

if (std::abs(z) <= 0.1) {
    switch(n) {
        case 0:
            c = (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z /
                132.0) / 90.0) / 56.0) / 30.0) / 12.0) / 2.0);
            break;
        case 1:
            c = (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z /
                156.0) / 110.0) / 72.0) / 42.0) / 20.0) / 6.0);
            break;

        case 2:
            c = (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z *
                (1.0 - z /182.0) / 132.0) / 90.0) / 56.0) / 30.0) /12.0)/  2.0;
            break;

        case 3:
            c = (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z *
                (1.0 - z /210.0) / 156.0) / 110.0) / 72.0) / 42.0) /20.0)/  6.0;
            break;

        case 4:
            c = (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0
                - z /240.0) / 182.0) / 132.0) / 90.0) / 56.0) /30.0)/ 24.0;
            break;
        case 5:
            c = (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z * (1.0 - z *
                (1.0 - z /272.0) / 210.0) / 156.0) / 110.0) / 72.0) /42.0)/120.0;
            break;
    default  : { }
    }
}

/* Hyperbolic path: use hyperbolic function representation. */

if (-z > 0.1) {
    tmp = std::sqrt(-z);
    switch (n) {
        case (0) : {
            c = std::cosh(tmp);
            break;
        }
        case (1) : {
            c = std::sinh(tmp) / tmp;
            break;
        }
        case (2) : {
            c = (1.0 - std::cosh(tmp)) / z;
            break;
        }
        case (3) : {
            c = (tmp - std::sinh(tmp)) / (z * tmp);
            break;
        }
        case (4) : {
            c = (std::cosh(tmp) - (1.0 - 0.5 * z)) / (z * z);
            break;
        }
        case (5) : {
            c = (std::sqrt(tmp) - (tmp - 0.16666666667 * z * tmp)) /
                (z * z * tmp);
            break;
        }
        default: { }
    }
}
    return c;
}

#endif //LAMBERTSPROBLEM_STUMFF_HPP
