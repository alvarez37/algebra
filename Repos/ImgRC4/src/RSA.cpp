#include "RSA.h"

ZZ RSA::Resto_Chino(ZZ num){
    ZZ d1 = modulo(d,p-1);
    ZZ d2 = modulo(d,q-1);
    ZZ D1 = modulo(num,p);
    D1 = potencia(D1,d1,p);
    ZZ D2 = modulo(num,q);
    D2 = potencia(D2,d2,q);
    ZZ P = p*q;
    ZZ P1 = P/p;
    ZZ P2 = P/q;
    ZZ Q1 = inversa(P1,p);
    ZZ Q2 = inversa(P2,q);
    ZZ resultado = modulo(D1 * P1 * Q1,P);
    resultado += modulo(D2 * P2 * Q2,P);
    resultado = modulo(resultado,P);
    return resultado;
}

string RSA::orden_1(int a){
    string tmp=int_to_string(a);
    string tmp_1=int_to_string(alfabeto.size());
    while(tmp.size()<tmp_1.size()){
        tmp='0'+tmp;
    }
    return tmp;
}
string RSA::orden_2(ZZ a,ZZ n){
    string tmp=zzToString(a);
    string tmp_1=zzToString(n);
    while(tmp.size()<tmp_1.size()){
        tmp='0'+tmp;
    }
    return tmp;
}

string RSA::orden_3(ZZ a,ZZ n){
    string tmp=zzToString(a);
    string tmp_1=zzToString(n);
    while(tmp.size()<(tmp_1.size()-1)){
        tmp='0'+tmp;
    }
    return tmp;
}

void RSA::getdata(){
    cout<<e<<" "<<d<<" "<<n<<" "<<p<<" "<<q<<endl;
}


RSA::RSA(int bits){
    p=RandomBits_ZZ(bits);
    while((ProbPrime(p))!=1){
        p=RandomBits_ZZ(bits);
    }
    cout<<p<<endl;
    q=RandomBits_ZZ(bits);
    while((ProbPrime(q))!=1){
        q=RandomBits_ZZ(bits);
    }
    cout<<q<<endl;
    n=p*q;
    cout <<"N : "<<n<<endl;
    phi_n = phi_euler(p, q);
    cout<<"Phi : "<<phi_n<<endl;

    e = RandomBits_ZZ(bits);
    while(euclides(e,phi_n)!=1){
        e = RandomBits_ZZ(bits);
    }
    cout <<"E : "<<e<<endl;
    d = inversa(e, phi_n);
    cout <<"D : "<<d<<endl;
    cout <<"Clave publica : <"<<e<<" , "<<n<<">"<<endl;
    cout <<"Clave privado : <"<<d<<" , "<<n<<">"<<endl;
    d=conv<ZZ>("26791");
    n=conv<ZZ>("41693");
    p=conv<ZZ>("241");
    q=conv<ZZ>("173");
    n_ext=conv<ZZ>("41693");
    e_ext=conv<ZZ>("151");
}

RSA::RSA(ZZ e_receptor,ZZ n_receptor,ZZ mi_de,ZZ mi_ene){
    e_ext=e_receptor;
    n_ext=n_receptor;
    d=mi_de;
    n=mi_ene;
}

string RSA::cifrado(string mensaje){
    string bloques;
    string letras;
    int bloquesNext=zzToString(n_ext).size();
    int bloquesN=zzToString(n).size();
    ZZ res1;
    ZZ resrubrub;
    ZZ resign;
    for(int i=0;i<mensaje.size();i++){
        letras+=orden_1(alfabeto.find(mensaje[i]));
    }
    //cifrado
    letras.append(conv<int>(ZZ(bloquesNext-1)-modulo(ZZ(letras.size()),ZZ(bloquesNext-1))),'2');
    for(int i=0;i<letras.size();i+=bloquesNext-1){
        res1=potencia(stringTozz(letras.substr(i,bloquesNext-1)),e_ext,n_ext);
        bloques+=orden_2(res1,n_ext);
    }
    if(ZZ(bloques.size()&1)!=ZZ(0)){
        bloques+='2';
    }
    //rubrica
    string rub;
    bloques.append(conv<int>(ZZ(bloquesN-1)-modulo(ZZ(bloques.size()),ZZ(bloquesN-1))),'2');
    for(int i=0;i<bloques.size();i+=bloquesN-1){
        resrubrub=potencia(stringTozz(bloques.substr(i,bloquesN-1)),d,n);
        rub+=orden_2(resrubrub,n);
    }
    if(ZZ(rub.size()&1)!=ZZ(0)){
        rub+='2';
    }
    //firma
    string sign;
    rub.append(conv<int>(ZZ(bloquesNext-1)-modulo(ZZ(rub.size()),ZZ(bloquesNext-1))),'2');
    for(int i=0;i<rub.size();i+=bloquesNext-1){
        resign=potencia(stringTozz(rub.substr(i,bloquesNext-1)),e_ext,n_ext);
        sign+=orden_2(resign,n_ext);
    }
    return sign;
}
string RSA::descifrado(string a){
    string mensaje;
    string bloques;
    string rub;
    string sign;

    int bloquesN=zzToString(n).size();
    int bloquesNext=zzToString(n_ext).size();

    ZZ res1;
    ZZ resrubrub;
    ZZ resign;
    if(ZZ(a.size()&1)!=ZZ(0)){
        a+='2';
    }
    a.append(conv<int>(ZZ(bloquesN)-modulo(ZZ(a.size()),ZZ(bloquesN))),'2');
    for(int i=0;i<a.size();i+=bloquesN){
        resign=Resto_Chino(stringTozz(a.substr(i,bloquesN)));
        sign+=orden_3(resign,n);
    }
    if(ZZ(sign.size()&1)!=ZZ(0)){
        sign+='2';
    }
    sign.append(conv<int>(ZZ(bloquesNext)-modulo(ZZ(sign.size()),ZZ(bloquesNext))),'2');
    for(int i=0;i<sign.size();i+=bloquesNext){
        resrubrub=potencia(stringTozz(sign.substr(i,bloquesNext)),e_ext,n_ext);
        rub+=orden_3(resrubrub,n_ext);
    }
    for(int i=0;i<rub.size();i+=bloquesN){
        resign=Resto_Chino(stringTozz(rub.substr(i,bloquesN)));
        bloques+=orden_3(resign,n);
    }
    for(int i=0;i<bloques.size();i+=(int_to_string(alfabeto.size()).size())){
      mensaje+=alfabeto[string_to_int(bloques.substr(i,int_to_string(alfabeto.size()).size()))];
    }
    return mensaje;
}
