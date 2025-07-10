#ifndef HITBOX_H
#define HITBOX_H

class Hitbox {
    private:
        int x;
        int y;
        int ancho;
        int alto;

    public:
        //Constructor
        Hitbox(int _x, int _y, int _ancho, int _alto)
        : x(_x), 
          y(_y),
          ancho(_ancho), 
          alto(_alto) 
        {}

        //Metodo para detectar colision entre dos hitbox
        bool colisionaCon(const Hitbox& otro) const ;
};  

#endif
