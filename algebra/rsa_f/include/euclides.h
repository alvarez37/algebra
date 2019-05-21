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
int t_entero(ZZ number)
{
    int n;
    conv(n,number);
    return n;
}

int string_a_int (string &tex_numero){
  int numero;
  string letra;
  int contador=0;
  int tam_string = tex_numero.size();
  for (int i = 0 ; tex_numero[i] != '-'; i++) {
    contador++;
    letra+=tex_numero[i];
  }
  numero = atoi(letra.c_str());
  tex_numero=tex_numero.substr(contador+1,tam_string);
  return numero;
}

ZZ elevar_n(int x, ZZ n,ZZ mod){
  ZZ n_result=n/2;
  ZZ x_result(x);

  ZZ result_cuadro;
  ZZ result_mod;

  ZZ zz_n(x);
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
