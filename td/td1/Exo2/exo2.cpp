#include <iostream>

void swap( int& a, int& b )
{
  std::cout << "swap" << std::endl;
  int tmp(a);
  a = b;
  b = tmp;
}

void exo2()
{
  int a(1), b(2);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
}

int main(int argc, char const *argv[])
{
  exo2();

  return 0;
}
