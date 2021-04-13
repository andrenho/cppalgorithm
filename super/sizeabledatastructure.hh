#ifndef CPPALGORITHM_SIZEABLE_DATASTRUCTURE_HH
#define CPPALGORITHM_SIZEABLE_DATASTRUCTURE_HH

#include "basicdatastructure.hh"

class SizeableDataStructure : public BasicDataStructure {
public:
    virtual size_t      size() const = 0;
};

#endif
