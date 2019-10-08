#include "RC4.h"

RC_4::RC_4(){

}
int Modulo_enteros(int a, int b){
    int q=a/b;
    int r=a-q*b;
    if(r<0){
        r+=b;
    }
    return r;
}
void RC_4::swap_int(int a, int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
vector<int> RC_4::Generar_Aleatorio(int numero_bits){
    vector<int> total;
    int K[numero_bits],S[numero_bits];

    Image img;
    if(img.loadFromFile("img/image.jpg")) {
        //cout << "Image is loaded"
    } else {
        cout << "couldn't load image";
    }
    Vector2u imageSize = img.getSize();
    int xSize = imageSize.x;
    int ySize = imageSize.y;
    Color tempColor;
    int red,green,blue;
    for(int i1 = 0; i1 < ySize ; i1++) {
        for(int j = 0; j < xSize; j++) {
            tempColor = img.getPixel(j, i1);
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
    for(int i=0;i<numero_bits;i++){
        f=Modulo_enteros(f+S[i]+K[i],numero_bits);
        swap_int(S[i],K[i]);
    }
    int i=0;
    int const numero_de_bits_necesarios=16;
    bitset<numero_de_bits_necesarios> index;
    for(int n=0;n<numero_bits;n++){
        i=Modulo_enteros(i+1,numero_bits);
        f=Modulo_enteros(f+S[n],numero_bits);
        swap_int(S[i],S[f]);
        index=Modulo_enteros(S[i]+S[f],numero_bits);
    }
    cout<<"INDEX: ";
    for(int m=0;m<16;m++){
        total.push_back(index[m]);
        cout<<total[m]<<" ";
    }
    cout<<endl;
    return total;
}
vector<int> RC_4::Numero_Grande(){
    vector<int> numero,temp,temp1;
    cout<<endl;
    while(numero.size()<=1024){
        temp=Generar_Aleatorio(1024);
        temp1=temp;
        cout<<"TEMP: ";
        for(int i=0;i<16;i++){
            cout<<temp1[i]<<" ";
            numero.push_back(temp1[i]);
        }
        cout<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<"NUMERO: ";
    for(int i=0;i<1024;i++){
        cout<<numero[i]<<" ";
    }
    return numero;
}
