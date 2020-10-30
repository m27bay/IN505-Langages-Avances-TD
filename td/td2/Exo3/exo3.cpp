#include "Dictionary.hpp"

int main(int argc, char const *argv[])
{
  Dictionary dico;
  std::cout << "dico : " << dico << std::endl;

  dico.addFirst("Motorcycle", "Vehicule with two wheels");
  std::cout << "dico : " << dico << std::endl;

  Dictionary dico2("Car", "Vehicule with four wheels");
  std::cout << "dico2 : " << dico2 << std::endl;

  dico2.addFirst("Boat", "Vehicule can be drive on the sea");
  std::cout << "dico2 : " << dico2 << std::endl;

  dico2.addEnd("Bicycle", "Like Motorcycle but without motor");
  std::cout << "dico2 : " << dico2 << std::endl;

  Dictionary dico3;
  dico3.addFirst("word2", "def2");
  dico3.addEnd("word3", "def3");
  dico3.addEnd("word5", "def5");
  std::cout << "dico3 : " << dico3 << std::endl;

  dico3.addIndex("word1", "def1", 0);
  std::cout << "dico3 : " << dico3 << std::endl;

  dico3.addIndex("word4", "def4", 3);
  std::cout << "dico3 : " << dico3 << std::endl;

  dico3.addIndex("word12", "def12", 11);
  std::cout << "dico3 : " << dico3 << std::endl;

  Dictionary dico4;
  dico4.addAlphabetize("Bicycle", "Like Motorcycle but without motor");
  std::cout << "dico4 : " << dico4 << std::endl;
  dico4.addAlphabetize("Airplane", "Vehicule with wings");
  std::cout << "dico4 : " << dico4 << std::endl;
  dico4.addAlphabetize("Motorcycle", "Vehicule with two wheels");
  std::cout << "dico4 : " << dico4 << std::endl;
  dico4.addAlphabetize("Car", "Vehicule with four wheels");
  std::cout << "dico4 : " << dico4 << std::endl;
  dico4.addAlphabetize("Boat", "Vehicule can be drive on the sea");
  std::cout << "dico4 : " << dico4 << std::endl;

  return 0;
}
