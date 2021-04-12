#ifndef CPPALGORITHM_FORWARDITERATOR_HH
#define CPPALGORITHM_FORWARDITERATOR_HH

#include "iterator.hh"

template <typename T>
class ForwardIterator : public MyIterator<T> {
public:
    explicit ForwardIterator(DataStructure<T> const* underlying) : underlying_(underlying) {}
    
    bool has_next() const override
    {
        if (index_ < underlying_->size())
            return true;
        return false;
    }
    
    T& next() override
    {
        index_++;
        return const_cast<DataStructure<T>*>(underlying_)->at(index_ - 1);
    }
    
    T const& next() const override
    {
        return underlying_->at(index_++);
    }

private:
    DataStructure<T> const* underlying_;
    mutable size_t index_ = 0;
};

#endif
