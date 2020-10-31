#include "Forme.hpp"
#include <cmath>

/* Builders */
// Default
Point::Point() : x(0), y(0) {}
Segment::Segment()
{
  this->points = new Point[ this->numPoints = 2 ];
  this->points[0]; this->points[1];
  this->size = length();
}
Forme::Forme() : points(nullptr), numPoints(0) {}

// Copy
Point::Point(const Point& P) : x(P.x), y(P.y) {}
Segment::Segment(const Segment& S)
{
  this->points = new Point[ (this->numPoints = 2) ];
  this->points[0] = S.points[0]; this->points[1] = S.points[1];
  this->size = S.size;
}

// With parameters
Point::Point(double Px, double Py) : x(Px), y(Py) {}
Segment::Segment(double Px, double Py, double P2x, double P2y)
{
  this->points = new Point[ (this->numPoints = 2) ];
  this->points[0] = Point(Px, Py); this->points[1] = Point(P2x, P2y);
  this->size = length();
}

Segment::Segment(const Point& P, const Point& P2)
{
  this->points = new Point[ (this->numPoints = 2) ];
  this->points[0] = P; this->points[1] = P2;
  this->size = length();
}
/* End builders */

/* Overloaded */
Point& Point::operator=(const Point& other)
{
  this->x = other.x;
  this->y = other.y;
}

Segment& Segment::operator=(const Segment& other)
{
  delete this->points;
  this->points = new Point[ this->numPoints = 2 ];
  this->points[0] = other.points[0]; this->points[1] = other.points[1];
  this->size = other.size;
}

std::ostream& operator<<(std::ostream &flux, const Point& other)
{
  flux << "(" << other.x << ";" << other.y << ")";
  return flux;
}

std::ostream& operator<<(std::ostream& flux, const Segment& other)
{
  flux << other.points[0] << ", " << other.points[1];

  return flux;
}
/* End overloaded */

/* Getters */
double Point::getX() const
{
  return this->x;
}

double Point::getY() const
{
  return this->y;
}
/* End getters */

/* Methods */
float Segment::length()
{
  /* Convert in float */
  float diffX = this->points[1].getX() - this->points[0].getX();
  float diffY = this->points[1].getY() - this->points[0].getY();

  /* */
  return sqrt( pow(diffX, 2) + pow(diffY ,2) );
}

bool Segment::isVertical()
{
  return (this->points[0].getX() == this->points[1].getX());
}

bool Segment::isHorizontal()
{
  return (this->points[0].getY() == this->points[1].getY());
}

bool Segment::isOnTheDiagonal()
{
  float diffX = this->points[1].getX() - this->points[0].getX();
  float diffY = this->points[1].getY() - this->points[0].getY();
  float m = diffX / diffY;

  return (m == 1);
}
/* End methods */

/* Destructor */
Point::~Point() {}
Segment::~Segment()
{
  delete this->points;
}
Forme::~Forme()
{
  delete this->points;
}
/* End destructor */
