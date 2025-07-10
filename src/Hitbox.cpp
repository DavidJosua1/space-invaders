#include "Hitbox.h"

bool Hitbox:: colisionaCon(const Hitbox& otro) const {
    return (x < otro.x + otro.ancho &&
            x + ancho > otro.x &&
            y < otro.y + otro.alto &&
            y + alto > otro.y);
}
