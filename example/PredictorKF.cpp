#include "PredictorKF.hpp"
#include <iostream>


int main(){
    /* 
    // Well-handled example

    // Choose random seed
    std::srand((unsigned int) time(NULL));

    // Generate noisy experimental data
    const int N = 20;
    const double k = 2.5;
    Eigen::Matrix<double, 1, N> noise = Eigen::Matrix<double, 1, N>::Random();
    Eigen::Matrix<double, 1, N> data = Eigen::Matrix<double, 1, N>::LinSpaced(0, k * (N- 1));
    data += noise;
    std::cout << "data = " << data << std::endl << std::endl;
    */
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

    // Set initial state
    _Kalman::Matrix_x1d X;
    _Kalman::Matrix_xxd A;
    _Kalman::Matrix_xxd P;
    _Kalman::Matrix_xxd R;
    _Kalman::Matrix_xzd K;
    _Kalman::Matrix_zxd H;
    _Kalman::Matrix_zzd Q;
    X << data[0], 0;
    A << 1, 1, 0, 1;
    H << 1, 0;
    R << 2, 0, 0, 2;
    Q << 10;
    _Kalman kalman(A, H, R, Q, X, 0);

    // Predict & Update
    std::cout << "predict = [0 ";
    for (int i = 1; i < N; i++) {
        // 更新预测
        _Kalman::Matrix_z1d Z{data[i]};
        _Kalman::Matrix_x1d X_k = kalman.update(Z, i);
        std::cout << X_k[1] << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}