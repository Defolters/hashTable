//!  Header file with the description
/*!
This file contains definitions of key classes used in the demo program
*/
#ifndef HASH_FUNCTIONS
#define HASH_FUNCTIONS
#include <string>


//! Simple hash function
/*!
\param string String that would be hashed
\return hash
*/
int simpleHash(std::string string_, int size_);

//! Serious hash function
/*!
\param string String that would be hashed
\return hash
*/
int seriousHash(std::string string_, int size_);

//! overSeriousHash
/*!
\param string String that would be hashed
\return hash
*/
int overSeriousHash(std::string string_, int size_);


#endif // HASH_FUNCTIONS
