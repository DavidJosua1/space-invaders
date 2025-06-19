#include <string>
#include <iostream>
#include <windows.h> 
#include <conio.h>
using namespace std;

void dibujar_avion(int x, int y){
    
    string espacio(x, ' ');

    string Avion_11 = "  A";
    string Avion_12 = " /-\\";
    string Avion_13 = "<o o>";
    string Avion_14 = " o o";

    for(int i=0;i<y;i++){
        cout<<"\n";
    }

    cout<<espacio<<Avion_11<<endl;
    cout<<espacio<<Avion_12<<endl;
    cout<<espacio<<Avion_13<<endl;
    cout<<espacio<<Avion_14<<endl;
}

int main(){
    int x=0,y=35;
     while (true) {
        system ("cls"); 
        dibujar_avion(x,y);
        if (GetAsyncKeyState('A') & 0x8000 && x > 0) x--;
        if (GetAsyncKeyState('D') & 0x8000 && x < 151) x++;
        if (GetAsyncKeyState('W') & 0x8000 && y > 1) y--;
        if (GetAsyncKeyState('S') & 0x8000 && y < 36) y++;
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break; // ESC para salir
    }
}