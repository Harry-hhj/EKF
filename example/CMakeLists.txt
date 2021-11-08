project(example)
add_compile_definitions(PROJECT_DIR="${PROJECT_SOURCE_DIR}")

add_executable(ekf_predictor PredictorAdaptiveEKF.cpp)
add_executable(kf_predictor PredictorKF.cpp)