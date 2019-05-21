#include <iostream>
#include<vector>
using namespace std;



int digitos(int a){
    int dig=1;
    while(a/10>0)
    {
        a=a/10;
        dig++;
    }return dig;
}

int MOD(int a,int b){
    int r=a-(a/b)*b;
	if(r<0){
		r=r+b;
	}
	return r;
}
int factor(int numero){
	int i=2;
	while(i<=numero)
	{
		if(MOD(numero,i)==0)  //a%b=0, implica que b es factor de a.
		{
			return i;
		}
		i++;  //Incrementamos indice.
	}
}
int modulo(int a,int tam_array){
  int residuo;
  if (a<0) {
    residuo=a-((a/tam_array)-1)*tam_array;
  }

  else{
    residuo=a-(a/tam_array)*tam_array;
  }
  return residuo;
}

int mod_inverso(int a,int b){
	int p0=0,p1=1,pn=0,q,cont=0,total;
	int r=a,modin=b;
    if(modulo(a,b)==1)
        return 1;
	if((modulo(b,a))==0){return 0;}

	else{
        r=modulo(a,b);
        while(r>1){
            cont=cont+1;
            total=b;
            b=r;
            q=(total/b);
            r=modulo(total,b);
            pn=modulo((p0-p1*q),modin);
            p0=p1;
            p1=pn;
        }
        if(r!=1){return 0;}
	}
	return pn;
}


bool esprimo(int n){
    int a=0;
    for(int i=1;i<(n+1);i++){
         if(n%i==0){
             a++;
            }
         }
         if(a!=2){
            return false;
         }else{return true;};
}
int mcd(int dividendo,int divisor){
    int residuo=MOD(dividendo,divisor);
    while(residuo>0){
        dividendo=divisor;
        divisor=residuo;
        residuo=MOD(dividendo,divisor);
    }
    return divisor;
}
int potencia(int a, int b){
    int r=b%2,acum=1,anterior=a,mult;
    while(b!=0){
        if(r!=0){
            acum=anterior*acum;

        }

        mult=anterior*anterior;
        anterior=mult;
        b=b/2;
        r=b%2;
    }return acum;
}
int potenciamod(int a, int b,int n){
	long int r=b%2,nuevomodu=1,modu=MOD(a,n),antmod=a;
	while(b!=0){
		//cout<<"modu "<<modu<<endl;
		//cout<<"r "<<r<<endl;
		if(r!=0){
			antmod=nuevomodu;
			nuevomodu=MOD((antmod*modu),n);
			//cout<<"modu "<<modu<<endl;
			//cout<<"antmod "<<antmod<<endl;
			//cout<<"nuevomod "<<nuevomodu<<endl;
		}
		modu=MOD(modu*modu,n);
		b=b/2;
		r=b%2;
	}return nuevomodu;
}

int euclidesExtendido(int a, int b) {
	int r1 = a;
	int r2 = b;
	int s1 = 1;
	int s2 = 0;
	int t1 = 0;
	int t2 = 1;
	int s = 0;
	int t = 0;
	while (r2 > 0) {
		int q = r1 / r2;
		int r = r1 - q * r2;
		r1 = r2;
		r2 = r;
		s = s1 - q * s2;
		s1 = s2;
		s2 = s;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	s = s1;
	t = t1;
	return s;
}


int resto_chino(vector<int> a, vector<int> p){
    int acum=1,acumsuma=0;
    vector<int>q,pes;
    for(int elemento:p){
        acum=acum*elemento;
    }
    for(int i=0;i<p.size();i++){
        pes.push_back(acum/p[i]);
        q.push_back(mod_inverso(acum/p[i],p[i]));
    }

    for(int i=0;i<p.size();i++){

        acumsuma=modulo(acumsuma+modulo((modulo(a[i],acum)*modulo(pes[i],acum)*modulo(q[i],acum)),acum),acum);
    }



    return acumsuma;
}
