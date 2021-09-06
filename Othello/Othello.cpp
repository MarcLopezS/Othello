#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "./include/Tablero.h"

using namespace std;

int main()
{
    //SetConsoleOutputCP(CP_UTF8);
    //printf("\u25cf  \u25cb");
    Tablero juego;
    juego.play();
    return 0;

}
