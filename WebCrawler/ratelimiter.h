#ifndef RATELIMITER_H
#define RATELIMITER_H
#include "dataStructure/customString/cstring.h"

#include "dataStructure/custommap/cmap.h"
#include "domaindate.h"

class RateLimiter {
private:
    Map<String, DomainData> domainData;

public:
    bool canFetch(const String& domain);
    void update(const String& domain, int urlFetched, time_t timestamp);
};

#endif // RATELIMITER_H
