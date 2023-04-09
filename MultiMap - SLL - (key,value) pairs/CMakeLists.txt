cmake_minimum_required(VERSION 3.23)
project(MultiMap___SLL____key_value__pairs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MultiMap___SLL____key_value__pairs
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        MultiMap.cpp
        MultiMap.h
        MultiMapIterator.cpp
        MultiMapIterator.h
        ShortTest.cpp
        ShortTest.h)
