#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>


using namespace std;

int modulo(int,int);
int euclides(int, int);
int inversa(int,int);
int generar_Aleatorio();
int generar_Aleatorio_Max(int);
bool comprobar_primo(int);
int multiplicacion_modular(int,int,int);
int exponenciacion_modular(int,int,int);
int phi_euler_primo(int,int);
int phi_euler_mult(int,int);
int phi_euler_exp(int,int, int);

#endif // FUNC_H
