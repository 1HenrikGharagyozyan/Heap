#include <iostream>
#include <vector>

#include "priority_queue.h" 
#include "max_heap.h"
#include "heap_algorithms.h"

void test_max_heap() 
{
    std::cout << "=== MaxHeap Test ===\n";
    MaxHeap<int> heap;

    std::cout << "Pushing: ";
    for (int x : {5, 3, 8, 1, 9}) 
    {
        std::cout << x << " ";
        heap.push(x);
    }
    std::cout << "\n";

    std::cout << "Heap top: " << heap.top() << "\n"; // должно быть 9

    std::cout << "Popping all:\n";
    while (!heap.empty()) 
    {
        std::cout << heap.top() << " ";
        heap.pop();
    }
    std::cout << "\n";
}

void test_priority_queue() 
{
    std::cout << "\n=== PriorityQueue Test ===\n";
    PriorityQueue<std::string> pq;

    pq.push("banana");
    pq.push("apple");
    pq.push("orange");

    std::cout << "Top (should be orange): " << pq.top() << "\n";

    std::cout << "All elements:\n";
    while (!pq.empty()) 
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}

void test_priority_queue_with_custom_compare() 
{
    std::cout << "\n=== PriorityQueue with Custom Compare (min-heap) ===\n";

    using MinHeap = PriorityQueue<int, std::vector<int>, std::greater<int>>;
    MinHeap pq;

    for (int x : {7, 2, 6, 3, 5}) 
        pq.push(x);

    std::cout << "Min values in order:\n";
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}

void test_std_style_heap_algorithms() 
{
    std::cout << "\n=== std::make_heap, push_heap, pop_heap ===\n";

    std::vector<int> data = { 1, 7, 3, 4, 9, 2 };

    std::cout << "Original: ";
    for (int v : data)
        std::cout << v << " ";
    std::cout << "\n";

    std::make_heap(data.begin(), data.end());
    std::cout << "After make_heap: ";
    for (int v : data) 
        std::cout << v << " ";
    std::cout << "\n";

    data.push_back(10);
    std::push_heap(data.begin(), data.end());
    std::cout << "After push_heap(10): ";
    for (int v : data) 
        std::cout << v << " ";
    std::cout << "\n";

    std::pop_heap(data.begin(), data.end());
    int max = data.back();
    data.pop_back();
    std::cout << "After pop_heap (max = " << max << "): ";
    for (int v : data) 
        std::cout << v << " ";
    std::cout << "\n";
}

int main() 
{
    test_max_heap();
    test_priority_queue();
    test_priority_queue_with_custom_compare();
    test_std_style_heap_algorithms();
    return 0;
}
