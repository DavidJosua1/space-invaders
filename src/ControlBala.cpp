#include "ControlBala.h"

#include <algorithm>//Para removeif

#include "Constantes.h"
#include "Bala.h"//Como controlador de bala necesita la clase bala

//Controla el tiempo de recarga del disparo
void ControlBala::TiempoCargaDisparo(){
    if(!disparoHabilitado) {
        tiempodeCarga++;
        if(tiempodeCarga >= 3){
            disparoHabilitado = true;
            tiempodeCarga = 0;  // 
        }
    }
}

//Crea dos balas en las posiciones iniciales
void ControlBala::disparar(float _x, float _y) {
    balas.emplace_back(_x,_y);
    balas.emplace_back(_x+7,_y);
}

//Actualiza la posicion de todas las balas y limpia las que salen de la pantalla
void ControlBala::actualizar() {
    for(Bala& b : balas){
        b.dibujarBala();
        b.movimientoBala();
    }

    //Elimina las balas que salieron del limite superior
    balas.erase(
        std::remove_if(balas.begin(), balas.end(), [](Bala& b) {
            if (b.getY() <= Limite_vertical_superior) {
                b.limpiarUltimaPosicion();  // LIMPIA donde se dibujó por última vez
                return true;
            }
            return false;
        }),
        balas.end()
    );
}
