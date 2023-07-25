#include <iostream>
#include <cstdlib> // For the system function
#include <string>
#include <filesystem>

using namespace std;

// Include the contents of HttpDownloader.cpp here
#include "WebCrawler/urlfetcher.cpp"
#include "WebCrawler/readfile.cpp"
#include "WebCrawler/urlparser.cpp"
#include "WebCrawler/node/node.cpp"
#include "WebCrawler/webcrawler.cpp"
#include "WebCrawler/dataStructure/customString/cstring.cpp"
#include "WebCrawler/dataStructure/customQueue/queue.cpp"
#include "WebCrawler/dataStructure/customSet/cSet.cpp"
#include "WebCrawler/dataStructure/dynamicarray/dynamicarray.cpp"
int main()
{
    int maxDepth = 5;
    int maxDomainLimit = 10;
    UrlFetcher urlFetcher("http://codequotient.com/", "./output/0/0");
    SimpleUrlParser urlParser;   

    WebCrawler crawler(&urlFetcher, &urlParser);
    
    crawler.startCrawling("https://codequotient.com/");

    return 0;
}