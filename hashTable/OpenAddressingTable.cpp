#include "OpenAddressingTable.h"
#include <iostream>

OpenAddressingTable::OpenAddressingTable(int sizeOfHashTable, int numberOfHashFunction)
{
    size = sizeOfHashTable;
    table.resize(size);// = new std::vector<std::string>[sizeOfHashTable]; // проверка если недостаточно памяти
                                                           // заполнить нулями таблицу?
    hashFunction = arrayHash[numberOfHashFunction - 1];
}


void OpenAddressingTable::addElem(std::vector<std::string> data)
{
    // get hash
    int hash = hashFunction(data[0], size);
    bool notInserted = true;
    //if 0 in table
    while (notInserted)
    {
        if (table[hash].empty() & (hash < size))
        {
            // put in table
            table[hash] = data;
            //table[hash].push_back("1");//заполнить with data
            notInserted = false;
        }
        else if (hash < size-1)
        {
            //std::cout << table[hash][0];
            collision++;
            hash++;
        }
        else
        {
            hash = hash - (size - 1);
            collision++;
            std::cout << "End of table" << std::endl;
            //break;
        }
    }
    // else + 1, while no 0 in table and +1 коллизия
}

std::vector<std::string> OpenAddressingTable::getElem(std::string string)
{
    int hash = hashFunction(string, size);
    int it = 0;
    while (1)
    {
        it++;
        if (table[hash].size() != 0)
        {
            if (table[hash][0] == string)
            {
                std::cout << "Search iterations: "<< it << std::endl;
                return table[hash];
            }
        }
        if (hash < size - 1)
        {
            hash++;
        }
        else
        {
            hash = hash - (size - 1);
            std::cout << "End of table" << std::endl;
            //break;
        }
        if (it > size) 
        {
            return { "No such word" };
        }
    }
    return table[hash];
}

int OpenAddressingTable::getCollision()
{
    return collision;
}


OpenAddressingTable::~OpenAddressingTable()
{
}
