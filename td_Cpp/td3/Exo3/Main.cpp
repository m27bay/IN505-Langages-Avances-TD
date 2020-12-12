#include "CList.hpp"

int main(void)
{
  CFile file;
  CList *ptList = &file;
  *ptList < 0;
  *ptList < 1;
  std::cout << "File : " << *ptList << std::endl;
  int i = 0;
  *ptList > &i;
  std::cout << "File : " << *ptList << " i=" << i << std::endl;

  CPile pile;
  ptList = &pile;
  *ptList < 0;
  *ptList < 1;
  std::cout << "Pile : " << *ptList << std::endl;
  *ptList > &i;
  std::cout << "Pile : " << *ptList << " i=" << i << std::endl;

  return 0;
}
