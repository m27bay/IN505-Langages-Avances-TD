#include "Forme.hpp"
#include <cmath>

/* Builders */
// Default
Point::Point() : x(0), y(0) {}
Segment::Segment() : P()

// Copy
Point::Point(const Point& P) : x(P.x), y(P.y) {}
Segment::Segment(const Segment& S) : this->P(P), this->P2(P2)

// With parameters
Point::Point(double Px, double Py) : x(Px), y(Py) {}
Segment::Segment(int Px, int Py, int P2x, int P2y) : P(Px, Py), P2(P2x, P2y) {}
Segment::Segment(const Point& P, const Point& P2) : this->P(P), this->P2(P2) {}
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

std::ostream& operator<<(std::ostream& flux, const Segment&)
{
  flux << P << ", " << P2;

  return flux;
}
/* End overloaded */


/* Methods */
float Segment::length()
{
  /* Convert in float */
  float diffX = P2.getX() - P.getX();
  float diffY = P2.getY() - P.getY();

  /* */
  return sqrt( pow(diffX, 2) + pow(diffY ,2) );
}

bool Segment::isVertical()
{
  return (P.getX() == P2.getX());
}

bool Segment::isHorizontal()
{
  return (P.getY() == P2.getY());
}

bool Segment::isOnTheDiagonal()
{
  float diffX = P2.getX() - P.getX();
  float diffY = P2.getY() - P.getY();
  float m = diffX / diffY;

  return (m == 1);
}
/* End methods */

/* Destructor */
Point::~Point() {}
Segment::~Segment() {}
/* End destructor */
