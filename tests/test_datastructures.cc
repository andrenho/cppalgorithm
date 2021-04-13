#include "catch.hpp"

#include "../datastructures/fixedarray.hh"
#include "../datastructures/dynamicarray.hh"
#include "../datastructures/linkedlist.hh"

template <typename T>
T run_test()
{
    T ds;
    REQUIRE(ds.empty() == true);
    ds.push(30);
    ds.push(40);
    ds.push(50);
    REQUIRE(ds.empty() == false);
    REQUIRE(ds.size() == 3);
    ds.pop();
    ds.pop();
    REQUIRE(ds.empty() == false);
    REQUIRE(ds.size() == 1);
    ds.push(60);
    REQUIRE(ds[0] == 30);
    REQUIRE(ds[1] == 60);

    auto it = ds.iterator();
    REQUIRE(it.has_current() == true);
    REQUIRE(it.get() == 30);
    it.next();
    REQUIRE(it.get() == 60);
    it.next();
    REQUIRE(it.has_current() == false);

    ds.pop();
    ds.pop();
    REQUIRE(ds.empty() == true);
    REQUIRE(ds.size() == 0);

    ds.push(10);
    ds.push(20);
    ds.push(40);
    ds.push(50);
    ds.insert(2, 30);
    REQUIRE(ds[1] == 20);
    REQUIRE(ds[2] == 30);
    REQUIRE(ds[3] == 40);

    REQUIRE(ds.remove(2) == 30);
    REQUIRE(ds[1] == 20);
    REQUIRE(ds[2] == 40);
    REQUIRE(ds[3] == 50);
    REQUIRE(ds.size() == 4);

    REQUIRE(ds.remove(0) == 10);
    REQUIRE(ds[0] == 20);
    REQUIRE(ds.size() == 3);
    
    REQUIRE(ds.remove(2) == 50);
    REQUIRE(ds.size() == 2);
    REQUIRE(ds[1] == 40);
    
    ds[1] = 50;
    REQUIRE(ds[1] == 50);
    
    ds.clear();
    REQUIRE(ds.empty() == true);
    return ds;
}

TEST_CASE("DynamicArray") {
    run_test<DynamicArray<int>>();
}

TEST_CASE("FixedArray") {
    auto ds = run_test<FixedArray<int, 10>>();
    for (size_t i = 0; i < 10; ++i)
        ds.push((int) i);
    REQUIRE_THROWS(ds.push(99));
}

TEST_CASE("LinkedList") {
    run_test<LinkedList<int>>();
}