#include "Avioncito.h"

#include <windows.h> //para Handle (dibujo)
#include <iostream> //para printf (dibujo)
#include <cmath>

#include "Constantes.h"
#include "utilidades.h" //para mover cursor y limpiar zona

void Avioncito:: moverDerecha() {
    x += velocidadX;

    if((x+AnchoA) >= Limite_horizontal_derecha) {
        x = Limite_horizontal_derecha - AnchoA;
    }
}

void Avioncito:: moverIzquierda() {
    x -= velocidadX;

    if(x <= Limite_horizontal_izquierda) {
        x = Limite_horizontal_izquierda;
    }
}

void Avioncito:: moverArriba() {
    y -= velocidadY;

    if(y <= Limite_vertical_superior) {
        y = Limite_vertical_superior;
    }
}

void Avioncito:: moverAbajo() {
    y += velocidadY;

    if(y + AltoA >= Limite_vertical_inferior) {
        y = Limite_vertical_inferior - AltoA;
    }
}

void Avioncito:: dibujar(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    int dibujarX = static_cast<int>(round(x));
    int dibujarY = static_cast<int>(round(y));

    // Limpia solo si cambió de posición
    if((lastX != dibujarX || lastY != dibujarY) && (lastX!=-1)) {
        limpiarZona(lastX, lastY, AnchoA, AltoA);
    } else {
        limpiarZona(dibujarX, dibujarY, AnchoA, AltoA);
    }

    lastX = dibujarX;
    lastY = dibujarY;

    if (animar) {
        SetConsoleTextAttribute(hConsole, 1);
        moverCursor(dibujarX + 3, dibujarY);     printf("%c%c", 47, 92);                    // "/\"
        moverCursor(dibujarX + 2, dibujarY + 1); printf("%c%c%c%c", 47, 207, 207, 92);      // "/░░\"
        moverCursor(dibujarX,     dibujarY + 2); printf("%c%c%c%c%c%c%c%c", 200, 91, 95, 95, 95, 95, 93, 188); // "╚[____]╝"
        SetConsoleTextAttribute(hConsole, 6);
        moverCursor(dibujarX + 2, dibujarY + 3); printf("%c  %c", 190, 190);               // "╝  ╝"
    } else {
        SetConsoleTextAttribute(hConsole, 1);
        moverCursor(dibujarX + 3, dibujarY);     printf("%c%c", 47, 92);
        moverCursor(dibujarX + 2, dibujarY + 1); printf("%c%c%c%c", 47, 207, 207, 92);
        moverCursor(dibujarX,     dibujarY + 2); printf("%c%c%c%c%c%c%c%c", 200, 91, 95, 95, 95, 95, 93, 188);
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);  // reset color

    // Control de animación
    contadorAnimacion++;
    if(contadorAnimacion == 1){
        animar = !animar;
        contadorAnimacion = 0;
    }
}
