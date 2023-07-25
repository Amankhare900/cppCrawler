#include "cmap.h"

// Default constructor
template <typename Key, typename Value>
Map<Key, Value>::Map() : head(nullptr) {}

// Destructor to free memory
template <typename Key, typename Value>
Map<Key, Value>::~Map() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Insert a key-value pair into the map
template <typename Key, typename Value>
void Map<Key, Value>::insert(const Key& key, const Value& value) {
    Node* newNode = new Node(key, value);
    newNode->next = head;
    head = newNode;
}

// Find the value associated with a given key
template <typename Key, typename Value>
bool Map<Key, Value>::find(const Key& key) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return true; // Key found
        }
        current = current->next;
    }
    return false; // Key not found
}

// Erase a key-value pair from the map
template <typename Key, typename Value>
bool Map<Key, Value>::erase(const Key& key) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true; // Key erased
        }
        prev = current;
        current = current->next;
    }

    return false; // Key not found
}
