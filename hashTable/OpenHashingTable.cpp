#include "OpenHashingTable.h"
#include "Node.h"
#include <iostream>


OpenHashingTable::OpenHashingTable(int sizeOfHashTable, int numberOfHashFunction)
{
    size = sizeOfHashTable;
    //table = new (Node*)[sizeOfHashTable]; // проверка если недостаточно памяти
                                                           // заполнить nullptr таблицу?
    table.resize(size);
    /*for (int i = 0; i < size; i++)
    {
        //table[i] = nullptr;
        table[i] = nullptr;
    }*/
    hashFunction = arrayHash[numberOfHashFunction - 1];
}

void OpenHashingTable::addElem(std::vector<std::string> data)
{
    int hash = hashFunction(data[0], size);
    Node* node = new Node(data);
    if (table[hash] == nullptr)
    {
        table[hash] = node;
    }
    else
    {
        Node* temp = table[hash];

        bool notInserted = true;
        while (notInserted)
        {
            if (temp->getNext() == nullptr)
            {
                temp->setNext(node);
                notInserted = false;
            }
            else
            {
                temp = temp->getNext();
                collision++;
            }
        }
    }
    

}

std::vector<std::string> OpenHashingTable::getElem(std::string string)
{
    int hash = hashFunction(string, size);
    Node* temp = table[hash];
    
    if (temp == nullptr)
    {
        return { "No such word" };
    }
    int it = 0;
    while (temp->getData()[0] != string)
    {
        it++;
        if (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        else
        {
            return { "No such word" };
        }
    }
    std::cout << "Search iterations: " << it << std::endl;
    return temp->getData();
}

int OpenHashingTable::getCollision()
{
    return collision;
}

OpenHashingTable::~OpenHashingTable()
{
}
