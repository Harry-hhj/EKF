# EKF (Extended Kalman Filter)

This project is a C++ implementation of EKF.For the related principles of EKF, please check [this tutorial]() (TODO).

## Project environment

- Eigen
- Ceres

If you have not installed them, please run the following commands in the terminal, otherwise, you can skip this step.

Eigen can be installed via apt:
```shell
sudo apt install libeigen3-dev
```

Ceres must be compiled and installed through source code.

If Ubuntu cannot find cxsparse or other libs during installation, you need to add the following source:

```shell
# First step: Open sources.list
sudo gedit /etc/apt/sources.list
# Second step: Paste the source below to the end of the file
deb http://cz.archive.ubuntu.com/ubuntu trusty main universe
# Third step: Update source
sudo apt update
# Fourth step, enter the dependency installation command to install the dependency
sudo apt-get install liblapack-dev libsuitesparse-dev libcxsparse3.1.2 libgflags-dev libgoogle-glog-dev libgtest-dev
```

Then download the source code from [github](https://github.com/ceres-solver/ceres-solver/releases) and unzip it `tar -xzvf <ceres-solves>.tar.gz`.

Enter the project directory, follow the steps below to enter commands in Terminal to compile and install.

```shell
mkdir build
cd build
cmake ..
make
sudo make install
```

## Usage

The code is header only, but it will rely on some third-party libraries as auxiliary functions.When applied to your project, you only need to include the hpp file in `include/`.

### run-example command

Run the following code to see the output of the sample program:

```shell
mkdir build
cd build
cmake .. -DWITH_EXAMPLE=ON -DCMAKE_BUILD_TYPE=Release
make
./example/kf_predictor
./example/ekf_predictor
```

The example compares the two filters to calculate the derivative of f(x)=kx^2. You will get the output of the program. Draw them in matlab, as shown below:

![lab](https://raw.githubusercontent.com/Harry-hhj/EKF/master/README.assets/ekf.png)

At the same time, we also draw and compare the output results of the Kalman filter, and **we can see the huge advantage of ekf for nonlinear input**.

## TODO

- [ ] ekf `estimate()`
- [ ] ukf implementation

**_If you think this project is helpful to you, please give me a thumbs up, it is very useful to me._**
**_如果你觉得这个项目对你有所帮助，请给我一个点赞，这对我很有用。_**


## Acknowledgement

JiaoLong: https://github.com/SJTU-RoboMaster-Team for Learning platform

txy: https://github.com/xinyang-go for Code implementation and Guidance

flx: https://github.com/E-T-E-R-N-A-L-B-L-U-E for Example

---
Author: [Harry-hhj](https://github.com/Harry-hhj?tab=repositories)

Code Implementation: [xinyang-go](https://github.com/xinyang-go)

Colaborator: [E-T-E-R-N-A-L-B-L-U-E](https://github.com/E-T-E-R-N-A-L-B-L-U-E)