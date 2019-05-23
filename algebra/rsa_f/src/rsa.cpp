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

// rsa::rsa(ZZ a, ZZ b){
//
//
//
// }
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
  for (int i = 0;mensaje_con_0 [i] != '\0'; i++) {
    base= bloques_de_enteros(mensaje_con_0,ZZ(tam_array));
    base_por_exponete=elevar_a_la_potencia_n(base, e ,n);
    std::cout  << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
    txt_cifrado_retorno+=zz_a_string(base_por_exponete);
  }
  return txt_cifrado_retorno;
}


string rsa::descifrado(string txt){

  string txt_descifrado_retorno;
  int numero;
  int tam_array_entrada = txt.size();
  int base;
  ZZ base_por_exponete;
  int x;


  return txt_descifrado_retorno;
}

ZZ rsa::get_p(){return p;}
ZZ rsa::get_q(){return q;}
