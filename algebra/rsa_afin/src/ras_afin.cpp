#include "ras_afin.h"
#include "euclides.h"

ZZ afin::clave_a(){
    return a;
}

ZZ afin::clave_b(){
    return b;
}

ZZ afin::inversa(){
    return inversa_ZZ;
}

ZZ euclides(ZZ a,ZZ b){
   while(b!=0)
   {
       ZZ t=b;
       b=a%b;
       a=t;
   }
   return a;
}


afin::afin(){

  generarClave();
  tam_array=alf.size();

	}

  void afin::generarClave(){
      RandomPrime(a,bits);
      RandomPrime(b,bits);

      n=a*b;
      phi=(a-1)*(b-1);

      //e=65537;
      RandomPrime(e,bits-1);
      while(mcd(e,phi)!=1){
        RandomPrime(e,bits-1);
      }

      d=mod_inverso(e,n);

      std::cout << phi << '\n';
      std::cout << "clave_a: " << a << " " << b << " :clave_b " <<'\n';
      std::cout <<"clave publica: "<<e<<" N: "<<n<<" d: "<<d<<endl;
  }


  afin::afin(ZZ publi, ZZ ene){


      n=ene;
      phi=factor(ene);

      e=publi;
      d=mod_inverso(e,phi);

      cout <<"-----RSA-------"<<endl;
      cout <<"Clave publica : <"<<e<<", "<<n<<">"<<endl;
      cout <<"Clave privado : <"<<d<<", "<<n<<">"<<endl;
  }


  string afin::cifrado(string mensaje){
      string mensaje_encriptado;
      int tem;
      for( int i=0;i<mensaje.size();i++){
          tem=alf.find(mensaje[i]);
          ZZ tem_zz = potencia(ZZ(tem),e,n);
          tem_zz=modulo(tem_zz,ZZ(tam_array));
          tem=t_entero(tem_zz);
          mensaje_encriptado+=alf[tem];
      }
      return mensaje_encriptado;
  }
  string afin::descifrado(string mensaje_encriptado){
      string mensaje_desencriptado;
      int tem;
      for( int i=0;i<mensaje_encriptado.size();i++){
          tem=alf.find(mensaje_encriptado[i]);
          ZZ tem_zz = potencia(ZZ(tem),d,n);
          tem_zz=modulo(tem_zz,ZZ(tam_array));
          tem=t_entero(tem_zz);
          mensaje_desencriptado+=alf[tem];
      }
      return mensaje_desencriptado;
  }
