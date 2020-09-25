#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
  public :

    /* Builder */
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

  private :

    /* Attributes */
    int x, y;
};

#endif
