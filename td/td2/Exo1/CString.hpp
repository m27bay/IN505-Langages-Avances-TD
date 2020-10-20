#ifndef CString_HPP
#define CString_HPP

#include <iostream>

class CString
{
  private :

    /* attributes */
    char* str;
    int size;
    static int _nbrStr;

  public :

    /* Builders */
    CString();
    CString(const char car);
    CString(const char* _str);
    CString(const CString&);

    /* Getter */
    char* getStr() const;
    int getSize() const;

    /* Setter */
    void setStr(char* newStr);
    int getNbrStr();

    /* Print */
    void print() const;

    /* Overloaded */
    CString &operator=(const CString&);

    CString &operator+(const CString&);

    bool operator>(const CString&);
    bool operator<=(const CString&);

    friend std::ostream &operator<<(std::ostream &flux, const CString&);
    friend std::istream &operator>>(std::istream &flux, CString&);

    /* Methods */
    CString cstradd(const char car);
    bool moreBigThan(char*);
    bool lessOrEqual(char* _str);
    char* moreBig(char* _str);

    /* Destructor */
    ~CString();
};

#endif
