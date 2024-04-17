cmake_minimum_required(VERSION 3.26)
project(DA-2024-TPs)

set(CMAKE_CXX_STANDARD 14)

set( CMAKE_BUILD_TYPE_TMP "${CMAKE_BUILD_TYPE}" )
set( CMAKE_BUILD_TYPE "Release" )
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(TP1)
include_directories(TP2)
include_directories(TP3)
include_directories(TP4)
include_directories(TP5)
include_directories(TP7)

set( CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_TMP} )

add_executable(DA-2024-TPs
        TP7/exercises.h
        TP7/ex8.cpp
        TP7/ex7.cpp
        TP7/ex6.cpp
        TP7/ex5.cpp
        TP7/ex4.cpp
        TP7/ex1.cpp
        TP5/testAux.h
        TP5/ex3.cpp
        TP5/ex2.cpp
        TP5/ex1.cpp
        TP4/ex9.cpp
        TP4/ex6.cpp
        TP4/ex5.cpp
        TP4/ex4.cpp
        TP4/ex3.cpp
        TP4/ex2.cpp
        TP4/ex1.cpp
        TP3/ex3.cpp
        TP3/ex2.cpp
        TP3/ex1.cpp
        TP2/ex5.cpp
        TP2/ex4.cpp
        TP2/ex3.cpp
        TP2/ex2.cpp
        TP2/ex1.cpp
        TP1/tests.cpp
        TP1/ex4.cpp
        TP1/ex3.cpp
        TP1/ex2.cpp
        TP1/ex1.cpp
        data_structures/Graph.h
        data_structures/Heap.cpp
        data_structures/MutablePriorityQueue.h
        data_structures/UFDS.cpp
        TP3/MSTTestAux.h
        running_examples/closest_point_pair/ClosestPointPair.cpp
)

target_link_libraries(DA-2024-TPs gtest gtest_main)
