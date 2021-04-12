cmake_minimum_required(VERSION 3.19)
project(cppalgorithm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES underlying/underlying.hh underlying/dynamic_array.hh underlying/fixed_array.hh iterator/iterator.hh iterator/forwarditerator.hh)

# add_library(algorithm ${SOURCES})

add_executable(test
               EXCLUDE_FROM_ALL
               ${SOURCES} tests/test_main.cc tests/test_array.cc)
