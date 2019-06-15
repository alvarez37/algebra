#include "rsa.h"
#include "euclides.h"

rsa::rsa(){
  tam_array=alf.size();
  bits=1024;
  q=GenPrime_ZZ(bits);
  p=GenPrime_ZZ(bits);
  n=p*q;
  phi_n=(p-1)*(q-1);

  e=GenPrime_ZZ(bits);
  while (true) {
    if (mcd(e,phi_n)==1) {
      break;
    }
    e=GenPrime_ZZ(bits);
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
  ZZ base;
  ZZ base_por_exponete;

  std::cout << "---------------------------------------------" << '\n';
  std::cout << mensaje_con_0 << '\n';
  std::cout << "---------------------------------------------" << '\n';
  for (int i=0; mensaje_con_0.size()>1 ;i++) {

    base= bloques_de_enteros(mensaje_con_0,n);
    base_por_exponete=elevar_a_la_potencia_n(base, e ,n);
    std::cout << "base " << base << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
    txt_cifrado_retorno+=zz_a_string(base_por_exponete);
  }
  std::cout << "---------------------------------------------" << '\n';

  return txt_cifrado_retorno;
}

string rsa::cifrado_ascii(string txt){
  //TODO: capturar los digitos de n
  n_string=zz_a_string(n);
  n_string_tam=n_string.size();

  string mensaje=copletar_ceros_ascii(txt);

  string txt_cifrado_retorno;

  ZZ base;
  ZZ base_por_exponete;
  std::cout << mensaje << '\n';
  for (int i=0;  mensaje.size() >1 ;i++) {
    base=bloques_de_enteros_atras(mensaje,n);
    base_por_exponete=elevar_a_la_potencia_n(base, e ,n);
    std::cout << "base " << base << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
    txt_cifrado_retorno.insert(0,zz_a_string(base_por_exponete));

  }
  std::cout << "---------------------------------------------" << '\n';
  std::cout << " txt_cifrado_retorno  " << txt_cifrado_retorno << '\n';
  return txt_cifrado_retorno;
}

string rsa::descifrado_ascii(string txt){
  //TODO: capturar los digitos de n
  n_string=zz_a_string(n);
  n_string_tam=n_string.size();

  string mensaje=txt;

  string txt_cifrado_retorno;
  string txt_descifrado_retorno;

  ZZ base;
  ZZ base_por_exponete;

  for (int i=0; mensaje.size()!=0 ;i++) {
    base=bloques_de_enteros_atras(mensaje,n);
    base_por_exponete=elevar_a_la_potencia_n(base, d ,n);
    std::cout << "base " << base << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
    txt_cifrado_retorno.insert(0,zz_a_string(base_por_exponete));

  }
  std::cout << "---------------------------------------------" << '\n';
  txt_descifrado_retorno = texto_de_salida_ascii( txt_cifrado_retorno );
  std::cout << "txt_cifrado_retorno " << txt_descifrado_retorno << '\n';
  return txt_descifrado_retorno;
}


string rsa::descifrado(string txt){
  string txt_descifrado_retorno;
  string txt_descifrado;

  ZZ base;
  ZZ base_por_exponete;

  for (int i=0; txt.size()>1 ;i++) {
    base= bloques_de_enteros(txt,n);
    base_por_exponete=restito(base,modulo(d,p-to_ZZ(1)),modulo(d,q-to_ZZ(1)),p,q);
    std::cout << "base " << base << " palabra_array [" << i << "] "<< base_por_exponete <<'\n';
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
