#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <NTL/ZZ.h>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace NTL;
using namespace std;

    ZZ modulo(ZZ a, ZZ n);
    int modulo_int(int a, int n);
    ZZ euclides(ZZ a, ZZ b);
    ZZ mcd(ZZ a, ZZ b);
    vector <ZZ> extendido(ZZ , ZZ );
    ZZ inversa(ZZ a, ZZ alfabeto);
    ZZ potencia(ZZ a, ZZ b, ZZ modu);
    ZZ potenciaMod(ZZ n, ZZ m, ZZ mod);
    string zzToString(ZZ z);
    ZZ stringTozz(string str);
    string int_to_string(int s);
    int string_to_int(string s);
    ZZ int_ZZ(int n);
    int ZZ_int(ZZ n);
    vector<bool> ZZtoBinary(ZZ num);
    ZZ raiz_primitiva(ZZ p);
    ZZ generar_clave(ZZ);
    ZZ phi_euler(ZZ,ZZ);
    ZZ phi_euler_de_n(ZZ);
    string invertir(string);
    string bin(ZZ);
    bool millerTest_G(ZZ N, ZZ D);
    bool isPrime_G(ZZ N);


#endif // FUNCTIONS_H
