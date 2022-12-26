cmake_minimum_required(VERSION 3.24)
project(PtzControl)

set(CMAKE_CXX_STANDARD 17)

link_directories(XNetSDK/lib)
add_executable(PtzControl main.cpp PtzCameraControl.cpp PtzCameraControl.h)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        libXNetSDK.so
        )
