#include <iostream>
using namespace std;


template<class tipodato>

class nodo{
    public:
    nodo (tipodato);
    tipodato valor;
    nodo *next;
    nodo *prev;
};

nodo::nodo(tipodato dato_){
    dato=dato_;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
