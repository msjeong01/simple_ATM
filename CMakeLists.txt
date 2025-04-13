cmake_minimum_required(VERSION 3.0)
project("simple_ATM")

set(CMAKE_CXX_COMPILER g++)
include_directories(include)

add_executable(simple_atm
    src/main.cpp
    src/ATMController.cpp
)