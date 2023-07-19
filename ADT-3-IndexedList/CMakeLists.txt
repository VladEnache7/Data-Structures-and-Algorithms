cmake_minimum_required(VERSION 3.22)
project(IndexedList CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(IndexedList
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IndexedList.cpp
        IndexedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
