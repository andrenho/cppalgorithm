#ifndef CPPALGORITHM_RANDOMACCESS_DATASTRUCTURE_HH
#define CPPALGORITHM_RANDOMACCESS_DATASTRUCTURE_HH

#include "sizeabledatastructure.hh"

template <typename T>
class RandomAccessDataStructure : public SizeableDataStructure {
public:
    virtual T&          operator[](size_t pos) = 0;
    virtual T const&    operator[](size_t pos) const = 0;
    virtual void        insert(size_t pos, T&& t) = 0;
    virtual T           remove(size_t pos) = 0;
    virtual void        clear() = 0;
};

#endif
