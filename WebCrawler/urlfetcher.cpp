#include "urlfetcher.h"
#include <cstdlib> // For the system function

UrlFetcher::UrlFetcher(const String &url, const String &fileName)
    : url_(url), fileName_(fileName)
{
}

bool UrlFetcher::download(String url,String fileName)
{
    std::cout<<fileName.c_str()<<endl;
    const char* curlPrefix = "curl ";
    const char* curlSuffix = " -o ";
    const char* urlCStr = url.c_str();
    const char* fileNameCStr = fileName.c_str();

    // size_t curlCommandSize = strlen(curlPrefix) + strlen(urlCStr) + strlen(curlSuffix) + strlen(fileNameCStr) + 1;
    String curlCommand;
    curlCommand+=curlPrefix;
    curlCommand+=urlCStr;
    curlCommand+=curlSuffix;
    curlCommand+=fileNameCStr;
    // string curlCommand = "curl " + url + " -o " + fileName.c_str();
    int result = system(curlCommand.c_str());
    return result == 0;
}
void UrlFetcher::setUrl(String url_){
    this->url_ = url_;
}

void UrlFetcher::setFileName(String fileName_){
    this->fileName_ = fileName_;
}