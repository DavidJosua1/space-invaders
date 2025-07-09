#ifndef MENU_H
#define MENU_H

#include <windows.h>  // ← NECESARIO para que el compilador entienda qué es HANDLE

class Menu {
private:
    bool entrar;
    bool salir;
    bool calabera;
    HANDLE hConsole;
    int xDerecha;
    int YposStart;
    int YposSalir;
    int posicionActual;

public:
    Menu();

    void imprimirFondo();
    void imprimirTitulo();
    void imprimirOpciones();
    void Calabera1();
    void Calabera2();
    void limpiarCalabera();
    void alternarCalabera();
    void dibujarCalabera();
    void controlOpciones();
    void desplegarMenu();
    
    bool debeEntrar() const { return entrar; }
    bool debeSalir() const { return salir; }
};

#endif
