#include <iostream>
#include "CString.hpp"

int main(void)
{
  std::cout << "########################" << std::endl;
  /* Init */
  CString s1("toto");
  CString s2('q');
  CString s3; // Default builder

  CString s4("Bonjour");

  /* Print */
  s1.print();
  s2.print();
  s3.print();

  s4.print();

  /* Test methodes */
  std::cout << "Number of strings : " << s1.getNbrStr() << std::endl;

  s3 = s1.cstradd('w');
  // std::cout << "s3 = " << s3.getStr() << std::endl;
  s3.print();
  // s3 = s2.cstradd('w');
  // s3.print();

  // s3 = str.cstradd('A');
  // s3.print();

  // s3 = s1.cstradd('w');
  // s3.print();

  std::cout << "s3 > s2 ? " << s3.moreBigThan( s2.getStr() ) << std::endl;
  std::cout << "s3 <= s2 ? " << s3.lessOrEqual( s2.getStr() ) << std::endl;
  // std::cout << "s3 > s2 ? " << s3.moreBig( s2.getStr() ) << std::endl;

  std::cout << "s5 = totoq ? ";
  CString s5 = s1 + s2;
  s5.print();

  std::cout << "s6 = bonjour ? ";
  CString s6 = s4;
  s6.print();
  std::cout << s6 << std::endl;

  std::cout << (s3 > s2) << std::endl;
  std::cout << (s3 <= s2) << std::endl;

  return 0;
}
