#ifndef DEFINITION_HPP
#define DEFINITION_HPP

#include "CString.hpp"

class Definition
{
    friend class Dictionnaire;

    private :
        /* Attributes */
        CString word, def;
        Definition* next;

        /* Builders */
        Definition(); // Default
        Definition(const Definition&); // Copy
        Definition(CString word, CString def);
        Definition(const char*, const char*);

    public :
        /* Getters */
        CString getWord() const;
        CString getDef() const;
        Definition* getNext() const;
};

#endif
