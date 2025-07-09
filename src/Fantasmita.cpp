#include "Fantasmita.h"

#include <cstdio>
#include <windows.h>

#include "utilidades.h"//incluye <windows.h>

//Funcion para dibujar y limpiar al fantasmita
void Fantasmita::dibujar() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    int dibujarX = static_cast<int>(getX());
    int dibujarY = static_cast<int>(getY());
    
    // Limpia solo si cambió de posición
    if((lastX != dibujarX || lastY != dibujarY) && (lastX!=-1)) {
        limpiarZona(lastX, lastY, AnchoF, AltoF);
    } else {
        limpiarZona(dibujarX, dibujarY, AnchoF, AltoF);
    }

    lastX = static_cast<int>(getX());
    lastY = static_cast<int>(getY());

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    moverCursor(dibujarX, dibujarY);     printf("%c%c%c%c%c", 219,219,219,219,219);
    moverCursor(dibujarX, dibujarY + 1); printf("%c %c %c", 219,219,219);
    moverCursor(dibujarX, dibujarY + 2); printf("%c%c%c%c%c", 219,219,219,219,219);

    if(getAnimar()) {
        moverCursor(dibujarX, dibujarY + 3); printf("%c %c %c", 223,223,223);
    } else {
        moverCursor(dibujarX, dibujarY + 3); printf(" %c %c ", 223,223);
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    // Control de animación
    setContadorAnimacion(getContadorAnimacion() + 1);
    if(getContadorAnimacion() == 1){
        setAnimar(!getAnimar());
        setContadorAnimacion(0);
    }
}

//Funcion que modifica el movimiento
void Fantasmita:: movimiento(){

    float nuevaX = getX() + getVelocidadX();
    float nuevaY = getY() + getVelocidadY();

    if (nuevaX +  static_cast<float>(getAncho()) >= Limite_horizontal_derecha){
        nuevaX = Limite_horizontal_derecha - static_cast<float>(getAncho());
        
        reboteConjunto = true;

    } else if (nuevaX <= Limite_horizontal_izquierda){
        nuevaX = Limite_horizontal_izquierda;

        reboteConjunto = true;
    }

    setX(nuevaX);
    setY(nuevaY);
}

//Funcion que cambia de direccion al fantasmita
void Fantasmita:: cambiarDireccion(){
    setVelocidadX(-getVelocidadX());
}
