#ifndef READFILE_H
#define READFILE_H

#include <string>

class ReadFile {
public:
    std::string readFromFile(const std::string& filename);
    // void writeToFile(const std::string& filename, const std::string& data);
};

#endif // READFILE_H
