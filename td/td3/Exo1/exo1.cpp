#include "PointColor.hpp"

int main(int argc, char const *argv[])
{
  Point P0;
  std::cout << "P0 : " << P0 << std::endl;

  Point P2(10.2, 46.3);
  std::cout << "P2 : " << P2 << std::endl;

  Point P3 = P2;
  std::cout << "P3 : " << P3 << std::endl;

  Point P4(4765, 64.15);
  std::cout << "P4 : " << P4 << std::endl;

  Point P5(P4);
  std::cout << "P5 : " << P5 << std::endl;

  PointColor P6;
  std::cout << "P6 : " << P6 << std::endl;

  PointColor P7(4566.3, 753.4, "green");
  std::cout << "P7 : " << P7 << std::endl;
  return 0;
}
