#ifndef AVIONCITO_H
#define AVIONCITO_H

class Avioncito {
    private:
        float x;
        float y;
        int lastX;
        int lastY;
        bool animar;
        int contadorAnimacion;
        float velocidadX;
        float velocidadY;

    public:
        //Constructores
        Avioncito(float _x, float _y) 
        : x(_x),
          y(_y),
          lastX(-1),
          lastY(-1),
          animar(true),
          contadorAnimacion(0),
          velocidadX(3.0f),
          velocidadY(1.5f)
        {}

        //Metodos de comportamiento
        void moverDerecha();
        void moverIzquierda();
        void moverArriba();
        void moverAbajo();
        void dibujar();

        //getters
        float getX() { return x; }
        float getY() { return y; }
};

#endif
