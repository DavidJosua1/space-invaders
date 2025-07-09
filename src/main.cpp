// Programa: Juego de naves en C++
#include "utilidades.h"   // Archivo de utilidades personalizadas (como moverCursor)
#include "Menu.h"
#include "marcianito.h"
#include "controlMarcianitos.h"
#include <iostream>       // Para entrada/salida por consola
#include <windows.h>      // Para funciones de consola específicas de Windows
#include <ctime>          // Para funciones relacionadas con el tiempo
#include <conio.h>        // Para capturar teclas sin esperar Enter
#include <vector>         // Para usar std::vector (arreglo dinámico)
#include <cmath>
#include <algorithm>
#include "Constantes.h"
#include "Bala.h"
#include "ControlBala.h"
#include "Avioncito.h"
#include "Enemigos.h"
#include "Fantasmita.h"
#include "ControlFantasmitas.h"

void procesarEntrada(Avioncito& nave, ControlBala& balaJugador);

int main() {
    // Semilla para números aleatorios (necesaria para que el fondo del menú sea aleatorio)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Ocultar cursor
    ocultarCursor();
    Menu MenuInicial;
    MenuInicial.desplegarMenu();
    if(MenuInicial.debeEntrar()){
        system ("cls");
        ControlFantasmitas controlador;
        Avioncito tungtungsahur(20,25);
        ControlBala balasJugador;

        // Agrega fantasmitas al juego (columnas, filas, x inicial, y inicial, separación horizontal)
        controlador.agregarFantasmitas(1, 11, 8, 1, 5); 
        controlador.agregarFantasmitas(1, 10, 13, 6, 5); 
        controlador.agregarFantasmitas(1, 11, 8, 11, 5); 
        controlador.agregarFantasmitas(1, 10, 13, 16, 5); 

        // Bucle principal del juego
        while (true) {
            controlador.actualizarFantasmita();  // Mueve y dibuja todos los fantasmitas
            if(controlador.comprobarReboteConjunto()) {                 
                controlador.cambiarDireccionTodos();
                controlador.reiniciarReboteConjunto();
                controlador.bajarFantasmitas();
            }

            tungtungsahur.dibujar();

            procesarEntrada(tungtungsahur,balasJugador);
            balasJugador.actualizar();
            balasJugador.TiempoCargaDisparo();
            Sleep(30);  // Espera 100 ms (10 FPS aprox.)
        }
    }
    return 0;
}

void procesarEntrada(Avioncito& nave, ControlBala& balasJugador) {
    if (_kbhit()) {
        if (GetAsyncKeyState('W') & 0x8000) nave.moverArriba();
        if (GetAsyncKeyState('S') & 0x8000) nave.moverAbajo();
        if (GetAsyncKeyState('A') & 0x8000) nave.moverIzquierda();
        if (GetAsyncKeyState('D') & 0x8000) nave.moverDerecha();
        if  (GetAsyncKeyState(VK_SPACE) & 0x8000 && balasJugador.getDisparoHabilitado()) {
            balasJugador.disparar(nave.getX(),nave.getY()-1);
            balasJugador.setDisparoHabilitado(false);
        }
    }
}
