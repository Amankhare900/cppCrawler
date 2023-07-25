// #ifndef WEBCRAWLER_H
// #define WEBCRAWLER_H

// #include "dataStructure/cusomeString/cstring.h"
// #include "dataStructure/customeQueue/queue.h"
// #include "dataStructure/dynamicarray/dynamicarray.h"
// #include "dataStructure/cusomeMap/cmap.h"
// #include <ctime>

// #include "urlfetcher.h"
// #include "urlparser.h"
// #include "readfile.h"

// using namespace std;

// class WebCrawler {
// public:
//     // WebCrawler(int maxDepth, int maxDomainLimit, UrlFetcher* fetcher, UrlParser* parser);
//     WebCrawler(UrlFetcher* fetcher, UrlParser* parser);

//     void startCrawling(const String& startUrl);
//     void crawlUrl(const String& url, int depth);
//     // void writeHtmlToFile(const String& filename, const String& html);
//     String readHtmlFromFile(const String& filename);

// private:
//     struct DomainData {
//         int maxUrlFetchedPerMinute;
//         int totalMaxUrlFetched;
//         Queue<time_t> urlTimestamps;
//     };

//     int maxDepth;
//     int maxDomainLimit;
//     UrlFetcher* urlFetcher;
//     UrlParser* urlParser;
//     ReadFile readFile;

//     Queue<String> urlQueue;
//     Queue<String> waitingQueue;
//     Map<String, DomainData> dataStorage;

//     void addToWaitingQueue(const String& url);
//     void moveToUrlQueueFromWaitingQueue(const String& url);
//     bool isDomainLimitReached(const String& domain);
//     void updateDataStorage(const String& domain, int urlFetched, time_t timestamp);
//     String getDomainFromUrl(const String& url);
// };

// #endif // WEBCRAWLER_H


#ifndef WEBCRAWLER_H
#define WEBCRAWLER_H

#include "dataStructure/customString/cstring.h"
#include <queue>
#include <map>
#include <vector>
#include <ctime>
#include <set>
#include "urlfetcher.h"
#include "urlparser.h"
#include "readfile.h"
#include "node/node.h"

class WebCrawler {
public:
    WebCrawler(UrlFetcher* fetcher, SimpleUrlParser* parser);

    void startCrawling(const String& startUrl);
    void crawlUrl(const String& url, int depth,int count);
    // void writeHtmlToFile(const std::string& filename, const std::string& html);
    // std::string readHtmlFromFile(const std::string& filename);

private:
    struct DomainData {
        int maxUrlFetchedPerMinute;
        int totalMaxUrlFetched;
        std::vector<time_t> urlTimestamps;
    };

    int maxDepth;
    int maxDomainLimit;
    UrlFetcher* urlFetcher;
    SimpleUrlParser* urlParser;
    ReadFile readFile;

    std::set<String> visitedUrl;
    std::queue<Node> urlQueue;
    std::queue<Node> waitingQueue;
    std::map<String, DomainData> dataStorage;
//     void addToWaitingQueue(const std::string& url);
//     void moveToUrlQueueFromWaitingQueue(const std::string& url);
//     bool isDomainLimitReached(const std::string& domain);
//     void updateDataStorage(const std::string& domain, int urlFetched, time_t timestamp);
//     std::string getDomainFromUrl(const std::string& url);
};

#endif // WEBCRAWLER_H