#include "HashFunctions.h"
#include "OpenAddressingTable.h"
#include "OpenHashingTable.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
/*
+ В программе задаётся размер хэш-таблицы, 
+ путь к файлу словаря  (русский или английских слов).
+Она должна считать указанный словарь и добавить каждое слово в таблицу.
+При этом она должна оценивать число возникающий коллизий во время процесса добавления.
+Это число она должна вывести по завершению процесса добавления.
+-Так же программа должна уметь выполнять поиск слова вводимиго через терминал.
+-В результате поиска она должна вывести информацию о том, есть ли такое слово, и сколько раз вычислялась хэш-функция и время работы процедуры поиска.
*/

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::vector<std::vector<std::string>> table;

    std::ifstream file;
    file.open("data.txt");
    if (file.fail())
    {
        exit(1);
    }
    std::string word;
    int position = 0;
    while (std::getline(file, word))
    {
        if (word != "")
        {
            
            table.push_back({ word });
            position++;
        }
    }
    /*std::string key(" ");
    std::string item, name, age;
    int itFirst, position = 0;
    while (std::getline(file, item))
    {
        if (item != "")
        {
            itFirst = item.find(key);
            name = item.substr(0, itFirst);
            age = item.substr(itFirst + 1);
            table.push_back({ name, age });
            position++;
        }
    }*/
    
    file.close();
    // choose m and hash function
    int sizeOfHashTable;
    std::cout << "Enter size of hash table, if size of normal table = " << table.size() << ": ";
    std::cin >> sizeOfHashTable;
    if (table.size() > sizeOfHashTable)
    {
        std::cout << "\nError, hash table should be more than table.";
        exit(1);
    }
    
    //select hash func
    int hashFunction = 0;
    std::cout << "Enter number of hash function 1 - simple, 2 - serious, 3 - overserious: ";
    std::cin >> hashFunction;
    //select table
    int tableNumber = 0;
    std::cout << "Enter number of table 1 - OpenAddressingTable, 2 - OpenHashingTable: ";
    std::cin >> tableNumber;
    std::string search;
    if (tableNumber == 1)
    {
        OpenAddressingTable oATable(sizeOfHashTable, hashFunction);
        for (int i = 0; i < table.size(); i++)
        {
            oATable.addElem(table[i]);
        }
        std::cout << "Collisions: " << oATable.getCollision() << std::endl;
        while (std::cin >> search)
        {
            start = std::chrono::system_clock::now();
            std::cout << oATable.getElem(search)[0] << std::endl;
            end = std::chrono::system_clock::now();
            std::cout << "Search: " << ((double)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()) / 1000 << " seconds\n";
        }
        
    }
    else if (tableNumber == 2)
    {
        OpenHashingTable oHTable(sizeOfHashTable, hashFunction);
        for (int i = 0; i < table.size(); i++)
        {
            oHTable.addElem(table[i]);
        }
        std::cout << "Collisions: " << oHTable.getCollision() << std::endl;
        while (std::cin >> search)
        {
            start = std::chrono::system_clock::now();
            std::cout << oHTable.getElem(search)[0] << std::endl;
            end = std::chrono::system_clock::now();
            std::cout << "Search: " << ((double)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()) / 1000 << " seconds\n";
        }
    }
    
    

    // example of searching element!!!!!!!!!!

    //create two tables
    //OpenAddressingTable oATable(sizeOfHashTable,hashFunction);
    //OpenHashingTable oHTable(sizeOfHashTable, hashFunction);
    //for each elem in table put it in two tables
    /*OpenAddressingTable oATable1(sizeOfHashTable, 1);
    OpenAddressingTable oATable2(sizeOfHashTable, 2);
    OpenAddressingTable oATable3(sizeOfHashTable, 3);
    OpenHashingTable oHTable1(sizeOfHashTable, 1);
    OpenHashingTable oHTable2(sizeOfHashTable, 2);
    OpenHashingTable oHTable3(sizeOfHashTable, 3);
    for (int i = 0; i < table.size(); i++)
    {
        oHTable1.addElem(table[i]);
        oHTable2.addElem(table[i]);
        oHTable3.addElem(table[i]);
        oATable1.addElem(table[i]);
        oATable2.addElem(table[i]);
        oATable3.addElem(table[i]);
    }
    std::cout << "Collisions: " << oATable1.getCollision() << std::endl;
    std::cout << "Collisions: " << oATable2.getCollision() << std::endl;
    std::cout << "Collisions: " << oATable3.getCollision() << std::endl;
    std::cout << "Collisions: " << oHTable1.getCollision() << std::endl;
    std::cout << "Collisions: " << oHTable2.getCollision() << std::endl;
    std::cout << "Collisions: " << oHTable3.getCollision() << std::endl;
    400-600
    21 79800
    31 79800
    11 79800
    32 38
    22 644
    12 109
    */
    std::cin >> sizeOfHashTable;
    return 0;
}