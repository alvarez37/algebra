
#include <iostream>
#include <windows.h>
#include <conio.h>

#define ARRIBA     72
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80

using namespace std;

int i=5;
int j=4;

void SetColor(int ForgC)
{
    WORD wColor;

    //This handle is needed to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //csbi is used for wAttributes word

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
      //To mask out all but the background attribute, and to add the color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0xF0);
      SetConsoleTextAttribute(hStdOut, wColor);
    }
 return;
}

void gotoxy(int x, int y)  // funcion que posiciona el cursos en la         coordenada (x,y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void seleccionarOpcion(char tecla){

    gotoxy(j, i); cout<<" ";

    if( tecla == ABAJO and i<16 ){
        gotoxy(0, 0);
        cout<<"                    ";
        i+=5;
    }
    if( tecla == ARRIBA and  i>5 ){
        gotoxy(0, 0);
        cout<<"                    ";
        i-=5;
    }

    if( tecla == IZQUIERDA and  j>4 ){
        gotoxy(0, 0);
        cout<<"                    ";
        j-=5;
    }
    if( tecla == DERECHA and j<15){
        gotoxy(0, 0);
        cout<<"                    ";
        j+=5;
    }



   gotoxy(j, i); cout<<">";
}

int cambiar(int lista){

  return 89;
}

void menu(char tecla,int lista[][4]){
seleccionarOpcion(tecla);

gotoxy(5,5); cout<<lista[0][0];
gotoxy(10,5); cout<<lista[0][1];
gotoxy(15, 5); cout<<lista[0][2];
gotoxy(20, 5); cout<<lista[0][3];

gotoxy(5, 10); cout<<lista[1][0];
gotoxy(10, 10); cout<<lista[1][1];
gotoxy(15, 10); cout<<lista[1][2];
gotoxy(20, 10); cout<<lista[1][3];

gotoxy(5, 15); cout<<lista[2][0];
gotoxy(10, 15); cout<<lista[2][1];
gotoxy(15, 15); cout<<lista[2][2];
gotoxy(20, 15); cout<<lista[2][3];


gotoxy(5, 20); cout<<lista[3][0];
gotoxy(10, 20); cout<<lista[3][1];
gotoxy(15, 20); cout<<lista[3][2];
gotoxy(20, 20); cout<<lista[3][3];

if( tecla == 13 ){
    lista[1][1]=14;
    gotoxy(0, 0);
    std::cout << " mover            " ;
  }
  gotoxy(10, 10); cout<<"  ";
}


int main()
{
    char tecla;
    while(true){

    if( kbhit() )
        tecla = getch();
    else
        tecla = ' ';
    int lista[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    menu(tecla,lista);


    Sleep(40);
}

return 0;

}
