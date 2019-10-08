#include <iostream>
#include "LSFR.h"
#include "RSA.h"
#include "Gamal.h"
#include "Functions.h"
using namespace std;

int main()
{
    //RC_4 prueba;
    //prueba.Numero_Grande();
    RSA a(8);
//    LFSR cuack(8,bih,lamp);
//    cuack.fill_seed();

    RSA objeto(conv<ZZ>("151"),conv<ZZ>("41693"),conv<ZZ>("26791"),conv<ZZ>("41693"));
    cout<<"Cifrado : "<<endl;
    cout<<objeto.cifrado("LIFEISPAINSOISDEATH")<<endl;
    cout<<"Descifrado : "<<endl;
    cout<<a.descifrado("4067711373307522841817677089213182200001175512198115270094170117711172132454137302787")<<endl;
    //potencia(conv<ZZ>("41693")conv<ZZ>("26791"),conv<ZZ>("41693"));
    Gamal Gamalsito(ZZ(2),ZZ(7),ZZ(29),ZZ(12),ZZ(5));
    string mensaje="LIVEWITHHONORDIEWITHGLORY";
    string cifgam=Gamalsito.cifrar(mensaje);
    cout<<cifgam<<endl;
    cout<<Gamalsito.descifrar(cifgam)<<endl;
    Gamal Gamalsito2(1024);
    string cifgam2=Gamalsito2.cifrar(mensaje);
    cout<<cifgam2<<endl;
    cout<<Gamalsito2.descifrar(cifgam2)<<endl;


    return 0;
}

