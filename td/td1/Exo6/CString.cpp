#include "CString.hpp"
#include <string.h>
#include <iostream>

int CString::_nbrStr = 0;

/* */

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

CString::CString(const CString &cstr)
{
    this->str = cstr.str;
    this->size = cstr.size;
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
/* End getter */

/* Setter */
void CString::setStr(char* newStr)
{
    str = newStr;
}
/* End setter */

/* Methods */
void CString::operator=(const CString &other)
{
    delete[] this->str;
    this->str = new char[ strlen( other.getStr() ) + 1 ];
    strcpy( this->str, other.getStr() );
    this->size = other.getSize();
}

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

/* */
int CString::nbrStr()
{
    return _nbrStr;
}

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
    delete[] str;
}
/* End destructor */
