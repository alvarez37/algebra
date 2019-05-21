#include <NTL/ZZ.h>

#include <iostream>
#include<vector>
using namespace std;
using namespace NTL;



ZZ digitos(ZZ a){
    ZZ dig(1);
    while(a/10>0)
    {
        a=a/10;
        dig++;
    }return dig;
}

ZZ MOD(ZZ a,ZZ b){
    ZZ r=a-(a/b)*b;
	if(r<0){
		r=r+b;
	}
	return r;
}
ZZ factor(ZZ numero){
	ZZ i(2);
	while(i<=numero)
	{
		if(MOD(numero,i)==0)  //a%b=0, implica que b es factor de a.
		{
			return i;
		}
		i++;  //Incrementamos indice.
	}
}

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



ZZ mcd(ZZ dividendo,ZZ divisor){
    ZZ residuo=MOD(dividendo,divisor);
    while(residuo>0){
        dividendo=divisor;
        divisor=residuo;
        residuo=MOD(dividendo,divisor);
    }
    return divisor;
}
//
// ZZ potencia(ZZ a, ZZ b){
//     ZZ r=b%2,acum=1,anterior=a,mult;
//     while(b!=0){
//         if(r!=0){
//             acum=anterior*acum;
//
//         }
//
//         mult=anterior*anterior;
//         anterior=mult;
//         b=b/2;
//         r=b%2;
//     }return acum;
// }
// ZZ potenciamod(ZZ a, ZZ b,ZZ n){
// 	long ZZ r=b%2,nuevomodu=1,modu=MOD(a,n),antmod=a;
// 	while(b!=0){
// 		//cout<<"modu "<<modu<<endl;
// 		//cout<<"r "<<r<<endl;
// 		if(r!=0){
// 			antmod=nuevomodu;
// 			nuevomodu=MOD((antmod*modu),n);
// 			//cout<<"modu "<<modu<<endl;
// 			//cout<<"antmod "<<antmod<<endl;
// 			//cout<<"nuevomod "<<nuevomodu<<endl;
// 		}
// 		modu=MOD(modu*modu,n);
// 		b=b/2;
// 		r=b%2;
// 	}return nuevomodu;
// }
//
int t_entero(ZZ number)
{
    int n;
    conv(n,number);
    return n;
}
ZZ multiplicacion_modular(ZZ a, ZZ b,ZZ mod)
{
    return modulo((modulo(a, mod) * modulo(b,mod)), mod);
}
ZZ potencia(ZZ a,ZZ b,ZZ mod)
{
    ZZ resultado = ZZ(1);
    while(b>0){
        if((b&1)==1){
            resultado = multiplicacion_modular(resultado,a,mod);
        }
        a=multiplicacion_modular(a,a,mod);
        b=b/2;
    }
    return resultado;
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

//
// ZZ resto_chino(vector<ZZ> a, vector<ZZ> p){
//     ZZ acum=1,acumsuma=0;
//     vector<ZZ>q,pes;
//     for(ZZ elemento:p){
//         acum=acum*elemento;
//     }
//     for(ZZ i=0;i<p.size();i++){
//         pes.push_back(acum/p[i]);
//         q.push_back(mod_inverso(acum/p[i],p[i]));
//     }
//
//     for(ZZ i=0;i<p.size();i++){
//
//         acumsuma=modulo(acumsuma+modulo((modulo(a[i],acum)*modulo(pes[i],acum)*modulo(q[i],acum)),acum),acum);
//     }
//
//
//
//     return acumsuma;
// }
