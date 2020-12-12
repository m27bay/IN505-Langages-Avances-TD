#include "CString.hpp"
#include <string.h>
#include <iostream>

int CString::_nbrStr = 0;

/* builders */
CString::CString()
{
  /* */
  size = 0;
  str = NULL;

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

CString::CString(const CString &other)
{
  this->str = new char[ (this->size = other.size) + 1 ];
  strcpy(this->str, other.str);
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

int CString::getNbrStr()
{
  return _nbrStr;
}
/* End getter */

/* Setter */
void CString::setStr(char* newStr)
{
  str = newStr;
}
/* End setter */

/* Overloaded */
CString& CString::operator=(const CString &other)
{
  // protect against invalid self-assignment
  if( this != &other )
  {
    // 1: allocate new memory and copy the elements
    char* newStr = new char[other.size + 1];
    strcpy(newStr, other.str);

    // 2: deallocate old memory
    delete[] this->str;

    // 3: assign the new memory to the object
    this->str = newStr;
    this->size = other.size;
  }

  // by convention, always return *this
  return *this;
}

CString& CString::operator+(const CString &other)
{

  // Alloc new memory
  char* tmp = new char[(this->size += other.size) + 1];

  // Fill new string
  strcpy(tmp, this->str);
  strcat(tmp, other.str);

  // Free
  delete[] this->str;

  // assign
  this->str = tmp;

  return *this;
}

bool CString::operator>(const CString &other)
{
  return ( ( strcmp(this->str, other.str) > 0 ) && this->size > other.size );
}

bool CString::operator<=(const CString &other)
{
  return ( ( strcmp(this->str, other.str) <= 0 ) && this->size <= other.size );
}

std::ostream &operator<<(std::ostream &flux, const CString &other)
{
  for (int i = 0; i < other.size; ++i)
  {
    flux << other.str[i];
  }

  return flux;
}

std::istream &operator>>(std::istream &flux, CString &other)
{
  delete [] other.str;

  std::string newStr;
  std::cout << "New Str = ";
  flux >> newStr;

  other.size = newStr.length();
  other.str = new char[other.size + 1];
  strcpy(other.str, newStr.c_str());

  return flux;
}
/* End overloaded */

/* Print */
void CString::print() const
{
  if( size )
  {
      std::cout << "String : " << *this << ", size : " << size <<std::endl;
  }
  else
  {
      std::cout << "*empyt*" << std::endl;
  }
}

/* Methodes */
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
  _nbrStr--;
  if( str != NULL )
  {
    delete[] str;
  }
  else
    std::cout << "error : null str" << std::endl;
}
/* End destructor */
