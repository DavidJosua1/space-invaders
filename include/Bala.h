#ifndef BALA_H
#define BALA_H

class Bala {
    private:
        float x;
        float y;
        int lastX;
        int lastY;
        float velocidadY;
        bool animar;
        int contadorAnimacion;
        int numeroCiclosAnimacion;
        bool activa;

    public:
        //Constructores
        Bala (float _x, float _y)
        : x(_x), 
          y(_y),
          lastX(-1),
          lastY(-1),
          velocidadY(1.4f),
          animar(true),
          contadorAnimacion(0),
          numeroCiclosAnimacion(1),
          activa (true)
        {}

        //Metodos de comportamiento
        void movimientoBala();
        void dibujarBala();
        void limpiarUltimaPosicion();

        //getters
        float getX() const { return x; }
        float getY() const { return y; }
};

#endif
