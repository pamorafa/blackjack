#ifndef MESA_H
#define MESA_H

#include <QMainWindow>
#include <vector>
#include <QLabel>
#include "mazo.h"
#include "jugador.h"
#include "crupier.h"

namespace Ui {
class mesa;
}

class mesa : public QMainWindow
{
    Q_OBJECT

public:
    explicit mesa(QWidget *parent = nullptr);
    ~mesa();

    void actualizarSaldoYapuesta();


private slots:
    void on_btnVOLVER_clicked();
    void on_btnPEDIR_clicked();
    void on_btnPLANTARSE_clicked();
    void on_btnREPARTIR_clicked();
    void on_btnApostar_clicked();
    void on_btnVolverAJugar_clicked();

private:
    Ui::mesa *ui;
    Mazo *mazo;
    Jugador *jugador;
    Crupier *crupier;

    std::vector<QLabel*> cartaLabels;          // Etiquetas para las cartas del jugador
    std::vector<QLabel*> cartaLabelsCrupier;  // Etiquetas para las cartas del crupier

    QLabel *labelSaldo;   // Puntero al QLabel para saldo
    QLabel *labelApuesta; // Puntero al QLabel para apuesta

    void reiniciarJuego();              // Reinicia el juego para una nueva ronda
    void actualizarMano();              // Actualiza las cartas visibles del jugador
    void turnoCrupier(bool BlackJack);                // Maneja el turno del crupier
    void mostrarCartasCrupier();        // Muestra todas las cartas del crupier

    void mostrarPrimeraCartaCrupier();    // Muestra solo la primera carta del crupier
    void revelarSegundaCartaCrupier();
    QString obtenerRutaImagen(const Carta& carta); // Devuelve la ruta de la imagen de una carta
};

#endif // MESA_H
