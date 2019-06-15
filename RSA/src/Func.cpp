#include "Func.h"

int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

int euclides(int a, int b)
{
    int res=modulo(a,b);
    while(res!=0)
    {
        ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
        a=b;
        b=res;
        res=modulo(a,b);
    }
    ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
    return b;
}

int inversa(int a, int b)
{
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    if(x1<0){
        return modulo(x1,b);
    }
    else{
        return x1;
    }

}
int generar_Aleatorio(){
    srand(time(NULL));
    int numero_aleatorio=rand();  ///Numeros entre 1-1000
    return numero_aleatorio;
}
int generar_Aleatorio_Max(int max){
    srand(time(NULL));
    int numero_aleatorio=rand()%(max);  ///Numeros entre 1-1000
    return numero_aleatorio;
}
bool comprobar_primo(int num)
{
    int fact = 2;
    if (num == 1){return 0;}
    for (int i = 2; i < num; i++){
        if(modulo(num,i)==0){fact++;}
    }
    if (fact == 2){return 1;}
    else{return 0;}
}
int multiplicacion_modular(int a, int b,int mod)
{
    return modulo((modulo(a, mod) * modulo(b,mod)), mod);
}
int exponenciacion_modular(int a, int b, int mod)
{
    int resultado = 1;
    int i = modulo(a,mod);
    while(b != 0){
        if(b&1){
            resultado = multiplicacion_modular(resultado,i, mod);
        }
        i = multiplicacion_modular(a, a, mod);
        b = b/2;
    }
    return resultado;
}
int phi_euler_primo(int n)
{
    return n-1;
}
int phi_euler_mult(int m, int n)
{
    return (phi_euler_primo(m)*phi_euler_primo(n));
}
int phi_euler_exp(int p, int e)
{
    return (p^e)-(p^(e-1));
}
