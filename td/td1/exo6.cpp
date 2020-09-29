#include <iostream>
#include "CString.hpp"

int main(int argc, char const *argv[])
{
  CString s1("toto"),
    s2('q'),
    s3 ;

  s1.print();
  s2.print();
  s3.print();

  // /* Print the number of strings */
  std::cout << "Number of strings : " << s1.nbrStr() << std::endl;

  s3 = s1.concat('w');
  // std::cout << "s3 = " << s3.getStr() << std::endl;

  return 0;
}
