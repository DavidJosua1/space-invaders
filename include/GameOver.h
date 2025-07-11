#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <windows.h>

#include "Constantes.h"

class GameOver {
    private: 
        HANDLE hConsole;
        int anchoC;
        int x;
        int y;
        bool animar;
        
    public:
        //Constructor
        GameOver()
        : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)),
          anchoC(20),
          x((Ancho-anchoC)/2),
          y(18),
          animar(true)
        {}

        //Funciones para el GameOver
        void dibujarFondo();
        void imprimirTexto();
        void dibujarCalavera1();
        void dibujarCalavera2();
        void borrarCalavera();
        void desplegarJuegoTerminado();
};

#endif
