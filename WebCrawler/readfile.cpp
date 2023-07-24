#include "readfile.h"
#include <fstream>

std::string ReadFile::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }

    std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return data;
}

// void FileIO::writeToFile(const std::string& filename, const std::string& data) {
//     std::ofstream file(filename);
//     if (file.is_open()) {
//         file << data;
//         file.close();
//     }
// }
