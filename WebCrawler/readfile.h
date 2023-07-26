#ifndef READFILE_H
#define READFILE_H

#include <string>
#include "dataStructure/customString/cstring.h"

class ReadFile {
public:
    String readFromFile(const String& filename);
    void writeToFile(const String& filename, const String& data);
};

#endif // READFILE_H
