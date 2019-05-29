#include "rsa.h"
#include "euclides.h"

rsa::rsa(){
  tam_array=alf.size();
  bits=5;
  RandomPrime(p,bits);
  RandomPrime(q,bits);
  n=p*q;
  phi_n=(p-1)*(q-1);
  RandomPrime(e,bits);

  while (mcd(e,phi_n)!=1) {
    RandomPrime(e,bits);
    }

  d= mod_inverso(e,phi_n);

  std::cout << "-------------------------"  << '\n';
  std::cout << "p: " << p << '\n';
  std::cout << "q: " << q << '\n';
  std::cout << "n: " << n << '\n';
  std::cout << "phi_n: " << phi_n << '\n';
  std::cout << "e: " << e << '\n';
  std::cout << "d: " << d << '\n';
  std::cout << "tam_array: " << tam_array << '\n';
  std::cout << "-------------------------" << '\n';

}





rsa::rsa(string e_, string n_){
  e=string_a_zz(e_);
  n=string_a_zz(n_);
  std::cout << "-------------------------"  << '\n';
  std::cout << "n: " << n << '\n';
  std::cout << "e: " << e << '\n';
  std::cout << "-------------------------" << '\n';

}
string rsa::cifrado(string txt){
  //TODO: capturar los digitos de n
  n_string=zz_a_string(n);
  n_string_tam=n_string.size();

  mensaje_con_0=string_a_string_numerico(txt,alf);

  string txt_cifrado_retorno;
  int tam_array_entrada = txt.size();
  ZZ base;
  ZZ base_por_exponete;
  std::cout << mensaje_con_0 << '\n';
  for (int i=0;1+tam_array_entrada > 0;i++) {
    base= bloques_de_enteros(mensaje_con_0,ZZ(n));
    base_por_exponete=elevar_a_la_potencia_n(base, e ,n);
    std::cout << "base " << base << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
    txt_cifrado_retorno+=zz_a_string(base_por_exponete);
    tam_array_entrada = mensaje_con_0.size();
    std::cout << tam_array_entrada << '\n';
  }
  return txt_cifrado_retorno;
}


string rsa::descifrado(string txt){
  string txt_descifrado_retorno;
  string txt_descifrado;

  int tam_array_entrada = txt.size();
  ZZ base;
  ZZ base_por_exponete;

  for (int i = 0;txt [i] != '\0'; i++) {
    base= bloques_de_enteros(txt,ZZ(n));
    base_por_exponete=elevar_a_la_potencia_n(base, d,n);
    std::cout  << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
    txt_descifrado_retorno+=zz_a_string(base_por_exponete);
  }
  std::cout << "numero  " << txt_descifrado_retorno<< '\n';
  for (int i = 0; i < txt_descifrado_retorno.size()-1; i+=2) {
    int j = txt_descifrado_retorno[i] - '0';
    j*=10;
    int e = txt_descifrado_retorno[i+1] - '0';
    int f=j+e-10;
    std::cout << i<<" " <<alf[f] << '\n';
    txt_descifrado +=alf[f];
  }
  return txt_descifrado;
}

ZZ rsa::get_p(){return p;}
ZZ rsa::get_q(){return q;}
string rsa::get_n(){return zz_a_string(n);}
string rsa::get_e(){return zz_a_string(e);}
