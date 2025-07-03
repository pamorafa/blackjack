#ifndef MESA_H
#define MESA_H

#include <QMainWindow>
#include <vector>
#include <QLabel>
#include <memory>
#include <QTimer>
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
    void on_btnDOBLAR_clicked();
    
    // Slots para la animación de reparto de cartas
    void repartirSiguienteCarta();

private:
    Ui::mesa *ui;
    std::unique_ptr<Mazo> mazo;
    std::unique_ptr<Jugador> jugador;
    std::unique_ptr<Crupier> crupier;

    std::vector<QLabel*> cartaLabels;          // Etiquetas para las cartas del jugador
    std::vector<QLabel*> cartaLabelsCrupier;  // Etiquetas para las cartas del crupier

    QLabel *labelSaldo;   // Puntero al QLabel para saldo
    QLabel *labelApuesta; // Puntero al QLabel para apuesta
    
    // Variables para la animación de reparto
    QTimer* timerReparto;
    int etapaReparto;
    
    void reiniciarJuego();              // Reinicia el juego para una nueva ronda
    void actualizarMano();              // Actualiza las cartas visibles del jugador
    void turnoCrupier(bool BlackJack);                // Maneja el turno del crupier
    void mostrarCartasCrupier();        // Muestra todas las cartas del crupier

    void mostrarPrimeraCartaCrupier();    // Muestra solo la primera carta del crupier
    void revelarSegundaCartaCrupier();
    QString obtenerRutaImagen(const Carta& carta); // Devuelve la ruta de la imagen de una carta
    
    // Nuevo método para mostrar una carta en un label
    void mostrarCarta(const Carta& carta, QLabel* label);
    
    // Método para actualizar la visibilidad del botón de doblar
    void actualizarBotonDoblar();
    
    // Método para repartir cartas con animación
    void repartirCartasConAnimacion();
    
    // Métodos para la animación del crupier
    void pedirCartasCrupierConAnimacion();
    void mostrarResultado();
};

#endif // MESA_H
