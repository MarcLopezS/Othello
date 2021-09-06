#include "../include/Jugador.h"

Jugador::Jugador()
{
    //ctor
}

Jugador::~Jugador()
{
    //dtor
}

void Jugador::setSimbolo(string sim)
{
    simbolo = sim;
}

string Jugador::getSimbolo()
{
    return simbolo;
}

void Jugador::setNFichas(int fichas)
{
    n_fichas = fichas;
}

int Jugador::getNFichas()
{
    return n_fichas;
}