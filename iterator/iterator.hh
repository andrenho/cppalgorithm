#ifndef CPPALGORITHM_ITERATOR_HH
#define CPPALGORITHM_ITERATOR_HH

#include "../underlying/underlying.hh"

template <typename T>
class MyIterator {
public:
    virtual bool     has_next() const = 0;
    virtual T&       next() = 0;
    virtual T const& next() const = 0;
protected:
    MyIterator() = default;
    int i = 0;
};

#endif
