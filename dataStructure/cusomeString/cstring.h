#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* data;

public:
    String();
    String(const char* cString);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String operator+(const String& other) const;

    const char* c_str() const;
};

#endif // STRING_H
