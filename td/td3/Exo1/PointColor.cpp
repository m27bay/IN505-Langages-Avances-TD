#include "PointColor.hpp"
#include "string"

/* builders */
// Default
PointColor::PointColor() : P(), color("undefined") {}

// Copy
PointColor::PointColor(const PointColor& other)
{
  this->P = other.P; // With
  this->color = other.color;
}

PointColor::PointColor(double Px, double Py, std::string color)
{
  this->P = Point(Px, Py);
  this->color = color;
}

PointColor::PointColor(Point& P, std::string color)
{
  this->P = P; // with Point::operator=()
  this->color = color;
}
/* End builders */

/* Overloaded */
PointColor& PointColor::operator=(const PointColor& other)
{
  if(this != &other)
  {
    this->P = P; // with Point::operator=()
    this->color = color;
  }
  return *this;
}

std::ostream& operator<<(std::ostream &flux, const PointColor& other)
{
  flux << other.P << ", color : " << other.color;

  return flux;
}
/* end overloaded */

/* Destructor */
PointColor::~PointColor() {}
