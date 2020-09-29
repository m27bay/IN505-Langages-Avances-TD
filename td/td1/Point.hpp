#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
  private :

    /* Attributes */
    int x, y;

  public :

    /* Builders */
    Point();
    Point(int Px, int Py);
    Point(const Point &P);

    /* Destructor */
    ~Point();

    /* Getters */
    int getX();
    int getY();

    /* Methods */
    void print();
    void clone(const Point &P);
};

#endif
