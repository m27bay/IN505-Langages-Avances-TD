#include "Forme.hpp"

int main(void)
{
  Point A;
  std::cout << "A : " << A << std::endl;

  Point B(1, 2);
  std::cout << "B : " << B << std::endl;

  Point C(2, 1);
  std::cout << "C : " << C << std::endl;

  Forme* BC = new Segment(B, C);
  std::cout << "BC : " << BC << std::endl;
  delete BC;

  return 0;
}
