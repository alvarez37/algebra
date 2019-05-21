#include "rsa.h"
#include "euclides.h"

rsa::rsa(){
  tam_array=alf.size();
  bits=10;
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
  string txt_cifrado;
  int tam_array_c = txt.size();
  int temp;
  ZZ temp_zz;
  int temp_n;
  string s;

  string zz_a_string =string (n);
  std::cout << zz_a_string << '\n';

  for (int i = 0; i < tam_array_c; i++) {
    temp= alf.find(txt[i]);
    temp_zz=elevar_n(temp, e ,n);
    temp_n=t_entero(temp_zz);
    s = static_cast<std::ostringstream*>(&(std::ostringstream() << temp_n))->str();
    std::cout << " palabra_array [" << i << "] "<< temp_n <<'\n';
    txt_cifrado+=s;

  }
  return txt_cifrado;
}








string rsa::descifrado(string txt){
  string txt_descifrado;
  int numero;
  int tam_array_c = txt.size();
  int temp;
  ZZ temp_zz;
  int temp_n;

  for (int i = 0; i < tam_array_c; i++) {
    numero= string_a_int(txt);
    temp_zz=elevar_n(numero, d ,n);
    temp_n=t_entero(temp_zz);
    txt_descifrado+=alf[temp_n];
    std::cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << txt_descifrado << '\n';
  }

  return txt_descifrado;
}

ZZ rsa::get_p(){return p;}
ZZ rsa::get_q(){return q;}
