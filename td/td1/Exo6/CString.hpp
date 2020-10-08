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

    /* Getter */
    char* getStr() const;
    int getSize() const;
    int getNbrStr() const;

    /* Setter */
    void setStr(char* newStr);

    /* Print */
    void print() const;

    /* Overloaded */
    CString& operator=(const CString &other);

    /* Methods */
    CString cstradd(const char car);
    bool moreBigThan(char* _str);
    bool lessOrEqual(char* _str);
    char* moreBig(char* _str);

    /* Destructor */
    ~CString();
};

#endif
