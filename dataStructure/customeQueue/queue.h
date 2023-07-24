#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef> // Include this header for size_t

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    size_t size;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}
    ~Queue();

    void push(const T& value);
    void pop();
    T front() const;
    bool empty() const;
    size_t getSize() const;
};

// Include the implementation of the templated class
#include "queue.cpp"

#endif // QUEUE_H
