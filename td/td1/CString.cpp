#include "CString.hpp"
#include <cstring>
#include <iostream>

int CString::_nbrStr = 0;

/* builders */
CString::CString(const char* _str)
{
    /* */
    size=strlen(_str);
    str = new char[ size + 1 ];
    strcpy(str, _str);
    str[ size ] = '\0';

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
    str[0] = '\0';

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
void CString::print()
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
char* CString::concat(const char car)
{
    char* newStr = new char[ size+2 ];
    strcpy( newStr, str );
    newStr[ size ] = car;
    newStr[ size+1 ] = '\0';

    /* */
    std::cout << "newStd : " << newStr << std::endl;
    return newStr;

}

CString CString::concat2(const char car)
{
    return CString();
}
/* End methods */
