#ifndef RSA_H
#define RSA_H

#include "Functions.h"

class RSA
{
    private:
        ZZ p;
        ZZ q;
        ZZ n;
        ZZ phi_n;
        ZZ e;
        ZZ d;
        ZZ n_ext;
        ZZ e_ext;
    public:
        string alfabeto = "         ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        //string alfabeto = "abcdefghijklmnopqrstuvwxyz";
        RSA(int bits);
        RSA(ZZ,ZZ,ZZ,ZZ);
        ZZ Resto_Chino(ZZ );
        string cifrado(string);
        string descifrado(string);
        void impr_claves(void);
        string orden_1(int);
        string orden_2(ZZ,ZZ);
        string orden_3(ZZ,ZZ);
        void getdata();
};

#endif // RSA_H
