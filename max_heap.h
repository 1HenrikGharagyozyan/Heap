#pragma once
#include <vector>
#include <functional>
#include <stdexcept>
#include <utility>
#include <iterator>


template<typename T, typename Compare = std::less<T>>
class MaxHeap 
{
public:
    using value_type = T;
    using container_type = std::vector<T>;
    using size_type = typename container_type::size_type;
    using reference = T&;
    using const_reference = const T&;

private:
    container_type data_;
    Compare comp_;

    void heapify_up(size_type index) 
    {
        while (index > 0) 
        {
            size_type parent = (index - 1) / 2;
            if (comp_(data_[parent], data_[index]))
            {
                std::swap(data_[parent], data_[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void heapify_down(size_type index) 
    {
        size_type n = data_.size();
        while (true) 
        {
            size_type largest = index;
            size_type left = 2 * index + 1;
            size_type right = 2 * index + 2;

            if (left < n && comp_(data_[largest], data_[left])) 
                largest = left;
            if (right < n && comp_(data_[largest], data_[right])) 
                largest = right;

            if (largest != index) 
            {
                std::swap(data_[index], data_[largest]);
                index = largest;
            }
            else 
                break;
        }
    }

public:
    MaxHeap() = default;
    explicit MaxHeap(const Compare& comp) 
        : comp_(comp) 
    {
    }

    template<typename InputIt>
    MaxHeap(InputIt first, InputIt last, const Compare& comp = Compare())
        : data_(first, last)
        , comp_(comp) 
    {
        build_heap();
    }

    void build_heap()
    {
        for (int i = static_cast<int>(data_.size()) / 2 - 1; i >= 0; --i)
            heapify_down(static_cast<size_type>(i));
    }

    void push(const value_type& value) 
    {
        data_.push_back(value);
        heapify_up(data_.size() - 1);
    }

    void push(value_type&& value) 
    {
        data_.push_back(std::move(value));
        heapify_up(data_.size() - 1);
    }

    template<typename... Args>
    void emplace(Args&&... args) 
    {
        data_.emplace_back(std::forward<Args>(args)...);
        heapify_up(data_.size() - 1);
    }

    const_reference top() const 
    {
        if (empty()) 
            throw std::out_of_range("Heap is empty");
        return data_.front();
    }

    void pop() 
    {
        if (empty()) 
            throw std::out_of_range("Heap is empty");
        std::swap(data_.front(), data_.back());
        data_.pop_back();
        if (!empty()) heapify_down(0);
    }

    [[nodiscard]] 
    bool empty() const noexcept 
    { 
        return data_.empty(); 
    }

    [[nodiscard]] 
    size_type size() const noexcept 
    { 
        return data_.size(); 
    }

    container_type& data() noexcept 
    { 
        return data_; 
    }

    const container_type& data() const noexcept 
    { 
        return data_; 
    }
};

