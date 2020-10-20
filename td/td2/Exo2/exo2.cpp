#include <iostream>
#include "Vector.hpp"

int main(int argc, char const *argv[])
{
  Vector v;

  int tab[5] = { 1, 10, 2, 20, 3 };
  Vector v2(tab, 5);
  std::cout << "v2\n" << v2 << std::endl;

  Vector v3(10);
  std::cout << "v3\n" << v3 << std::endl;

  int tab2[3] = { 1, 2, 3 };
  Vector v4(tab2, 3);
  Vector v5 = v4;
  std::cout << "v4\n" << v4 << std::endl;
  std::cout << "Assignment of v4\nv5\n" << v5 << std::endl;

  v3 += v2;
  std::cout << "v3 += v2\n" << v3 << std::endl;

  v4 += v5;
  std::cout << "v4 += v5\n" << v4 << std::endl;

  int tab3[3] = { 10, 20, 30 };
  Vector v7(tab3, 3);
  std::cout << "v7\n" << v7 << std::endl;
  v7 -= v4;
  std::cout << "v7 -= v4\n" << v7 << std::endl;

  int tab4[3] = { 1, 2, 4 };
  Vector v9(tab4, 3);
  std::cout << "v9\n" << v9 << std::endl;
  std::cout << "v9 < v4 ? " << (v9 < v4) << std::endl;

  std::cout << "v7 >= v4 ? " << (v7 >= v4 ) << std::endl;
  return 0;
}
