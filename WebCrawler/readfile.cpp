#include "readfile.h"
#include "string.h" // Include the custom String header file
#include <fstream>

String ReadFile::readFromFile(const String& filename) {
    std::ifstream file(filename.c_str()); // Use c_str() to get the C-style string from custom String
    if (!file.is_open()) {
        return String(); // Return an empty String in case of failure
    }

    String data;
    char *ch;
    while (file.get(*ch)) {
        data = data + String(ch); // Append each character to the data string
    }

    file.close();
    return data;
}
