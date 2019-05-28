#include <NTL/ZZ.h>
#include <iostream>
#include<vector>
using namespace std;
using namespace NTL;


ZZ modulo(ZZ a,ZZ tam_array){
  ZZ residuo;
  if (a<0) {
    residuo=a-((a/tam_array)-1)*tam_array;
  }

  else{
    residuo=a-(a/tam_array)*tam_array;
  }
  return residuo;
}

ZZ mcd(ZZ dividendo,ZZ divisor){
    ZZ residuo=modulo(dividendo,divisor);
    while(residuo>0){
        dividendo=divisor;
        divisor=residuo;
        residuo=modulo(dividendo,divisor);
    }
    return divisor;
}

ZZ mod_inverso(ZZ a,ZZ b){
    ZZ p0,p1(1),pn(0),q,cont(0),total;
    ZZ uno(1),cero(0);
	ZZ r=a,modin=b;
    if(modulo(a,b)==uno)
        return uno;
	if((modulo(b,a))==cero){return cero;}

	else{
        r=modulo(a,b);
        while(r>uno){
            cont=cont+uno;
            total=b;
            b=r;
            q=(total/b);
            r=modulo(total,b);
            pn=modulo((p0-p1*q),modin);
            p0=p1;
            p1=pn;
        }
        if(r!=uno){return cero;}
	}
	return pn;
}

ZZ euclidesExtendido(ZZ a, ZZ b) {
	ZZ r1 = a;
	ZZ r2 = b;
	ZZ s1 (0);
	ZZ s2 (0);
	ZZ t1 (0);
	ZZ t2 (1);
	ZZ s (0) ;
	ZZ t (0) ;
	while (r2 > 0) {
		ZZ q = r1 / r2;
		ZZ r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		s = s1 - q * s2;
		s1 = s2;
		s2 = s;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	s = s1;
	t = t1;
	return s;
}

int zz_a_entero(ZZ number)
{
    int n;
    conv(n,number);
    return n;
}

int string_a_entero (string tex_numero){
  int numero;
  string letra;
  numero = atoi(letra.c_str());
  return numero;
}

ZZ elevar_a_la_potencia_n(ZZ x, ZZ n,ZZ mod){
  ZZ n_result=n/2;
  ZZ x_result=x;

  ZZ result_cuadro;
  ZZ result_mod;

  ZZ zz_n=x;
  int x_mod2;

  while (n_result>0) {

      result_cuadro=modulo(zz_n*zz_n,mod);
      zz_n=result_cuadro;

      if (n_result%2==1) {
        result_mod=modulo(result_cuadro*x_result,mod);
        x_result=result_mod;
      }

      n_result=n_result/2;

  }

  return x_result;
}

string completar_ceros_string(string digitos,int y,int x) {
    string salida=digitos;
    for (int i = y; i < x; i++) {
        salida="0"+salida;
    }
    std::cout  <<"*************************************************************" <<salida;
    return salida;
  }


string entero_a_string(int x) {

    if (x==0) {
      return "00";
    }
    if (x<10) {
      return "0"+static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
    }
      return static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
  }

string string_a_string_numerico(string texto , string alf){
  string salida;

  for (size_t i = 0; texto[i] != '\0'; i++) {
    salida+=entero_a_string(alf.find(texto[i])+10);
  }

  return salida;
}

string zz_a_string(const ZZ &z) {
      std::stringstream buffer;
      buffer << z;
      return buffer.str();
  }

  ZZ string_a_zz(string message){
     NTL::ZZ number(NTL::INIT_VAL, message.c_str());
     return number;
   }

ZZ bloques_de_enteros(string &tex,ZZ n){
  ZZ numero;
  ZZ numero_de_salida;
  string numero_zz;
  int i;
  for ( i=0 ; numero < n and tex[i] != '\0' ; i++) {
    numero_zz+=tex[i];
    numero=string_a_zz(numero_zz);
    if (numero < n) {
      numero_de_salida=numero;
    }
  }
  std::cout << "-------------------------" << '\n';
  std::cout << " sin cortar " << tex <<'\n';

  if (i>0) {
    i--;
  }
  tex=tex.substr(i,tex.size());
  std::cout<< "numero de salida "<< numero_de_salida <<'\n';
  std::cout  << " cortado " << tex <<'\n';
  std::cout << "-------------------------" << '\n';


  return numero_de_salida;
}
