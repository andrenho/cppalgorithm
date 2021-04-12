#ifndef CPPALGORITHM_DATASTRUCTURE_HH
#define CPPALGORITHM_DATASTRUCTURE_HH

template <typename T>
class DataStructure {
public:
    virtual void        push(T&& t) = 0;
    virtual bool        empty() const = 0;
    virtual size_t      size() const = 0;
    virtual T&          at(size_t pos) = 0;
    virtual void        insert(size_t pos, T&& t) = 0;
    virtual T           remove(size_t pos) = 0;
    virtual void        clear() = 0;
    
    T pop() {
        if (empty())
            throw std::runtime_error("Empty structure.");
        return unchecked_pop();
    }
    
    T const& at(size_t pos) const {
        return const_cast<DataStructure*>(this)->at(pos);
    }
    
protected:
    virtual T      unchecked_pop() = 0;
};

#endif
