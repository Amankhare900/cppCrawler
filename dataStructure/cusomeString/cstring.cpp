#include "cstring.h"
#include <cstring>

// Default constructor
String::String() : data(new char[1]) {
    data[0] = '\0';
}

// Constructor with C-style string
String::String(const char* cString) : data(new char[strlen(cString) + 1]) {
    strcpy(data, cString);
}

// Copy constructor
String::String(const String& other) : data(new char[strlen(other.data) + 1]) {
    strcpy(data, other.data);
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

    delete[] data;
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);

    return *this;
}

// Concatenation operator
String String::operator+(const String& other) const {
    size_t len1 = strlen(data);
    size_t len2 = strlen(other.data);
    char* newData = new char[len1 + len2 + 1];

    strcpy(newData, data);
    strcpy(newData + len1, other.data);

    String result(newData);
    delete[] newData;

    return result;
}

// Get the C-style string representation
const char* String::c_str() const {
    return data;
}
