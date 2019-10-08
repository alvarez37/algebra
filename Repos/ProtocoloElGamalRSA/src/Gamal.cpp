#include "Gamal.h"

Gamal::Gamal(int bits)
{
    ZZ bits_2=RandomBits_ZZ(bits);
    p=bits_2;
    e_1=raiz_primitiva(p);
    r=ZZ(2)+RandomBnd(p-ZZ(4));
    d=ZZ(2)+RandomBnd(p-ZZ(4));
    e_2=potencia(e_1,d,p);
    cout<<"P: "<<p<<" "<<"e_1: "<<e_1<<" "<<"e_2: "<<e_2<<" "<<"r: "<<r<<" "<<"d: "<<d<<endl;
}

Gamal::Gamal(ZZ e1,ZZ e2,ZZ n_pub,ZZ d_p,ZZ r_p)
{
    e_1 = e1;
    e_2 = e2;
    p = n_pub;
    d = d_p;
    r = r_p;
}

string Gamal::cifrar(string mensaje){
    ZZ c_1 = potencia(e_1,r,p);
    ZZ Km = potencia(e_2,r,p);

    string digitos;
    for(int i = 0; i < mensaje.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(mensaje[i]));
        string nume = zzToString(to_ZZ(alfabeto.find(alfabeto[alfabeto.size()-1])));
        int num_pos = zzToString(pos).size();
        if(num_pos < nume.size()){
            digitos += "0";
            num_pos++;
        }
        digitos += zzToString(pos);
    }
    ZZ temp = to_ZZ(digitos.size());
    ZZ N_1 = to_ZZ(zzToString(p).size()-1);
    while(modulo(temp,N_1) != 0){
        int pos = alfabeto.find("w");
        digitos += zzToString(to_ZZ(pos));
        temp = to_ZZ(digitos.size());
    }
    string dig_2;
    for(int j = 0; j < digitos.size();){
        int temp = 0;
        string tempi;
        while(temp < to_int(N_1)){
            tempi += digitos[j];
            ++temp;
            ++j;
        }
        ZZ temp_2 = modulo(stringTozz(tempi)*Km,p);
        ZZ cont_num = to_ZZ(zzToString(temp_2).size());
        while(cont_num < zzToString(p).size()){
            dig_2 += "0";
            ++cont_num;
        }
        dig_2 += zzToString(temp_2);
    }
    int tama = zzToString(p).size()-zzToString(c_1).size();
    string cifrado(tama,'0');
    cifrado += zzToString(c_1);
    cifrado += dig_2;
    return cifrado;
}

string Gamal::descifrar(string mensaje){
    string C = mensaje.substr(0,zzToString(p).size());
    mensaje = mensaje.substr(zzToString(p).size());
    ZZ Km = potencia(stringTozz(C),d,p);
    string resultado;
    int num = (zzToString(p).size());
    for(int i = 0; i < mensaje.size();){
        int a = 0;
        string temp;
        while(a < num){
            a++;
            temp += mensaje[i];
            ++i;
        }
        ZZ valor = modulo(stringTozz(temp)*inversa(Km,p),p);
        int x = zzToString(valor).size();
        while(x < zzToString(p).size()-1){
            resultado += "0";
            ++x;
        }
        resultado += zzToString(valor);
    }
    string dig = zzToString(to_ZZ(alfabeto.size()-1));
    string rpta;
    for(int j = 0; j < resultado.size();){
        int s = 0;
        string tempi;
        while(s < dig.size()){
            tempi += resultado[j];
            ++s;
            ++j;
        }
        rpta += alfabeto[to_int(stringTozz(tempi))];
    }
    while(rpta[rpta.size()-1] == 'w'){
        rpta.erase(rpta.size()-1);
    }
    return rpta;
}
