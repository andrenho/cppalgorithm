#ifndef CPPALGORITHM_FIXEDARRAY_HH
#define CPPALGORITHM_FIXEDARRAY_HH

#include <cstddef>
#include <stdexcept>
#include "../super/array.hh"

template <typename T, size_t N>
class FixedArray : public Array<T> {
protected:
    void increase_capacity() override
    {
        if (this->size() >= N)
            throw std::runtime_error("Cannot increase fixed array size.");
    }
    
    void reduce_capacity() override
    {
    }
    
    T* data() override
    {
        return data_;
    }

private:
    T data_[N];
};

#endif
