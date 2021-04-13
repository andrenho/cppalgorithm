#include "catch.hpp"

#include "../datastructures/fixedarray.hh"
#include "../datastructures/dynamicarray.hh"
#include "../datastructures/linkedlist.hh"
#include "../datastructures/bag.hh"
#include "../datastructures/queue.hh"
#include "../datastructures/stack.hh"

template <typename T>
T test_list()
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
    test_list<DynamicArray<int>>();
}

TEST_CASE("FixedArray") {
    auto ds = test_list<FixedArray<int, 10>>();
    for (size_t i = 0; i < 10; ++i)
        ds.push((int) i);
    REQUIRE_THROWS(ds.push(99));
}

TEST_CASE("LinkedList") {
    test_list<LinkedList<int>>();
}

TEST_CASE("Bag") {
    Bag<int> bag;
    bag.add(10);
    bag.add(20);
    bag.add(30);
    REQUIRE(bag.size() == 3);
    size_t count = 0;
    for (auto it = bag.iterator(); it.has_current(); it.next())
        ++count;
    REQUIRE(count == 3);
}

TEST_CASE("Stack") {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    REQUIRE(stack.peek() == 30);
    REQUIRE(stack.pop() == 30);
    REQUIRE(stack.pop() == 20);
    REQUIRE(stack.peek() == 10);
    REQUIRE(stack.empty() == false);
    REQUIRE(stack.pop() == 10);
    REQUIRE(stack.empty() == true);
}

TEST_CASE("Queue") {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    REQUIRE(queue.peek() == 10);
    REQUIRE(queue.dequeue() == 10);
    REQUIRE(queue.dequeue() == 20);
    REQUIRE(queue.peek() == 30);
    REQUIRE(queue.empty() == false);
    REQUIRE(queue.dequeue() == 30);
    REQUIRE(queue.empty() == true);
}