#include "mazo.h"
#include <stdexcept>

Mazo::Mazo() {
    resetear(); // Crea las cartas
}

void Mazo::barajar() {
    // Generador aleatorio basado en el tiempo
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cartas.begin(), cartas.end(), rng);
}

Carta Mazo::repartirCarta() {
    if (!cartas.empty()) {
        Carta carta = cartas.back(); // Obtiene la última carta
        cartas.pop_back();           // La elimina del mazo
        return carta;                // Devuelve la carta
    }
    throw std::out_of_range("El mazo está vacío"); // Lanza un error si no hay cartas
}

void Mazo::resetear() {
    cartas.clear(); // Vacía el vector antes de recrear las cartas
    std::vector<std::string> palos = {"Corazones", "Diamantes", "Treboles", "Picas"};

    for (const auto& palo : palos) {
        for (int valor = 1; valor <= 13; ++valor) {
            cartas.emplace_back(valor, palo); // Crea cartas del 1 al 13 para cada palo
        }
    }
}
