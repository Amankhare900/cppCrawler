#ifndef DOMAINDATA_H
#define DOMAINDATA_H

#include <vector>
#include <ctime>

class DomainData {
public:
    int maxUrlFetchedPerMinute;
    int totalMaxUrlFetched;
    std::vector<time_t> urlTimestamps;
};

#endif // DOMAINDATA_H
