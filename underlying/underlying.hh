#ifndef CPPALGORITHM_UNDERLYING_HH
#define CPPALGORITHM_UNDERLYING_HH

template <typename T>
class Underlying {
public:
    virtual void        push(T&& t) = 0;
    virtual bool        is_empty() const = 0;
    virtual size_t      size() const = 0;
    virtual T&          at(size_t pos) = 0;
    
    T pop() {
        if (is_empty())
            throw std::runtime_error("Empty structure.");
        return unchecked_pop();
    }
    
    T const& at(size_t pos) const {
        return const_cast<Underlying*>(this)->at(pos);
    }
    
protected:
    virtual T      unchecked_pop() = 0;
};

#endif
