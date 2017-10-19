/*! \class OpenHashingTable
\brief A class that contain open hashing table.

There's linked list. If there happens collision, the item will be added to old elem.
*/
#ifndef OPEN_HASHING_TABLE
#define OPEN_HASHING_TABLE
#include "HashFunctions.h"
#include "Node.h"

class OpenHashingTable
{
public:
    OpenHashingTable(int sizeOfHashTable, int hashFunction);
    void addElem(std::vector<std::string> data);
    std::vector<std::string> getElem(std::string string);
    int getCollision();
    ~OpenHashingTable();

private:
    int size;
    int collision = 0;
    //Node* table;
    std::vector<Node *> table;
    //std::vector<std::string>* table;
    int(*arrayHash[3])(std::string string_, int size_) = { simpleHash, seriousHash, overSeriousHash };
    int(*hashFunction)(std::string string_, int size_);
};
#endif // OPEN_HASHING_TABLE

