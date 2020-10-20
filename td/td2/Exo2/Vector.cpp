#include <iostream>

#include "Vector.hpp"

/* Builders */
Vector::Vector()
{
  tab = NULL;
  size = 0;
}

Vector::Vector(const Vector& other)
{
  this->tab = new int[ (this->size = other.size) ];

  for (int i = 0; i < this->size; ++i)
  {
    this->tab[i] = other.tab[i];
  }
}

Vector::Vector(int* tab, int size)
{
  this->tab = new int[ (this->size = size) ];

  for (int i = 0; i < this->size; ++i)
  {
    this->tab[i] = tab[i];
  }
}

Vector::Vector(int size)
{
  this->tab = new int[ (this->size = size) ];
  for (int i = 0; i < this->size; ++i)
  {
    this->tab[i] = 0;
  }
}

/* End builders */

/* Overloaded */
Vector &Vector::operator=(const Vector &other)
{
  if( this != &other )
  {
    int* newTab = new int[this->size = other.size];

    for (int i = 0; i < this->size; ++i)
    {
      newTab[i] = this->tab[i];
    }

    delete[] tab;

    this->tab = newTab;
  }

  return *this;
}

Vector &Vector::operator+=(const Vector &other)
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

Vector &Vector::operator-=(const Vector &other)
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

bool Vector::operator<(const Vector &other)
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

bool Vector::operator<=(const Vector &other)
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

bool Vector::operator>(const Vector &other)
{
  return !(*this > other);
}

bool Vector::operator>=(const Vector &other)
{
  return !(*this >= other);
}

int Vector::operator[](const int index)
{
  if (index > this->size)
  {
    std::cout << "Index out of bound" << std::endl;
    return -1;
  }

  return this->tab[index];
}

std::ostream &operator<<(std::ostream &flux, const Vector &other)
{
  flux << "Vector : " << std::endl;

  flux << "{ ";
  for (int i = 0; i < other.size - 1; ++i)
  {
    flux << other.tab[i] << ", ";
  }
  flux << other.tab[ other.size -1 ];
  flux << " }\n";

  return flux;
}

std::istream &operator>>(std::istream &flux, Vector &other)
{
  int* newTab;
  delete [] other.tab;

  std::cout << "size = ? ";
  flux >> other.size;
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

  return flux;
}

/* End overloaded */

/* Destructor */
Vector::~Vector()
{
  delete[] tab;
}
