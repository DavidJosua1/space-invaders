#ifndef CONTROLFANTASMITAS_H
#define CONTROLFANTASMITAS_H

#include <vector>

#include "Enemigos.h"

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

        //Destructor
        ~ControlFantasmitas();
};

#endif
