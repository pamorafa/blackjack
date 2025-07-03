#ifndef CRUPIER_H
#define CRUPIER_H

#include "jugador.h"

class Crupier : public Jugador {
public:
    Crupier();

    void jugarTurno(Mazo &mazo); // Sigue las reglas del crupier
};

#endif // CRUPIER_H
