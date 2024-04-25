cmake_minimum_required(VERSION 3.28.6)
project(cpphw1)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpphw1 main.cpp float.h float.cpp Myfloat_overflow.h Myfloat_overflow.cpp)