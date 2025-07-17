#include "Bala.h"

#include <windows.h>
#include <iostream>
#include <cmath>

#include "utilidades.h"
#include "constantes.h"

//Modifica y en base a su velocidad
void Bala::movimientoBala(){
    y-=velocidadY;
}

//Limpia la ultima zona y dibuja la bala
void Bala::dibujarBala(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int dibujarX = static_cast<int>(round(x));
    int dibujarY = static_cast<int>(round(y));

    if((lastX != dibujarX || lastY != dibujarY) && (lastX!=-1)) {
        limpiarZona(lastX, lastY, AnchoB, AltoB);
    } else {
        limpiarZona(dibujarX, dibujarY, AnchoB, AltoB);
    }

    lastX = dibujarX;
    lastY = dibujarY;

    //dibuja la bala
    if (animar) {
        SetConsoleTextAttribute(hConsole, 4);
        moverCursor(dibujarX, dibujarY); printf("%c", 33);
    } else {
        SetConsoleTextAttribute(hConsole, 6);
        moverCursor(dibujarX, dibujarY); printf("%c", 33);
    }

    // Control de animación
    contadorAnimacion++;
    if(contadorAnimacion == numeroCiclosAnimacion){
        animar = !animar;
        contadorAnimacion = 0;
    }
}

//Funcion que limpia la ultima posicion de manera independiente
void Bala::limpiarUltimaPosicion() {
    if (lastX != -1 && lastY != -1) {
        limpiarZona(lastX, lastY, AnchoB, AltoB);
    }
}
