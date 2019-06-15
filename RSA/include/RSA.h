#ifndef RSA_H
#define RSA_H
#include "Func2.h"



class RSA
{
    public:
        RSA();
        RSA(int,int);
        int RSA_Encriptacion(int);
        int RSA_Desencriptacion(int);
        int clave_publica_e;
        int get_phi(){return phi_n;}
    private:
        string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
        int numero_p;
        int numero_q;
        int numero_n;
        int phi_n;
        int clave_privada_d;

};

#endif // RSA_H
