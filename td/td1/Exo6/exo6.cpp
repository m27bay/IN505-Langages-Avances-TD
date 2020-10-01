#include <iostream>
#include "CString.hpp"

int main(int argc, char const *argv[])
{
  /* Init */
  CString s1("toto"),
    s2('q'),
    s3 ;

  /* Print */
  s1.print();
  s2.print();
  s3.print();

  /* Test methodes */
  // /* Print the number of strings */
  std::cout << "Number of strings : " << s1.nbrStr() << std::endl;

  s3.setStr( s1.cstradd('w') );
  std::cout << "s3 = " << s3.getStr() << std::endl;
  s3.setStr( s3.cstradd('w') );
  std::cout << "s3 = " << s3.getStr() << std::endl;

  // s3 = s1.concat2('w');
  // std::cout << "s3 = " << s3.getStr() << std::endl;

  std::cout << "s3 > s2 ? " << s3.moreBigThan( s2.getStr() ) << std::endl;
  std::cout << "s3 <= s2 ? " << s3.lessOrEqual( s2.getStr() ) << std::endl;
  std::cout << "s3 > s2 ? " << s3.moreBig( s2.getStr() ) << std::endl;

  return 0;
}
