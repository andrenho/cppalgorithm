#ifndef CPPALGORITHM_BAG_HH
#define CPPALGORITHM_BAG_HH

#include <cstddef>
#include "../super/addeabledatastructure.hh"
#include "../super/sizeabledatastructure.hh"
#include "linkedlist.hh"

template <typename T, typename U = LinkedList<T>>
class Bag : public AddeableDataStructure<T>, public SizeableDataStructure {
public:
    void add(T&& t) override
    {
        list_.push(std::move(t));
    }
    
    bool empty() const override
    {
        return list_.empty();
    }
    
    void clear() override
    {
        list_.clear();
    }
    
    size_t size() const override
    {
        return list_.size();
    }
    
    Iterator<U, T> iterator() const {
        return list_.iterator();
    }

private:
    U list_;
};

#endif
