#include <fstream>
#include <NTL/ZZ.h>
#include <iostream>
#include "rsa.h"
#include <stdlib.h>
#include <string.h>

using namespace std;
using namespace NTL;

string leertxt(string nombre){

  string cadena;
  ifstream fe(nombre.c_str());
  while (!fe.eof()) {
    fe >> cadena;
    cout << cadena << endl;
  }
  return cadena;
  fe.close();
}


void escribir_txt(string txt,string nombre){

  ofstream fs(nombre.c_str(), ios::out);
  fs << txt << endl;
  fs.close();
}



int main(){

  string nombre1="doc1.txt";
  string nombre2="doc2.txt";
  string nombre3="doc3.txt";
  string nombre4="doc4.txt";
  string texto;
  rsa p1;
  int intercambio;

  while (true) {
    std::cout << "1 para cifrar " << '\n';
    std::cout << "2 para descifrado" << '\n';
    std::cin >> intercambio;
    if (intercambio==1) {
      std::cout << "que mensaje" << '\n';
      std::cin >> texto;
      // std::getline (std::cin,texto);
      // cin.ignore();

      string cifrado=p1.cifrado(texto);
      escribir_txt(cifrado,nombre1);
      std::cout << "-------gardado----------" << '\n';
    }
    if (intercambio==2) {
      string descifrado=p1.descifrado(leertxt(nombre1));
      escribir_txt(descifrado,nombre2);

    }

  }


}
