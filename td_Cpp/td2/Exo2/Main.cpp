#include <iostream>
#include <string.h>
#include "Vector.hpp"

void vectorTab()
{
  VectorTab v;
  std::cout << "v : " << v << std::endl;

  int tab[5] = { 1, 10, 2, 20, 3 };
  VectorTab v2(tab, 5);
  std::cout << "v2 : " << v2 << std::endl;

  VectorTab v3(10);
  std::cout << "v3 : " << v3 << std::endl;

  int tab2[3] = { 1, 2, 3 };
  VectorTab v4(tab2, 3);
  std::cout << "v4 : " << v4 << std::endl;

  VectorTab v5 = v4;
  std::cout << "v5 = v4 : " << v5 << std::endl;

  v3 += v2;
  std::cout << "v3 += v2 : " << v3 << std::endl;

  v4 += v5;
  std::cout << "v4 += v5 : " << v4 << std::endl;

  int tab3[3] = { 10, 20, 30 };
  VectorTab v7(tab3, 3);
  std::cout << "v7 : " << v7 << std::endl;
  v7 -= v4;
  std::cout << "v7 -= v4 : " << v7 << std::endl;

  int tab4[3] = { 1, 2, 4 };
  VectorTab v9(tab4, 3);
  std::cout << "v9 : " << v9 << std::endl;
  std::cout << "v9 < v4 ? " << (v9 < v4) << std::endl;

  std::cout << "v7 >= v4 ? " << (v7 >= v4 ) << std::endl;

  VectorTab v10;
  std::cin >> v10;
  std::cout << "v10 : " << v10 << std::endl;
}

void vectorList()
{
  VectorList v;
  std::cout << "v : " << v << std::endl;

  VectorList v2(0);
  std::cout << "v2 : " << v2 << std::endl;

  VectorList v2b(1);
  std::cout << "v2b : " << v2b << std::endl;

  int tab[1] = { 1 };
  VectorList v3(tab, 1);
  std::cout << "v3 : " << v3 << std::endl;

  int tab2[2] = { 1, 10 };
  VectorList v3b(tab2, 2);
  std::cout << "v3b : " << v3b << std::endl;

  int tab3[5] = { 1, 10, 2, 20, 3 };
  VectorList v3c(tab3, 5);
  std::cout << "v3c : " << v3c << std::endl;
}

int main(int argc, char const *argv[])
{
  if (argc == 1)
  {
    vectorTab();
    vectorList();
  }
  else if (!strcmp(argv[1], "vectorTab"))
  {
    vectorTab();
  }
  else if (!strcmp(argv[1], "vectorList"))
  {
    vectorList();
  }
  else if (!strcmp(argv[1], "help"))
  {
    std::cout << "Arg : " << std::endl;
    std::cout << "vectorTab : use vector with table" << std::endl;
    std::cout << "vectorList : use vector with linked list" << std::endl;
  }
  
  else
  {
    std::cout << "use : ./Main [arg]" << std::endl;
  }

  return 0;
}
