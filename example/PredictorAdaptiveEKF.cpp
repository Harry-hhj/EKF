#include "PredictorAdaptiveEKF.hpp"


int main() {
    // Choose random seed
    std::srand(0);

    // Generate noisy experimental data
    const int N = 100;
    const double k = 1;
    Eigen::Matrix<double, 1, N> noise = Eigen::Matrix<double, 1, N>::Random();
    Eigen::Matrix<double, 1, N> data = Eigen::Matrix<double, 1, N>::LinSpaced(0, k * (N- 1));
    data += noise;
    data = (data.array() * data.array()).matrix();
    std::cout << "data = [" << data << "]" << std::endl << std::endl;

    // Update & Predict
    Predict predict;
    predict.delta_x = 1;
    Measure measure;
    AdaptiveEKF<X_N, Z_N> ekf;
    ekf.Q << 1, 0, 0,
             0, 1, 0,
             0, 0, 1;
    ekf.R << 1, 0,
             0, 1;
    ekf.Xe << data[0], 0, 0;

    std::cout << "predict = [0 ";
    for (int i = 1; i < N; i++) {
        ekf.predict(predict);  // Update internal state
        Eigen::Matrix<double, Z_N, 1> watch;
        watch << data[i], i;
        auto Xe = ekf.update(measure, watch);  // estimate
        std::cout << 2 * Xe[1] * Xe[2] << " ";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}