#include "HashFunctions.h"
#include <string>
#include <vector>

int simpleHash(std::string string_, int size_)
{
    int hash = 0;
    for (int i = 0; i < string_.length(); i++)
    {
        hash += (int)string_[i];
    }
    //hash = hash * 123;
    hash = hash * 9;
    return abs(hash) % size_;
}

int seriousHash(std::string string_, int size_)
{
    int hash = 0;
    for (int i = 0; i < string_.length(); i++)
    {
        hash += (int)string_[i];
        hash *= (int)string_[i];
        hash %= (size_ * 2);
    }
    //hash = hash * 38;
    //hash = hash * 365;
    return abs(hash) % size_;
}

int overSeriousHash(std::string string_, int size_)
{
    std::vector<int> vect;
    int hash = 0;
    for (int i = 0; i < string_.length() - 2; i++)
    {
        vect.push_back(((int)string_[i] | (int)string_[i + 1]) ^ (int)string_[i + 2]);
        vect.push_back((int)string_[i] & (int)string_[i + 2]);
    }
    for (int i : vect)
    {
        hash = ((hash^i) + 1) * 23;//*12;
    }
    return abs(hash) % size_;
}
