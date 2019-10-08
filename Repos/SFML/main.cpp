#include <vector>
#include <bitset>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void swap_int(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int Modulo_enteros(int a, int b){
    int q=a/b;
    int r=a-q*b;
    if(r<0){
        r+=b;
    }
    return r;
}
int main(){
    vector<int> total;
    int K[16],S[16];
    Image imagensita;
    imagensita.loadFromFile("image.jpg");
    if(true) {
        cout << "Image is loaded";
    } else {
        cout << "couldn't load image";
    }
    Vector2u imageSize = imagensita.getSize();
    int xSize = imageSize.x;
    int ySize = imageSize.y;
    Color tempColor;
    int red,green,blue;
    for(int i1 = 0; i1 < ySize ; i1++) {
        for(int j = 0; j < xSize; j++) {
            tempColor = imagensita.getPixel(j, i1);
            red = tempColor.r;
            green = tempColor.g;
            blue = tempColor.b;
            if(i1&1==1){
                S[j]=green;}
            if(i1&1==0){
                S[j]=red;
                }
        }
    }
    int f=0;
    for(int i=0;i<16;i++){
        f=Modulo_enteros(f+S[i]+K[i],16);
        swap_int(S[i],K[i]);
    }
    int i=0;
    int const numero_de_bits_necesarios=16;
    bitset<numero_de_bits_necesarios> index;
    for(int n=0;n<16;n++){
        i=Modulo_enteros(i+1,16);
        f=Modulo_enteros(f+S[n],16);
        swap_int(S[i],S[f]);
        index=Modulo_enteros(S[i]+S[f],16);
    }
    cout<<"INDEX: ";
    for(int m=0;m<16;m++){
        total.push_back(index[m]);
        cout<<total[m]<<" ";
    }
    cout<<endl;
    cout<<"SOLUCION TEMPORALXD ";
    for (int i=0;i<total.size();i++)
    {
        cout<<total[i];
    }
}

