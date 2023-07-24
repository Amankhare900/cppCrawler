#ifndef URLPARSER_H
#define URLPARSER_H

#include <string>
#include <vector>

class UrlParser {
public:
    // virtual ~UrlParser() {}
    virtual std::vector<std::string> extractUrls(const std::string& html) = 0;
};

class SimpleUrlParser : public UrlParser {
public:
    std::vector<std::string> extractUrls(const std::string& html) override;
    std::string makeAbsoluteUrl(const std::string &url);
    void setBaseurl(const std::string &baseurl);

private:
    std::string baseUrl_;
};

#endif // URLPARSER_H
