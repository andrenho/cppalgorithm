#ifndef CPPALGORITHM_PUSHABLE_DATASTRUCTURE_HH
#define CPPALGORITHM_PUSHABLE_DATASTRUCTURE_HH

#include "basicdatastructure.hh"

template <typename T>
class PushableDataStructure : public BasicDataStructure {
public:
    virtual void        push(T&& t) = 0;
    
    T pop() {
        if (empty())
            throw std::runtime_error("Empty structure.");
        return unchecked_pop();
    }
    
    virtual T      unchecked_pop() = 0;
};

#endif
