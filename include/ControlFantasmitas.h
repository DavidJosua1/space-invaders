#ifndef CONTROLFANTASMITAS_H
#define CONTROLFANTASMITAS_H

#include <vector>

#include "Enemigos.h"
#include "Bala.h"

class ControlFantasmitas {
    private: 
        std::vector<Enemigos*> enemigos;

    public:
        //Constructor
        ControlFantasmitas() : enemigos() {}

        //Metodos de control
        void agregarFantasmitas(int cantidad, int filas, int xInicial, int yInicial, int distancia);
        void actualizarFantasmita();
        void bajarFantasmitas();
        bool comprobarReboteConjunto();
        void cambiarDireccionTodos();
        void reiniciarReboteConjunto(); 
        void eliminarFantasmitasInactivos();

        //getters
        std::vector<Enemigos*>& getEnemigos() { return enemigos; }

        //Destructor
        ~ControlFantasmitas();
};

#endif
