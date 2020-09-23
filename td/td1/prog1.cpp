#include <iostream> /* <- Classic library */

// Function
int sum(int a, int b)
{
  return a+b;
}

void sum2(int a, int b, int& res)
{
  res = a+b;
}

void printHelloWorld()
{
  /* cout = Print, endl = end of ligne */
  std::cout << "Hello world" << std::endl;
}

void firstManipVar()
{
  /* Init */
  int var(1); /* <=> int var = 1 */
  std::string str("bonjour");
  std::cout << "variable : " << var << std::endl;
  std::cout << "string : " << str << std::endl;

  /* Reference */
  int& ref(var);
  std::cout << "reference : " << ref << " => variable : " << var << std::endl;

  /* Ask a var */
  int varUser(0);
  std::cout << "Give me a number" << std::endl;
  std::cin >> varUser;
  std::cout << "varUser : " << varUser << std::endl;

  /**/
  std::cout << "1+1 = " << sum(1, 1) << std::endl;

  int a(1), b(1), tmp(0);
  int& res(tmp);
  sum2(a, b, res);
  std::cout << a << "+" << b << " = " << res << std::endl;
}

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
}

void exo1()
{
  exo1Part1();
  std::cout << "\n";
  exo1Part2();
}

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

void tabWrite( int* tabInt, int size )
{
  for (int i = 0; i < size; ++i)
  {
    tabInt[i]=i;
  }
}

void exo3()
{
  /* Init */
  int* tabInt;
  int size(10);
  tabInt = new int[size];

  /* Fill */
  for (int i = 0; i < size; ++i)
  {
    tabInt[i] = i*10;
  }

  /* Print */
  for (int i = 0; i < size; ++i)
  {
    std::cout << tabInt[i] << " ";
  }
  std::cout << "\n";
}

int main(int argc, char const *argv[])
{
  /*
  printHelloWorld();
  firstManipVar();
  */

  /*
  exo1();
  exo2();
  */

  exo3();

  return 0;
}
