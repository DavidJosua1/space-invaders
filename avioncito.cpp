#include <string>
#include <iostream>
#include <windows.h> 
#include <conio.h>
using namespace std;

//achho=156 lineas
//alto=41 filas

void dibujar_avion(int x){
    
    string espacio(x, ' ');

    string Avion_11 = "  A";
    string Avion_12 = " /-\\";
    string Avion_13 = "<o o>";
    string Avion_14 = " o o";

    cout<<espacio<<Avion_11<<endl;
    cout<<espacio<<Avion_12<<endl;
    cout<<espacio<<Avion_13<<endl;
    cout<<espacio<<Avion_14<<endl;
}
void dibujar_disparo(int x){
    string espacio(x, ' ');
    cout<<espacio<<"|"<<endl;
}

int main(){
    int x=0,y=36;
    int x1=-1,y1=-1;
     while (true) {
        system ("cls"); 
        for(int i=0;i<40;i++){
            if(i==y){
                dibujar_avion(x);
                i+=3;
            }else if(i==y1&&y1!=-1){
                dibujar_disparo(x1);
            }else{
                cout<<endl;
            }
        }

        if (GetAsyncKeyState('A') & 0x8000 && x > 0) x-=2;
        if (GetAsyncKeyState('D') & 0x8000 && x < 152) x+=2;
        if (x < 0) x = 0;
        if (x > 151) x = 151;

        if (GetAsyncKeyState('W') & 0x8000 && y > 2) y--;
        if (GetAsyncKeyState('S') & 0x8000 && y < 37) y++;
        if(y==37){
            y=36;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break; // ESC para salir
        if (GetAsyncKeyState(' ') & 0x8000 && x1==-1&&y1==-1){
            x1=x+2;
            y1=y-1;
        } 
        if(y1!=-1){
            y1--;
        }
        if(y1!=-1&&y1<1){  
            x1=-1;
            y1=-1;         
        }

    Sleep(30);
    }
}