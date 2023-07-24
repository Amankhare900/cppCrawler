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
int main()
{
    int maxDepth = 5;
    int maxDomainLimit = 10;
    UrlFetcher urlFetcher("http://codequotient.com/", "./output/0/0"); // Instantiate SimpleUrlFetcher
    SimpleUrlParser urlParser;   // Instantiate SimpleUrlParser

    WebCrawler crawler(&urlFetcher, &urlParser);
    
    crawler.startCrawling("https://codequotient.com/");
    // URL to fetch
    // string url = "https://codequotient.com/";

    // // File name to save the response
    // string file_name = "./output/response.html";

    // // Create an instance of HttpDownloader
    // UrlFetcher downloader(url, file_name);

    // // Perform the HTTP request and download the file
    // if (downloader.download())
    // {
    //     cout << "HTTP request executed successfully." << endl;
    //     cout << "File downloaded at: " << file_name << endl;
    //     ReadFile readFile;
    //     string str = readFile.readFromFile(file_name);
    //     SimpleUrlParser urlParse;
    //     std::vector<std::string> extractedUrls= urlParse.extractUrls(str);
    //     cout<<"extracting the link from the "<<file_name<<" total Extracted Links are "<<extractedUrls.size();
    //     for(int i = 0;i<extractedUrls.size();i++){
    //         cout<<extractedUrls[i]<<endl;
    //     }
    // }
    // else
    // {
    //     cerr << "HTTP request execution failed." << endl;
    // }

    return 0;
}