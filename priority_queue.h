#pragma once
#include "max_heap.h"

template<typename T, typename Container = std::vector<T>, typename Compare = std::less<T>>
class PriorityQueue 
{
public:
    using value_type = T;
    using container_type = Container;
    using size_type = typename container_type::size_type;
    using reference = T&;
    using const_reference = const T&;

private:
    MaxHeap<T, Compare> _heap;

public:
    PriorityQueue() = default;
    explicit PriorityQueue(const Compare& comp) 
        : _heap(comp) 
    {
    }

    template<typename InputIt>
    PriorityQueue(InputIt first, InputIt last, const Compare& comp = Compare())
        : _heap(first, last, comp) 
    {
    }

    void push(const value_type& value) 
    { 
        _heap.push(value);
    }

    void push(value_type&& value) 
    { 
        _heap.push(std::move(value)); 
    }

    template<typename... Args>
    void emplace(Args&&... args) 
    { 
        _heap.emplace(std::forward<Args>(args)...); 
    }

    const_reference top() const 
    { 
        return _heap.top(); 
    }

    void pop() 
    {
        _heap.pop();
    }

    [[nodiscard]] 
    bool empty() const noexcept 
    {
        return _heap.empty(); 
    }

    [[nodiscard]] 
    size_type size() const noexcept 
    {
        return _heap.size(); 
    }
};
