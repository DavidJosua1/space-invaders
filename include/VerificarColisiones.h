#ifndef VERIFICARCOLISIONES_H
#define VERIFICARCOLISIONES_H

#include <vector>

#include "Enemigos.h"
#include "Bala.h"

class VerificarColisiones {

    public:
    
    static void EnemigoBalas(std::vector<Enemigos*>& enemigos, std::vector<Bala>& balas);
};

#endif
