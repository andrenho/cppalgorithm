#ifndef CPPALGORITHM_STACK_HH
#define CPPALGORITHM_STACK_HH

#include "../super/pushabledatastructure.hh"

template <typename T, typename U = LinkedList<T>>
class Stack : public PushableDataStructure<T> {
public:
    bool empty() const override
    {
        return list_.empty();
    }
    
    void clear() override
    {
        list_.clear();
    }
    
    void push(T&& t) override
    {
        list_.insert(0, std::move(t));
    }
    
    T const& peek() const {
        return (*(const U*)(&list_))[0];
    }

protected:
    T unchecked_pop() override
    {
        return list_.remove(0);
    }

private:
    U list_;
};

#endif
