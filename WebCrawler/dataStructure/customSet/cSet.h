#ifndef CUSTOMSET_H
#define CUSTOMSET_H

#include "../dynamicarray/dynamicarray.h"

template <typename T>
class Set {
private:
    struct Node {
        T data;  
        Node* next;
        size_t hashValue;
        Node(const T& value, size_t hash) : data(value), hashValue(hash), next(nullptr) {}
    };

    DynamicArray<Node*>* table;
    size_t tableSize;
    size_t numElements;

    size_t hash(const T& value) const;
    void destroyList(Node* head);
    Node* createNode(const T& value, size_t hash);

public:
    Set();
    ~Set();

    bool contains(const T& value) const;
    void insert(const T& value);
    void remove(const T& value);
    Node* find(const T& value) const;
    bool empty() const;
    Node* end() const;
};

#endif // CUSTOMSET_H
