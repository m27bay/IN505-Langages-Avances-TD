#include <iostream>

#include "Definition.hpp"

int main(void)
{
  std::cout << "#########################" << std::endl;

  /* */
  std::cout << "def1 : " << std::endl;
  Definition def1; // Call default builder
  def1.print();

  /* */
  std::cout << "def2 : " << std::endl;
  CString word("car");
  CString def("a road vehicle, [..].");
  Definition def2(word, def);
  def2.print();

  /* */
  std::cout << "def3 : " << std::endl;
  Definition def3("car", "a road vehicle, [..].");
  def3.print();

  return 0;
}
