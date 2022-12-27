cmake_minimum_required(VERSION 3.20)
project(PtzControl)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system program_options)

link_directories(XNetSDK/lib)
add_executable(PtzControl main.cpp PtzCameraControl.cpp PtzCameraControl.h)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        ${Boost_PROGRAM_OPTIONS_LIBRARY}
        libXNetSDK.so
        PRIVATE
        Boost::boost
        )
