#ifndef CPPALGORITHM_DYNAMIC_ARRAY_HH
#define CPPALGORITHM_DYNAMIC_ARRAY_HH

#include <cstddef>
#include <cstdint>
#include "underlying.hh"

template <typename T>
class DynamicArray : public Underlying<T> {
public:
    void push(T&& t) override
    {
        if (size_ == capacity_)
            resize(capacity_ * 2);
        data_[size_++] = std::move(t);
    }
    
    T unchecked_pop() override
    {
        if (size_ > 0 && size_ < capacity_ / 4)
            resize(capacity_ / 2);
        return data_[size_--];
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
    
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;
    
    void resize(size_t new_size)
    {
        data_ = (T*) realloc((void*) data_, new_size * sizeof(T));
    }
};

#endif
