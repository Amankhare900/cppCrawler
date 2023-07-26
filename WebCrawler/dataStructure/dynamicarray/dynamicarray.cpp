#include "dynamicarray.h"

// Default constructor
template <typename T>
DynamicArray<T>::DynamicArray() : arr(nullptr), capacity(0), size(0) {}

// Constructor with initial capacity
template <typename T>
DynamicArray<T>::DynamicArray(size_t initialCapacity, const T& defaultValue)
    : arr(nullptr), capacity(initialCapacity), size(0) {
    arr = new T[capacity];
    for (size_t i = 0; i < capacity; i++) {
        arr[i] = defaultValue;
    }
}

// Destructor to free memory
template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] arr;
}

// Push element to the back of the dynamic array 
template <typename T>
void DynamicArray<T>::pushBack(const T& value) {
    if (size >= capacity/2) {
        // Double the capacity and create a new array
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newArr = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    arr[size] = value;
    size++;
}

// Pop the last element from the dynamic array
template <typename T>
void DynamicArray<T>::popBack() {
    if (size > 0) {
        size--;
    }
}

// Access an element by index (non-const version)
template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    // std::cout<<capacity<<endl;
    if (index >= capacity) {
        throw std::out_of_range("index out of Bound");
    }
    // std::cout<<arr[index]->data.c_str();
    // std::cout<<"hello";
    return arr[index];
}

// Access an element by index (const version)
template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= size) {
        // std::cout<<index<<" "<<size<<endl;
        throw std::out_of_range("index out of Bound");
    }
    return arr[index];
}

// Get the current size of the dynamic array
template <typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

// Get the current capacity of the dynamic array
template <typename T>
size_t DynamicArray<T>::getCapacity() const {
    return capacity;
}
