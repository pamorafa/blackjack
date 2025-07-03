#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include <algorithm>
#include <random>
#include "carta.h"

class Mazo
{
public:
    Mazo();
    void barajar();
    Carta repartirCarta();
    void resetear();
    void reiniciar();
private:
    std::vector<Carta> cartas;
};

#endif // MAZO_H
