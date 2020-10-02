#include <iostream>

#include "Definition.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "#########################" << std::endl;

  /* */
  std::cout << "Start def1" << std::endl;
  Definition def1 = Definition();
  def1.print();
  std::cout << "End def1" << std::endl;

  /* */
  std::cout << "Start def2" << std::endl;
  CString word = CString("car");
  CString def = CString("a road vehicle, [..].");
  Definition def2 = Definition(word, def);
  def2.print();
  std::cout << "End def2" << std::endl;

  /* */
  // Definition def3 = Definition("car", "a road vehicle, [..].");
  // def3.print();

  return 0;
}
