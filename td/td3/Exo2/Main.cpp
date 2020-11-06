#include "Forme.hpp"

int main(void)
{
  Point A;
  std::cout << "A : " << A << std::endl;

  Point B(1, 2);
  std::cout << "B : " << B << std::endl;

  Point C(2, 1);
  std::cout << "C : " << C << std::endl;

  Segment BC(B, C);
  std::cout << "BC : " << BC << std::endl;

  BC.move(4, 0);
  std::cout << "BC : " << BC << std::endl;

  Point D(10, 20);
  Point E(42, 4563.25);
  Segment DE(D, E);

  Rectangle BCDE(B, C, D, E);
  std::cout << "BCDE : " << BCDE << std::endl;
  
  BCDE.move(42.36, 453.32);
  std::cout << "BCDE : " << BCDE << std::endl;

  return 0;
}
