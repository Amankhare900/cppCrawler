#ifndef URLPARSER_H
#define URLPARSER_H

#include "dataStructure/cusomeString/cstring.h"
#include <vector>

class UrlParser {
public:
    // virtual ~UrlParser() {}
    virtual std::vector<String> extractUrls(const String& html) = 0;
};

class SimpleUrlParser : public UrlParser {
public:
    std::vector<String> extractUrls(const String& html) override;
    String makeAbsoluteUrl(const String &url);
    void setBaseurl(const String &baseurl);

private:
    String baseUrl_;
};

#endif // URLPARSER_H
