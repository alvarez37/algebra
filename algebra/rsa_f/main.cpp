#include <NTL/ZZ.h>
#include <iostream>
#include "rsa.h"

using namespace std;
using namespace NTL;

int main(){

  rsa p1;
  string texto="hola";
  string cifrado=p1.cifrado(texto);
  std::cout << "-------------------------" << '\n';
  std::cout << cifrado << '\n';
  //std::cout << p1.descifrado(cifrado) << '\n';

}
