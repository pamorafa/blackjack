#include "crupier.h"
#include <QDebug>

Crupier::Crupier() : Jugador("Crupier", 0) {}

// El crupier juega su turno automáticamente


// El crupier juega su turno automáticamente
void Crupier::jugarTurno(Mazo &mazo) {
    while (calcularPuntaje() < 17) {
        pedirCarta(mazo);  // El crupier pide una carta
    }

    // Verifica si el crupier se plantó o se pasó de 21
    int puntajeCrupier = calcularPuntaje();
    if (puntajeCrupier >= 17) {
        qDebug() << "El crupier se ha plantado con un puntaje de " << puntajeCrupier;
    } else if (puntajeCrupier > 21) {
        qDebug() << "El crupier se pasó de 21 y ha perdido.";
    }
}
