#include <iostream>

#include "Segment.hpp"

int main(void)
{
  Point A = Point(1, 1);
  Point B = Point(2, 2);
  Segment S = Segment(A, B);
  S.print();
  printf("length of S : %f\n", S.length());

  std::cout << ( S.isVertical() ? "true" : "false" ) << std::endl;
  std::cout << ( S.isHorizontal() ? "true" : "false" ) << std::endl;
  std::cout << S.isOnTheDiagonal() << std::endl;

  return 0;
}
