#include "queue.h"

// Constructor
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

// Destructor to free memory
template <typename T>
Queue<T>::~Queue() {
    while (frontNode != nullptr) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
}

// Push element to the back of the queue
template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (rearNode == nullptr) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    size++;
}

// Pop the front element from the queue
template <typename T>
void Queue<T>::pop() {
    if (frontNode == nullptr) {
        return; // Queue is already empty. Nothing to pop.
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    size--;
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
}

// Get the front element of the queue
template <typename T>
T Queue<T>::front() const {
    if (frontNode == nullptr) {
        return T(); // Return a default-constructed value of T (assuming T has a default constructor)
    }
    return frontNode->data;
}

// Check if the queue is empty
template <typename T>
bool Queue<T>::empty() const {
    return frontNode == nullptr;
}

// Get the current size of the queue
template <typename T>
size_t Queue<T>::getSize() const {
    return size;
}
