#include "urlfetcher.h"
#include <cstdlib> // For the system function

UrlFetcher::UrlFetcher(const string &url, const string &fileName)
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
void UrlFetcher::setUrl(std:: string url_){
    this->url_ = url_;
}

void UrlFetcher::setFileName(std::string fileName_){
    this->fileName_ = fileName_;
}