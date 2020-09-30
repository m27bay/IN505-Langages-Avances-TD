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

    /* Setter */
    void setStr(char* newStr);

    /* Methods */
    /* */
    void print() const;

    /* */
    int nbrStr();

    /* */
    char* concat(const char car);
    CString concat2(const char car);
    bool moreBigThan(char* _str);
    bool lessOrEqual(char* _str);
    char* moreBig(char* _str);
};

#endif
