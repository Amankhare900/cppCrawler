// node.cpp

#include "node.h"

Node::Node(const String& urlname, int depth)
    : urlname(urlname), depth(depth) {}

String Node::getUrlname() const {
    return urlname;
}

int Node::getDepth() const {
    return depth;
}
