#ifndef CPPALGORITHM_ARRAY_HH
#define CPPALGORITHM_ARRAY_HH

#include <cstddef>
#include <stdexcept>
#include "../super/pushabledatastructure.hh"
#include "../super/randomaccessdatastructure.hh"
#include "../iterator/iterator.hh"

template <typename T>
class Array : public PushableDataStructure<T>, public RandomAccessDataStructure<T> {
public:
    void push(T&& t) override
    {
        increase_capacity();
        data()[size_++] = std::move(t);
    }
    
    T unchecked_pop() override
    {
        reduce_capacity();
        return data()[size_--];
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
        return data()[pos];
    }
    
    T const& operator[](size_t pos) const override
    {
        if (pos >= size_)
            throw std::runtime_error("Array size exceeded.");
        return data()[pos];
    }
    
    void insert(size_t pos, T&& t) override
    {
        increase_capacity();
        for (size_t i = size_ - 1; i >= pos; --i)
            data()[i + 1] = std::move(data()[i]);
        data()[pos] = t;
        size_++;
    }
    
    T remove(size_t pos) override
    {
        if (pos >= size_)
            throw std::runtime_error("There is no item at this location.");
        reduce_capacity();
        T t = std::move(data()[pos]);
        for (size_t i = pos; i < size_; ++i)
            data()[i] = data()[i + 1];
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
    
    Iterator<Array<T>, T> iterator() const {
        return Iterator<Array<T>, T>(*this, Item());
    }
    
    bool has_current(Item const& item) const {
        return item.current < size_;
    }
    
    T& get(Item const& item) {
        return data()[item.current];
    }
    
    Item next(Item const& item) const {
        return Item { item.current + 1 };
    }
    
protected:
    virtual void increase_capacity() = 0;
    virtual void reduce_capacity() = 0;
    virtual T*   data() = 0;
    
    size_t size_ = 0;

private:
    T const* data() const {
        return const_cast<Array<T>*>(this)->data();
    }
};

#endif //CPPALGORITHM_ARRAY_HH
