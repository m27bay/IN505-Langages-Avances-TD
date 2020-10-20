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

  Vector v6 = (v3 + v2);
  std::cout << "Sum v3 + v2\nv6\n" << v6 << std::endl;

  int tab3[3] = { 10, 20, 30 };
  Vector v7(tab3, 3);
  std::cout << "v7\n" << v7 << std::endl;
  Vector v8 = ( v4 + v7 );
  std::cout << "Subtraction v4 - v7\nv8\n" << v8 << std::endl;

  return 0;
}
