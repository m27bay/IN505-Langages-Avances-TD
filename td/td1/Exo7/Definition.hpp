#ifndef DEFINITION_HPP
#define DEFINITION_HPP

#include "../Exo6/CString.hpp"

class Definition
{
  private :
    /* Attributes */
    CString word, def;

  public :
    /* Builders */
    Definition();
    Definition(CString word, CString def);
    Definition(const char* word, const char* def);
    Definition(const Definition &def);


    /* Getters */
    CString getWord() const;
    CString getDef() const;

    /* Print */
    void print() const;

    /* Methods */
    void operator=(const Definition &def);

    /* Destructor */
    ~Definition();
};

#endif
