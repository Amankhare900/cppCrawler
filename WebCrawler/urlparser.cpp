#include "urlparser.h"
#include <regex>

DynamicArray<String> SimpleUrlParser::extractUrls(const String& html) {
    // This is a simple implementation for testing purposes.
    // Replace this with your actual implementation to extract URLs from the HTML content.
    DynamicArray<String> extractedUrls;
    const char* urlRegex = "<a\\s+(?:[^>]*?\\s+)?href=\"([^\"]*)\"";

    // Use the C-style regex functions
    std::regex regex(urlRegex);
    const char* it = html.c_str();
    const char* end = it + html.size();
    std::match_results<const char*> match;

    while (std::regex_search(it, end, match, regex))
    {
        // match[1].first will give the url under the double quotes
        String url(match[1].first, match[1].second - match[1].first);
        String absoluteUrl = makeAbsoluteUrl(url);
        if (absoluteUrl.size()!=0){
            extractedUrls.pushBack(absoluteUrl);
        }
        it = match[0].second;
    }

    return extractedUrls;
}




String SimpleUrlParser::makeAbsoluteUrl(const String &url)
{

    // std::cout << "url: " << url << std::endl;
    // ignore #Urls and url of size 1 and 0
    if (url.find("#") != String::npos || url.size() <= 1)
    {
        return "";
    }

    // Check if the URL is relative
    if (url.size()==0 || url.find("://") != String::npos)
    {
        return url;
    }

    // Resolve relative URL using base URL
    return baseUrl_ + url;
}

void SimpleUrlParser::setBaseurl(const String &baseurl){
    baseUrl_ = baseurl;
}