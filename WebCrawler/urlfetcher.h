#ifndef URLFETCHER_H
#define URLFETCHER_H

#include <string>

using namespace std; // Using namespace std in the header for simplicity (not recommended in larger projects)

class UrlFetcher
{
public:
    UrlFetcher(const string &url, const string &fileName);
    bool download(string url,string fileName);
    void setUrl(std::string url_);
    void setFileName(std::string fileName_);

private:
    string url_;
    string fileName_;
};

#endif // URLFETCHER_H