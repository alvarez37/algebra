#include "LSFR.h"

LFSR::LFSR(int bits, vector<int> seed, vector<int> vect_tap)
{
    n_bits = bits;
    this ->our_seed = seed;
    this -> tap = vect_tap;
    ///cout<<"SEMILLA ASIGNADA"<<endl;
}
void LFSR::fill_seed()
{
    int temp = 0;
    for(unsigned int i = our_seed.size(); i<n_bits;i++){
        our_seed.push_back(modulo_int(our_seed[temp]+our_seed[temp+1],2));
        temp++;
    }
    int cont_0, cont_1;
    for(unsigned int i = 0; i<our_seed.size();i++){
        cout<<our_seed[i];
        if(our_seed[i]==1){cont_1++;}
        else{cont_0++;}
    }
    while(cont_1!=cont_0){
        if(cont_1>cont_0){
        ///Esto quiere decir que hay más 1's que 0's
            int time_lap_ass = 1+rand()%(n_bits-1);
            while(our_seed[time_lap_ass-1]== 0){
                time_lap_ass = rand()%(n_bits);
            }
            our_seed[time_lap_ass] = 0;
            cont_0++;
            cont_1--;
            cout<<"AGREGE 0 PES"<<endl;
        }
        else{
        ///Esto quiere decir que hay más 0's que 1's
            int time_lap_ass2 = 1+rand()%(n_bits-1);
            while(our_seed[time_lap_ass2-1]== 1){
                time_lap_ass2 = 1+rand()%(n_bits-1);
            }
            our_seed[time_lap_ass2] = 1;
            cont_1++;
            cont_0--;
            cout<<"AGREGE 1 PES"<<endl;
        }
    }
    for(unsigned int i = 0; i<our_seed.size();i++){
        cout<<our_seed[i];
        if(our_seed[i]==1){cont_1++;}
        else{cont_0++;}
    }
}
