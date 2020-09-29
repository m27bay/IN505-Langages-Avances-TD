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
    CString(const char* _str);
    CString(const char car);
    CString();

    /* Destructor */
    ~CString();

    /* Getter */
    char* getStr();

    /* Methods */
    /* */
    void print();

    /* */
    int nbrStr();

    /* */
    CString concat(const char car);
    bool moreBigThan(const char* _str);
    bool lessOrEqual(const char* _str);
    char* moreBig(const char* _str);
};

#endif
