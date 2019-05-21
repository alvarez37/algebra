#ifndef AFIN_H
#define AFIN_H

#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std ;

class afin{

    public:
        afin();
        afin(int,int);
        int clave_a();
        int clave_b();
        int inversa();
        string cifrado(string);
        string descifrado(string);
    private:
        int tam_array;
        string alf="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
        int inversa_int;
        int a;
        int b;

};

#endif // AFIN_H
