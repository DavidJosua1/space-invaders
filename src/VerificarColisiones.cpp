#include "VerificarColisiones.h"

void VerificarColisiones::EnemigoBalas(std::vector<Enemigos*>& enemigos, std::vector<Bala>& balas, Avioncito& avioncito) {
    for (auto& bala : balas) {
        if (!bala.getActiva()) continue; // Si tienes ese método

        for (auto& enemigo : enemigos) {
            if (!enemigo->getActivo()) continue;

            if (bala.getHitbox().colisionaCon(enemigo->getHitbox())) {
                // ↓↓↓ Lógica de colisión ↓↓↓
                bala.setActiva(false);               // Método que debes tener en Bala
                enemigo->setVida(enemigo->getVida() - avioncito.getDaño()); // Métodos que podrías implementar
                enemigo->setAnimar(true);

                if (enemigo->getVida() <= 0) {
                    enemigo->setActivo(false);
                }

                break; // la bala ya colisionó, no sigas verificando
            }
        }
    }
}

void VerificarColisiones::AvioncitoEnemigo(std::vector<Enemigos*>& enemigos, Avioncito& avioncito) {
    for(auto& enemigo : enemigos){
        if(!enemigo->getActivo()) continue;

        if(enemigo->getHitbox().colisionaCon(avioncito.getHitbox())){
            enemigo->setVida(enemigo->getVida() - avioncito.getDaño());
            avioncito.setVida(avioncito.getVida() - 1);
            
            if(enemigo->getVida() <= 0) {
                enemigo->setActivo(false);
            }
            if(avioncito.getVida() <= 0) {
                avioncito.limpiarAvion();
                avioncito.setActivo(false);
            }
        }
    }
}
