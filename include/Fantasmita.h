#ifndef FANTASMITA_H
#define FANTASMITA_H

#include "Enemigos.h"
#include "Constantes.h"

class Fantasmita : public Enemigos{
    private:
        bool reboteConjunto;

    public:
        //constructor
        Fantasmita (float _x, float _y, int _vida)
            : Enemigos(_x,_y, AnchoF , AltoF, _vida, 0.15f, 0.0f, true, 5, true, 0), reboteConjunto(false){}

        //Metodos virtuales
        void dibujar() override;
        void movimiento() override;
        void disparar(){}

        //Metodos de Comportamiento
        void cambiarDireccion();
        
        //Getters
        bool getReboteConjunto() { return reboteConjunto; }

        //Setters
        void setReboteConjunto(bool nuevoReboteConjunto) { reboteConjunto = nuevoReboteConjunto; }

        //Destructor
        ~Fantasmita() override = default;
};

#endif
