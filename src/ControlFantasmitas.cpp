#include "ControlFantasmitas.h"

#include <vector>
#include <algorithm>

#include "Constantes.h"
#include "Enemigos.h"
#include "Fantasmita.h"
#include "Bala.h"

void ControlFantasmitas::agregarFantasmitas(int cantidad, int filas, int xInicial, int yInicial, int distancia) {
    distancia += AnchoF;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < cantidad; j++) {
            int x = xInicial + i*distancia;
            int y = yInicial + j*(AltoF+1);
            Fantasmita* f = new Fantasmita(static_cast<float>(x), static_cast<float>(y), 2, true);
            enemigos.push_back(f);
        }
    }
}

void ControlFantasmitas::actualizarFantasmita() {
    for (Enemigos* e : enemigos) {
        Fantasmita* f = dynamic_cast<Fantasmita*>(e);
        if(f){
        e->dibujar();
        e->movimiento();
        }
    }
}

void ControlFantasmitas:: bajarFantasmitas() {
    for(Enemigos* e : enemigos){
        Fantasmita* f = dynamic_cast<Fantasmita*>(e);
        if(f){
            f->setY(f->getY()+1);
        }
    }
}

bool ControlFantasmitas::comprobarReboteConjunto() {
    for (Enemigos* e : enemigos) {
        Fantasmita* f = dynamic_cast<Fantasmita*>(e);
        if (f && f->getReboteConjunto()) {
            return true;
        }
    }
    return false;
}

void ControlFantasmitas::cambiarDireccionTodos() {
    for(Enemigos* e : enemigos) {
        Fantasmita* f = dynamic_cast<Fantasmita*>(e);
        if(f) {
        f->cambiarDireccion();
        }
    }
}

void ControlFantasmitas::reiniciarReboteConjunto() {
    for(Enemigos* e : enemigos){
        Fantasmita* f = dynamic_cast<Fantasmita*>(e);
        if(f){
            f->setReboteConjunto(false);
        }
    }
}

ControlFantasmitas::~ControlFantasmitas() {
    for (Enemigos* enemigo : enemigos) {
        delete enemigo;
    }
    enemigos.clear();
}

void ControlFantasmitas::eliminarFantasmitasInactivos() {
    for (auto it = enemigos.begin(); it != enemigos.end(); ) {
        if (!(*it)->getActivo()) {
            (*it)->limpiarUltimaPosicion();
            delete *it;
            it = enemigos.erase(it);
        } else {    
            ++it;
        }
    }
}

