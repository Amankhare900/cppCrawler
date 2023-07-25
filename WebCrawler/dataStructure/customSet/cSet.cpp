#include <cstring>
template <typename T>
Set<T>::Set() : table(nullptr), tableSize(10) {
    table = new DynamicArray<Node*>(tableSize);
    cout<<table->getCapacity();
}

template <typename T>
Set<T>::~Set() {
    for (size_t i = 0; i < tableSize; ++i) {
        cout<<"destroying the table object"
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

    return hashValue % tableSize; // Modulo to ensure the hash value fits within the table size
}

template <typename T>
void Set<T>::destroyList(Node* head) {
    while (head) {
        cout<<"destroying the object";
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
typename Set<T>::Node* Set<T>::createNode(const T& value) {
    return new Node(value);
}

template <typename T>
bool Set<T>::contains(const T& value) const {
    size_t index = hash(value);
    Node* current = table->operator[](index);
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void Set<T>::insert(const T& value) {
    size_t index = hash(value);
    Node* current = table->operator[](index);
    while (current) {
        if (current->data == value) {
            return; // Value already exists in the set
        }
        current = current->next;
    }

    // Value not found, insert it at the beginning of the linked list
    Node* newNode = createNode(value);
    newNode->next = table->operator[](index);
    table->operator[](index) = newNode;
}

template <typename T>
void Set<T>::remove(const T& value) {
    size_t index = hash(value);
    Node* current = table->operator[](index);
    Node* prev = nullptr;

    while (current) {
        if (current->data == value) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->operator[](index) = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename T>
typename Set<T>::Node* Set<T>::find(const T& value) const {
    size_t index = hash(value);
    Node* current = table->operator[](index);
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
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