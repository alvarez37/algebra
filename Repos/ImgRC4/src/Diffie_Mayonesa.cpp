#include "Diffie_Mayonesa.h"

CDiffie_Hellman::CDiffie_Hellman(ZZ P1,ZZ G1)
{
    P=P1;
    G=G1;
    A=RandomBnd(P);
    while (A<2){
        A=RandomBnd(P);
    }
    C_Publica=potencia(G,A,P);
}

ZZ CDiffie_Hellman::Generar_Clave(ZZ C_Recibida){
    return potencia(C_Recibida,A,P);
}
