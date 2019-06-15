#include<iostream>
#include<string>
#include <stdlib.h>
#include <fstream>

using namespace std ;

class alg_cesar{
  public:
    alg_cesar(int);
    string cifrado( string );
    string desifrado(string);
    int modulo(int);
  private:
    string alf="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
    string mensaje;
    int clave;
    int tam_array;
    int posicion;

};


  alg_cesar::alg_cesar(int x){
      clave=x;
      tam_array=alf.size();
  }

  int alg_cesar::modulo(int a){
    int residuo;
    if (a<0) {
      residuo=a-((a/tam_array)-1)*tam_array;
    }
    else{
      residuo=a-(a/tam_array)*tam_array;
    }
    return residuo;
  }

  string alg_cesar::cifrado( string txt){
    mensaje=txt;
  for (int i = 0; i < txt.size(); i++) {
    posicion=alf.find(txt[i]);
    mensaje[i]=alf[modulo(posicion+clave)];
  }
  std::cout  << '\n';
  return mensaje;
}


  string alg_cesar::desifrado(  string txt ){
    mensaje=txt;

    for (int i = 0; i < txt.size(); i++) {
      posicion=alf.find(txt[i]);

      mensaje[i]=alf[modulo(posicion-clave)];
    }
    return mensaje;
  }



string cifrado(string cadena, int filas,int tam){
  string cadena_salida;
  cadena_salida=cadena;

  int x=0;
  int plusfilas=1;
  int cont=1;
  int ndos=2;
  for ( int i=0; i<cadena.size();i++){

      if(!(cadena.size()>x)){
        cadena_salida[i]=cadena[plusfilas];
        plusfilas+=((2*filas)-2)-(ndos);
        if (plusfilas<cadena.size()) {
          i++;
          cadena_salida[i]=cadena[plusfilas];

          plusfilas+=ndos;
        }
        else{
          cont++;
          plusfilas=cont;
          ndos+=2;
        }

        if (cont>filas-2) {
          x=filas-1;
          i++;
        }
      }

      if (cadena.size()>x) {
        cadena_salida[i]=cadena[x];

        x=x+((2*filas)-2);
      }


  }
  return cadena_salida ;
}

string descifrado(string cadena, int filas,int tam){
  string cadena_salida;
  cadena_salida=cadena;

  int x=0;
  int plusfilas=1;
  int cont=1;
  int ndos=2;
  for ( int i=0; i<cadena.size();i++){

        if(!(cadena.size()>x)){
          cadena_salida[plusfilas]=cadena[i];
          plusfilas+=((2*filas)-2)-(ndos);
          if (plusfilas<cadena.size()) {
            i++;
            cadena_salida[plusfilas]=cadena[i];

            plusfilas+=ndos;
          }
          else{
            cont++;
            plusfilas=cont;
            ndos+=2;
          }

          if (cont>filas-2) {
            x=filas-1;
            i++;
          }
        }

        if (cadena.size()>x) {
          cadena_salida[x]=cadena[i];
          x=x+((2*filas)-2);
        }

    }
    return cadena_salida ;
}

void escribir_txt(string txt,string nombre){
  fstream ficheroEntrada;
  string frase;
  ofstream fs(nombre.c_str(), ios::out);
  fs << txt << endl;
  fs.close();
}

int main(){


      // string txtcifrado;
      // string text;
      // int clave=4;
      //
      //   alg_cesar emisor( clave );
      //   alg_cesar receptor( clave );
      //   std::cout  << '\n';
      //   string text__="jean-carlos-alvarez-guerreros-171-10-39169-holaholaholaholaholaholaholaho";
      //   std::cout << "cifrado cesar:  " << emisor.cifrado(text__) << '\n';
      //   txtcifrado=emisor.cifrado(text__);
      //
      //
      //   int filas;
      //   std::cout << "numero de filas: " << '\n';
      //   std::cin >> filas;
      //   int tam=text__.size();
      //   string cifrado_= cifrado(txtcifrado,filas,tam);
      //   std::cout << '\n';
      //   escribir_txt(txtcifrado,"txt.3.txt");
      //   std::cout << tam <<"  "<< txtcifrado.size() <<"cifrado_ :  "  <<txtcifrado << '\n';

       string texto="glhEzhf7z3hql vOzhglhfObzgJfgghJOh fgulb";


        // string texto="Epvmu64mDDiX7DwDlDDAmimyigenhsDrEihepCsyb57-pDsIwuqDre6DmqyxpggieyhQDhhiyzirgeDwDyisssADlpbOiDArDiDli548DsGqweyDGiw5eqikeiimDDwiMYADgrizxDrsDyqpwnnDADm9OpeZGD8LsxIyDDDDzBxEhmDihxtDshDO";
        int clave=5;
        alg_cesar emisor( clave );
        string textodes=descifrado(texto,5,texto.size());
        // string textodes=emisor.desifrado(texto);

        std::cout << textodes << '\n';
        std::cout << "desifrado final: " <<  emisor.desifrado(textodes) << '\n';
        // std::cout << "desifrado final: " << descifrado(texto,5,texto.size()) << '\n';



 return 0;

}
