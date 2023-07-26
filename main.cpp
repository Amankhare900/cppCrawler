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
#include <fstream>
#include <cstdlib>


// Implementation of readAndUpdateSessionId
String readAndUpdateSessionId() {
    // Read the current s_id from session.txt
    String s_id;
    ReadFile readfile;
    s_id = readfile.readFromFile("session.txt");

    // Convert the string s_id to an integer
    int s_id_value = atoi(s_id.c_str());
    std::cout<<s_id_value<<endl;;
    // Increment the s_id value
    s_id_value++;

    // Convert the updated s_id back to a string
    // s_id = String::fromInt(s_id_value);
    // std::cout<<s_id.c_str()<<endl;
    // Write the updated s_id back to session.txt
    readfile.writeToFile("./session.txt", String::fromInt(s_id_value));

    return s_id;
}

// Implementation of createSIdFolder
void createSIdFolder(const String& sId) {
    // Assuming you have an 'output' directory in the current working directory.
    // If not, please adjust the path accordingly.
    String folderName = String("output/sessionNo") + sId;

    if (!std::filesystem::exists(folderName.c_str())) {
        std::filesystem::create_directory(folderName.c_str());
    }
    // You can now use 'folderName' to store the HTML files for this session.
    // For example, you can append the filenames to 'folderName' when saving HTML files.
}


int main()
{
    int maxDepth = 5;
    int maxDomainLimit = 10;
    UrlFetcher urlFetcher("http://codequotient.com/", "./output/0/0");
    SimpleUrlParser urlParser;   

    WebCrawler& crawler = WebCrawler::getInstance(&urlFetcher, &urlParser);
    
    String s_id = readAndUpdateSessionId();
    createSIdFolder(s_id);

    crawler.startCrawling("https://codequotient.com/",s_id);

    return 0;
}

