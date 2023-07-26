#include "cstring.h"
#include <cstring> // Include this for string operations

// Default constructor
String::String() : data(nullptr) {}

// Constructor from C-style string
String::String(const char* cString) {
    if (cString) {
        // Allocate memory for the string and copy the C-string
        length = strlen(cString);
        data = new char[length + 1];
        strcpy(data, cString);
    } else {
        // Handle nullptr case
        data = new char[1];
        *data = '\0';
        length = 0; // Set the length to 0 for an empty string
    }
}


// Copy constructor
String::String(const String& other) {
    // Allocate memory and copy the content from 'other'
    length = strlen(other.data);
    data = new char[length + 1];
    strcpy(data, other.data);
}


// write the length function code
size_t String::size() const {
    return length;
}

String String::operator+(const char* other) const {
    // Get the length of the other char* (assuming it's null-terminated)
    size_t len_other = strlen(other);

    // Create a new String that can hold both the original String and the other char*
    size_t new_length = length + len_other;
    char* new_data = new char[new_length + 1]; // +1 for null-terminator

    // Copy the characters from the original String to the new data
    memcpy(new_data, data, length);
    // Copy the characters from the other char* to the new data
    memcpy(new_data + length, other, len_other);
    // Add the null-terminator at the end
    new_data[new_length] = '\0';

    // Create a new String object with the concatenated data
    String result(new_data);

    // Clean up memory
    delete[] new_data;

    return result;
}

size_t String::find(const String& substring) const {
    const char* result = std::strstr(data, substring.data);
    if (result) {
        return static_cast<size_t>(result - data);
    } else {
        return static_cast<size_t>(-1); // Return a value indicating substring not found
    }
}
// Destructor
String::~String() {
    delete[] data;
}

String::String(const char* cString, size_t len) {
    length = len;
    data = new char[length + 1];
    std::memcpy(data, cString, length);
    data[length] = '\0';
}


// Assignment operator
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data; // Deallocate existing data

        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    return *this;
}


String::String(String&& other) noexcept : data(nullptr), length(0) {
    // Move constructor, take ownership of the data from 'other'
    data = other.data;
    length = other.length;

    // Reset 'other' to a valid state to avoid double deletion of data
    other.data = nullptr;
    other.length = 0;
}

String& String::operator=(String&& other) noexcept {
    // Move assignment operator, take ownership of the data from 'other'
    if (this != &other) {
        delete[] data; // Deallocate existing data

        data = other.data;
        length = other.length;

        // Reset 'other' to a valid state to avoid double deletion of data
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}



String& String::operator+=(const String& other) {
    size_t newLength = length + other.length;

    // std::cout<<newLength<<endl;
    // std::cout<<length<<endl;
    // std::cout<<other.length<<endl;
    char* newData = new (std::nothrow) char[newLength + 1]; // Use 'nothrow' to avoid exceptions on allocation failure
    // std::cout<<"hello";
    if (newData) {
        std::memcpy(newData, data, length);             // Copy the first part of the data
        std::memcpy(newData + length, other.data, other.length); // Copy the second part of the data

        newData[newLength] = '\0'; // Null-terminate the new string

        delete[] data; // Deallocate the old data
        data = newData;
        length = newLength;
    } else {
        // Handle memory allocation failure gracefully
        std::cerr << "Memory allocation failed in operator+=. Concatenation aborted." << std::endl;
    }

    return *this;
}



String::String(char ch) {
    length = 1;
    data = new char[length + 1];
    data[0] = ch;
    data[length] = '\0';
}
bool String::operator<(const String& rhs) const {
    return strcmp(data, rhs.data) < 0;
}
// Concatenation operator
String String::operator+(const String& other) const {
    // Get the lengths of the two Strings
    size_t len_this = length;
    size_t len_other = other.length;

    // Create a new String that can hold both Strings
    size_t new_length = len_this + len_other;
    char* new_data = new char[new_length + 1]; // +1 for null-terminator

    // Copy the characters from the first String to the new data
    memcpy(new_data, data, len_this);
    // Copy the characters from the second String to the new data
    memcpy(new_data + len_this, other.data, len_other);
    // Add the null-terminator at the end
    new_data[new_length] = '\0';

    // Create a new String object with the concatenated data
    String result(new_data);

    // Clean up memory
    delete[] new_data;

    return result;
}



// Accessor function to get the C-style string representation
const char* String::c_str() const {
    return data;
}

const char* String::begin() const { return data; }

String String::fromInt(int value) {
    if (value == 0) {
        return String("0");
    }

    bool isNegative = false;
    if (value < 0) {
        isNegative = true;
        value = -value;
    }

        // Determine the number of digits in the integer value
    int numDigits = 0;
    int temp = value;
    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

        // Allocate memory for the resulting string
    int bufferSize = numDigits + (isNegative ? 1 : 0) + 1; // +1 for the null-terminator
    char* buffer = new char[bufferSize];
    int index = bufferSize - 1;
    buffer[index] = '\0';
// Convert each digit to a character and store it in the buffer
    while (index > 0) {
        buffer[--index] = '0' + (value % 10);
        value /= 10;
    }

        // Add the negative sign if the number is negative
    if (isNegative) {
        buffer[--index] = '-';
    }

    String result(buffer);
    delete[] buffer;
    return result;
}