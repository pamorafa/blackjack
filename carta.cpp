#include "carta.h"

Carta::Carta(int valor, Palo palo) : valor(valor), palo(palo) {}

int Carta::getValor() const {
    return valor;
}

Carta::Palo Carta::getPalo() const {
    return palo;
}

std::string Carta::getPaloStr() const {
    switch (palo) {
        case Palo::CORAZONES:
            return "Corazones";
        case Palo::DIAMANTES:
            return "Diamantes";
        case Palo::TREBOLES:
            return "Treboles";
        case Palo::PICAS:
            return "Picas";
        default:
            return "Desconocido";
    }
}

// Representación textual de la carta
std::string Carta::toString() const {
    // Traduce el valor si es una carta especial (As, J, Q, K)
    std::string valorStr;
    if (valor == 1) {
        valorStr = "As";
    } else if (valor == 11) {
        valorStr = "J";
    } else if (valor == 12) {
        valorStr = "Q";
    } else if (valor == 13) {
        valorStr = "K";
    } else {
        valorStr = std::to_string(valor);
    }
    return valorStr + " de " + getPaloStr();
}
