#ifndef CPPALGORITHM_QUEUE_HH
#define CPPALGORITHM_QUEUE_HH

#include "../super/basicdatastructure.hh"

template <typename T, typename U = LinkedList<T>>
class Queue : public BasicDataStructure {
public:
    bool empty() const override
    {
        return list_.empty();
    }
    
    void clear() override
    {
        list_.clear();
    }
    
    void enqueue(T&& t) {
        list_.push(std::move(t));
    }
    
    T dequeue() {
        return list_.remove(0);
    }
    
    T const& peek() const {
        return list_[0];
    }

private:
    U list_;
};


#endif
