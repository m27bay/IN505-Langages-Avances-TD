#ifndef CString_HPP
#define CString_HPP

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
    CString(const CString &cstr);

    /* Destructor */
    ~CString();

    /* Getter */
    char* getStr() const;
    int getSize() const;

    /* Setter */
    void setStr(char* newStr);

    /* Methods */
    /* */
    void print() const;

    /* */
    int nbrStr();

    /* */
    void operator=(const CString &other);
    CString cstradd(const char car);
    bool moreBigThan(char* _str);
    bool lessOrEqual(char* _str);
    char* moreBig(char* _str);
};

#endif
