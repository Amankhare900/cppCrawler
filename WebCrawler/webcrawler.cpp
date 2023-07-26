
#include "webcrawler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

WebCrawler::WebCrawler(UrlFetcher* fetcher, SimpleUrlParser* parser)
    : maxDepth(1), maxDomainLimit(0), urlFetcher(fetcher), urlParser(parser) {}

void WebCrawler::startCrawling(const String& startUrl) {
    urlQueue.push(Node(startUrl, 0));
    int depth = 0;
    int count = -1;
    while (!urlQueue.empty() && urlQueue.front().getDepth() <= maxDepth) {
        Node currentNode = urlQueue.front();
        urlQueue.pop();
        // cout<<"checking "<<endl;
        if (currentNode.getUrlname().size()!=0 && visitedUrl.find(currentNode.getUrlname()) == visitedUrl.end()) {
            // cout<<"visitedUrl not contain "<<currentNode.getUrlname().c_str();
            visitedUrl.insert(currentNode.getUrlname());
            if (depth == currentNode.getDepth()) {
                count++;
                cout<<"fetching data from "<< currentNode.getUrlname().c_str() << "for depth "<<currentNode.getDepth()<<endl;
            } else {
                depth = currentNode.getDepth();
                count = 0;
            }
            crawlUrl(currentNode.getUrlname(), currentNode.getDepth(), count);
        }
    }
}
void WebCrawler::crawlUrl(const String& url, int depth, int count) {
    // Build the output directory path
    std::stringstream ss;
    ss << "./output/" << depth;
    String outputDir = ss.str().c_str();

    // Check if the output directory exists, and create it if it doesn't
    if (!std::filesystem::exists(outputDir.c_str())) {
        std::filesystem::create_directory(outputDir.c_str());

    }

    // Construct the output file path
    ss << "/" << count << ".html";
    outputDir = ss.str().c_str();
    // Now you can proceed with downloading and processing the HTML data
    
    if (urlFetcher->download(url.c_str(), outputDir.c_str())) {
        if(depth<maxDepth){
        String htmlData = readFile.readFromFile(outputDir.c_str());
        urlParser->setBaseurl(url.c_str());
        DynamicArray<String> extractedUrls = urlParser->extractUrls(htmlData.c_str());
        // for (const String& extractedUrl : extractedUrls) {
        //     urlQueue.push(Node(extractedUrl, depth + 1));
        //     // std::cout<<extractedUrl.c_str()<<endl;
        // }
        for(int i = 0;i<extractedUrls.getSize();i++){
            urlQueue.push(Node(extractedUrls[i], depth + 1));
            // std::cout<<extractedUrl.c_str()<<endl;
        }
        }
    } else {
        std::cerr << "HTTP request execution failed. " <<url.c_str()<< std::endl;
    }
}

// #include "webcrawler.h"
// #include <iostream>
// #include <fstream>

// WebCrawler::WebCrawler(UrlFetcher* fetcher, UrlParser* parser)
//     : maxDepth(0), maxDomainLimit(0), urlFetcher(fetcher), urlParser(parser) {}

// void WebCrawler::startCrawling(const std::string& startUrl) {
//     urlQueue.push(Node(startUrl, 0));
//     int depth = 0;
//     int count = 0;
//     while (!urlQueue.empty() && urlQueue.front().getDepth() <= maxDepth) {
//         Node currentNode = urlQueue.front();
//         urlQueue.pop();

//         // if (!isDomainLimitReached(getDomainFromUrl(currentNode.getUrlname()))) {
//         // if (getDomainFromUrl(currentNode.getUrlname())) {
//             if (!currentNode.getUrlname().empty() && visitedUrl.find(currentNode.getUrlname()) == visitedUrl.end()) {
//                 visitedUrl.insert(currentNode.getUrlname());
//                 if(depth==currentNode.getDepth()){
//                     count++;
//                 }else{
//                     depth = currentNode.getDepth();
//                     count = 0;
//                 }
//                 crawlUrl(currentNode.getUrlname(), currentNode.getDepth(),count);
//             }
//         // }
//     }
// }

// void WebCrawler::crawlUrl(const std::string& url, int depth, int count) {
//     if (urlFetcher->download(url,"output/"+to_string(depth)+"/"+to_string(count))) {
//         // writeHtmlToFile("output_" + std::to_string(depth) + ".html", htmlData);
//         std::string htmlData = readFile.readFromFile("output/"+to_string(depth)+"/"+to_string(count));
//         std::vector<std::string> extractedUrls = urlParser->extractUrls(htmlData);
//         for (const std::string& extractedUrl : extractedUrls) {
//             urlQueue.push(Node(extractedUrl, depth + 1));
//         }
//     } else
//     {
//         cerr << "HTTP request execution failed." << endl;
//     }
// }


// // std::string WebCrawler::readHtmlFromFile(const std::string& filename) {
// //     std::ifstream infile(filename);
// //     std::string content;
// //     if (infile) {
// //         infile.seekg(0, std::ios::end);
// //         content.reserve(infile.tellg());
// //         infile.seekg(0, std::ios::beg);
// //         content.assign((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
// //     } else {
// //         std::cerr << "Failed to read from file: " << filename << std::endl;
// //     }
// //     return content;
// // }


// // void WebCrawler::writeHtmlToFile(const std::string& filename, const std::string& html) {
// //     std::ofstream outfile(filename);
// //     if (outfile) {
// //         outfile << html;
// //         outfile.close();
// //     } else {
// //         std::cerr << "Failed to write to file: " << filename << std::endl;
// //     }
// // }


// // bool WebCrawler::isDomainLimitReached(const std::string& domain) {
// //     auto it = dataStorage.find(domain);
// //     if (it != dataStorage.end()) {
// //         DomainData& domainData = it->second;
// //         time_t currentTime = time(nullptr);
// //         int count = 0;
// //         for (const auto& timestamp : domainData.urlTimestamps) {
// //             if (currentTime - timestamp <= 60) { // Within last 60 seconds
// //                 count++;
// //             }
// //         }
// //         domainData.maxUrlFetchedPerMinute = std::max(domainData.maxUrlFetchedPerMinute, count);
// //         return count >= maxDomainLimit;
// //     }
// //     return false; // No data for domain, limit not reached
// // }

// // void WebCrawler::updateDataStorage(const std::string& domain, int urlFetched, time_t timestamp) {
// //     auto it = dataStorage.find(domain);
// //     if (it != dataStorage.end()) {
// //         DomainData& domainData = it->second;
// //         domainData.urlTimestamps.push_back(timestamp);
// //         domainData.totalMaxUrlFetched += urlFetched;
// //     }
// // }

// // std::string WebCrawler::getDomainFromUrl(const std::string& url) {
// //     size_t pos = url.find("://");
// //     if (pos != std::string::npos) {
// //         size_t domainStart = pos + 3;
// //         size_t domainEnd = url.find('/', domainStart);
// //         if (domainEnd != std::string::npos) {
// //             return url.substr(domainStart, domainEnd - domainStart);
// //         } else {
// //             return url.substr(domainStart);
// //         }
// //     }
// //     return "";
// // }




// // #include <iostream>
// // #include "webcrawler.h"
// // WebCrawler::WebCrawler(UrlFetcher* fetcher, UrlParser* parser)
// //     :urlFetcher(fetcher), urlParser(parser) {}

// // void WebCrawler::startCrawling(const std::string& startUrl){
// //     urlQueue.push(startUrl);
// //     crawlUrl(startUrl,1);
// // }

// // void WebCrawler::crawlUrl(const std::string& url, int depth){
// //     int depthUrl = 0;
// //     // int nextDepthUrl = 0;
// //     while(urlQueue.size() >0 && depth<=maxDepth){
// //         std::string file_name = "./output/response.html";
// //         urlFetcher->setUrl(url);
// //         urlFetcher->setFileName(file_name);
// //         if (urlFetcher->download())
// //         {
// //             std::cout << "HTTP request executed successfully." << std::endl;
// //             std::cout << "File downloaded at: " << file_name << std::endl;
// //             visitedUrl.insert(url);
// //             ReadFile readFile;
// //             std::string str = readFile.readFromFile(file_name);
// //             std::vector<std::string> extractedUrls= urlParser->extractUrls(str);
// //             std::cout<<"extracting the link from the "<<file_name<<" total Extracted Links are "<<extractedUrls.size()<<std::endl;
// //             for(int i = 0;i<extractedUrls.size();i++){
// //                 if(!visitedUrl.find(url)){
// //                     urlQueue.push(extractedUrls[i]);
// //                     depthUrl++;
// //                 }
// //             }

// //         }   
// //         else
// //         {
// //             std::cerr << "HTTP request execution failed." << std::endl;
// //         }
// //     std::cout<<"Crawling:" << url<<", Depth: "<<depth<<std::endl;
// //     }
// // }

