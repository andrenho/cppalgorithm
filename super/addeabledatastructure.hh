#ifndef CPPALGORITHM_ADDEABLEDATASTRUCTURE_HH
#define CPPALGORITHM_ADDEABLEDATASTRUCTURE_HH

template <typename T>
class AddeableDataStructure : public BasicDataStructure {
public:
    virtual void add(T&& t) = 0;
};

#endif
