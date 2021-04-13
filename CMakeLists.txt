cmake_minimum_required(VERSION 3.19)
project(cppalgorithm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES datastructures/datastructure.hh datastructures/dynamicarray.hh datastructures/fixedarray.hh iterator/iterator.hh datastructures/linkedlist.hh iterator/iterator.hh)

# add_library(algorithm ${SOURCES})

add_executable(test
               EXCLUDE_FROM_ALL
               ${SOURCES} tests/test_main.cc tests/test_datastructures.cc)
