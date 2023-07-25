#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length = 0;

public:
    static const size_t npos = -1;
    String();
    String(const char* cString);
    String(const char* cString, size_t len); // New constructor
    
    bool operator<(const String& rhs) const; // Comparison operator
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String(char ch);
    String operator+(const String& other) const;
    // Move constructor
    String(String&& other) noexcept;

    // Move assignment operator
    String& operator=(String&& other) noexcept;
    String& operator+=(const String& other);
    bool operator==(const String& other) const {
        return std::strcmp(data, other.data) == 0;
    }
    const char* c_str() const;
    size_t find(const String& substring) const;
    
    const char* begin() const; 
    size_t size() const; // New method to get the size of the string
};

#endif // STRING_H
