#pragma once

#include <iterator>
#include <functional>
#include <algorithm>

template<typename RandomIt, typename Compare>
void make_heap(RandomIt first, RandomIt last, Compare comp)
{
    const auto n = std::distance(first, last);
    for (auto i = n / 2 - 1; i >= 0; --i)
        std::push_heap(first, first + i + 1, comp);
}

template<typename RandomIt>
void make_heap(RandomIt first, RandomIt last) 
{
    make_heap(first, last, std::less<typename std::iterator_traits<RandomIt>::value_type>());
}

template<typename RandomIt, typename Compare>
void push_heap(RandomIt first, RandomIt last, Compare comp) 
{
    auto child = std::distance(first, last) - 1;
    while (child > 0) 
    {
        auto parent = (child - 1) / 2;
        if (comp(*(first + parent), *(first + child))) 
        {
            std::swap(*(first + parent), *(first + child));
            child = parent;
        }
        else break;
    }
}

template<typename RandomIt>
void push_heap(RandomIt first, RandomIt last) 
{
    push_heap(first, last, std::less<typename std::iterator_traits<RandomIt>::value_type>());
}

template<typename RandomIt, typename Compare>
void pop_heap(RandomIt first, RandomIt last, Compare comp) 
{
    std::swap(*first, *(last - 1));
    auto n = std::distance(first, last) - 1;
    size_t index = 0;
    while (true) 
    {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t largest = index;

        if (left < n && comp(*(first + largest), *(first + left))) 
            largest = left;
        if (right < n && comp(*(first + largest), *(first + right))) 
            largest = right;

        if (largest != index) 
        {
            std::swap(*(first + index), *(first + largest));
            index = largest;
        }
        else 
            break;
    }
}

template<typename RandomIt>
void pop_heap(RandomIt first, RandomIt last) 
{
    pop_heap(first, last, std::less<typename std::iterator_traits<RandomIt>::value_type>());
}


