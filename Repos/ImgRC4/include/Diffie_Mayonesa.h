#ifndef DIFFIE_MAYONESA_H
#define DIFFIE_MAYONESA_H

#include <iostream>
#include <Functions.h>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

class CDiffie_Hellman{
    public:
        ZZ P;
        ZZ G;
        ZZ A;
        ZZ C_Publica;
        CDiffie_Hellman(ZZ,ZZ);
        ZZ Generar_Clave(ZZ);

};

#endif // DIFFIE_MAYONESA_H
