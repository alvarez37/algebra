#include <iostream>
#include <NTL/ZZ.h>
#include "ras_afin.h"

using namespace std;
using namespace NTL;

int main(){

  afin p1;
  string cifrado=p1.cifrado("hola");
  std::cout << "cifrado" << '\n';

  std::cout << cifrado << '\n';
  string descifrado=p1.cifrado(cifrado);

  std::cout << "descifrado" << '\n';
  std::cout << descifrado << '\n';

}
