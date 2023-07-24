#include "ratelimiter.h"

bool RateLimiter::canFetch(const String& domain) {
    DomainData domainDataObj;
    if (domainData.find(domain)) {
        time_t currentTime = time(nullptr);
        int count = 0;
        for (size_t i = 0; i < domainDataObj.urlTimestamps.getSize(); i++) {
            if (currentTime - domainDataObj.urlTimestamps[i] <= 60) { // Within last 60 seconds
                count++;
            }
        }
        domainDataObj.maxUrlFetchedPerMinute = std::max(domainDataObj.maxUrlFetchedPerMinute, count);
        return count < 5; // Limit to 5 URLs per domain in 1 minute
    }
    return true; // No data for domain, allow fetching
}

void RateLimiter::update(const String& domain, int urlFetched, time_t timestamp) {
    DomainData domainDataObj;
    if (domainData.find(domain)) {
        domainDataObj.urlTimestamps.pushBack(timestamp);
        domainDataObj.totalMaxUrlFetched += urlFetched;
        domainData.insert(domain, domainDataObj);
    }
}