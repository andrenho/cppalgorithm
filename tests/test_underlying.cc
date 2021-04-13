#include "catch.hpp"

#include "../underlying/fixedarray.hh"
#include "../underlying/dynamicarray.hh"
#include "../underlying/linkedlist.hh"

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
    REQUIRE(ds.at(0) == 30);
    REQUIRE(ds.at(1) == 60);

    auto it = ds.iterator();
    REQUIRE(it.has_next() == true);
    REQUIRE(it.next() == 30);
    REQUIRE(it.next() == 60);
    REQUIRE(it.has_next() == false);

    ds.pop();
    ds.pop();
    REQUIRE(ds.empty() == true);
    REQUIRE(ds.size() == 0);

    ds.push(10);
    ds.push(20);
    ds.push(40);
    ds.push(50);
    ds.insert(2, 30);
    REQUIRE(ds.at(1) == 20);
    REQUIRE(ds.at(2) == 30);
    REQUIRE(ds.at(3) == 40);

    REQUIRE(ds.remove(2) == 30);
    REQUIRE(ds.at(1) == 20);
    REQUIRE(ds.at(2) == 40);
    REQUIRE(ds.at(3) == 50);
    REQUIRE(ds.size() == 4);

    REQUIRE(ds.remove(0) == 10);
    REQUIRE(ds.at(0) == 20);
    REQUIRE(ds.size() == 3);
    
    REQUIRE(ds.remove(2) == 50);
    REQUIRE(ds.size() == 2);
    REQUIRE(ds.at(1) == 40);
    
    ds.clear();
    REQUIRE(ds.empty() == true);
    return ds;
}

TEST_CASE("FixedArray") {
    auto ds = run_test<FixedArray<int, 10>>();
    for (size_t i = 0; i < 10; ++i)
        ds.push((int) i);
    REQUIRE_THROWS(ds.push(99));
}

TEST_CASE("DynamicArray") {
    run_test<DynamicArray<int>>();
}

TEST_CASE("LinkedList") {
    run_test<LinkedList<int>>();
}
