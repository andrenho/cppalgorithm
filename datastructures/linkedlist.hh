#ifndef CPPALGORITHM_LINKEDLIST_HH
#define CPPALGORITHM_LINKEDLIST_HH

#include <cstddef>
#include <stdexcept>
#include "../super/pushabledatastructure.hh"
#include "../super/randomaccessdatastructure.hh"
#include "../iterator/iterator.hh"

template <typename T>
class LinkedList : public PushableDataStructure<T>, public RandomAccessDataStructure<T> {
    struct Node {
        T t;
        Node* next = nullptr;
    };

public:
    void push(T&& t) override
    {
        Node* new_node = new Node();
        new_node->t = std::move(t);
        if (data_ == nullptr) {
            data_ = new_node;
        } else {
            Node* node = data_;
            while (node->next)
                node = node->next;
            node->next = new_node;
        }
    }
    
    bool empty() const override
    {
        return data_ == nullptr;
    }
    
    size_t size() const override
    {
        Node* node = data_;
        size_t i = 0;
        while (node) {
            ++i;
            node = node->next;
        }
        return i;
    }
    
    T& operator[](size_t pos) override
    {
        return find_node(pos)->t;
    }
    
    T const& operator[](size_t pos) const override
    {
        return find_node(pos)->t;
    }
    
    void insert(size_t pos, T&& t) override
    {
        Node* new_node = new Node();
        new_node->t = std::move(t);
        
        if (pos == 0) {
            new_node->next = data_;
            data_ = new_node;
        } else {
            Node* current_node = find_node(pos - 1);
            Node* next_node = current_node->next;
            new_node->next = next_node;
            current_node->next = new_node;
        }
    }
    
    T remove(size_t pos) override
    {
        if (!data_)
            throw std::runtime_error("Array size exceeded.");
    
        if (pos == 0) {
            Node* old = data_;
            T t = std::move(old->t);
            data_ = data_->next;
            delete old;
            return t;
        } else {
            Node* previous_node = find_node(pos - 1);
            Node* current_node = previous_node->next;
            previous_node->next = current_node->next;
            T t = std::move(current_node->t);
            delete current_node;
            return t;
        }
    }
    
    void clear() override
    {
        Node* node = data_;
        while (node) {
            Node* to_delete = node;
            node = node->next;
            delete to_delete;
        }
        data_ = nullptr;
    }
    
    // iterator support
    
    struct Item {
        LinkedList<T>::Node* node = nullptr;
    };
    
    Iterator<LinkedList<T>, T> iterator() const {
        return Iterator<LinkedList<T>, T>(*this, Item { data_ });
    }
    
    bool has_current(Item const& item) const {
        return item.node != nullptr;
    }
    
    T& get(Item const& item) {
        return item.node->t;
    }
    
    Item next(Item const& item) const {
        return Item { item.node->next };
    }

protected:
    T unchecked_pop() override
    {
        Node* node = data_;
        Node* previous = nullptr;
        while (node->next) {
            previous = node;
            node = node->next;
        }
        if (previous)
            previous->next = nullptr;
        else
            data_ = nullptr;
        T t = std::move(node->t);
        delete node;
        return t;
    }

private:
    Node* data_ = nullptr;
    
    Node* find_node(size_t pos) const
    {
        Node* node = data_;
        for (size_t i = 0; i < pos; ++i) {
            if (!node)
                throw std::runtime_error("Array size exceeded.");
            node = node->next;
        }
        return node;
    }
};

#endif
