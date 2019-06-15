#include "RSA.h"
#include "Func2.h"

int main()
{
    srand(time(NULL));
    int mensaje = 19;
    cout <<mensaje<<endl;
    RSA my_rsa;
    int mensaje_e = my_rsa.RSA_Encriptacion(mensaje);
    cout <<mensaje_e<<endl;
    cout <<my_rsa.RSA_Desencriptacion(mensaje_e)<<endl;
    ///cout <<exponenciacion_modular(19,5,119)<<endl;
    ///cout <<exponenciacion_modular(66,77,119)<<endl;
    cout <<inversa(4039,my_rsa.get_phi())<<endl;
    descomposicion_primos(2809);
    cout <<phi_euler_chidori(2809)<<endl;
    return 0;
}
///'setso-anial-abstracto:v::Ana-Mario'
