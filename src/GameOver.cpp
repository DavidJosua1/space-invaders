#include "GameOver.h"

#include <windows.h>
#include <cstdio>

#include "Constantes.h"
#include "utilidades.h"

void GameOver::dibujarFondo() {
    // Limpiar pantalla con estrellas
    for (int j = 0; j < 30; j++) {
        for (int i = 0; i < 119; i++) {
            moverCursor(i, j);
            int estrella = rand() % 100;
            if (estrella < 2) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                putchar('*');
            }
            else if (estrella < 5) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                putchar('.');
            }
            else if (estrella < 7) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                putchar('o');
            }
            else {
                SetConsoleTextAttribute(hConsole, 0);
                putchar(' ');
            }
        }
    }
}

void GameOver::imprimirTexto() {
    // T�tulo ASCII
    const char* titulo[] = {
        "_______  _______  _______  _______    _______           _______  _______",
        "(  ____ \\(  ___  )(       )(  ____ \\  (  ___  )|\\     /|(  ____ \\(  ____ )",
        "| (    \\/| (   ) || () () || (    \\/  | (   ) || )   ( || (    \\/| (    )|",
        "| |      | (___) || || || || (__      | |   | || |   | || (__    | (____)|",
        "| | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __)",
        "| | \\_  )| (   ) || |   | || (        | |   | | \\ \\_/ / | (      | (\\ (   ",
        "| (___) || )   ( || )   ( || (____/\\  | (___) |  \\   /  | (____/\\| ) \\ \\__",
        "(_______)|/     \\||/     \\|(_______/  (_______)   \\_/   (_______/|/   \\__/"
    };

    int numLineas = sizeof(titulo) / sizeof(titulo[0]);

    for (int i = 0; i < numLineas; i++) {
        int longitudLinea = (int)strlen(titulo[i]);
        int posX = (Ancho - longitudLinea) / 2;
        int posY = 5 + i;
        moverCursor(posX, posY);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("%s", titulo[i]);
    }

    // Restaurar color normal
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GameOver::dibujarCalavera1() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    int y1 = y;
    moverCursor(x, y1++); printf("       ______");
    moverCursor(x, y1++); printf("    .-        -.");
    moverCursor(x, y1++); printf("   /            \\");
    moverCursor(x, y1++); printf("  |              |");
    moverCursor(x, y1++); printf("  |,  .-.  .-.  ,|");
    moverCursor(x, y1++); printf("  | )(_o/  \\o_)( |");
    moverCursor(x, y1++); printf("  |/     /\\     \\|");
    moverCursor(x, y1++); printf("  (_     ^^     _)");
    moverCursor(x, y1++); printf("   \\__|IIIIII|__/");
    moverCursor(x, y1++); printf("    | \\IIIIII/ |");
    moverCursor(x, y1++); printf("    \\          /");
    moverCursor(x, y1++); printf("     `--------`");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Funci�n para dibujar la calavera en estado 2
void GameOver::dibujarCalavera2() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    int y1 = y;
    moverCursor(x, y1++); printf("       ______");
    moverCursor(x, y1++); printf("    .-        -.");
    moverCursor(x, y1++); printf("   /            \\");
    moverCursor(x, y1++); printf("  |              |");
    moverCursor(x, y1++); printf("  |,  .-.  .-.  ,|");
    moverCursor(x, y1++); printf("  | )(---''---)( |");
    moverCursor(x, y1++); printf("  |/     /\\     \\|");
    moverCursor(x, y1++); printf("  (_     ^^     _)");
    moverCursor(x, y1++); printf("   \\__|IIIIII|__/");
    moverCursor(x, y1++); printf("    | \\      / |");
    moverCursor(x, y1++); printf("    \\  \\IIII/  /");
    moverCursor(x, y1++); printf("     `--------`");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Funci�n para borrar la calavera (solo el �rea que ocupa)
void GameOver::borrarCalavera() {
    int y1 = y;
    for (int i = 0; i < 13; i++) {
        moverCursor(x, y1 + i);
        printf("                    "); // 20 espacios para borrar
    }
}

void GameOver::desplegarJuegoTerminado() {
    system ("cls");

    while (true) {
        dibujarFondo();
        imprimirTexto();

        if (animar) dibujarCalavera1();
        else dibujarCalavera2();

        Sleep(300);
        borrarCalavera();

        animar = !animar;
    }
}
