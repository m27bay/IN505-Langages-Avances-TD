#include <iostream>

void tabWritePos( int* tabInt, int size )
{
  std::cout << "Write position" << std::endl;

  /* Write position */
  for (int i = 0; i < size; ++i)
  {
    tabInt[i]=i;
  }
}

void tabRead( int tabInt[10] )
{
  std::cout << "Read tab" << std::endl;

  /* Read */
  for (int i = 0; i < 10; ++i)
  {
    std::cout << tabInt[i] << " ";
  }
  std::cout << "\n";
}

void exo3()
{
  /* Init */
  int* tabInt;
  int size(10);
  tabInt = new int[size];

  /* Fill */
  for (int i = 0; i < size; ++i)
  {
    tabInt[i] = i*10;
  }

  /* Print */
  for (int i = 0; i < size; ++i)
  {
    std::cout << tabInt[i] << " ";
  }
  std::cout << "\n";

  /* */
  tabWritePos(tabInt, size);

  /* Print */
  for (int i = 0; i < size; ++i)
  {
    std::cout << tabInt[i] << " ";
  }
  std::cout << "\n";

  /* */
  tabRead(tabInt);
}

int main(void)
{
  exo3();

  return 0;
}
