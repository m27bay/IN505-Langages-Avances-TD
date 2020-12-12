#ifndef PointColor_HPP
#define PointColor_HPP

#include <iostream>
#include "Point.hpp"

class PointColor : public Point
{
  private :
    /* Attributs */
    Point P;
    std::string color;

  public :
    /* Builder */
    PointColor(); // Default
    PointColor(const PointColor&); // Copy
    PointColor(double Px, double Py, std::string color);
    PointColor(Point& P, std::string color);

    /* Overloaded */
    PointColor& operator=(const PointColor&);

    friend std::ostream& operator<<(std::ostream &flux, const PointColor&);

    /* Destructor */
    ~PointColor();
};

#endif
