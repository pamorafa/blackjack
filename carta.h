#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    // Constructor
    Carta(int valor, const std::string &palo);

    int getValor() const;
    std::string getPalo() const;

    std::string toString() const;

private:
    int valor;
    std::string palo;
};

#endif // CARTA_H
