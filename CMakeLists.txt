cmake_minimum_required(VERSION 3.26)
project(da2324_p02_student)
project(da2324_p01_student)
project(da2324_p03_student)
project(da2324_p04_sol)

set(CMAKE_CXX_STANDARD 14)

set( CMAKE_BUILD_TYPE_TMP "${CMAKE_BUILD_TYPE}" )
set( CMAKE_BUILD_TYPE "Release" )
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
include_directories(TP1)
include_directories(TP2)
include_directories(TP3)

set( CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE_TMP} )

add_executable(da2324_p01_student
        TP1/ex1.cpp
        TP1/ex2.cpp
        TP1/ex3.cpp
        TP1/tests.cpp
        TP1/ex4.cpp
)

target_link_libraries(da2324_p01_student gtest gtest_main)

add_executable(da2324_p02_student
        TP2/ex1.cpp
        TP2/ex2.cpp
        TP2/ex3.cpp
        TP2/ex4.cpp
        TP2/ex5.cpp
)

target_link_libraries(da2324_p02_student gtest gtest_main)

add_executable(da2324_p03_student
        data_structures/MutablePriorityQueue.h
        data_structures/UFDS.cpp
        data_structures/UFDS.h
        TP3/MSTTestAux.h
        TP3/ex1.cpp
        TP3/ex2.cpp
        TP3/ex3.cpp
)

target_link_libraries(da2324_p03_student gtest gtest_main)

add_executable(da2324_p04_sol
        TP4/ex1.cpp
        TP4/ex2.cpp
        TP4/ex3.cpp
        TP4/ex4.cpp
        TP4/ex5.cpp
        TP4/ex6.cpp
        TP4/ex9.cpp
        running_examples/closest_point_pair/ClosestPointPair.cpp
)

target_link_libraries(da2324_p04_sol gtest gtest_main)
