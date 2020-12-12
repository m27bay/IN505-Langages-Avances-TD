#include "Forme.hpp"
#include <cmath>

/* Builders */
// Default
Point::Point() : x(0), y(0) {}
Forme::Forme() : points(nullptr), numPoints(0) {}
Segment::Segment()
{
  this->points = new Point[ this->numPoints = 2 ];
  this->points[0] = Point();
  this->points[1] = Point();
  this->size = length();
}

Rectangle::Rectangle()
{
  this->points = new Point[this->numPoints = 4];
  for(int i = 0; i < this->numPoints; ++i)
  {
    this->points[i] = Point();
  }
}

// Copy
Point::Point(const Point& P) : x(P.x), y(P.y) {}
Forme::Forme(const Forme& F)
{
  this->points = new Point[this->numPoints = F.numPoints];
  for(int i = 0; i < this->numPoints; ++i)
  {
    this->points[i] = F.points[i];
  }
}

Segment::Segment(const Segment& S) : Forme()
{
  this->points = new Point[this->numPoints = 2];
  this->points[0] = S.points[0]; this->points[1] = S.points[1];
  this->size = S.size;
}

Rectangle::Rectangle(const Rectangle &rect) : Forme()
{
  this->points = new Point[this->numPoints = 4];
  for (int i = 0; i < this->numPoints; ++i)
  {
    this->points[i] = rect.points[i];
  }
}

// With parameters
Point::Point(double Px, double Py) : x(Px), y(Py) {}
Forme::Forme(Point* points, int numPoints)
{
  this->points = points;
  this->numPoints = numPoints;
}

Segment::Segment(double Px, double Py, double P2x, double P2y)
{
  this->points = new Point[this->numPoints = 2];
  this->points[0] = Point(Px, Py); this->points[1] = Point(P2x, P2y);
  this->size = length();
}

Segment::Segment(const Point& P, const Point& P2)
{
  this->points = new Point[this->numPoints = 2];
  this->points[0] = P; this->points[1] = P2;
  this->size = length();
}

Rectangle::Rectangle(const Point &P, const Point &P2, const Point &P3, const Point &P4)
{
  this->points = new Point[this->numPoints = 4];
  this->points[0] = P;
  this->points[1] = P2;
  this->points[2] = P3;
  this->points[3] = P4;
}
/* End builders */

/* Overloaded */
Point& Point::operator=(const Point& other)
{
  if(this!=&other)
  {
    this->x = other.x;
    this->y = other.y;
  }
  return *this;
}

Forme& Forme::operator=(const Forme& other)
{
  if(this!=&other)
  {
    delete this->points;
    this->points = new Point[this->numPoints = other.numPoints];
    for (int i = 0; i < this->numPoints; ++i)
    {
      this->points[i] = other.points[i];
    }
  }
  return *this;
}

std::ostream& operator<<(std::ostream &flux, const Point& other)
{
  flux << "(" << other.x << ";" << other.y << ")";
  return flux;
}

std::ostream& operator<<(std::ostream& flux, const Forme& other)
{
  Point P;
  for (int i = 0; i < other.getNumPoint() - 1; ++i)
  {
    P = other.getPointsIndex(i);
    flux << P << ", ";
  }
  flux << other.getPointsIndex(other.getNumPoint() - 1);
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

int Forme::getNumPoint() const
{
  return this->numPoints;
}

Point* Forme::getPoints() const
{
  return this->points;
}

Point Forme::getPointsIndex(int index) const
{
  if(0 <= index && index < this->numPoints)
  {
    return this->points[index];
  }
  else
  {
    // std::cout << "ERROR : index '" << index << "' out of band" << std::endl;
    std::cout << "ERROR : index out of band" << std::endl;
    return Point();
  }
  
}
/* End getters */

/* Setters */
void Point::setX(double x)
{
  this->x = x;
}

void Point::setY(double y)
{
  this->y = y;
}
/* End setters */

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

void Forme::move(double dx, double dy)
{
  Point P;
  for(int i = 0; i < this->numPoints; ++i)
  {
    P = this->points[i];

    P.setX(P.getX() + dx);
    P.setY(P.getY() + dy);

    this->points[i] = P;
  }
}
/* End methods */

/* Destructor */
Point::~Point() {}
Forme::~Forme()
{
  delete this->points;
}
/* End destructor */
