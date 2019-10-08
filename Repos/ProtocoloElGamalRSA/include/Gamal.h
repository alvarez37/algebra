#ifndef GAMAL_H
#define GAMAL_H
#include <string>
#include "Functions.h"
#include <fstream>

class Gamal
{
private:
    ZZ p;
    ZZ d;
    ZZ e_1;
    ZZ e_2;
    ZZ r;
    string alfabeto = "0123456789abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    Gamal(int bits);
    Gamal(ZZ e1, ZZ e2, ZZ publica,ZZ,ZZ);
    string cifrar(string mensaje);
    string descifrar(string mensaje);
};

#endif // GAMAL_H
