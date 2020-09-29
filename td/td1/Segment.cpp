#include "Segment.hpp"
#include <cmath>

/* builders */
Segment::Segment(int Px, int Py, int P2x, int P2y)
{
  P = Point(Px, Py);
  P2 = Point(P2x, P2y);
}

Segment::Segment(const Point &_P, const Point &_P2)
{
  P = _P;
  P2 = _P2;
}
/* End builders */

/* Destructor */
Segment::~Segment()
{
  std::cout << "Destructor" << std::endl;
}
/* End destructor */

/* Methods */
float Segment::length()
{
  /* Convert in float */
  float diffX = P2.getX() - P.getX();
  float diffY = P2.getY() - P.getY();

  /* */
  return sqrt( pow(diffX, 2) + pow(diffY ,2) );
}

void Segment::print()
{
  P.print();
  P2.print();
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

