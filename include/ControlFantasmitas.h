#ifndef CONTROLFANTASMITAS_H
#define CONTROLFANTASMITAS_H

#include <vector>

#include "Enemigos.h"
#include "Bala.h"
#include "Avioncito.h"

class ControlFantasmitas {
    private: 
        std::vector<Enemigos*> enemigos;
        
    public:
        //Constructor
        ControlFantasmitas() : enemigos() {}

        //Metodos de control
        void agregarFantasmitas(int cantidad, int filas, int xInicial, int yInicial, int distancia, float velocidadX, float velocidadY);
        void actualizarFantasmita();
        void establecerVelocidad(float velocidadX, float VelocidadY);
        void bajarFantasmitas();
        bool comprobarReboteConjunto();
        void cambiarDireccionTodos();
        void reiniciarReboteConjunto();
        void comprobarLlegadaInvasora(Avioncito& avion); 
        void eliminarFantasmitasInactivos();

        //getters
        std::vector<Enemigos*>& getEnemigos() { return enemigos; }
        float getVelocidadX();
        float getVelocidadY();

        //Destructor
        ~ControlFantasmitas();
};

#endif
