#include <fstream>
#include <NTL/ZZ.h>
#include <iostream>
#include "rsa.h"
#include <stdlib.h>

using namespace std;
using namespace NTL;

string leertxt(string nombre){
     ifstream ficheroEntrada;
     string frase;
     ficheroEntrada.open ("doc1.txt");
     getline(ficheroEntrada, frase);
     ficheroEntrada.close();
     return frase;
}
void escribir_txt(string txt,string nombre){
  fstream ficheroEntrada;
  ficheroEntrada.open ("doc1.txt");
  string frase;
  ofstream fs(nombre.c_str(), ios::out);
  fs << txt << endl;
  fs.close();
}
 void escribir_txt2(string txt,string nombre){
   fstream ficheroEntrada;
   ficheroEntrada.open ("doc2.txt");
   string frase;
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
      string cifrado=p1.cifrado(texto);
      escribir_txt(cifrado,nombre1);
      std::cout << "-------gardado----------" << '\n';
    }
    if (intercambio==2) {
      string descifrado=p1.descifrado(leertxt(nombre1));
      escribir_txt2(descifrado,nombre2);

    }


  }


}
