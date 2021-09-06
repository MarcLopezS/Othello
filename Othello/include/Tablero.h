#ifndef TABLERO_H
#define TABLERO_H

const int MAX_SIZE_TABLERO = 10;

#include "./Jugador.h"
#include "string"

using namespace std;

class Tablero
{
public:
    Tablero();
    virtual ~Tablero();

    void inicializarTablero();

    void contarFichasJugador();

    void comprovarFila(int fil, int col, Jugador jugador, bool all);
    void comprovarColumna(int fil, int col, Jugador jugador, bool all);
    void comprovarDiagonalDerecha(int fil, int col, Jugador jugador, bool all);
    void comporvarDiagonalIzquierda(int fil, int col, Jugador jugador, bool all);

    bool checkCasilla(int fil, int col);
    void checkAllCasillas();

    void setTablero(string val, int fil, int col);

    void actualizarBola(Jugador jugador, int fila, int columna);

    void movementPlayer(Jugador jugador);

    void isWinner();

    void printTablero();
    void play();

protected:
private:
    string tablero[MAX_SIZE_TABLERO][MAX_SIZE_TABLERO]; //tablero de 10x10 pero 2 filas y 2 columnas
                                                        // son de máscara (filas y columnas 0 y 9), asi que realmente es de 8x8
    Jugador player1;
    Jugador player2;
    bool isMovementP1;
    bool isMovementP2;
};

#endif // TABLERO_H
