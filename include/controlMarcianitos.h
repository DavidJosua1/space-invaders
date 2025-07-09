#ifndef CONTROLMARCIANITOS_H
#define CONTROLMARCIANITOS_H
#include <iostream>
#include <vector>
#include "marcianito.h"

class controlMarcianitos {
private:
    std::vector<marcianito> enemigos; // Vector que almacena todos los enemigos
    bool animar;                      // Alternador para cambiar sprite

public:
    // Constructor con lista de inicialización
    controlMarcianitos()
        : enemigos(), animar(true) {}

    // Métodos para controlar el grupo de enemigos
    void generarMarcianitos(std::size_t cantidad, std::size_t xInicial, std::size_t yInicial);
    void generarMarcianitos(std::size_t cantidad, std::size_t cantidadY, std::size_t xInicial, std::size_t yInicial, std::size_t distancia); // Crea marcianitos
    void dibujar();           // Dibuja todos los enemigos
    void limpiar();
    void moverDerecha();      // Mueve todos hacia la derecha
    void moverIzquierda();    // Mueve todos hacia la izquierda
    void bajar();             // Baja todos una línea
    void alternarAnimacion(); // Cambia entre sprite1 y sprite2
    bool indicadorVacio();    // Indica si el vector está vacío
};

#endif
