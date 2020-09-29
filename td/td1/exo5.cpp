#include <iostream>

#include "Segment.hpp"

int main(int argc, char const *argv[])
{
  Point A = Point(1, 1);
  Point B = Point(2, 2);
  Segment S = Segment(A, B);
  S.print();
  printf("length of S : %f\n", S.length());

  printf("%d\n", S.isVertical() );
  printf("%d\n", S.isHorizontal() );
  printf("%d\n", S.isOnTheDiagonal() );

  return 0;
}
