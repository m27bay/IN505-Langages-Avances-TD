#include "CString.hpp"
#include <string.h>
#include <iostream>
#include <algorithm>

int CString::_nbrStr = 0;

/* builders */
CString::CString()
{
  /* */
  size = 0;
  str = new char[1];
  str[0] = '\0';

  /* */
  _nbrStr++;
}

CString::CString(const char car)
{
  /* */
  size = 1;
  str = NULL;
  str = new char[2];
  str[0] = car;
  str[1] = '\0';

  /* */
  _nbrStr++;
}

CString::CString(const char* _str)
{
  /* */
  size = strlen(_str);
  str = NULL;
  str = new char[ size + 1 ];
  strcpy(str, _str);

  /* */
  _nbrStr++;
}

// Copy constructor
CString::CString(const CString &other)
{
  str = new char[ other.size + 1];
  strcpy( str, other.str );
  size = other.size;
}
/* End builders */

/* Getter */
char* CString::getStr() const
{
  return str;
}

int CString::getSize() const
{
  return size;
}

int CString::getNbrStr() const
{
  return _nbrStr;
}
/* End getter */

/* Print */
void CString::print() const
{
  if( size )
  {
      std::cout << "String : " << str << ", size : " << size <<std::endl;
  }
  else
  {
      std::cout << "*empyt*" << std::endl;
  }
}

/* Setter */
void CString::setStr(char* newStr)
{
  str = newStr;
}
/* End setter */

/* Overloaded */
CString& CString::operator=(const CString &other)
{
  // // protect against invalid self-assignment
  if( this != &other )
  {
    // 1: allocate new memory and copy the elements
    char* newStr = new char[other.size + 1];
    std::copy(other.str, other.str + other.size, newStr);

    // 2: deallocate old memory
    delete[] str;

    // 3: assign the new memory to the object
    str = newStr;
    size = other.size;
  }

  // by convention, always return *this
  return *this;
}
/* End overloaded */

/* Methods */
CString CString::cstradd(char car)
{
  /* */
  int newSize = size + 2;
  char* tmp = new char[ newSize ];
  strcpy( tmp, str );
  tmp[ size ] = car;
  tmp[ newSize - 1 ] = '\0';

  /* */
  CString CStmp(tmp);
  delete[] tmp;
  return CStmp;
}

bool CString::moreBigThan(char* _str)
{
  return ( strcmp(str, _str) > 0 );
}

bool CString::lessOrEqual(char* _str)
{
  return ( strcmp(str, _str) <= 0 );
}

char* CString::moreBig(char* _str)
{
  if( strcmp(str, _str) > 0 )
  {
      return str;
  }
  else
  {
      return _str;
  }
}
/* End methods */

/* destructor */
CString::~CString()
{
  std::cout << "destructor of " << str << std::endl;
  _nbrStr--;
  if( str != NULL )
  {
    delete[] str;
  }
  else
    std::cout << "error : null str" << std::endl;
}
/* End destructor */
