#ifndef READFILE_H
#define READFILE_H

#include <string>
#include "dataStructure/cusomeString/cstring.h"
class ReadFile {
public:
    String readFromFile(const String& filename);
    // void writeToFile(const std::string& filename, const std::string& data);
};

#endif // READFILE_H
