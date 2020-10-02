#include <iostream>

#include "Definition.hpp"

int main(int argc, char const *argv[])
{
  std::cout << "#########################" << std::endl;

  /* */
  Definition def1; // Default builder
  def1.print();

  /* */
  CString word("car");
  CString def("a road vehicle, [..].");
  Definition def2(word, def);
  def2.print();

  /* */
  // Definition def3("car", "a road vehicle, [..].");
  // def3.print();

  return 0;
}
