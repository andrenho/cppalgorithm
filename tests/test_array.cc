#include "catch.hpp"

#include "../underlying/fixed_array.hh"
#include "../underlying/dynamic_array.hh"

template <typename T>
T run_test()
{
    T ds;
    REQUIRE(ds.is_empty() == true);
    ds.push(30);
    ds.push(40);
    ds.push(50);
    REQUIRE(ds.is_empty() == false);
    REQUIRE(ds.size() == 3);
    ds.pop();
    ds.pop();
    REQUIRE(ds.is_empty() == false);
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
    REQUIRE(ds.is_empty() == true);
    REQUIRE(ds.size() == 0);
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