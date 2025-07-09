#include "controlMarcianitos.h"
//Implementacion de controles de marcianito

// Crea múltiples marcianitos distribuidos horizontalmente
void controlMarcianitos:: generarMarcianitos(std::size_t cantidad, std::size_t xInicial, std::size_t yInicial){
    for(std::size_t i=0;i < cantidad;i++){
        enemigos.emplace_back(xInicial+i*20, yInicial);
    }

}
// Crea múltiples marcianitos distribuidos horizontalmente y verticalmente
void controlMarcianitos::generarMarcianitos(std::size_t cantidadX, std::size_t cantidadY,std::size_t xInicial, std::size_t yInicial, std::size_t distancia) {
    for (std::size_t fila = 0; fila < cantidadY; ++fila) {
        for (std::size_t col = 0; col < cantidadX; ++col) {
            std::size_t x = xInicial+ col * (9+distancia);
            std::size_t y = yInicial+ fila * 7;
            enemigos.emplace_back(x, y);
        }
    }
}

// Dibuja todos los enemigos con el sprite correspondiente
void controlMarcianitos::dibujar() {
    for (marcianito& m : enemigos) {
        if (animar) m.imprimirSprite1();
        else        m.imprimirSprite2();
    }
}

void controlMarcianitos:: limpiar(){
    for (marcianito& m : enemigos) {
        m.limpiarSprite();
    }
}
// Mueve a todos hacia la derecha
void controlMarcianitos::moverDerecha() {
    for (marcianito& m : enemigos) {
        m.moverDerecha();
    }
}

// Mueve a todos hacia la izquierda
void controlMarcianitos::moverIzquierda() {
    for (marcianito& m : enemigos) {
        m.moverIzquierda();
    }
}

// Baja todos una línea
void controlMarcianitos::bajar() {
    for (marcianito& m : enemigos) {
        m.bajar();
    }
}

// Alterna entre sprite1 y sprite2 (animación)
void controlMarcianitos::alternarAnimacion() {
    animar = !animar; // Invierte el valor booleano
}

// Verifica si no hay enemigos
bool controlMarcianitos::indicadorVacio() {
    return enemigos.empty();
}
