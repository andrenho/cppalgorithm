#ifndef CPPALGORITHM_ITERATOR_HH
#define CPPALGORITHM_ITERATOR_HH

template <typename D, typename T>
class Iterator {
public:
    explicit Iterator(D const& ds, typename D::Item initial) : ds_(ds), current_(initial) {}
    
    bool has_current() const
    {
        return ds_.has_current(current_);
    }
    
    void next()
    {
        current_ = ds_.next(current_);
    }
    
    T& get()
    {
        return const_cast<D*>(&ds_)->get(current_);
    }
    
    T const& get() const
    {
        return ds_.get(current_);
    }
    
private:
    D const&          ds_;
    typename D::Item  current_;
};

#endif
