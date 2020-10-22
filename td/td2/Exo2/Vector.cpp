#include <iostream>

#include "Vector.hpp"

/* ########## */
/* VectorTab  */
/* ########## */

/* Builders */

// Default
VectorTab::VectorTab()
{
  this->tab = nullptr;
  this->size = 0;
}

// Copy
VectorTab::VectorTab(const VectorTab& other)
{
  // Alloc
  this->tab = new int[ (this->size = other.size) ];

  // Alloc failed ?
  if (!this->tab)
  {
    this->tab = nullptr;
    this->size = 0;
  }
  else
  {
    // Fill
    for (int i = 0; i < this->size; ++i)
    {
      this->tab[i] = other.tab[i];
    }
  }
}

VectorTab::VectorTab(int* tab, int size)
{
  // Alloc
  this->tab = new int[ (this->size = size) ];

  // Alloc failed ?
  if (!this->tab)
  {
    this->tab = nullptr;
    this->size = 0;
  }
  else
  {
    // Fill
    for (int i = 0; i < this->size; ++i)
    {
      this->tab[i] = tab[i];
    }
  }
}

VectorTab::VectorTab(int size)
{
  // Alloc
  this->tab = new int[ (this->size = size) ];

  // Alloc failed ?
  if (!this->tab)
  {
    this->tab = nullptr;
    this->size = 0;
  }
  else
  {
    // Fill
    for (int i = 0; i < this->size; ++i)
    {
      this->tab[i] = 0;
    }
  }
}
/* End builders */

/* Overloaded */
VectorTab &VectorTab::operator=(const VectorTab &other)
{
  // Protect var = var
  if( this != &other )
  {
    // Alloc
    int* newTab = new int[this->size = other.size];

    // Alloc Failed
    while (!newTab)
    {
      newTab = new int[this->size];
    }
    // Fill
    for (int i = 0; i < this->size; ++i)
    {
      newTab[i] = this->tab[i];
    }

    // Swap tab;
    delete[] tab;
    this->tab = newTab;
  }

  return *this;
}

VectorTab &VectorTab::operator+=(const VectorTab &other)
{
  if (this->size == other.size)
  {
    for (int i = 0; i < this->size; ++i)
    {
      this->tab[i] += other.tab[i];
    }
  }
  else if (this->size < other.size)
  {
    int *tmp = new int[ (this->size = other.size) ];

    for (int i = 0; i < other.size; ++i)
    {
      if (other.size > this->size)
      {
        tmp[i] = other.tab[i];
      }

      tmp[i] = this->tab[i] + other.tab[i];
    }

    delete[] this->tab;
    this->tab = tmp;
  }
  else
  {
    for (int i = 0; i < other.size; ++i)
    {
      this->tab[i] += other.tab[i];
    }
  }

  return *this;
}

VectorTab &VectorTab::operator-=(const VectorTab &other)
{
  if (this->size == other.size)
  {
    for (int i = 0; i < this->size; ++i)
    {
      this->tab[i] -= other.tab[i];
    }
  }
  else if (this->size < other.size)
  {
    int *tmp = new int[ (this->size = other.size) ];

    for (int i = 0; i < other.size; ++i)
    {
      if (other.size > this->size)
      {
        tmp[i] = other.tab[i];
      }

      tmp[i] = this->tab[i] - other.tab[i];
    }

    delete[] this->tab;
    this->tab = tmp;
  }
  else
  {
    for (int i = 0; i < other.size; ++i)
    {
      this->tab[i] -= other.tab[i];
    }
  }

  return *this;
}

bool VectorTab::operator<(const VectorTab &other)
{
  int minSize = ( this->size < other.size ) ? this->size : other.size;

  for (int i = 0; i < minSize; ++i)
  {
    if (!(this->tab[i] < other.tab[i]))
    {
      return false;
    }
  }

  return (this->size == other.size);
}

bool VectorTab::operator<=(const VectorTab &other)
{
  int minSize = ( this->size < other.size ) ? this->size : other.size;

  for (int i = 0; i < minSize; ++i)
  {
    if (!(this->tab[i] <= other.tab[i]))
    {
      return false;
    }
  }
  return (this->size == other.size);
}

bool VectorTab::operator>(const VectorTab &other)
{
  return !(*this < other);
}

bool VectorTab::operator>=(const VectorTab &other)
{
  return !(*this <= other);
}

int VectorTab::operator[](const int index)
{
  if (index > this->size)
  {
    std::cout << "Index out of bound" << std::endl;
    return -1;
  }

  return this->tab[index];
}

std::ostream &operator<<(std::ostream &flux, const VectorTab &other)
{
  flux << "{ ";
  if (other.size)
  {
    for (int i = 0; i < other.size - 1; ++i)
    {
      flux << other.tab[i] << ", ";
    }
    flux << other.tab[ other.size -1 ];
  }
  else
  {
    flux << "*empty*";
  }
  flux << " }";

  return flux;
}

std::istream &operator>>(std::istream &flux, VectorTab &other)
{
  int* newTab;
  delete[] other.tab;

  std::cout << "size = ? ";
  flux >> other.size;
  if (other.size)
  {
    newTab = new int[ other.size ];
    for (int i = 0; i < other.size; ++i)
    {
      std::cout << "value of tab[" << i << "] = ? ";
      flux >> newTab[i];
    }

    other.tab = new int[ other.size ];
    for (int i = 0; i < other.size; ++i)
    {
      other.tab[i] = newTab[i];
    }

    delete[] newTab;
  }
  else
  {
    other.tab = nullptr;
  }

  return flux;
}
/* End overloaded */

/* Destructor */
VectorTab::~VectorTab()
{
  delete[] tab;
}
/* End destructor */

/* ########## */
/* VectorList */
/* ########## */

/* Builders */
VectorList::VectorList()
{
  this->first = this->end = nullptr;
  this->size = 0;
}

VectorList::VectorList(const VectorList& other)
{
  if (!other.first)
  {
    this->first = this->end = nullptr;
    this->size = 0;
  }
  else
  {
    this->first = new VectorList::elem;
    this->first->data = other.first->data;

    this->end = new VectorList::elem;

    VectorList::elem* currentThis = this->first;
    VectorList::elem* currentOther = other.first->next;

    while (currentOther)
    {
      currentThis->next = new VectorList::elem;
      currentThis->next->data = currentOther->data;

      currentOther = currentOther->next;
      this->end = currentThis;
      currentThis = currentThis->next;
    }
    currentThis = nullptr;

    this->size = other.size;
  }
}

VectorList::VectorList(int size)
{
  if (!size)
  {
    this->first = this->end = nullptr;
    this->size = 0;

    return;
  }

  this->first = new VectorList::elem;
  this->first->data = 0;
  VectorList::elem* current = this->first;

  int sizeTmp = 1;
  while (sizeTmp < size )
  {
    current->next = new VectorList::elem;
    current->next->data = 0;

    sizeTmp++;
  }
  current->next = nullptr;
  this->end = current;
}

VectorList::VectorList(int* tab, int size)
{
  if (!tab)
  {
    this->first = this->end = nullptr;
    this->size = 0;
  }
  else
  {
    this->first = new VectorList::elem;
    this->first->data = tab[0];

    this->end = new VectorList::elem;

    VectorList::elem* currentThis = this->first;

    int pos = 1;
    while (pos < size)
    {
      currentThis->next = new VectorList::elem;
      currentThis->next->data = tab[pos];

      currentThis = currentThis->next;
      this->end = currentThis;

      pos++;
    }
    this->end = currentThis;
    currentThis->next = nullptr;

    this->size = size;
  }
}
/* End builders */

/* Overloaded */
VectorList &VectorList::operator=(const VectorList& other)
{
    // Protect var = var
  if( this != &other )
  {
    VectorList::elem* currentThis = this->first;
    VectorList::elem* currentOther = other.first;

    while (currentOther)
    {
      currentThis->data = currentOther->data;
    }
  }

  return *this;
}

std::ostream &operator<<(std::ostream &flux, const VectorList& other)
{
  flux << "{ ";
  if (other.size)
  {
    VectorList::elem* current = other.first;
    while (current)
    {
      flux << current->data << ", ";
      current = current->next;
    }
    flux << other.end->data;
  }
  else
  {
    flux << "*empty*";
  }
  flux << " }";

  return flux;
}
/* End overloaded */

/* Destructor */
VectorList::~VectorList()
{

}
/* End destructor */
