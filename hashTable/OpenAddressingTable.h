/*!
\class OpenAddressingTable
\brief A class that contain open adressing table.

There's no linked list. If there happens collision, the item will move to the cell below.
*/
#ifndef OPEN_ADDRESSING_TABLE
#define OPEN_ADDRESSING_TABLE
#include "HashFunctions.h"
#include <vector>
#include <string>


class OpenAddressingTable
{
public:
    /// Create an instance of OpenAddressingTable with given size
    OpenAddressingTable(int sizeOfHashTable, int numberOfHashFunction);
    void addElem(std::vector<std::string> data);
    std::vector<std::string> getElem(std::string string);
    int getCollision();
    ~OpenAddressingTable();
    //std::vector<std::string> findElem(int id);
    //deleteElem();

private:
    int size;
    int collision = 0;
    std::vector<std::vector<std::string>> table;
    int(*arrayHash[3])(std::string string_, int size_) = { simpleHash, seriousHash, overSeriousHash };
    int(*hashFunction)(std::string string_, int size_);
};
#endif // OPEN_ADDRESSING_TABLE
