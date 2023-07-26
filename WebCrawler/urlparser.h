#ifndef URLPARSER_H
#define URLPARSER_H

#include "dataStructure/customString/cstring.h"
#include "dataStructure/dynamicarray/dynamicarray.h"

#include <vector>

class UrlParser {
public:
    // virtual ~UrlParser() {}
    virtual DynamicArray<String> extractUrls(const String& html)=0;
};

class SimpleUrlParser : public UrlParser {
public:
    DynamicArray<String> extractUrls(const String& html) override;
    String makeAbsoluteUrl(const String &url);
    void setBaseurl(const String &baseurl);


private:
    String baseUrl_;
    
};

#endif // URLPARSER_H
