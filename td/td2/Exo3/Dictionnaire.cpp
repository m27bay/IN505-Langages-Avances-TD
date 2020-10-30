#include "Dictionnaire.hpp"

/* Builders */
// Default
Dictionnaire::Dictionnaire() : size(0), first(nullptr) {}

// Copy
Dictionnaire::Dictionnaire(const Dictionnaire& other)
{
    // Init list
  this->size = other.size;
  this->first = nullptr;

  // Create the first element
  Definition* firstDefinition = new Definition(other.first->word, other.first->def);
  this->first = firstDefinition;

  // Creation current
  Definition* currentThis = first;
  Definition* currentOther = other.first->next;

  // Ride in currentOther
  while (currentOther)
  {
    // Init next
    currentThis->next = currentOther;

    // Skip to the next
    currentOther = currentOther->next;
    currentThis = currentThis->next;
  }
}

Dictionnaire::Dictionnaire(const char* word, const char* def)
{
  this->size = 1;
  this->first = new Definition(word, def);
}
/* End builders */

/* Getters */
Definition* Dictionnaire::getFirst() const
{
  return this->first;
}
/* End getters */

/* Overloaded */
std::ostream &operator<<(std::ostream &flux, const Dictionnaire& other)
{
  if (!other.first)
  {
    flux << "{ *empty* }" << std::endl;
  }
  else
  {
    Definition* current = other.first;

    flux << "{\n";
    while (current->getNext())
    {
      flux << current->getWord() << " : " << current->getDef() << "\n";
      current = current->getNext();
    }
    flux << current->getWord() << " : " << current->getDef() << " \n }, size : " << other.size << std::endl;
  }

  return flux;
}
/* End overloaded */

/* Methodes */
// Add
int Dictionnaire::addFirst(const char* newWord, const char* newDef)
{
  Definition* newDefinition = new Definition(newWord, newDef);
  if (!newDefinition)
  {
    std::cout << "ERROR : new failed" << std::endl;
    return -1;
  }
  else if (!this->first)
  {
    this->first = newDefinition;
    this->size = 1;

    return 0;
  }

  newDefinition->next = this->first;
  this->first = newDefinition;

  this->size += 1;

  return 0;
}

int Dictionnaire::addEnd(const char* newWord, const char* newDef)
{
  Definition* newDefinition = new Definition(newWord, newDef);
  if (!newDefinition)
  {
    std::cout << "ERROR : new failed" << std::endl;
    return -1;
  }
  else if (!this->first)
  {
    this->first = newDefinition;
    this->size = 1;

    return 0;
  }

  Definition* current = this->first;
  while (current->next)
  {
    current = current->next;
  }

  current->next = newDefinition;
  this->size += 1;

  return 0;
}

int Dictionnaire::addIndex(const char* word, const char* def, int index)
{
  if (index < 0 || index > this->size)
  {
    std::cout << "ERROR : index out of band" << std::endl;
    return -1;
  }
  else if (index == 0)
  {
    addFirst(word, def);
    return 0;
  }
  else if (index == this->size)
  {
    addEnd(word, def);
    return 0;
  }

  Definition* current = this->first;
  int tmp = 1;

  while (tmp < index)
  {
    current = current->next;
    tmp++;
  }

  Definition* newDefinition = new Definition(word, def);
  newDefinition->next = current->next;
  current->next = newDefinition;

  this->size += 1;
  return 0;
}

int Dictionnaire::addAlphabetize(const char* word, const char* def)
{
  CString cword = CString(word);

  if (!this->first)
  {
    addFirst(word, def);
    return 0;
  }
  else if (this->size == 1)
  {
    (this->first->word >= cword) ? addFirst(word, def) : addEnd(word, def);
    return 0;
  }
  else if (cword <= this->first->word)
  {
    addFirst(word, def);
    return 0;
  }

  int index = 1;
  Definition* current = this->first;
  while (current->next)
  {
    // std::cout << current->word << " <= " << cword << " : " << (current->word <= cword) << std::endl;
    // std::cout << cword << " <= " << current->next->word << " : " << (cword <= current->next->word) << std::endl;
    // std::cout << "index : " << index << std::endl;
    if ((current->word <= cword) && (cword <= current->next->word))
    {
      addIndex(word, def, index);
      return 0;
    }

    current = current->next;
    index++;
  }

  addEnd(word, def);
  return 0;
}

// Dell
int Dictionnaire::dellFirst()
{
  if (!this->first)
  {
    std::cout << "ERROR : list empty" << std::endl;
    return -1;
  }

  Definition* tmp = this->first;
  this->first = this->first->next;
  delete tmp;
  this->size -= 1;

  return 0;
}

void Dictionnaire::empty()
{
  while (this->size)
  {
    dellFirst();
  }
}
/* End methodes */

/* Destructor */
Dictionnaire::~Dictionnaire()
{
  empty();
}
/* End destructors */
