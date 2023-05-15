//
// Created by lonertutu on 14.05.23.
//

#include "../src/Lambert.hpp"
#include "gtest/gtest.h"
#include <vector>

TEST(TEST_Lambert, Lambert_first) {
    Vector3D a = {5000., 10000., 2100.};
    Vector3D b = {-14600., 2500., 7000.};
    std::string str = "pro";
    double tolerance = 1e-5;
    std::pair<Vector3D, Vector3D> c = LambertsProblem<double>(a, b, 3600, 398600.0, str);
    std::cout << "Velocity "<<c.first.x << " " << c.first.y  << " " << c.first.z << std::endl;
    std::cout << c.second.x << " " << c.second.y  << " " << c.second.z;
    double compare0 = EuclidNorm(c.first - Vector3D {-6.93888, 1.22911, 3.34382});
    double compare1 = EuclidNorm(c.second - Vector3D {-4.47112, -4.40799, 0.000483585});
    ASSERT_NEAR(compare0, 0., tolerance);
    ASSERT_NEAR(compare1, 0., tolerance);
}

TEST(TEST_Lambert, Stumpff_func) {
    double tolerance = 1e-6;
    double comp0 = stumpS(-100.);
    double comp1 = stumpS(0.);
    double comp2 = stumpS(10.);
    double comp3 = stumpC(-50.);
    double comp4 = stumpC(0.);
    double comp5 = stumpC(50.);
    ASSERT_NEAR(comp1, 0.166667, tolerance);
    ASSERT_NEAR(comp2, 1.01975, tolerance);
    ASSERT_NEAR(comp3, 11.754054, tolerance);
    ASSERT_NEAR(comp4, 0.5, tolerance);
    ASSERT_NEAR(comp5, 0.00589304, tolerance);
    ASSERT_NEAR(comp0, 1332173878.449922, tolerance);
}
