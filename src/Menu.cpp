#include "Menu.h"              // Incluye la definición de la clase Menu
#include "utilidades.h"        // Incluye funciones como moverCursor y limpiarZona
#include <windows.h>           // Para manipular consola de Windows (colores, cursor, teclas)
#include <cstdio>            // Entrada/salida estándar
#include <cstdlib>             // Para funciones como rand()
#include <conio.h>             // Para _kbhit() y _getch()

// Constructor: inicializa todas las variables del menú
Menu::Menu()
    : entrar(false),          // No entra al juego aún
      salir(false),           // No ha elegido salir aún
      calabera(true),         // Alterna calaveras (animación)
      hConsole(GetStdHandle(STD_OUTPUT_HANDLE)), // Obtiene el manejador de la consola
      xDerecha(91),           // Posición horizontal del menú y calavera
      YposStart(23),          // Fila para la opción START
      YposSalir(25),          // Fila para la opción SALIR
      posicionActual(YposStart) // El cursor comienza en START
{}

// Dibuja el fondo con estrellas aleatorias
void Menu::imprimirFondo(){
    for (int j = 0; j < 30; j++) {            // Recorre cada fila
        for (int i = 0; i < 120; i++) {       // Recorre cada columna
            moverCursor(i, j);               // Mueve el cursor a la posición actual
            int estrella = rand() % 100;     // Genera un número aleatorio de 0 a 99

            // Probabilidades de estrellas diferentes
            if (estrella < 2) {              // 2% de probabilidad
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                putchar('*');                // Estrella brillante
            } else if (estrella < 5) {       // 3% de probabilidad adicional
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                putchar('.');
            } else if (estrella < 7) {       // 2% más
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                putchar('o');
            } else {                         // 86% de espacios vacíos
                SetConsoleTextAttribute(hConsole, 0);
                putchar(' ');
            }
        }
    }
}

// Dibuja el título del juego en formato ASCII
void Menu::imprimirTitulo(){
    int yTexto = 9;                          // Línea inicial del título
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Verde brillante
    // Línea por línea se dibuja el arte ASCII del título
    moverCursor(0, yTexto++); printf("              .-')     _ (`-.    ('-.                  ('-.                       ");
    moverCursor(0, yTexto++); printf("             ( OO ).  ( (OO  )  ( OO ).-.            _(  OO)                      ");
    moverCursor(0, yTexto++); printf("            (_)---\\_)_.`     \\  / . --. /   .-----. (,------.                     ");
    moverCursor(0, yTexto++); printf("            /    _ |(__...--''  | \\-.  \\   '  .--./  |  .---'                     ");
    moverCursor(0, yTexto++); printf("            \\  :` `. |  /  | |.-'-'  |  |  |  |('-.  |  |                         ");
    moverCursor(0, yTexto++); printf("             '..`''.)|  |_.' | \\| |_.'  | /_) |OO  )(|  '--.                      ");
    moverCursor(0, yTexto++); printf("            .-._)   \\|  .___.'  |  .-.  | ||  |`-'|  |  .--'                      ");
    moverCursor(0, yTexto++); printf("            \\       /|  |       |  | |  |(_'  '--'\\  |  `---.                     ");
    moverCursor(0, yTexto++); printf("             `-----' `--'       `--' `--'   `-----'  `------'                     ");
    moverCursor(0, yTexto++); printf("              .-') _      (`-.     ('-.     _ .-') _     ('-.  _  .-')    .-')    ");
    moverCursor(0, yTexto++); printf("             ( OO ) )   _(OO  )_  ( OO ).-.( (  OO) )  _(  OO)( \\( -O )  ( OO ).  ");
    moverCursor(0, yTexto++); printf("  ,-.-') ,--./ ,--,',--(_/   ,. \\ / . --. / \\     .'_ (,------.,------. (_)---\\_) ");
    moverCursor(0, yTexto++); printf("  |  |OO)|   \\ |  |\\\\   \\   /(__/ | \\-.  \\  ,`'--..._) |  .---'|   /`. '/    _ |  ");
    moverCursor(0, yTexto++); printf("  |  |  \\|    \\|  | )\\   \\ /   /.-'-'  |  | |  |  \\  ' |  |    |  /  | |\\  :` `.  ");
    moverCursor(0, yTexto++); printf("  |  |(_/|  .     |/  \\   '   /, \\| |_.'  | |  |   ' |(|  '--. |  |_.' | '..`''.) ");
    moverCursor(0, yTexto++); printf(" ,|  |_.'|  |\\    |    \\     /__) |  .-.  | |  |   / : |  .--' |  .  '.'.-._)   \\ ");
    moverCursor(0, yTexto++); printf("(_|  |   |  | \\   |     \\   /     |  | |  | |  '--'  / |  `---.|  |\\  \\ \\       / ");
    moverCursor(0, yTexto++); printf("  `--'   `--'  `--'      `-'      `--' `--' `-------'  `------'`--' '--' `-----'  ");
}

// Dibuja la primera versión de la calavera ASCII
void Menu::Calabera1(){
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Rojo brillante
    int y = 9;
    moverCursor(xDerecha, y++); printf("       ______");
    moverCursor(xDerecha, y++); printf("    .-        -.");
    moverCursor(xDerecha, y++); printf("   /            \\");
    moverCursor(xDerecha, y++); printf("  |              |");
    moverCursor(xDerecha, y++); printf("  |,  .-.  .-.  ,|");
    moverCursor(xDerecha, y++); printf("  | )(_o/  \\o_)( |");
    moverCursor(xDerecha, y++); printf("  |/     /\\     \\|");
    moverCursor(xDerecha, y++); printf("  (_     ^^     _)");
    moverCursor(xDerecha, y++); printf("   \\__|IIIIII|__/");
    moverCursor(xDerecha, y++); printf("    | \\IIIIII/ |");
    moverCursor(xDerecha, y++); printf("    \\          /");
    moverCursor(xDerecha, y++); printf("     `--------`");
}

// Segunda versión de la calavera (cambia los ojos y boca para simular animación)
void Menu::Calabera2(){
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Rojo brillante
    int y = 9;
    moverCursor(xDerecha, y++); printf("       ______");
    moverCursor(xDerecha, y++); printf("    .-        -.");
    moverCursor(xDerecha, y++); printf("   /            \\");
    moverCursor(xDerecha, y++); printf("  |              |");
    moverCursor(xDerecha, y++); printf("  |,  .-.  .-.  ,|");
    moverCursor(xDerecha, y++); printf("  | )(---''---)( |");
    moverCursor(xDerecha, y++); printf("  |/     /\\     \\|");
    moverCursor(xDerecha, y++); printf("  (_     ^^     _)");
    moverCursor(xDerecha, y++); printf("   \\__|IIIIII|__/");
    moverCursor(xDerecha, y++); printf("    | \\      / |");
    moverCursor(xDerecha, y++); printf("    \\  \\IIII/  /");
    moverCursor(xDerecha, y++); printf("     `--------`");
}

// Limpia la zona donde se dibuja la calavera
void Menu::limpiarCalabera(){
    limpiarZona(xDerecha, 9, 20, 13); // x, y, ancho, alto
}

// Cambia de una calavera a otra
void Menu::alternarCalabera(){
    calabera = !calabera;
}

// Borra y dibuja la nueva calavera
void Menu::dibujarCalabera(){
    limpiarCalabera();
    if(calabera)
        Calabera1();
    else
        Calabera2();
}

// Controla la navegación del menú usando teclado
void Menu::controlOpciones() {
    moverCursor(xDerecha,YposStart); printf("  ");
    moverCursor(xDerecha,YposSalir); printf("  ");

    if (_kbhit()) {
        // Si se presiona flecha arriba y estamos en "SALIR", subimos a "START"
        if (GetAsyncKeyState(VK_UP) & 0x8000 && posicionActual == YposSalir)
            posicionActual = YposStart;

        // Si se presiona flecha abajo y estamos en "START", bajamos a "SALIR"
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 && posicionActual == YposStart)
            posicionActual = YposSalir;

        // Si se presiona ENTER y está en START, entra al juego
        if (GetAsyncKeyState(VK_RETURN) & 0x8000 && posicionActual == YposStart)
            entrar = true;

        // Si se presiona ENTER y está en SALIR, activa salir
        if (GetAsyncKeyState(VK_RETURN) & 0x8000 && posicionActual == YposSalir)
            salir = true;
    }
}

// Imprime las opciones y marca la actual con ">>"
void Menu::imprimirOpciones() {
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // blanco

    moverCursor(xDerecha, YposStart);
    if (posicionActual == YposStart)
        printf(">> START ");
    else
        printf("   START ");

    moverCursor(xDerecha, YposSalir);
    if (posicionActual == YposSalir)
        printf(">> SALIR ");
    else
        printf("   SALIR ");
}

// Método principal para desplegar el menú
void Menu::desplegarMenu(){
    system ("cls");           // Limpia pantalla
    imprimirFondo();          // Dibuja estrellas
    imprimirTitulo();         // Dibuja el título

    int cont = 0;             // Contador para animar la calavera

    while (entrar == false) {
        if (cont == 10) {     // Cada 10 ciclos, cambia la calavera
            dibujarCalabera();
            alternarCalabera();
            cont = 0;
        } else {
            cont++;
        }

        controlOpciones();   // Lee teclas
        imprimirOpciones(); // Actualiza las opciones

        if (salir == true)
            break;

        Sleep(30);           // Espera para evitar saturar la CPU
    }
}
