#include "Node.h"



Node::Node(std::vector<std::string> data)
{
    this->data = data;
    next = nullptr;
}

Node * Node::getNext()
{
    return next;
}

void Node::setNext(Node * node)
{
    next = node;
}

std::vector<std::string> Node::getData()
{
    return data;
}

Node::~Node()
{
}
