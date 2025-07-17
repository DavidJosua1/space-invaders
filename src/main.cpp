// Programa: Juego de naves en C++
#include <iostream>       // Para entrada/salida por consola
#include <windows.h>      // Para funciones de consola específicas de Windows
#include <ctime>          // Para funciones relacionadas con el tiempo
#include <conio.h>        // Para capturar teclas sin esperar Enter
#include <vector>         // Para usar std::vector (arreglo dinámico)
#include <cmath>
#include <algorithm>
#include <SFML/Audio.hpp>//para audio

#include "utilidades.h"   // Archivo de utilidades personalizadas (como moverCursor)
#include "Menu.h"
#include "Constantes.h"
#include "Bala.h"
#include "ControlBala.h"
#include "Avioncito.h"
#include "Enemigos.h"
#include "Fantasmita.h"
#include "ControlFantasmitas.h"
#include "Hitbox.h"
#include "VerificarColisiones.h"
#include "GameOver.h"

void procesarEntrada(Avioncito& nave, ControlBala& balaJugador);

int main() {
    // Semilla para números aleatorios (necesaria para que el fondo del menú sea aleatorio)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf:: Music musicaMenu;
    sf:: Music musicaJuego;

    if (musicaMenu.openFromFile("assets/MusicaMenu.ogg")) {
    musicaMenu.play();
    }

    // Ocultar cursor
    ocultarCursor();
    Menu MenuInicial;

    GameOver JuegoTerminado;
    bool game_over = false;

    MenuInicial.desplegarMenu();
    if(MenuInicial.debeEntrar()){
        musicaMenu.stop();

        if (musicaJuego.openFromFile("assets/MusicaJuego.ogg")) {
            musicaJuego.play();
        }

        system ("cls");
        ControlFantasmitas controlador;
        Avioncito avion(50,25);
        ControlBala balasJugador;

        // Para el cronometro
        DWORD tiempoAnterior = GetTickCount();

        int contBajada = 0;
        bool grupo = true;
        int segundo = 0;
        int decenaSegundo = 0;
        int minutos = 0;
        
        //Incrementos de velocidad
        bool velocidad1 = true;
        bool velocidad2 = true;
        bool velocidad3 = true;
        bool velocidad4 = true;
        bool velocidadfinal = true;

        float velocidadX = 0.075f;
        float velocidadY = 0.01875f;

        bool sprint = true;
        bool antiSprint = true;

        // Agrega fantasmitas al juego (columnas, filas, x inicial, y inicial, separación horizontal)
        controlador.agregarFantasmitas(1, 11, 8, 2, 5, velocidadX, velocidadY); 
        controlador.agregarFantasmitas(1, 10, 13, 7, 5, velocidadX, velocidadY); 
        controlador.agregarFantasmitas(1, 11, 8, 12, 5, velocidadX, velocidadY); 
        
        int intervaloSpawn = 267; // valor por defecto

        // Bucle principal del juego
        while (true) {
            // Determinar en qué fase estás
            if (minutos == 0 && decenaSegundo <= 4 && segundo <5) {
                intervaloSpawn = 267;
            } else if (minutos == 0 && decenaSegundo == 4 && segundo >= 5) {
                intervaloSpawn = 133;
            } else if (minutos == 1 && decenaSegundo == 1 && segundo >= 5) {
                intervaloSpawn = 89;
            } else if (minutos == 1 && decenaSegundo == 4 && segundo >= 5) {
                intervaloSpawn = 267;
            } else if (minutos == 1 && decenaSegundo == 5 && segundo >= 9) {
                intervaloSpawn = 67;
            } else if (minutos == 2 && decenaSegundo == 2 && segundo >= 8) {
                intervaloSpawn = 11;
            }

            if (contBajada >= intervaloSpawn) {
                if(grupo) {
                    controlador.agregarFantasmitas(1, 10, 13, 2, 5, velocidadX, velocidadY); 
                }else {
                    controlador.agregarFantasmitas(1, 11, 8, 2, 5, velocidadX, velocidadY); 
                }
                contBajada = 0;
                grupo = !grupo;
            }

            if (GetTickCount() - tiempoAnterior >= 1000) {
                segundo++;
                tiempoAnterior = GetTickCount();
            }

            if(segundo == 10){
                decenaSegundo ++;
                segundo = 0;
            }
            
            if(decenaSegundo == 6){
                minutos ++;
                decenaSegundo = 0;
            }

            moverCursor(58,0);
            std::cout << "0" << minutos << ":" << decenaSegundo << segundo;  
            
            //
            if(minutos == 0 && decenaSegundo == 4 && segundo == 5 && velocidad1){
                velocidadX *= 2.0f;
                velocidadY *= 2.0f;
                velocidad1 = false;
                controlador.establecerVelocidad(velocidadX, velocidadY);
            }

            if(minutos == 0 && decenaSegundo == 5 && segundo == 9 && sprint){
                antiSprint = true;
                velocidadX *= 3;
                velocidadY *= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                sprint = false;
            }
            
            if(minutos == 1 && decenaSegundo == 0 && segundo == 0 && antiSprint) {
                sprint = true;
                velocidadX /= 3;
                velocidadY /= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                antiSprint = false;
            }

            if(minutos == 1 && decenaSegundo == 1 && segundo == 5 && velocidad2){
                velocidadX *= (3.0f / 2.0f);
                velocidadY *= (3.0f / 2.0f);
                velocidad2 = false;
                controlador.establecerVelocidad(velocidadX, velocidadY);
            }

            if(minutos == 1 && decenaSegundo == 2 && segundo == 9 && sprint){
                antiSprint = true;
                velocidadX *= 3;
                velocidadY *= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                sprint = false;
            }
            
            if(minutos == 1 && decenaSegundo == 3 && segundo == 0 && antiSprint) {
                sprint = true;
                velocidadX /= 3;
                velocidadY /= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                antiSprint = false;
            }
            
            if(minutos == 1 && decenaSegundo == 4 && segundo == 4 && velocidad3){
                velocidadX *= (2.0f / 6.0f);
                velocidadY *= (2.0f / 6.0f);
                velocidad3 = false;
                controlador.establecerVelocidad(velocidadX, velocidadY);
            }

            if(minutos == 1 && decenaSegundo == 5 && segundo == 9 && velocidad4){
                velocidadX *= 4.0f;
                velocidadY *= 4.0f;
                velocidad4 = false;
                controlador.establecerVelocidad(velocidadX, velocidadY);

                avion.setVelocidadX(avion.getVelocidadX()*2);
                avion.setDaño(2);
            }
            
            //2:14
            if(minutos == 2 && decenaSegundo == 1 && segundo == 4 && sprint){
                antiSprint = true;
                velocidadX *= 3;
                velocidadY *= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                sprint = false;
            }
            
            if(minutos == 2 && decenaSegundo == 1 && segundo == 5 && antiSprint) {
                sprint = true;
                velocidadX /= 3;
                velocidadY /= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                antiSprint = false;
            }

            //2:19
            if(minutos == 2 && decenaSegundo == 1 && segundo == 9 && sprint){
                antiSprint = true;
                velocidadX *= 3;
                velocidadY *= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                sprint = false;
            }
            
            if(minutos == 2 && decenaSegundo == 2 && segundo == 0 && antiSprint) {
                sprint = true;
                velocidadX /= 3;
                velocidadY /= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                antiSprint = false;
            }

            //2:24
            if(minutos == 2 && decenaSegundo == 2 && segundo == 4 && sprint){
                antiSprint = true;
                velocidadX *= 3;
                velocidadY *= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                sprint = false;
            }
            
            if(minutos == 2 && decenaSegundo == 2 && segundo == 5 && antiSprint) {
                sprint = true;
                velocidadX /= 3;
                velocidadY /= 6;
                controlador.establecerVelocidad(velocidadX, velocidadY);
                antiSprint = false;
            }

            //2:28
            
            if(minutos == 2 && decenaSegundo == 2 && segundo == 8 && velocidadfinal){
                velocidadX *= 3;
                velocidadY *= 6;
                velocidadfinal = false;
                controlador.establecerVelocidad(velocidadX, velocidadY);
            }

            controlador.actualizarFantasmita();  // Mueve y dibuja todos los fantasmitas
            if(controlador.comprobarReboteConjunto()) {                 
                controlador.cambiarDireccionTodos();
                controlador.reiniciarReboteConjunto();
            }

            balasJugador.actualizar();
            balasJugador.TiempoCargaDisparo();

            avion.dibujar();
            procesarEntrada(avion, balasJugador);

            VerificarColisiones::EnemigoBalas(controlador.getEnemigos(), balasJugador.getBalas(), avion);
            VerificarColisiones::AvioncitoEnemigo(controlador.getEnemigos(), avion);
    
            controlador.comprobarLlegadaInvasora(avion);
            controlador.eliminarFantasmitasInactivos();
            balasJugador.limpiarBalasInactivas();
            
            if(!avion.getEstado()) { 
                game_over = true;
                break;
            }
            contBajada++;
            Sleep(30);  // Espera 30 ms (33 FPS aprox.)
        }
    }

    if(game_over){
        musicaJuego.stop();
        JuegoTerminado.desplegarJuegoTerminado();
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
