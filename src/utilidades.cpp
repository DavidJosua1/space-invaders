// utilidades.cpp (or directly in utilidades.h if functions are inline/simple)
#include "utilidades.h"

#include <windows.h>

void moverCursor(int x, int y) {
    COORD coord;
    coord.X = static_cast<short>(x);
    coord.Y = static_cast<short>(y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void limpiarZona(int x, int y, int ancho, int alto) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {static_cast<short>(x), static_cast<short>(y)};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwSize = static_cast<DWORD>(ancho);

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    for (int i = 0; i < alto; ++i) {
        FillConsoleOutputCharacter(hConsole, ' ', dwSize, coord, &cCharsWritten);
        coord.Y++;
    }
}

void ocultarCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // set the cursor visibility
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
