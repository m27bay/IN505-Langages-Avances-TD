#include "CString.hpp"
#include <cstring>
#include <iostream>

int CString::_nbrStr = 0;

/* builders */
CString::CString(const char* _str)
{
    /* */
    str = new char[ size=strlen(_str) + 1 ];
    strcpy(str, _str);
    str[ size - 1 ] = '\0';

    /* */
    _nbrStr++;
}

CString::CString(const char car)
{
    /* */
    str = new char[ size=2 ];
    str[0] = car;
    str[ 1 ] = '\0';

    /* */
    _nbrStr++;
}

CString::CString()
{
    /* */
    str = new char[ size=1 ];
    str[0] = '\0';

    /* */
    _nbrStr++;
}
/* End builders */

/* destructor */
CString::~CString()
{
    std::cout << "destructor" << std::endl;
    delete[] str;
    _nbrStr--;
}
/* End destructor */

/* Getter */
char* CString::getStr()
{
    return str;
}
/* End getter */

/* Methods */
void CString::print()
{
    std::cout << str << std::endl;
}

/* */
int CString::nbrStr()
{
    return _nbrStr;
}

/* */
CString CString::concat(const char car)
{
    std::cout << "hello world" << std::endl;
    // char* newStr = new char[ size+2 ];
    // strcpy( newStr, str );
    // newStr[ size ] = car;
    // newStr[ size+1 ] = '\0';

    // /* */
    return CString( "hello world" );

}
/* End methods */
