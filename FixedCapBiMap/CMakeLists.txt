cmake_minimum_required(VERSION 3.23)
project(FixedCapBiMap)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(FixedCapBiMap
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        FixedCapBiMap.cpp
        FixedCapBiMap.h
        FixedCapBiMapIterator.cpp
        FixedCapBiMapIterator.h
        ShortTest.cpp
        ShortTest.h)
