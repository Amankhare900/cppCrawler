#include <cstring>
#include "cSet.h"
template <typename T>
Set<T>::Set() : table(nullptr), tableSize(10),numElements(0) {
    table = new DynamicArray<Node*>(tableSize,nullptr);
}

template <typename T>
Set<T>::~Set() {
    for (size_t i = 0; i < tableSize; ++i) {
        // cout<<"destroying the table object"<<endl;
        destroyList(table->operator[](i));
    }
    delete table;
}

template <typename T>
size_t Set<T>::hash(const T& value) const {
    // djb2 hash function
    size_t hashValue = 5381; // Start with a prime number as the initial hash value

    // Get the C-style string representation of the value
    const char* cString = value.c_str();

    // Iterate through each character of the C-style string
    for (size_t i = 0; i < strlen(cString); ++i) {
        // Multiply the current hash value by 33 (using bitwise left shift by 5 and add the current character)
        hashValue = ((hashValue << 5) + hashValue) + static_cast<size_t>(cString[i]);
    }

    return hashValue; // Modulo to ensure the hash value fits within the table size
}

template <typename T>
void Set<T>::destroyList(Node* head) {
    while (head) {
        // std::cout<<"destroying the object";
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
typename Set<T>::Node* Set<T>::createNode(const T& value, size_t hash) {
    // std::cout<<"creating new node";
    return new Node(value, hash);
}

template <typename T>
bool Set<T>::contains(const T& value) const {
    size_t hash_value = hash(value);
    size_t index = hash_value%tableSize;;
    Node* current = table->operator[](index);
    while (current) {

        if(current->hashValue == hash_value){
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void Set<T>::insert(const T& value) {
    // cout<<"inserting the Node";
    size_t hash_value = hash(value);
    size_t index = hash_value%tableSize;
    Node* current = table->operator[](index);
    if(current == nullptr){
        // cout<<"hello";
    }
    while (current) {
        if(current->hashValue == hash_value){
            return; // Value already exists in the set
        }
        current = current->next;
    }

    // Value not found, insert it at the beginning of the linked list
    Node* newNode = createNode(value,hash_value);
    newNode->next = table->operator[](index);
    numElements++;
    table->operator[](index) = newNode;
}

template <typename T>
void Set<T>::remove(const T& value) {
    size_t hash_value = hash(value);
    size_t index = hash_value%tableSize;
    Node* current = table->operator[](index);
    Node* prev = nullptr;

    while (current) {
        if (current->hashValue == hash_value) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->operator[](index) = current->next;
            }
            numElements--;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename T>
typename Set<T>::Node* Set<T>::find(const T& value) const {
    // std::cout<<value.c_str()<<endl;
    size_t hash_value = hash(value);
    size_t index = hash_value%tableSize;
    cout<<"hash value of "<<value.c_str()<<hash_value<<endl;
    cout<<"find element at index " <<index<<endl;
    if(index>=table->getCapacity()){
        // cout<<"index out of bound";
        return nullptr;
    }
    Node* current = table->operator[](index);
    
    // std::cout<<"std"<<current->data.c_str()<<"nullptr"<<endl;
    while (current) {
    cout<<"hash value of this index "<<current->data.c_str()<<current->hashValue<<endl;;
        if(current->hashValue == hash_value){
            return current;
        }
        current = current->next;
    }
    // cout<<"passing the Nullptr";
    return nullptr;
}

template <typename T>
bool Set<T>::empty() const {
    for (size_t i = 0; i < tableSize; ++i) {
        if (table->operator[](i)) {
            return false;
        }
    }
    return true;
}

template <typename T>
typename Set<T>::Node* Set<T>::end() const {
    return nullptr;
}