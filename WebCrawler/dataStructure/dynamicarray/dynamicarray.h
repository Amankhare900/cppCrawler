#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef> // Include this header for size_t

template <typename T>
class DynamicArray {
private:
    T* arr;
    size_t capacity;
    size_t size;

public:
    DynamicArray();
    DynamicArray(size_t initialCapacity, const T& defaultValue);
    ~DynamicArray();

    void pushBack(const T& value);
    void popBack();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t getSize() const;
    size_t getCapacity() const;
};

#endif // DYNAMIC_ARRAY_H
