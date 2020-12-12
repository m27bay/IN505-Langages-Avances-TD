#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "../Exo4/Point.hpp"

class Segment
{
  private :

    /* attributes */
    Point P, P2;

  public :

    /* Builders */
    Segment(int Px, int Py, int P2x, int P2y);
    Segment(const Point &_P, const Point &_P2);

    /* Destructor */
    ~Segment();

    /* Methods */
    float length();

    /* */
    void print();

    /* */
    bool isVertical();
    bool isHorizontal();
    bool isOnTheDiagonal();
};

#endif
