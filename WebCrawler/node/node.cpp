// node.cpp

#include "node.h"

Node::Node(const std::string& urlname, int depth)
    : urlname(urlname), depth(depth) {}

std::string Node::getUrlname() const {
    return urlname;
}

int Node::getDepth() const {
    return depth;
}
