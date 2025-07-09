#include"marcianito.h"
#include<windows.h>
#include"utilidades.h"
#include<iostream>

//Implementación de metodos para marcianito
void marcianito::imprimirSprite1() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Azul brillante

    // Dibuja el sprite en múltiples líneas usando printf y moverCursor
    moverCursor(cordenadaX, cordenadaY);     printf(" %c     %c\n", 219, 219);
    moverCursor(cordenadaX, cordenadaY + 1); printf("  %c   %c\n", 219, 219);
    moverCursor(cordenadaX, cordenadaY + 2); printf(" %c%c%c%c%c%c%c\n", 219,219,219,219,219,219,219);
    moverCursor(cordenadaX, cordenadaY + 3); printf("%c%c  %c  %c%c\n", 219,219,219,219,219); // Ojitos con 29
    moverCursor(cordenadaX, cordenadaY + 4); printf("%c%c%c%c%c%c%c%c%c\n", 219,219,219,219,219,219,219,219,219);
    moverCursor(cordenadaX, cordenadaY + 5); printf("  %c   %c\n", 223, 223);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset color
}

void marcianito::imprimirSprite2() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    // Versión alternativa del sprite
    moverCursor(cordenadaX, cordenadaY);     printf("  %c   %c\n", 219, 219);
    moverCursor(cordenadaX, cordenadaY + 1); printf("  %c   %c\n", 219, 219);
    moverCursor(cordenadaX, cordenadaY + 2); printf(" %c%c%c%c%c%c%c\n", 219,219,219,219,219,219,219);
    moverCursor(cordenadaX, cordenadaY + 3); printf("%c%c  %c  %c%c\n", 219,219,219,219,219);
    moverCursor(cordenadaX, cordenadaY + 4); printf("%c%c%c%c%c%c%c%c%c\n", 219,219,219,219,219,219,219,219,219);
    moverCursor(cordenadaX, cordenadaY + 5); printf("   %c %c\n", 223, 223);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void marcianito:: limpiarSprite(){
    limpiarZona(cordenadaX, cordenadaY, 9, 6);
}
// Métodos de movimiento
void marcianito::moverDerecha()   { cordenadaX++; }
void marcianito::moverIzquierda() { cordenadaX--; }
void marcianito::bajar()          { cordenadaY--; }

// Getters
int marcianito::conseguirX() { return cordenadaX; }
int marcianito::conseguirY() { return cordenadaY; }
