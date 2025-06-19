#include <string>
#include <iostream>
#include <windows.h> 
#include <time.h>
using namespace std;

//ancho=156 lineas
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
void dibujar_enemigo(int x){
    string espacio(x, ' ');
    cout<<espacio<<"(o_o)"<<endl;
    cout<<espacio<<"<   >"<<endl;
    cout<<espacio<<"/---\\"<<endl;
}
int main(){
    int x=0,y=36;
    //-1 indica el estado en el que no se encuentra algo en la pantalla, ya sea el enemigo o el disparo
    int x1=-1,y1=-1;
    int x2=-1,y2=-1;
    //definimos semilla aleatoria para la aparicion de enemigos aleatorios
    srand(time(NULL));
    //contador para el enemigo
    int cont=0;
     while (true) {
        //imprimir la pantalla
        system ("cls"); 
        for(int i=0;i<40;i++){
            if(i==y){
                dibujar_avion(x);
                i+=3;
            }else if(i==y1&&y1!=-1){
                dibujar_disparo(x1);
            }else if(i==y2&&y2!=-1){
                dibujar_enemigo(x2);
                i+=2;   
            }else{
                cout<<endl;
            }
        }
        //tema_controles de movimiento
        if (GetAsyncKeyState('A') & 0x8000 && x > 0) x-=2;
        if (GetAsyncKeyState('D') & 0x8000 && x < 152) x+=2;
        if (x < 0) x = 0;
        if (x > 151) x = 151;

        if (GetAsyncKeyState('W') & 0x8000 && y > 2) y--;
        if (GetAsyncKeyState('S') & 0x8000 && y < 37) y++;
        if(y==37){
            y=36;
        }
        //controles para el disparo
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
        //enemigo
        //el enemigo aparecera en una posicion aleatoria
        if(x2==-1&&y2==-1){
            x2=rand()%152;
            y2=rand()%15;
        }

        cont++;
        //el enemigo descendera desde su posicion
        if(x2!=-1&&y2!=-1&&cont==4){
            y2++;
        }
        //reiniciamos el contador
        if(cont==4){
            cont=0;
        }
        //colision por fuera de campo
        if(y2>40){
            x2=-1;
            y2=-1;
        }
        //colision por bala
    
        //Colision en x
        bool colision_en_x=false;
        if(x1>=x2&&x1<=x2+4){
            colision_en_x=true;
        }
        //Colision en y
        bool colision_en_y=false;
        if(y2<=y1&&y1<=y2+2){
            colision_en_y=true;
        }

        //Colision total
        if(colision_en_x&&colision_en_y){
            x2=-1;
            y2=-1;
            x1=-1;
            y1=-1;
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break; // ESC para salir
        Sleep(30);
    }
}