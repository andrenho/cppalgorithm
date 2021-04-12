#ifndef CPPALGORITHM_FIXED_ARRAY_HH
#define CPPALGORITHM_FIXED_ARRAY_HH

#include <cstddef>
#include <stdexcept>
#include "../iterator/forwarditerator.hh"
#include "underlying.hh"

template <typename T, size_t N>
class FixedArray : public Underlying<T> {
public:
    void push(T&& t) override
    {
        if (size_ == N)
            throw std::runtime_error("Maximum number of items exceeded.");
        data_[size_++] = std::move(t);
    }
    
    bool is_empty() const override
    {
        return size_ == 0;
    }
    
    size_t size() const override
    {
        return size_;
    }
    
    T& at(size_t pos) override
    {
        if (pos >= size_)
            throw std::runtime_error("Array size exceeded.");
        return data_[pos];
    }
    
    ForwardIterator<T> iterator() const
    {
        return ForwardIterator<T>(this);
    }

protected:
    T unchecked_pop() override
    {
        return data_[size_--];
    }

private:
    size_t size_ = 0;
    T data_[N];
};

#endif
