#ifndef CPPALGORITHM_DYNAMICARRAY_HH
#define CPPALGORITHM_DYNAMICARRAY_HH

#include <cstddef>
#include <cstdint>
#include "../super/array.hh"

template <typename T>
class DynamicArray : public Array<T> {
protected:
    void increase_capacity() override
    {
        if (this->size() == capacity_)
            resize(capacity_ * 2);
    }
    
    void reduce_capacity() override
    {
        if (this->size() > 0 && this->size() < capacity_ / 4)
            resize(capacity_ / 2);
    }
    
    T* data() override
    {
        return data_;
    }

private:
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
