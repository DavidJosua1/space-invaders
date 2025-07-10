#ifndef BALA_H
#define BALA_H

#include <cmath>

#include "Hitbox.h"
#include "Constantes.h"

class Bala {
    private:
        float x;
        float y;
        int lastX;
        int lastY;
        float velocidadY;
        bool animar;
        int contadorAnimacion;
        int numeroCiclosAnimacion;
        bool activa;

    public:
        //Constructores
        Bala (float _x, float _y)
        : x(_x), 
          y(_y),
          lastX(-1),
          lastY(-1),
          velocidadY(1.4f),
          animar(true),
          contadorAnimacion(0),
          numeroCiclosAnimacion(1),
          activa (true)
        {}

        //Metodos de comportamiento
        void movimientoBala();
        void dibujarBala();
        void limpiarUltimaPosicion();

        //getters
        float getX() const { return x; }
        float getY() const { return y; }
        Hitbox getHitbox() const { return Hitbox(static_cast<int>(round(x)), static_cast<int>(round(y)), AnchoB, AltoB); }
        bool getActiva() const { return activa; }

        //setters
        void setActiva(bool estado) { activa = estado; }
};

#endif
