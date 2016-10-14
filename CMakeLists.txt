cmake_minimum_required(VERSION 3.6)
project(adv_cpp_hs16)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp exercise1/HelloWorld.h exercise1/HelloWorld.cpp exercise2/fraction.cpp exercise2/fraction.h exercise2/fractionTestDriver.cpp exercise2/fractionTestDriver.h exercise2/interactiveFraction.cpp exercise2/interactiveFraction.h utils/inputUtils.cpp utils/inputUtils.h)
add_executable(adv_cpp_hs16 ${SOURCE_FILES})