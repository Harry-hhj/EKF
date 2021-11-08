#include "../include/ekf/AdaptiveEKF.hpp"
#include <iostream>


constexpr int Z_N = 2, X_N = 3;
/*
 * Before using ekf, now define Predict and Measure here.
 */

/* Define your model here i.e. how to predict next state */
struct Predict
{
    template <typename T>
    void operator () (const T x0[X_N], T x1[X_N]) {
        x1[0] = x0[2] * (x0[1] + delta_x) * (x0[1] + delta_x);      // y = kx^2
        x1[1] = x0[1] + delta_x;    // x
        x1[2] = x0[2];  // k
    }
    double delta_x;
};

/* Define the conversion of observations to forecasts here */
struct Measure
{
    template <typename T>
    void operator () (const T x0[X_N], T z0[Z_N]) {
        z0[0] = x0[0];
        z0[1] = z0[1];
    }
};