mkdir build
cd build
cmake .. -DWITH_EXAMPLE=ON -DCMAKE_BUILD_TYPE=Release
make
./example/kf_predictor
./example/ekf_predictor