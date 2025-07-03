#include "jugador.h"
#include "carta.h"
#include <stdexcept>

Jugador::Jugador(const std::string &nombre, int saldoInicial)
    : nombre(nombre), saldo(saldoInicial), apuesta(0), plantado(false) {}

// Agrega una carta a la mano
void Jugador::pedirCarta(Mazo &mazo) {
    if (!plantado) {
        Carta carta = mazo.repartirCarta();
        mano.push_back(carta);
    }
}

// Marca al jugador como plantado
void Jugador::plantarse() {
    plantado = true;
}




// El jugador gana la apuesta (recupera 2 veces su apuesta)
void Jugador::ganarApuesta() {
    saldo += 2 * apuesta; // Gana el doble de lo que apostó
    apuesta = 0;          // Reinicia la apuesta
}

void Jugador::ganarBlackJack() {
    saldo += 2 * apuesta; // Gana el doble de lo que apostó
    saldo += apuesta / 2;
    apuesta = 0;          // Reinicia la apuesta
}

// El jugador recupera su apuesta (en caso de empate)
void Jugador::recuperarApuesta() {
    saldo += apuesta;     // Recupera la cantidad apostada
    apuesta = 0;          // Reinicia la apuesta
}


// Calcula el puntaje de la mano actual
int Jugador::calcularPuntaje() const {
    int total = 0;
    int ases = 0;

    for (const auto &carta : mano) {
        int valor = carta.getValor();
        if (valor > 10) {
            valor = 10; // J, Q, K valen 10 puntos
        }
        if (valor == 1) {
            ases++; // Contamos los ases para tratarlos más adelante
        }
        total += valor;
    }

    // Ajustamos el valor de los ases si es posible sin pasarse de 21
    while (ases > 0 && total + 10 <= 21) {
        total += 10;
        ases--;
    }

    return total;
}


// Realiza una apuesta
void Jugador::apostar(int cantidad) {
    if (cantidad > saldo) {
        throw std::invalid_argument("No tienes suficiente saldo para esta apuesta.");
    }
    apuesta = cantidad;
    saldo -= cantidad;
}

// Reinicia la mano para una nueva ronda
void Jugador::reiniciarMano() {
    mano.clear();    // Limpiar la mano
    apuesta = 0;     // Resetear la apuesta
    plantado = false; // El jugador ya no está plantado
}


// Métodos de acceso
std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getSaldo() const {
    return saldo;
}

int Jugador::getApuesta() const {
    return apuesta;
}

const std::vector<Carta>& Jugador::getMano() const {
    return mano;
}
