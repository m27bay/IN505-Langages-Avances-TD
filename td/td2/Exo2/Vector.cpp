#include <iostream>

#include "Vector.hpp"

/* Builders */
Vector::Vector()
{
  vector = NULL;
  numComponents = 0;
}

Vector::Vector(const Vector& other)
{

}

Vector::Vector(int size)
{

}

/* End builders */

/* Overloaded */
void Vector::Vector() const
{
  delete[] this->vector;
  this->vector = new int[ (this->numComponents = other.getNumComponents()) ];
  this->vector = other.getVector();
}

Vector Vector::operator+(const Vector& other)
{
  this->vector = new int[ (this->numComponents = other.getNumComponents()) ];
  return *this;
}

Vector Vector::operator-(const Vector& other)
{
  this->vector
}

/* End overloaded */

/* Destructor */
Vector::~Vector()
{
  delete[] vector;
}
