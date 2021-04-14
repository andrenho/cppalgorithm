cmake_minimum_required(VERSION 3.19)
project(cppalgorithm)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES datastructures/dynamicarray.hh datastructures/fixedarray.hh iterator/iterator.hh datastructures/linkedlist.hh
    iterator/iterator.hh super/basicdatastructure.hh super/sizeabledatastructure.hh super/pushabledatastructure.hh
    super/randomaccessdatastructure.hh datastructures/bag.hh super/addeabledatastructure.hh datastructures/stack.hh datastructures/queue.hh super/array.hh)

# add_library(algorithm ${SOURCES})

add_executable(test
               EXCLUDE_FROM_ALL
               ${SOURCES} tests/test_main.cc tests/test_datastructures.cc)
