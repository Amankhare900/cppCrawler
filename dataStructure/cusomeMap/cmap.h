#ifndef MAP_H
#define MAP_H

#include <iostream>

template <typename Key, typename Value>
class Map {
private:
    struct Node {
        Key key;
        Value value;
        Node* next;
        Node(const Key& k, const Value& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;

public:
    Map();
    ~Map();

    void insert(const Key& key, const Value& value);
    bool find(const Key& key) const;
    bool erase(const Key& key);
};

#endif // MAP_H
