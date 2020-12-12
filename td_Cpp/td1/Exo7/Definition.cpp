#include <iostream>

#include "Definition.hpp"

/* Builders */
Definition::Definition()
{
  CString word, def;
}

Definition::Definition(CString _word, CString _def)
{
  word = _word;
  def = _def;
}

Definition::Definition(const char* _word, const char* _def)
{
  CString word(_word), def(_def);
}

Definition::Definition(const Definition &def)
{
  this->word = def.word;
  this->def = def.def;
}
/* End builders */

/* Getters */
CString Definition::getWord() const
{
  return word;
}

CString Definition::getDef() const
{
  return def;
}
/* End getters */

/* Print */
void Definition::print() const
{
  if( word.getSize() )
  {
    std::cout << word.getStr() << " : " << def.getStr() << std::endl;
  }
  else
    std::cout << "*empty* : *empty*" << std::endl;
}
/* End print */

/* Methodes */
void Definition::operator=(const Definition &defTmp)
{
  word = defTmp.getWord();
  def = defTmp.getDef();
}
/* End methodes */

/* Destructor */
Definition::~Definition() {}
