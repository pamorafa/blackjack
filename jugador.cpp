#include "jugador.h"
#include "carta.h"
#include <stdexcept>
#include <QDebug>

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

// El jugador gana la apuesta (recupera su apuesta original y gana una cantidad igual)
void Jugador::ganarApuesta() {
    int apuestaActual = apuesta;
    qDebug() << "ganarApuesta - Antes: Saldo=" << saldo << ", Apuesta=" << apuestaActual;
    
    // Verificar que la apuesta sea válida
    if (apuestaActual <= 0) {
        qDebug() << "Error: Intentando ganar con apuesta inválida: " << apuestaActual;
        return;
    }
    
    // Calcular la ganancia (recupera la apuesta original + gana una cantidad igual)
    int gananciaTotal = apuestaActual * 2; // Apuesta original + ganancia
    
    // Actualizar el saldo
    saldo += gananciaTotal;
    
    // Imprimir información detallada
    qDebug() << "ganarApuesta - Apuesta original: " << apuestaActual;
    qDebug() << "ganarApuesta - Ganancia total: " << gananciaTotal;
    qDebug() << "ganarApuesta - Después: Saldo=" << saldo;
    
    // Reiniciar la apuesta
    apuesta = 0;
}

// El jugador gana con Blackjack (recupera su apuesta original y gana 1.5 veces su apuesta - pago 3:2)
void Jugador::ganarBlackJack() {
    int apuestaActual = apuesta;
    qDebug() << "ganarBlackJack - Antes: Saldo=" << saldo << ", Apuesta=" << apuestaActual;
    
    // Verificar que la apuesta sea válida
    if (apuestaActual <= 0) {
        qDebug() << "Error: Intentando ganar con apuesta inválida: " << apuestaActual;
        return;
    }
    
    // Calcular la ganancia (recupera la apuesta original + gana 1.5 veces la apuesta)
    int gananciaTotal = apuestaActual + static_cast<int>(1.5 * apuestaActual);
    
    // Actualizar el saldo
    saldo += gananciaTotal;
    
    // Imprimir información detallada
    qDebug() << "ganarBlackJack - Apuesta original: " << apuestaActual;
    qDebug() << "ganarBlackJack - Ganancia total: " << gananciaTotal;
    qDebug() << "ganarBlackJack - Después: Saldo=" << saldo;
    
    // Reiniciar la apuesta
    apuesta = 0;
}

// El jugador recupera su apuesta (en caso de empate)
void Jugador::recuperarApuesta() {
    int apuestaActual = apuesta;
    qDebug() << "recuperarApuesta - Antes: Saldo=" << saldo << ", Apuesta=" << apuestaActual;
    
    // Verificar que la apuesta sea válida
    if (apuestaActual <= 0) {
        qDebug() << "Error: Intentando recuperar apuesta inválida: " << apuestaActual;
        return;
    }
    
    // Recuperar la apuesta (sin ganancia)
    saldo += apuestaActual;
    
    // Imprimir información detallada
    qDebug() << "recuperarApuesta - Después: Saldo=" << saldo;
    
    // Reiniciar la apuesta
    apuesta = 0;
}

// Dobla la apuesta actual (double down)
bool Jugador::doblarApuesta() {
    if (puedeDobleApuesta()) {
        saldo -= apuesta;  // Resta del saldo la cantidad igual a la apuesta actual
        apuesta *= 2;      // Dobla la apuesta
        return true;
    }
    return false;
}

// Verifica si el jugador puede doblar su apuesta
bool Jugador::puedeDobleApuesta() const {
    // El jugador puede doblar si:
    // 1. Tiene suficiente saldo para igualar su apuesta actual
    // 2. Tiene exactamente 2 cartas
    bool puede = (saldo >= apuesta && mano.size() == 2);
    
    // Añadir información de depuración
    qDebug() << "puedeDobleApuesta: " << puede 
             << ", saldo: " << saldo 
             << ", apuesta: " << apuesta 
             << ", cartas: " << mano.size();
    
    return puede;
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
    qDebug() << "apostar - Antes: Saldo=" << saldo << ", Apuesta=" << apuesta << ", Cantidad=" << cantidad;
    
    if (cantidad > saldo) {
        throw std::invalid_argument("No tienes suficiente saldo para esta apuesta.");
    }
    
    apuesta = cantidad;
    saldo -= cantidad;
    
    qDebug() << "apostar - Después: Saldo=" << saldo << ", Apuesta=" << apuesta;
}

// Reinicia la mano para una nueva ronda
void Jugador::reiniciarMano() {
    mano.clear();    // Limpiar la mano
    apuesta = 0;     // Resetear la apuesta
    plantado = false; // El jugador ya no está plantado
}

// Limpia solo la mano sin afectar otros estados
void Jugador::limpiarMano() {
    qDebug() << "Limpiando mano de " << nombre.c_str() << " - Tamaño antes: " << mano.size();
    mano.clear();
    plantado = false;
    qDebug() << "Mano limpiada - Tamaño después: " << mano.size();
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
