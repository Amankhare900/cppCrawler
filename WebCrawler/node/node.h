// node.h

#ifndef NODE_H
#define NODE_H
#include "../dataStructure/customString/cstring.h"


class Node {
public:
    Node();
    Node(const String& urlname, int depth);

    // Getters
    String getUrlname() const;
    int getDepth() const;

    // Setters (if needed)

private:
    String urlname;
    int depth;
};

#endif // NODE_H
