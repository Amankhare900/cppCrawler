#include "urlparser.h"

#include <regex>

std::vector<std::string> SimpleUrlParser::extractUrls(const std::string& html) {
    // This is a simple implementation for testing purposes.
    // Replace this with your actual implementation to extract URLs from the HTML content.
    std::vector<std::string> extractedUrls;
    std::regex urlRegex("<a\\s+(?:[^>]*?\\s+)?href=\"([^\"]*)\"");
    std::sregex_iterator it(html.begin(), html.end(), urlRegex);
    std::sregex_iterator end;

    while (it != end) {
        auto url = (*it)[1].str();
        std::string absoluteUrl = makeAbsoluteUrl(url);
        if (!absoluteUrl.empty()){
            extractedUrls.push_back(absoluteUrl);
            
        }
        ++it;
        // extractedUrls.push_back((*it)[1].str());
        // ++it;
    }

    return extractedUrls;
}
std::string SimpleUrlParser::makeAbsoluteUrl(const std::string &url)
{

    // std::cout << "url: " << url << std::endl;
    // ignore #Urls and url of size 1 and 0
    if (url.find("#") != std::string::npos || url.size() <= 1)
    {
        return "";
    }

    // Check if the URL is relative
    if (url.empty() || url.find("://") != std::string::npos)
    {
        return url; // Already an absolute URL or empty
    }

    // Resolve relative URL using base URL
    return baseUrl_ + url;
}

void SimpleUrlParser::setBaseurl(const std::string &baseurl){
    baseUrl_ = baseurl;
}