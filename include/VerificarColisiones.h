#ifndef VERIFICARCOLISIONES_H
#define VERIFICARCOLISIONES_H

#include <vector>

#include "Enemigos.h"
#include "Bala.h"
#include "Avioncito.h"

class VerificarColisiones {
    public:
    
    static void EnemigoBalas(std::vector<Enemigos*>& enemigos, std::vector<Bala>& balas);
    static void AvioncitoEnemigo(std::vector<Enemigos*>& enemigos, Avioncito& Avioncito);
};

#endif
