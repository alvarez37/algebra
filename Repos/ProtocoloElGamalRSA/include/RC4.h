#ifndef RC4_H
#define RC4_H

#include <vector>
#include <bitset>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Functions.h"

using namespace std;
using namespace sf;

class RC_4{
private:

public:
    RC_4();
    int S[256];
    int K[256];
    void swap_int(int,int);
    vector<int> Generar_Aleatorio(int);
    vector<int> Numero_Grande();
};

#endif // RC4_H
