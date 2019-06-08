#include <fstream>
#include <NTL/ZZ.h>
#include <iostream>
#include "rsa.h"
#include <stdlib.h>
#include <string.h>
// HOLA NEL
using namespace std;
using namespace NTL;

string leertxt(string documento){

  string cadena;
  ifstream fe(documento.c_str());
  while (!fe.eof()) {
    fe >> cadena;
    cout << cadena << endl;
  }
  return cadena;
  fe.close();
}


void escribir_txt(string txt,string documento){

  ofstream fs(documento.c_str(), ios::out);
  fs << txt << endl;
  fs.close();
}



int main(){

  string documento1="doc1.txt";
  string documento2="doc2.txt";
  string documento3="doc3.txt";
  string documento4="doc4.txt";
  string texto;
  int intercambio;
  rsa emisor;
  escribir_txt("n: "+emisor.get_n()+" e: "+emisor.get_e(),documento3);

  while (true) {
    std::cout << "1 para cifrar emisor" << '\n';
    std::cout << "2 para descifrado emisor" << '\n';
    std::cout << "3 para cifrar reseptor" << '\n';
    std::cin >> intercambio;

    switch (intercambio) {
      case 1: {std::cout << "que mensaje" << '\n';
               cin.ignore();
               getline(cin, texto);
              string cifrado=emisor.cifrado(texto);
              escribir_txt(cifrado,documento1);
              std::cout << "-------gardado----------" << '\n';
              break;}
      case 2:  {string descifrado=emisor.descifrado(leertxt(documento1));
               escribir_txt(descifrado,documento2);
               break;}
      case 3:   {string e=leertxt(documento3);
                string n=leertxt(documento4);

                rsa reseptor(e,n);
                std::cout << "que mensaje" << '\n';
                cin.ignore();
                 std::getline (std::cin,texto);

                string descifrado_reseptor=reseptor.cifrado(texto);
                escribir_txt(descifrado_reseptor,documento1);
                break;}
    }
  }

  return 0;
}
