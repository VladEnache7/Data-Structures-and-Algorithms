cmake_minimum_required(VERSION 3.22)
project(MAP___hashtable_with_open_addressing_and_quadratic_probing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MAP___hashtable_with_open_addressing_and_quadratic_probing
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Map.cpp
        Map.h
        MapIterator.cpp
        MapIterator.h
        ShortTest.cpp
        ShortTest.h)
