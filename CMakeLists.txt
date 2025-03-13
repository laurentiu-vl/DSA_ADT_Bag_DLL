cmake_minimum_required(VERSION 3.30)
project(DSA_Bag_DLL_L2)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA_Bag_DLL_L2 main.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
