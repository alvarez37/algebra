#include <NTL/ZZ.h>

#ifndef RAS_AFIN_H
#define RAS_AFIN_H

#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace NTL;

using namespace std ;

class afin{

    public:
        afin();
        afin(ZZ,ZZ);
        void generarClave();
        ZZ clave_a();
        ZZ clave_b();
        ZZ inversa();
        string cifrado(string);
        string descifrado(string);

    private:
        int bits=10;
        int tam_array;
        string alf="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
        ZZ inversa_ZZ;
        ZZ a;
        ZZ b;
        ZZ phi;
        ZZ e;
        ZZ d;
        ZZ n;
        ZZ alf_digitos;
        ZZ n_dig;

};


#endif // RAS_AFIN_H
