#include "CString.hpp"
#include <cstring>
#include <iostream>

int CString::_nbrStr = 0;

/* */

/* builders */
CString::CString(const char* _str)
{
    /* */
    size=strlen(_str);
    str = new char[ size + 1 ];
    strcpy(str, _str);

    /* */
    _nbrStr++;
}

CString::CString(const char car)
{
    /* */
    size = 1;
    str = new char[2];
    str[0] = car;
    str[1] = '\0';

    /* */
    _nbrStr++;
}

CString::CString()
{
    /* */
    size = 0;
    str = new char[1];

    /* */
    _nbrStr++;
}
/* End builders */

/* destructor */
CString::~CString()
{
    std::cout << "destructor" << std::endl;
    _nbrStr--;
    delete[] str;
}
/* End destructor */

/* Getter */
char* CString::getStr()
{
    return str;
}
/* End getter */

/* Setter */
void CString::setStr(char* newStr)
{
    str = newStr;
}
/* End setter */

/* Methods */
void CString::print() const
{
    if( size )
    {
        std::cout << str << std::endl;
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

/* */
char* CString::cstradd(const char car)
{
    char* newStr = new char[ size+2 ];
    strcpy( newStr, str );
    newStr[ size ] = car;
    newStr[ size+1 ] = '\0';

    /* */
    return newStr;

}

CString CString::cstradd2(char car){
    char* tmp = new char[ strlen( str ) + 1 ];
    strcpy( tmp, str );
    tmp[ strlen( str ) ] = car;
    return CString(tmp);
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
