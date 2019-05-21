#include "afin.h"
#include "euclides.h"

int afin::clave_a(){
    return a;
}

int afin::clave_b(){
    return b;
}

int afin::inversa(){
    return inversa_int;
}

int euclides(int a,int b){
   while(b!=0)
   {
       int t=b;
       b=a%b;
       a=t;
   }
   return a;
}


afin::afin(){

  tam_array=alf.size();
  srand(time(0));
	a = rand() % tam_array;
	b = rand() % tam_array;
	while (true) {
		if (euclides(a, tam_array) == 1) {
      break;
		}
		a = rand() % tam_array;
		}
	}

afin::afin(int m, int n) {
  tam_array=alf.size();

	a = m;
	b = n;
	inversa_int=euclidesExtendido(m,tam_array);
}



string afin::cifrado(string txt){
    string mensaje;
    int capturar;
    for(int i=0; i<txt.size(); i++) {
        capturar = modulo(alf.find(txt[i])*clave_a()+clave_b(),tam_array);
        mensaje += alf[capturar];
    }
    return mensaje;
}

string afin::descifrado(string txt) {
	string mensaje;
  int capturar;
    for(int i=0; i<txt.size(); i++) {
        capturar = modulo(inversa_int*(alf.find(txt[i])-b),tam_array);
        std::cout << "capturar :" << alf[capturar] << " " << capturar<< '\n';
        mensaje += alf[capturar];
    }
    return mensaje;

}
