#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;

public:
    static const size_t npos = -1;
    String();
    String(const char* cString);
    String(const char* cString, size_t len); // New constructor
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String operator+(const String& other) const;

    const char* c_str() const;
    size_t find(const String& substring) const;
    
    const char* begin() const; 
    size_t size() const; // New method to get the size of the string
};

#endif // STRING_H
