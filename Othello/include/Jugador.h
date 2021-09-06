#ifndef JUGADOR_H
#define JUGADOR_H
#include "string"

using namespace std;

class Jugador
{
public:
    Jugador();
    virtual ~Jugador();

    void setSimbolo(string sim);
    string getSimbolo();
    void setNFichas(int fichas);
    int getNFichas();

protected:
private:
    string simbolo;
    int n_fichas;
};

#endif // JUGADOR_H
