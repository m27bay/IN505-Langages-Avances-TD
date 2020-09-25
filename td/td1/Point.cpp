#include "Point.hpp"

/* Builders */
Point::Point()
{
  x = 0, y = 0;
}

Point::Point(int Px, int Py)
{
  x = Px, y = Py;
}

Point::Point(const Point &P)
{
  x = P.x;
  y = P.y;
}
/* End builders */

/* Destructor */
Point::~Point()
{
  std::cout << "Destructor" << std::endl;
}
/* End destructor */

/* Getters */
int Point::getX()
{
  return x;
}

int Point::getY()
{
  return y;
}
/* End getters */

/* Methods */
void Point::print()
{
  std::cout << "Point (" << x << ";" << y << ")" << std::endl;
}

void Point::clone(const Point &P)
{
  std::cout << "Clone" << std::endl;
  x = P.x, y = P.y;
}
/* End methods */
