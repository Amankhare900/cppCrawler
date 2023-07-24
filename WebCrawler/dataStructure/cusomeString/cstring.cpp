#include "cstring.h"
#include <cstring> // Include this for string operations

// Default constructor
String::String() : data(nullptr) {}

// Constructor from C-style string
String::String(const char* cString) {
    if (cString) {
        // Allocate memory for the string and copy the C-string
        data = new char[strlen(cString) + 1];
        strcpy(data, cString);
    } else {
        // Handle nullptr case
        data = new char[1];
        *data = '\0';
    }
}

// Copy constructor
String::String(const String& other) {
    // Allocate memory and copy the content from 'other'
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);
}


// write the length function code
size_t String::size() const {
    return strlen(data);
}

size_t String::find(const String& substring) const {
    const char* result = std::strstr(data, substring.data);
    if (result) {
        return static_cast<size_t>(result - data);
    } else {
        return static_cast<size_t>(-1); // Return a value indicating substring not found
    }
}
String::String(const char* cString, size_t len) {
    length = len;
    data = new char[length + 1];
    std::memcpy(data, cString, length);
    data[length] = '\0';
}
// Destructor
String::~String() {
    delete[] data;
}

// Assignment operator
String& String::operator=(const String& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Deallocate existing memory and copy the content from 'other'
    delete[] data;
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);

    return *this;
}

// Concatenation operator
String String::operator+(const String& other) const {
    // Calculate the size of the concatenated string
    size_t newSize = strlen(data) + strlen(other.data) + 1;
    // Allocate memory for the concatenated string
    char* newData = new char[newSize];

    // Copy the content of both strings to the new memory
    strcpy(newData, data);
    strcat(newData, other.data);

    // Create a new String object and return it
    String result(newData);
    delete[] newData; // Cleanup the allocated memory

    return result;
}

// Accessor function to get the C-style string representation
const char* String::c_str() const {
    return data;
}

const char* String::begin() const { return data; }