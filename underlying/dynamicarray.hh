#ifndef CPPALGORITHM_DYNAMICARRAY_HH
#define CPPALGORITHM_DYNAMICARRAY_HH

#include <cstddef>
#include <cstdint>
#include "datastructure.hh"

template <typename T>
class DynamicArray : public DataStructure<T> {
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
    
    bool empty() const override
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
    
    void insert(size_t pos, T&& t) override
    {
        if (size_ == capacity_)
            resize(capacity_ * 2);
        for (size_t i = size_ - 1; i >= pos; --i)
            data_[i + 1] = std::move(data_[i]);
        data_[pos] = t;
        size_++;
    }
    
    T remove(size_t pos) override
    {
        if (pos >= size_)
            throw std::runtime_error("There is no item at this location.");
        if (size_ > 0 && size_ < capacity_ / 4)
            resize(capacity_ / 2);
        T t = std::move(data_[pos]);
        for (size_t i = pos; i < size_; ++i)
            data_[i] = data_[i + 1];
        --size_;
        return t;
    }
    
    void clear() override
    {
        size_ = 0;
    }
    
    ForwardIterator<T> iterator() const
    {
        return ForwardIterator<T>(this);
    }
    
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;
    
    void resize(size_t new_capacity)
    {
        if (new_capacity == 0)
            new_capacity = 1;
        data_ = (T*) realloc((void*) data_, new_capacity * sizeof(T));
        capacity_ = new_capacity;
    }
};

#endif
