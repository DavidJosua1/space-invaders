#ifndef MARCIANITO_H
#define MARCIANITO_H

class marcianito {
private:
    int cordenadaX; // Posición X del marcianito
    int cordenadaY; // Posición Y del marcianito

public:
    // Constructor que inicializa las coordenadas usando lista de inicialización
    marcianito(int x, int y)
        : cordenadaX(x), cordenadaY(y) {}

    // Métodos para dibujar el marcianito en dos "formas"
    void imprimirSprite1(); // Sprite en forma A
    void imprimirSprite2(); // Sprite en forma B
    void limpiarSprite(); 
    // Métodos de movimiento
    void moverDerecha();
    void moverIzquierda();
    void bajar();

    // Getters para coordenadas
    int conseguirX();
    int conseguirY();
};

#endif
