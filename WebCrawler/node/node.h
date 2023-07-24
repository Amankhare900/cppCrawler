// node.h

#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    Node(const std::string& urlname, int depth);

    // Getters
    std::string getUrlname() const;
    int getDepth() const;

    // Setters (if needed)

private:
    std::string urlname;
    int depth;
};

#endif // NODE_H
