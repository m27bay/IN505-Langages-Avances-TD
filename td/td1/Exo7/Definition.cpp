#include <iostream>

#include "Definition.hpp"

/* Builders */
Definition::Definition()
{
  std::cout << "Definition : default builder" << std::endl;
  word = CString();
  def = CString();
}

Definition::Definition(CString _word, CString _def)
{
  std::cout << "Definition : builder with CString" << std::endl;
  word = _word;
  def = _def;
}

Definition::Definition(const char* _word, const char* _def)
{
  std::cout << "Definition : builder with char*" << std::endl;
  word = CString(_word);
  def = CString(_def);
}

Definition::Definition(const Definition &def)
{
  std::cout << "Definition : copy builder" << std::endl;
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
  std::cout << word.getStr() << " : \n\t" << def.getStr() << std::endl;
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
Definition::~Definition()
{
  std::cout << "Definition : destructor" << std::endl;
}
