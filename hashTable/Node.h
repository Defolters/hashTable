#ifndef NODE_H
#define NODE_H
#include <vector>
#include <string>

class Node
{
public:
    Node(std::vector<std::string> data);
    Node* getNext();
    void setNext(Node* node);
    std::vector<std::string> getData();
    ~Node();

private:
    std::vector<std::string> data;
    Node* next;
};
#endif // NODE_H
