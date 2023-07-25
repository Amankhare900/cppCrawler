#include "urlfetcher.h"
#include <cstdlib> // For the system function

UrlFetcher::UrlFetcher(const String &url, const String &fileName)
    : url_(url), fileName_(fileName)
{
}

bool UrlFetcher::download(string url,string fileName)
{
    std::cout<<fileName<<endl;
    string curlCommand = "curl " + url + " -o " + fileName;
    int result = system(curlCommand.c_str());
    return result == 0;
}
void UrlFetcher::setUrl(String url_){
    this->url_ = url_;
}

void UrlFetcher::setFileName(String fileName_){
    this->fileName_ = fileName_;
}