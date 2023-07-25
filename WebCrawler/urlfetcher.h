#ifndef URLFETCHER_H
#define URLFETCHER_H

#include "dataStructure/cusomeString/cstring.h"

using namespace std; // Using namespace std in the header for simplicity (not recommended in larger projects)

class UrlFetcher
{
public:
    UrlFetcher(const String &url, const String &fileName);
    bool download(string url,string fileName);
    void setUrl(String url_);
    void setFileName(String fileName_);

private:
    String url_;
    String fileName_;
};

#endif // URLFETCHER_H