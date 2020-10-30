#include "Point.hpp"

/* Builders */
// Default
Point::Point() : x(0), y(0) {}

// Copy
Point::Point(const Point &P) : x(P.x), y(P.y) {}
Point::Point(double Px, double Py) : x(Px), y(Py) {}
/* End builders */

/* Overloaded */
Point& Point::operator=(const Point& other)
{
  this->x = other.x;
  this->y = other.y;
}

std::ostream& operator<<(std::ostream &flux, const Point& other)
{
  flux << "(" << other.x << ";" << other.y << ")";
  return flux;
}
/* End overloaded */

/* Destructor */
Point::~Point() {}
/* End destructor */
