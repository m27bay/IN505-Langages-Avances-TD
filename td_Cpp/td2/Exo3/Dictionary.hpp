#ifndef Dictionary_HPP
#define Dictionary_HPP

#include <iostream>
#include "Definition.hpp"

class Dictionary
{
  private :
    /* Attributes */
    int size;
    Definition* first;

  public :
    /* Builders */
    Dictionary(); // Default
    Dictionary(const Dictionary&); // Copy
    Dictionary(const char*, const char*);

    /* Getters */
    Definition* getFirst() const;

    /* Overloaded */
    Dictionary &operator=(const Dictionary&);

    friend std::ostream &operator<<(std::ostream &flux, const Dictionary&);

    /* methodes */
    // Add
    int addFirst(const char*, const char*);
    int addEnd(const char*, const char*);
    int addIndex(const char*, const char*, int index);
    int addAlphabetize(const char*, const char*);

    // Dell
    int dellFirst();
    void empty();

    /* Destructor */
    ~Dictionary();
};

#endif
