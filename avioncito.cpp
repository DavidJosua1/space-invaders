#include <string>
#include <iostream>
#include <windows.h> 
#include <conio.h>
using namespace std;

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

int main(){
    int x=0;

     while (true) {
        system ("cls"); 
        dibujar_avion(x);
        
        char tecla = getch();
        if (tecla =='a'&&x>0){
            x--;
        }else if(tecla=='d'&&x<151){
            x++;
        }else if(tecla==27){
            break;
        }
    }
}