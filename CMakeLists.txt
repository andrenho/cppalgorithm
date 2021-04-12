cmake_minimum_required(VERSION 3.19)
project(cppalgorithm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES underlying/datastructure.hh underlying/dynamicarray.hh underlying/fixedarray.hh iterator/iterator.hh iterator/forwarditerator.hh underlying/linkedlist.hh)

# add_library(algorithm ${SOURCES})

add_executable(test
               EXCLUDE_FROM_ALL
               ${SOURCES} tests/test_main.cc tests/test_underlying.cc)
