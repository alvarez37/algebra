#include <math.h>
#include <iostream>
using namespace std;

int main() {
  int primorsa;
  std::cout << "incresa un numero primo\n";
  std::cin >> primorsa;

  primorsa = sqrt(primorsa);

  std::cout << primorsa++ << '\n';
  std::cout << primorsa*primorsa << '\n';


  return 0;
}
