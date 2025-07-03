#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    // Enumeración para los palos de las cartas
    enum class Palo {
        CORAZONES,
        DIAMANTES,
        TREBOLES,
        PICAS
    };

    // Constructor
    Carta(int valor, Palo palo);

    int getValor() const;
    Palo getPalo() const;
    std::string getPaloStr() const;

    std::string toString() const;

private:
    int valor;
    Palo palo;
};

#endif // CARTA_H
