#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include "carta.h"
#include "mazo.h"

class Jugador {
public:
    Jugador(const std::string &nombre, int saldoInicial);

    void pedirCarta(Mazo &mazo);
    void plantarse();
    int calcularPuntaje() const;
    void apostar(int cantidad);
    void reiniciarMano();

    void ganarApuesta();       // Recupera 2 veces la apuesta
    void ganarBlackJack();
    void recuperarApuesta();   // Recupera la apuesta en caso de empate

    std::string getNombre() const;
    int getSaldo() const;
    int getApuesta() const;
    const std::vector<Carta>& getMano() const;

private:
    std::string nombre;
    std::vector<Carta> mano;
    int saldo;
    int apuesta;
    bool plantado;
};

#endif // JUGADOR_H
