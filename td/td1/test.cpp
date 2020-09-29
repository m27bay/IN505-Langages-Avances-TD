#include <iostream> /* <- Classic library */

/* Functions */
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

void test()
{
  char* str = new char[1];
  str[0] = '\0';
  delete[] str;
}

/* End functions */

int main(int argc, char const *argv[])
{
  // printHelloWorld();
  // firstManipVar();

  test();

  return 0;
}
