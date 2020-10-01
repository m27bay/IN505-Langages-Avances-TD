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

int cstrlen(const char* str)
{
    if( str == NULL )
    {
        std::cout << "Error : null string" << std::endl;
        return -1;
    }
    int len = 0;
    while( str[len] != '\0' )
    {
        len++;
    }
    return len;
}

void cstrcpy(char* dest, const char* src)
{
    if( dest == NULL || src == NULL )
    {
        std::cout << "Error : null string" << std::endl;
    }
    dest = new char[ cstrlen(src) ];
    for( int i = 0; i <cstrlen(src); i++)
    {
        dest[i] = src[i];
    }
}

void test2()
{
  const char* str = "bonjour";
  int sizeStr = cstrlen(str);
  std::cout << sizeStr << std::endl;

  char* str2 = new char[sizeStr + cstrlen("ToutLeMonde")];
  cstrcpy(str, "ToutLeMonde");
  std::cout << str2 << std::endl;
}

/* End functions */

int main(int argc, char const *argv[])
{
  // printHelloWorld();
  // firstManipVar();

  // test();
  test2();

  return 0;
}
