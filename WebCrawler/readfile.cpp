

// String ReadFile::readFromFile(const String& filename) {
//     std::ifstream file(filename.c_str()); // Use c_str() to get the C-style string from custom String
//     if (!file.is_open()) {
//         std::cerr << "Failed to open file: " << filename.c_str() << std::endl;
//         return String(); // Return an empty String in case of failure
//     }

//     String data;
//     char ch;
//     while (file.get(ch)) {
//         data +=String(ch); // Append each character to the data string
//     }

//     file.close();
//     std::cout << data.c_str();
//     return data;
// }
#include "readfile.h"
// #include "string.h" // Include the custom String header file
#include <fstream>

String ReadFile::readFromFile(const String& filename) {
    // std::cout<<filename.c_str();
    std::ifstream file(filename.c_str()); // Use c_str() to get the C-style string from custom String
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename.c_str() << std::endl;
        return String(); // Return an empty String in case of failure
    }

    String data;
    // std::cout<<"size of data"<<data.size();
    char ch;
    // int count = 0;
    while (file.get(ch)) {
        data += String(ch); // Append each character to the data string
    }

    file.close();
    // std::cout << data.c_str();

    return data;
}
