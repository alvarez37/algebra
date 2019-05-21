#ifndef RSA_H
#define RSA_H
#include <sstream>
#include <NTL/ZZ.h>
#include <iostream>
#include "string"
#include <cstdlib>

using namespace std;
using namespace NTL;

class rsa{
    public:

        rsa();
        ZZ get_p();
        ZZ get_q();
        string cifrado(string);
        string descifrado(string);


    private:
      string alf="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
      int tam_array;
      ZZ p;
      ZZ q;
      int bits;
      ZZ n;
      ZZ phi_n;
      ZZ e;
      ZZ d;

};

#endif // RSA_H
