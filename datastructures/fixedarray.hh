#ifndef CPPALGORITHM_FIXEDARRAY_HH
#define CPPALGORITHM_FIXEDARRAY_HH

#include <cstddef>
#include <stdexcept>
#include "../super/pushabledatastructure.hh"
#include "../super/randomaccessdatastructure.hh"
#include "../iterator/iterator.hh"

template <typename T, size_t N>
class FixedArray : public PushableDataStructure<T>, public RandomAccessDataStructure<T> {
public:
    void push(T&& t) override
    {
        if (size_ == N)
            throw std::runtime_error("Maximum number of items exceeded.");
        data_[size_++] = std::move(t);
    }
    
    bool empty() const override
    {
        return size_ == 0;
    }
    
    size_t size() const override
    {
        return size_;
    }
    
    T& operator[](size_t pos) override
    {
        if (pos >= size_)
            throw std::runtime_error("Array size exceeded.");
        return data_[pos];
    }
    
    T const& operator[](size_t pos) const override
    {
        if (pos >= size_)
            throw std::runtime_error("Array size exceeded.");
        return data_[pos];
    }
    
    void insert(size_t pos, T&& t) override
    {
        if (pos >= size_)
            throw std::runtime_error("Array size exceeded.");
        for (size_t i = size_ - 1; i >= pos; --i)
            data_[i + 1] = std::move(data_[i]);
        data_[pos] = t;
        size_++;
    }
    
    T remove(size_t pos) override
    {
        if (pos >= size_)
            throw std::runtime_error("There is no item at this location.");
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
    
    // iterator support
    
    struct Item {
        size_t current = 0;
    };
    
    Iterator<FixedArray<T, N>, T> iterator() const {
        return Iterator<FixedArray<T, N>, T>(*this, Item());
    }
    
    bool has_current(Item const& item) const {
        return item.current < size_;
    }
    
    T& get(Item const& item) {
        return data_[item.current];
    }
    
    Item next(Item const& item) const {
        return Item { item.current + 1 };
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
