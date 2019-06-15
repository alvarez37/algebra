#include "RSA.h"

RSA::RSA()
{
    numero_p = generar_Aleatorio_Max(100);
    while(!comprobar_primo(numero_p)){
        ///cout <<"NEL ";
        numero_p = generar_Aleatorio_Max(100);
    }
    cout <<"A: "<<numero_p<<endl;
    numero_q = generar_Aleatorio_Max(100);
    while(!comprobar_primo(numero_q)){
        ///cout <<"NEL ";
        numero_q = generar_Aleatorio_Max(100);
    }
    cout <<"B: "<<numero_q<<endl;
    numero_n = numero_p * numero_q;
    cout <<" N : "<<numero_n<<endl;
    phi_n = phi_euler(numero_p, numero_q);
    cout <<" PHI-N :"<<phi_n<<endl;
    clave_publica_e = generar_Aleatorio_Max(phi_n);
    while(!comprobar_primo(clave_publica_e)){
        clave_publica_e = generar_Aleatorio_Max(phi_n);
    }
    cout <<" E :"<<clave_publica_e<<endl;
    clave_privada_d = inversa(clave_publica_e, phi_n);
    cout <<" D :"<<clave_privada_d<<endl;
    cout <<"-----RSA-------"<<endl;
    cout <<"Clave publica : <"<<clave_publica_e<<", "<<numero_n<<">"<<endl;
    cout <<"Clave privado : <"<<clave_privada_d<<", "<<numero_n<<">"<<endl;
}
RSA::RSA(int e, int n)
{
    numero_n = n;
    phi_n = phi_euler_chidori(n);
    clave_publica_e = e;
    clave_privada_d = inversa(clave_publica_e, phi_n);
    cout <<"-----RSA-------"<<endl;
    cout <<"Clave publica : <"<<clave_publica_e<<", "<<numero_n<<">"<<endl;
    cout <<"Clave privado : <"<<clave_privada_d<<", "<<numero_n<<">"<<endl;
}
int RSA::RSA_Encriptacion(int mensaje)
{
    /*int pos;
    for(int i = 0; i < mensaje.length(); i++){
        pos = alfabeto.find(mensaje[i]);;
        pos = exponenciacion_modular(pos,clave_publica_e,numero_n);
    }
    return mensaje_cifrado;*/
    return exponenciacion_modular(mensaje,clave_publica_e, numero_n);
}
int RSA::RSA_Desencriptacion(int mensaje_e)
{
    /*string mensaje_Descifrado;
    int pos;
    for(int i = 0; i < mensaje_e.length(); i++){
        pos = alfabeto.find(mensaje_e[i]);;
        pos = exponenciacion_modular(pos,clave_privada_d,numero_n);
        mensaje_Descifrado+=mensaje_e[pos];
    }
    return mensaje_Descifrado;*/
    return exponenciacion_modular(mensaje_e,clave_privada_d, numero_n);
}


