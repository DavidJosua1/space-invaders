#ifndef AVIONCITO_H
#define AVIONCITO_H

#include "Constantes.h"
#include "Hitbox.h"
#include "cmath"

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
        int vida;
        bool estado;

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
          velocidadY(1.5f),
          vida(1),
          estado(true)
        {}

        //Metodos de comportamiento
        void moverDerecha();
        void moverIzquierda();
        void moverArriba();
        void moverAbajo();
        void dibujar();
        void limpiarAvion();

        //setters
        void setVida(int nuevaVida) { vida = nuevaVida; }
        void setActivo(bool nuevoEstado) { estado = nuevoEstado; }
         
        //getters
        float getX() const { return x; }
        float getY() const { return y; }
        int getVida() const { return vida; }
        bool getEstado() const { return estado; }
        Hitbox getHitbox() const { return Hitbox(static_cast<int>(round(x)), static_cast<int>(round(y)), AnchoA, AltoA); }
};

#endif
