#include "CList.hpp"

int main(void)
{
  CPile pile;
  CFile file;

  CList *ptList = &file;
  *ptList < 0;
  *ptList < 1;
  std::cout << "File : " << *ptList << std::endl;
  
  int i = 0;
  *ptList > i;
  std::cout << *ptList << " i=" << i << std::endl;

  ptList = &pile;
  *ptList < 0;
  *ptList < 1;
  std::cout << "Pile : " << *ptList << std::endl;
  *ptList > i;
  std::cout << *ptList << " i=" << i << std::endl;

  return 0;
}
