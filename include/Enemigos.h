#ifndef ENEMIGOS_H
#define ENEMIGOS_H

class Enemigos{
    protected:
        int lastX;
        int lastY;

    private:
        float x;
        float y;
        int ancho;
        int alto;
        int vida;
        float velocidadX;
        float velocidadY;
        bool activo;
        int daño;
        bool animar;
        int contadorAnimacion;

    public:
        //constructor
        Enemigos(float _x, float _y, int _ancho, int _alto, int _vida, float _velocidadX,
                 float _velocidadY, bool _activo, int _daño, bool _animar, int _contadorAnimacion)
        : lastX(-1),
          lastY(-1),
          x(_x), 
          y(_y),
          ancho(_ancho),
          alto(_alto),
          vida(_vida),
          velocidadX(_velocidadX),
          velocidadY(_velocidadY),
          activo(_activo),
          daño(_daño),
          animar(_animar),
          contadorAnimacion(_contadorAnimacion)
        {}
        
        //Metodos virtuales
        virtual void movimiento() = 0;
        virtual void disparar() = 0;
        virtual void dibujar() =0;

        //getters
        int getAncho() const { return ancho; }
        int getAlto() const { return alto; }
        float getVelocidadX() const { return velocidadX; }
        float getVelocidadY() const { return velocidadY; }
        float getX() const { return x; }
        float getY() const { return y; }
        bool getActivo() const { return activo; }
        bool getAnimar() const { return animar; }
        int getContadorAnimacion() const { return contadorAnimacion; }

        //setters
        void setVelocidadX(float nuevaVelocidadX) { velocidadX = nuevaVelocidadX; }
        void setVelocidadY(float nuevaVelocidadY) { velocidadY = nuevaVelocidadY; }
        void setX(float nuevoX) { x = nuevoX; }
        void setY(float nuevoY) { y = nuevoY; }
        void setAnimar(bool nuevoAnimar){ animar = nuevoAnimar; }
        void setContadorAnimacion(int nuevoContador){ contadorAnimacion = nuevoContador; }
        
        //Destructor virutal para ejecutar todos los destructores derivados
        virtual ~Enemigos() {}
};

#endif
