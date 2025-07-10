#ifndef CONTROLBALA_H
#define CONTROLBALA_H

#include <vector> //para vector

#include "Bala.h"

class ControlBala {
    private:
        std:: vector<Bala> balas;
        bool disparoHabilitado;
        int tiempodeCarga;

    public:
        //constructor
        ControlBala() 
        : balas(),
          disparoHabilitado(true), 
          tiempodeCarga(0) {}
                                                
        //metodos de comportamiento
        void TiempoCargaDisparo();
        void disparar(float _x, float _y);
        void actualizar();
        void limpiarBalasInactivas();
        
        //getters
        bool getDisparoHabilitado() const { return disparoHabilitado; }
        std::vector<Bala>& getBalas() { return balas; }

        //setters
        void setDisparoHabilitado(bool nuevoEstado){ disparoHabilitado = nuevoEstado; }
};

#endif
