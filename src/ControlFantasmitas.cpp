#include "ControlFantasmitas.h"

#include <vector>
#include <algorithm>

#include "Constantes.h"
#include "Enemigos.h"
#include "Fantasmita.h"
#include "Bala.h"
#include "Avioncito.h"

void ControlFantasmitas::agregarFantasmitas(int cantidad, int filas, int xInicial, int yInicial, int distancia, float velocidadX, float velocidadY) {
    distancia += AnchoF;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < cantidad; j++) {
            int x = xInicial + i*distancia;
            int y = yInicial + j*(AltoF+1);
            Fantasmita* f = new Fantasmita(static_cast<float>(x), static_cast<float>(y), 2, true, velocidadX, velocidadY);
            enemigos.push_back(f);
        }
    }
}

float ControlFantasmitas::getVelocidadX(){ 
    float velocidadX = 0.0f;

    for (Enemigos* e : enemigos) {
        velocidadX = e->getVelocidadX();
    }
    return velocidadX;
}

float ControlFantasmitas::getVelocidadY(){ 
    float velocidadY = 0.0f;

    for (Enemigos* e : enemigos) {
        velocidadY = e->getVelocidadY();
    }
    return velocidadY;
}

void ControlFantasmitas::establecerVelocidad(float velocidadX, float velocidadY){
    for (Enemigos* e : enemigos) {
        Fantasmita* f = dynamic_cast<Fantasmita*>(e);
        if(f){
            f->setVelocidadX(velocidadX);
            f->setVelocidadY(velocidadY);
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

void ControlFantasmitas::comprobarLlegadaInvasora(Avioncito& avion) {
    for (Enemigos* e : enemigos) {
        Fantasmita* f = dynamic_cast<Fantasmita*>(e);
        if (f && (f->getAlto() + static_cast<int>(round(f->getY()))) >= Limite_vertical_inferior) {
            avion.setActivo(false);
        }
    }
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

ControlFantasmitas::~ControlFantasmitas() {
    for (Enemigos* enemigo : enemigos) {
        delete enemigo;
    }
    enemigos.clear();
}
