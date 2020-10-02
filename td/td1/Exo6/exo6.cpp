#include <iostream>
#include "CString.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "########################" << std::endl;
  /* Init */
  CString s1("toto");
  CString s2('q');
  CString s3; // Default builder

  CString str("Bonjour");

  /* Print */
  s1.print();
  s2.print();
  s3.print();

  str.print();

  /* Test methodes */
  std::cout << "Number of strings : " << s1.nbrStr() << std::endl;

  s3 = s1.cstradd('w');
  // std::cout << "s3 = " << s3.getStr() << std::endl;
  // s3.print();
  // s3 = s2.cstradd('w');
  // s3.print();

  // s3 = str.cstradd('A');
  // s3.print();

  // s3 = s1.cstradd('w');
  // s3.print();

  // std::cout << "s3 > s2 ? " << s3.moreBigThan( s2.getStr() ) << std::endl;
  // std::cout << "s3 <= s2 ? " << s3.lessOrEqual( s2.getStr() ) << std::endl;
  // std::cout << "s3 > s2 ? " << s3.moreBig( s2.getStr() ) << std::endl;

  return 0;
}
