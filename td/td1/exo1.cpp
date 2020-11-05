#include <iostream>

void exo1Part1()
{
  std::cout << "\tPart1" << std::endl;

  /* Init */
  int* tabInt;
  int size(10);
  tabInt = new int[size];

  /* Fill */
  for (int i = 0; i < size; ++i)
  {
    tabInt[i] = i;
  }

  /* Print */
  std::cout << "without ptr : " << std::endl;
  for (int i = 0; i < size; ++i)
  {
    std::cout << tabInt[i] << " ";
  }

  std::cout << "\n";
  std::cout << "with ptr : " << std::endl;

  /* Init ptr */
  int* ptrTab = tabInt;

  /* Print */
  for (int i = 0; i < size; ++i)
  {
    std::cout << ptrTab[i] << " ";
  }

  std::cout << "\n";
  /* Free */
  delete[] tabInt;
}

void exo1Part2()
{
  std::cout << "\tPart2" << std::endl;

  /* Init */
  std::string* tab2;
  tab2 = new std::string[3];

  /* Fill */
  tab2[0] = "truc";
  tab2[1] = "machin";
  tab2[2] = "chose";

  /* Print */
  for (int i = 0; i < 3; ++i)
  {
    std::cout << tab2[i] << std::endl;
  }

  delete[] tab2;
}

void exo1()
{
  exo1Part1();
  std::cout << "\n";
  exo1Part2();
}

int main(int argc, char const *argv[])
{
  exo1();
  return 0;
}
