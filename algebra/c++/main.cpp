#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void fib(int *a,int tam){
    int * ptr2=a;
    ptr2++;
    int temp;
    for(int i=0; i<tam;i++){
        temp=*ptr2+*a;
        *a++;
        *a++;
        *a=temp;
        *a--;
        *ptr2++;
        cout<<temp<<" ";
    }


}

int main()
{

    int a[]={0,1};

    fib(a,9);

    return 0;
}
