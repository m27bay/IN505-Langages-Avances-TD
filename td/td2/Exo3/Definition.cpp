#include <iostream>

#include "Definition.hpp"

/* Builders */
Definition::Definition()
{
  this->word = CString("*empty*");
  this->def = CString("*empty*");
  this->next = nullptr;
}

Definition::Definition(CString word, CString def)
{
  this->word = word;
  this->def = def;
  this->next = nullptr;
}

Definition::Definition(const char* word, const char* def)
{
  this->word = CString(word);
  this->def = CString(def);
  this->next = nullptr;
}
/* End builders */

/* Getters */
CString Definition::getWord() const
{
  return this->word;
}

CString Definition::getDef() const
{
  return this->def;
}

Definition* Definition::getNext() const
{
  return this->next;
}
/* End getters */
