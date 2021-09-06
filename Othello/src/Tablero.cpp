#include "../include/Tablero.h"
#include <iostream>
#include <windows.h>
#include <conio.h>


using namespace std;

Tablero::Tablero()
{
    //player1.setSimbolo("\u25cf");
    //player2.setSimbolo("\u25cb");
    player1.setSimbolo("O");
    player2.setSimbolo("X");
    inicializarTablero();
    isMovementP1 = false;
    isMovementP2 = false;
}

Tablero::~Tablero()
{
    //dtor
}

void Tablero::inicializarTablero()
{
    for (int i = 0; i < MAX_SIZE_TABLERO; i++) //filas
    {
        for (int j = 0; j < MAX_SIZE_TABLERO; j++) //columnas
        {
            if ((i == 4 && j == 4) || (i == 5 && j == 5))
            {
                tablero[i][j] = player1.getSimbolo();
            }
            else
            {
                if ((i == 4 && j == 5) || (i == 5 && j == 4))
                {
                    tablero[i][j] = player2.getSimbolo();
                }
                else
                {
                    tablero[i][j] = " ";
                }
            }
        }
    }
}

void Tablero::contarFichasJugador()
{
    int n_fichas_p1 = 0, n_fichas_p2 = 0;

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (tablero[i][j] == player1.getSimbolo())
            {
                n_fichas_p1++;
            }

            if (tablero[i][j] == player2.getSimbolo())
            {
                n_fichas_p2++;
            }
        }
    }

    player1.setNFichas(n_fichas_p1);
    player2.setNFichas(n_fichas_p2);
}

void Tablero::comprovarFila(int fil, int col, Jugador jugador, bool all)
{

    Jugador actual, adversario;
    bool isMovement;
    jugador.getSimbolo() == player1.getSimbolo() ? actual = player1 : actual = player2;
    jugador.getSimbolo() == player1.getSimbolo() ? adversario = player2 : adversario = player1;
    jugador.getSimbolo() == player1.getSimbolo() ? isMovement = isMovementP1 : isMovement = isMovementP2;

    //Comprueba que está dentro del tablero
    if (col > 0 && col < MAX_SIZE_TABLERO - 1)
    {
        if (tablero[fil][col - 1] == adversario.getSimbolo())
        {
            //analiza el lado izquierdo de la fila de la posición que ha colocado el jugador
            for (int i = col - 1; i > 0; i--)
            {

                if (tablero[fil][i] != adversario.getSimbolo() && tablero[fil][i] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = col - 1; j > i; j--)
                        {
                            actualizarBola(actual, fil, j);
                        }
                    }
                }
                else
                {
                    if (tablero[fil][i] == " ")
                    {
                        break;
                    }
                }
            }
        }

        //Comprueba el lado derecho de la fila en donde se coloca la ficha
        if (tablero[fil][col + 1] == adversario.getSimbolo())
        {
            //analiza el lado derecho de la fila de la posicion que ha colocado el jugador
            for (int i = col + 1; i < MAX_SIZE_TABLERO - 1; i++)
            {
                if (tablero[fil][i] != adversario.getSimbolo() && tablero[fil][i] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = col + 1; j < i; j++)
                        {
                            actualizarBola(actual, fil, j);
                        }
                    }
                }
                else
                {
                    if (tablero[fil][i] == " ")
                    {
                        break;
                    }
                }
            }
        }
    }

    jugador.getSimbolo() == player1.getSimbolo() ? isMovementP1 = isMovement : isMovementP2 = isMovement;
}

void Tablero::comprovarColumna(int fil, int col, Jugador jugador, bool all)
{
    Jugador actual, adversario;
    bool isMovement;
    jugador.getSimbolo() == player1.getSimbolo() ? actual = player1 : actual = player2;
    jugador.getSimbolo() == player1.getSimbolo() ? adversario = player2 : adversario = player1;
    jugador.getSimbolo() == player1.getSimbolo() ? isMovement = isMovementP1 : isMovement = isMovementP2;

    //Comprueba que está dentro del tablero
    if (fil > 0 && fil < MAX_SIZE_TABLERO - 1)
    {
        //Comprueba el lado de arriba de la columna en donde se coloca la ficha
        if (tablero[fil - 1][col] == adversario.getSimbolo())
        {
            //analiza el lado de arriba de la columna de la posición que ha colocado el jugador
            for (int i = fil - 1; i > 0; i--)
            {

                if (tablero[i][col] != adversario.getSimbolo() && tablero[i][col] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = fil - 1; j > i; j--)
                        {
                            actualizarBola(actual, j, col);
                        }
                    }
                }
                else
                {
                    if (tablero[i][col] == " ")
                    {
                        break;
                    }
                }
            }
        }

        //Comprueba el lado de abajo de la columna en donde se coloca la ficha
        if (tablero[fil + 1][col] == adversario.getSimbolo())
        {
            //analiza el lado de abajo de la columna de la posicion que ha colocado el jugador
            for (int i = fil + 1; i < MAX_SIZE_TABLERO - 1; i++)
            {
                if (tablero[i][col] != adversario.getSimbolo() && tablero[i][col] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = fil + 1; j < i; j++)
                        {
                            actualizarBola(actual, j, col);
                        }
                    }
                }
                else
                {
                    if (tablero[i][col] == " ")
                    {
                        break;
                    }
                }
            }
        }
    }

    jugador.getSimbolo() == player1.getSimbolo() ? isMovementP1 = isMovement : isMovementP2 = isMovement;
}

void Tablero::comprovarDiagonalDerecha(int fil, int col, Jugador jugador, bool all)
{

    Jugador actual, adversario;
    bool isMovement;
    jugador.getSimbolo() == player1.getSimbolo() ? actual = player1 : actual = player2;
    jugador.getSimbolo() == player1.getSimbolo() ? adversario = player2 : adversario = player1;
    jugador.getSimbolo() == player1.getSimbolo() ? isMovement = isMovementP1 : isMovement = isMovementP2;

    //Comprueba que está dentro del tablero
    if (fil > 0 && fil < MAX_SIZE_TABLERO - 1 && col > 0 && col < MAX_SIZE_TABLERO - 1)
    {
        //Comprueba la casilla de arriba a la derecha en donde se coloca la ficha
        if (tablero[fil - 1][col + 1] == adversario.getSimbolo())
        {
            int col_aux = col + 1;
            //analiza el lado de arriba de la columna de la posición que ha colocado el jugador
            for (int i = fil - 1; i > 0; i--)
            {

                if (tablero[i][col_aux] != adversario.getSimbolo() && tablero[i][col_aux] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        col_aux = col + 1;
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = fil - 1; j > i; j--)
                        {
                            actualizarBola(actual, j, col_aux);
                            col_aux++;
                        }
                    }
                }
                else
                {
                    if (tablero[i][col_aux] == " ")
                    {
                        break;
                    }
                }

                col_aux++;
            }
        }

        //Comprueba la casilla de abajo a la izquierda en donde se coloca la ficha
        if (tablero[fil + 1][col - 1] == adversario.getSimbolo())
        {
            int col_aux = col - 1;
            //analiza el lado de abajo de la columna de la posicion que ha colocado el jugador
            for (int i = fil + 1; i < MAX_SIZE_TABLERO - 1; i++)
            {
                if (tablero[i][col_aux] != adversario.getSimbolo() && tablero[i][col_aux] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        col_aux = col - 1;
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = fil + 1; j < i; j++)
                        {
                            actualizarBola(actual, j, col_aux);
                            col_aux--;
                        }
                    }
                }
                else
                {
                    if (tablero[i][col_aux] == " ")
                    {
                        break;
                    }
                }

                col_aux--;
            }
        }
    }
    jugador.getSimbolo() == player1.getSimbolo() ? isMovementP1 = isMovement : isMovementP2 = isMovement;
}

void Tablero::comporvarDiagonalIzquierda(int fil, int col, Jugador jugador, bool all)
{

    Jugador actual, adversario;
    bool isMovement;
    jugador.getSimbolo() == player1.getSimbolo() ? actual = player1 : actual = player2;
    jugador.getSimbolo() == player1.getSimbolo() ? adversario = player2 : adversario = player1;
    jugador.getSimbolo() == player1.getSimbolo() ? isMovement = isMovementP1 : isMovement = isMovementP2;

    //Comprueba que está dentro del tablero
    if (fil > 0 && fil < MAX_SIZE_TABLERO - 1 && col > 0 && col < MAX_SIZE_TABLERO - 1)
    {
        //Comprueba la casilla de arriba a la izquerda en donde se coloca la ficha
        if (tablero[fil - 1][col - 1] == adversario.getSimbolo())
        {
            int col_aux = col - 1;
            //analiza el lado de arriba de la columna de la posición que ha colocado el jugador
            for (int i = fil - 1; i > 0; i--)
            {

                if (tablero[i][col_aux] != adversario.getSimbolo() && tablero[i][col_aux] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        col_aux = col - 1;
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = fil - 1; j > i; j--)
                        {
                            actualizarBola(actual, j, col_aux);
                            col_aux--;
                        }
                    }
                }
                else
                {
                    if (tablero[i][col_aux] == " ")
                    {
                        break;
                    }
                }

                col_aux--;
            }
        }

        //Comprueba la casilla de abajo a la derecha en donde se coloca la ficha
        if (tablero[fil + 1][col + 1] == adversario.getSimbolo())
        {
            int col_aux = col + 1;
            //analiza el lado de abajo de la columna de la posicion que ha colocado el jugador
            for (int i = fil + 1; i < MAX_SIZE_TABLERO - 1; i++)
            {
                if (tablero[i][col_aux] != adversario.getSimbolo() && tablero[i][col_aux] != " ")
                {
                    isMovement = true;

                    if (!all)
                    {
                        col_aux = col + 1;
                        //actualiza todas las bolas enemigas que hay entre las piezas del jugador
                        for (int j = fil + 1; j < i; j++)
                        {
                            actualizarBola(actual, j, col_aux);
                            col_aux++;
                        }
                    }
                }
                else
                {
                    if (tablero[i][col_aux] == " ")
                    {
                        break;
                    }
                }

                col_aux++;
            }
        }
    }

    jugador.getSimbolo() == player1.getSimbolo() ? isMovementP1 = isMovement : isMovementP2 = isMovement;
}

bool Tablero::checkCasilla(int fil, int col)
{

    bool isEmpty = true;

    if (tablero[fil][col] != " ")
    {
        isEmpty = false;
    }

    return isEmpty;
}

void Tablero::checkAllCasillas()
{
    for (int i = 1; i < MAX_SIZE_TABLERO - 1; i++)
    {
        for (int j = 1; j < MAX_SIZE_TABLERO - 1; j++)
        {
            comprovarFila(i, j, player1, true);
            comprovarColumna(i, j, player1, true);
            comprovarDiagonalDerecha(i, j, player1, true);
            comporvarDiagonalIzquierda(i, j, player1, true);
            comprovarFila(i, j, player2, true);
            comprovarColumna(i, j, player2, true);
            comprovarDiagonalDerecha(i, j, player2, true);
            comporvarDiagonalIzquierda(i, j, player2, true);
        }
    }
}

void Tablero::setTablero(string val, int fil, int col)
{
    tablero[fil][col] = val;
}

void Tablero::actualizarBola(Jugador jugador, int fila, int columna)
{
    tablero[fila][columna] = jugador.getSimbolo();
}

void Tablero::movementPlayer(Jugador jugador)
{
    int fila = 0;
    int columna = 0;
    isMovementP1 = false;
    isMovementP2 = false;

    while ((!isMovementP1 && jugador.getSimbolo() == "O") || (!isMovementP2 && jugador.getSimbolo() == "X"))
    {
        cout << "\n TURNO DEL JUGADOR " << jugador.getSimbolo() << endl;
        cout << "\n Introduce la fila: ";
        cin >> fila;
        while (fila < 1 || fila > 8)
        {
            printTablero();
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n Introduce la fila: ";
            cin >> fila;
        }
        cout << "\n Introduce la columna: ";
        cin >> columna;
        while (columna < 1 || columna > 8)
        {
            printTablero();
            cin.clear();
            cin.ignore(100, '\n');
            cout << " Fila : " << fila << endl;
            cout << "\n Introduce la columna: ";
            cin >> columna;
        }

        if (checkCasilla(fila, columna)) //si la casilla está vacía
        {
            tablero[fila][columna] = jugador.getSimbolo();
            comprovarFila(fila, columna, jugador, false);
            comprovarColumna(fila, columna, jugador, false);
            comprovarDiagonalDerecha(fila, columna, jugador, false);
            comporvarDiagonalIzquierda(fila, columna, jugador, false);

            if ((!isMovementP1 && jugador.getSimbolo() == "O") || (!isMovementP2 && jugador.getSimbolo() == "X")) //ESTA BIEN???????????
            {

                tablero[fila][columna] = " ";
                printTablero();
                cout << " Esta posición no es válida" << endl;
            }
        }
        else
        {
            printTablero();
            cout << " La casilla solicitada está ocupada" << endl;
        }
    }
}

void Tablero::isWinner()
{
    if (player1.getNFichas() > player2.getNFichas())
    {
        cout << "Ha ganado el Jugador " << player1.getSimbolo() << "!!! Enhorabuena!!!! :)";
    }
    else
    {
        if (player1.getNFichas() < player2.getNFichas())
        {
            cout << "Ha ganado el Jugador " << player2.getSimbolo() << "!!! Enhorabuena!!!! :)";
        }
        else
        {
            cout << "EMPATE!! nadie gana...";
        }
    }
}

void Tablero::printTablero()
{
    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    cout << "  ";
    for (int k = 1; k < 9; k++)
    {
        cout << "  " << k << " ";
    }

    cout << "\n    -------------------------------" << endl;

    for (int i = 1; i < MAX_SIZE_TABLERO - 1; i++)
    {
        cout << " " << i << " ";
        for (int j = 1; j < MAX_SIZE_TABLERO - 1; j++)
        {

            cout << "| " << (tablero[i][j] == " " ? " " : tablero[i][j]) << " ";
        }
        cout << "|" << endl;
        cout << "    -------------------------------" << endl;
    }

    contarFichasJugador();
    cout << "\n Numero de fichas de Jugador " << player1.getSimbolo() << ": " << player1.getNFichas();
    cout << "\n Numero de fichas de Jugador " << player2.getSimbolo() << ": " << player2.getNFichas() << "\n"
         << endl;
}

void Tablero::play()
{
    SetConsoleOutputCP(CP_UTF8);
    inicializarTablero();
    printTablero();

    bool isPlayer1 = true;

    do
    {
        if (isPlayer1) //Jugador 1
        {
            checkAllCasillas();
            if (isMovementP1)
            {
                movementPlayer(player1);
            }

            isPlayer1 = false;
            printTablero();
        }
        else
        { //Jugador 2
            checkAllCasillas();
            if (isMovementP2)
            {
                movementPlayer(player2);
            }

            isPlayer1 = true;
            printTablero();
        }

    } while (isMovementP1 || isMovementP2 || (isMovementP1 && isMovementP2));

    isWinner();
}
