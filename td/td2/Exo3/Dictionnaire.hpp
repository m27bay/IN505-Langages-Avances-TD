#ifndef Dictionnaire_HPP
#define Dictionnaire_HPP

#include <iostream>
#include "Definition.hpp"

class Dictionnaire
{
  private :
    /* Attributes */
    int size;
    Definition* first;

  public :
    /* Builders */
    Dictionnaire(); // Default
    Dictionnaire(const Dictionnaire&); // Copy
    Dictionnaire(const char*, const char*);

    /* Getters */
    Definition* getFirst() const;

    /* Overloaded */
    Dictionnaire &operator=(const Dictionnaire&);

    friend std::ostream &operator<<(std::ostream &flux, const Dictionnaire&);

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
    ~Dictionnaire();
};

#endif
