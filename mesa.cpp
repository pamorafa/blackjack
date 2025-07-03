#include "mesa.h"
#include "ui_mesa.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include "mazo.h"
#include "jugador.h"
#include "crupier.h"
#include <QMessageBox>
#include <QTimer>
#include <QIcon>


mesa::mesa(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mesa)
    , mazo(std::make_unique<Mazo>())
    , jugador(std::make_unique<Jugador>("Jugador 1", 10000))
    , crupier(std::make_unique<Crupier>())
    , timerReparto(new QTimer(this))
    , etapaReparto(0)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/imagenes/icon/icon.png"));
    // Establecer tamaño fijo para la ventana
    this->setFixedSize(924, 683);

    this->menuBar()->setVisible(false);  // Oculta la barra de menú
    this->statusBar()->setVisible(false);  // Oculta la barra de estado
    ui->labelPuntajeJugador->setVisible(false);
    ui->labelPuntajeCroupier->setVisible(false);
    ui->label_CROUPIER->setVisible(false);
    ui->label_JUGADOR->setVisible(false);
    ui->btnPEDIR->setVisible(false);
    ui->btnPLANTARSE->setVisible(false);
    ui->btnREPARTIR->setVisible(false);  // Ocultar el botón de repartir cartas desde el inicio
    
    // Crear el botón DOBLAR programáticamente
    QPushButton* btnDoblar = new QPushButton("DOBLAR", this);
    btnDoblar->setObjectName("btnDOBLAR");
    // Posicionar el botón junto a los otros botones de juego
    btnDoblar->setGeometry(ui->btnPLANTARSE->geometry().x() + ui->btnPLANTARSE->width() + 10, 
                          ui->btnPLANTARSE->geometry().y(),
                          ui->btnPLANTARSE->width(), 
                          ui->btnPLANTARSE->height());
    btnDoblar->setVisible(false);
    // Conectar el botón a su slot
    connect(btnDoblar, &QPushButton::clicked, this, &mesa::on_btnDOBLAR_clicked);
    
    // Establecer el fondo desde mesa.cpp
    this->setStyleSheet(
        "QMainWindow {"
        "   background-image: url(':/imagenes/fondos/a2.jpg');"
        "   background-repeat: no-repeat;"
        "   background-position: center;"
        "   background-size: contain;"
        "}"
        );
    ui->label_CROUPIER->setStyleSheet(
        "background-color: #333333; "    // Fondo oscuro
        "color: #FFFFFF; "               // Texto blanco
        "font-size: 12px; "              // Tamaño de fuente
        "font-weight: bold; "            // Fuente en negrita
        "border: 2px solid #FFFFFF; "    // Borde dorado
        "border-radius: 5px; "           // Bordes redondeados
        "padding: 5px;"                  // Espaciado interno
        );

    // Configuración estética para label_JUGADOR
    ui->label_JUGADOR->setStyleSheet(
        "background-color: #333333; "    // Fondo gris oscuro
        "color: #FFFFFF; "               // Texto dorado
        "font-size: 12px; "              // Tamaño de fuente
        "font-weight: bold; "            // Fuente en negrita
        "border: 2px solid #FFFFFF; "    // Borde blanco
        "border-radius: 5px; "           // Bordes redondeados
        "padding: 5px;"                  // Espaciado interno
        );
    ui->label_CROUPIER->setMinimumWidth(80);  // Ancho mínimo
    ui->label_CROUPIER->setMinimumHeight(30); // Alto mínimo
    ui->label_JUGADOR->setMinimumWidth(80);
    ui->label_JUGADOR->setMinimumHeight(30);
    ui->labelPuntajeCroupier->setStyleSheet(
        "background-color: #333333; "    // Fondo oscuro
        "color: #FFFFFF; "               // Texto blanco
        "font-size: 12px; "              // Tamaño de fuente
        "font-weight: bold; "            // Fuente en negrita
        "border: 2px solid #FFFFFF; "    // Borde dorado
        "border-radius: 5px; "           // Bordes redondeados
        "padding: 5px;"                  // Espaciado interno
        );

    // Configuración estética para label_JUGADOR
    ui->labelPuntajeJugador->setStyleSheet(
        "background-color: #333333; "    // Fondo gris oscuro
        "color: #FFFFFF; "               // Texto dorado
        "font-size: 12px; "              // Tamaño de fuente
        "font-weight: bold; "            // Fuente en negrita
        "border: 2px solid #FFFFFF; "    // Borde blanco
        "border-radius: 5px; "           // Bordes redondeados
        "padding: 5px;"                  // Espaciado interno
        );
    ui->labelPuntajeCroupier->setMinimumWidth(80);  // Ancho mínimo
    ui->labelPuntajeCroupier->setMinimumHeight(30); // Alto mínimo
    ui->labelPuntajeJugador->setMinimumWidth(80);
    ui->labelPuntajeJugador->setMinimumHeight(30);


    ui->labelResultado->setStyleSheet(
        "background-color: #222222;"   // Fondo oscuro para contraste
        "color: #FFFFFF;"              // Texto dorado, consistente con el estilo del casino
        "font-size: 12px;"             // Tamaño de fuente adecuado para visibilidad
        "font-weight: bold;"           // Texto en negrita
        "border: 2px solid #FFD700;"   // Borde dorado para resaltar
        "border-radius: 10px;"         // Bordes redondeados para suavidad
        "padding: 10px;"               // Espaciado interno para mejor apariencia
        "text-align: center;"          // Centrado del texto
        "margin: 5px;"                 // Espaciado externo
        );

    QString labelStyle = R"(
    QLabel {
        background-color: #222222;     /* Fondo oscuro */
        color: #FFD700;               /* Texto dorado */
        font-size: 10px;              /* Tamaño de fuente */
        font-weight: bold;            /* Texto en negrita */
        border: 1px solid #FFD700;    /* Borde dorado */
        border-radius: 10px;          /* Bordes redondeados */
        padding: 5px;                 /* Espaciado interno */
        text-align: center;           /* Centrado del texto */
    }
)";
    ui->labelSaldo->setStyleSheet(labelStyle);
    ui->labelApuesta->setStyleSheet(labelStyle);

    QString lineEditStyle = R"(
    QLineEdit {
        background-color: #FFFFF1;   /* Fondo oscuro */
        color: #000000;             /* Texto dorado */
        font-size: 10px;            /* Tamaño de fuente */
        font-weight: bold;          /* Texto en negrita */
        border: 1px solid #FFD700;  /* Borde dorado */
        border-radius: 10px;        /* Bordes redondeados */
        padding: 5px;               /* Espaciado interno */
        selection-background-color: #FFD700; /* Fondo de selección */
        selection-color: #222222;  /* Texto de selección */
    }
)";
    ui->lineEditApuesta->setStyleSheet(lineEditStyle);



    QString buttonStyle = R"(
    QPushButton {
        background-color: #333333;      /* Fondo oscuro */
        color: #FFD700;                /* Texto dorado */
        font-size: 12px;               /* Tamaño de fuente */
        font-weight: bold;             /* Texto en negrita */
        border: 1px solid #FFD700;     /* Borde dorado */
        border-radius: 10px;           /* Bordes redondeados */
        padding: 8px;                  /* Espaciado interno */
    }
    QPushButton:hover {
        background-color: #555555;     /* Fondo más claro al pasar el mouse */
    }
    QPushButton:pressed {
        background-color: #FFD700;     /* Fondo dorado al presionar */
        color: #333333;                /* Texto oscuro al presionar */
    }
)";

    // Aplicar estilo a los botones
    ui->btnVOLVER->setStyleSheet(buttonStyle);
    ui->btnApostar->setStyleSheet(buttonStyle);
    ui->btnREPARTIR->setStyleSheet(buttonStyle);
    ui->btnPEDIR->setStyleSheet(buttonStyle);
    ui->btnPLANTARSE->setStyleSheet(buttonStyle);
    ui->btnVolverAJugar->setStyleSheet(buttonStyle);
    btnDoblar->setStyleSheet(buttonStyle);  // Aplicar estilo al botón de doblar




    // Obtener los punteros a los QLabel desde la interfaz
    labelSaldo = ui->labelSaldo;
    labelApuesta = ui->labelApuesta;

    ui->btnVolverAJugar->setVisible(false);
    ui->labelResultado->setVisible(false);
    ui->labelApuestaInvalida->setVisible(false);
    ui->labelmakeBet->setVisible(false);
    ui->labelValorCrupier->setVisible(false);
    ui->labelValorJugador->setVisible(false);

    // Barajar el mazo al inicio
    mazo->barajar();

    actualizarSaldoYapuesta();

    // Conectar el timer para la animación de reparto
    connect(timerReparto, &QTimer::timeout, this, &mesa::repartirSiguienteCarta);
}

mesa::~mesa()
{
    delete ui;
    // No es necesario eliminar manualmente los objetos gestionados por smart pointers
    if (timerReparto->isActive()) {
        timerReparto->stop();
    }
}

void mesa::actualizarSaldoYapuesta() {
    int saldoActual = jugador->getSaldo();
    int apuestaActual = jugador->getApuesta();
    
    qDebug() << "Actualizando UI - Saldo: " << saldoActual << ", Apuesta: " << apuestaActual;
    
    // Actualizar las etiquetas de la interfaz
    ui->labelSaldo->setText("SALDO: " + QString::number(saldoActual) + " €");
    ui->labelApuesta->setText("APUESTA: " + QString::number(apuestaActual) + " €");
    
    // Habilitar o deshabilitar el botón de apostar según el saldo disponible
    ui->btnApostar->setEnabled(saldoActual > 0);
}


void mesa::on_btnVOLVER_clicked()
{
    this->close();
    if (parentWidget()) {
        parentWidget()->show();
    }
}

void mesa::on_btnApostar_clicked()
{
    bool ok;
    int apuesta = ui->lineEditApuesta->text().toInt(&ok);  // Leer la cantidad de apuesta desde el QLineEdit

    if (ok && apuesta > 0 && apuesta <= jugador->getSaldo()) {
        ui->labelApuestaInvalida->setVisible(false);
        ui->lineEditApuesta->setText("");
        ui->lineEditApuesta->setVisible(false);  // Ocultar el campo de entrada de apuesta
        ui->btnApostar->setVisible(false);       // Ocultar el botón de apostar
        ui->btnREPARTIR->setVisible(false);      // Ocultar el botón de repartir
        ui->labelmakeBet->setVisible(false);     // Ocultar el mensaje de apuesta
        
        try {
            // Reiniciar manos antes de comenzar una nueva ronda
            jugador->reiniciarMano();
            crupier->reiniciarMano();
            
            // Realizar la apuesta
            jugador->apostar(apuesta);
            
            // Actualizar la interfaz con el nuevo saldo y apuesta
            actualizarSaldoYapuesta();
            
            qDebug() << "Apuesta realizada: " << apuesta << ", Saldo restante: " << jugador->getSaldo();
            
            // Repartir cartas automáticamente
            repartirCartasConAnimacion();
            
        } catch (const std::invalid_argument &e) {
            // Mostrar un mensaje de advertencia con un flujo controlado
            QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText(e.what());
            msgBox.setStyleSheet("QMessageBox { background-color: white; }"
                                 "QLabel { color: black; }"
                                 "QPushButton { background-color: lightgray; border: 1px solid black; }");
            msgBox.exec();

            // Mostrar nuevamente los elementos para apostar
            ui->lineEditApuesta->setVisible(true);
            ui->btnApostar->setVisible(true);
            ui->labelmakeBet->setVisible(true);
            
            return;
        }
    } else {
        ui->lineEditApuesta->setText("");
        ui->labelApuestaInvalida->setVisible(true);
    }
}

// Reinicia el juego para una nueva ronda
void mesa::reiniciarJuego() {
    qDebug() << "Reiniciando juego - Estado antes: Saldo=" << jugador->getSaldo() << ", Apuesta=" << jugador->getApuesta();
    
    // Limpiar las manos
    jugador->limpiarMano();
    crupier->limpiarMano();
    
    // Limpiar las etiquetas de cartas
    for (auto label : cartaLabels) {
        if (label) {
            label->clear();
            label->setVisible(false);
            delete label;
        }
    }
    cartaLabels.clear();
    
    for (auto label : cartaLabelsCrupier) {
        if (label) {
            label->clear();
            label->setVisible(false);
            delete label;
        }
    }
    cartaLabelsCrupier.clear();
    
    // Reiniciar el mazo
    mazo->reiniciar();
    mazo->barajar();
    
    // Ocultar elementos de juego
    ui->labelPuntajeJugador->setVisible(false);
    ui->labelPuntajeCroupier->setVisible(false);
    ui->label_JUGADOR->setVisible(false);
    ui->label_CROUPIER->setVisible(false);
    ui->labelValorJugador->setVisible(false);
    ui->labelValorCrupier->setVisible(false);
    
    // Ocultar botones de juego
    ui->btnPEDIR->setVisible(false);
    ui->btnPLANTARSE->setVisible(false);
    
    // Ocultar el botón de doblar
    QPushButton* btnDoblar = findChild<QPushButton*>("btnDOBLAR");
    if (btnDoblar) {
        btnDoblar->setVisible(false);
    }
    
    // Restablecer etapa de reparto
    etapaReparto = 0;
    
    qDebug() << "Juego reiniciado - Estado después: Saldo=" << jugador->getSaldo() << ", Apuesta=" << jugador->getApuesta();
}



void mesa::on_btnPEDIR_clicked() {
    jugador->pedirCarta(*mazo);      // El jugador pide una carta
    actualizarMano();               // Actualiza las cartas en la interfaz
    
    // Ocultar el botón de doblar después de pedir una carta
    QPushButton* btnDoblar = findChild<QPushButton*>("btnDOBLAR");
    if (btnDoblar) {
        btnDoblar->setVisible(false);
    }

    // Actualizar el puntaje total del jugador
    ui->labelPuntajeJugador->setText("Puntaje: " + QString::number(jugador->calcularPuntaje()));

    int puntajeJugador = jugador->calcularPuntaje();
    if (puntajeJugador > 21) {       // Si el puntaje supera 21, el jugador pierde
        turnoCrupier(false);             // Finaliza el turno y muestra las cartas del crupier
    }
}

void mesa::on_btnPLANTARSE_clicked() {
    jugador->plantarse();            // Marca al jugador como plantado
    turnoCrupier(false);                  // Pasa el turno al crupier
    ui->btnPLANTARSE->setVisible(false);
    ui->btnPEDIR->setVisible(false);
}

void mesa::turnoCrupier(bool BlackJack) {
    // Ocultar los botones de juego
    ui->btnPEDIR->setVisible(false);
    ui->btnPLANTARSE->setVisible(false);
    
    QPushButton* btnDoblar = findChild<QPushButton*>("btnDOBLAR");
    if (btnDoblar) {
        btnDoblar->setVisible(false);
    }
    
    // Revelar la segunda carta del crupier con animación
    QTimer::singleShot(1000, this, [this, BlackJack]() {
        revelarSegundaCartaCrupier();
        
        // Mostrar todas las cartas del crupier
        mostrarCartasCrupier();
        
        // Lógica del crupier para pedir cartas con animación
        if (jugador->calcularPuntaje() <= 21 && !BlackJack) {
            pedirCartasCrupierConAnimacion();
        } else {
            mostrarResultado();
        }
    });
}

// Nuevo método para pedir cartas al crupier con animación
void mesa::pedirCartasCrupierConAnimacion() {
    // Si el crupier necesita pedir carta
    if (crupier->calcularPuntaje() < 17) {
        // Esperar 1 segundo y luego pedir carta
        QTimer::singleShot(1000, this, [this]() {
            crupier->pedirCarta(*mazo);
            mostrarCartasCrupier();
            
            // Llamada recursiva para la siguiente carta si es necesario
            pedirCartasCrupierConAnimacion();
        });
    } else {
        // Si el crupier ya no necesita más cartas, mostrar el resultado
        mostrarResultado();
    }
}

// Nuevo método para mostrar el resultado del juego
void mesa::mostrarResultado() {
    // Ocultar los botones de juego
    ui->btnPEDIR->setVisible(false);
    ui->btnPLANTARSE->setVisible(false);
    
    // Ocultar el botón de doblar si existe
    QPushButton* btnDoblar = findChild<QPushButton*>("btnDOBLAR");
    if (btnDoblar) {
        btnDoblar->setVisible(false);
    }
    
    // Resto de la lógica para decidir el resultado
    int puntajeJugador = jugador->calcularPuntaje();
    int puntajeCrupier = crupier->calcularPuntaje();
    int apuestaActual = jugador->getApuesta();
    int saldoAntes = jugador->getSaldo();
    
    qDebug() << "Mostrando resultado - Apuesta actual: " << apuestaActual << ", Saldo antes: " << saldoAntes;
    qDebug() << "Puntuaciones - Jugador: " << puntajeJugador << ", Crupier: " << puntajeCrupier;

    QString resultado;
    
    // Caso 1: Jugador se pasa de 21 (pierde automáticamente)
    if (puntajeJugador > 21) {
        resultado = "Perdiste, superaste los 21";
        qDebug() << "Jugador pierde por pasarse de 21";
    } 
    // Caso 2: Jugador tiene Blackjack (21 con 2 cartas)
    else if (puntajeJugador == 21 && jugador->getMano().size() == 2) {
        // Si el crupier también tiene Blackjack, es empate
        if (puntajeCrupier == 21 && crupier->getMano().size() == 2) {
            resultado = "¡Empate con Blackjack!";
            jugador->recuperarApuesta();
            qDebug() << "Empate con Blackjack, saldo después: " << jugador->getSaldo();
        } else {
            resultado = "¡BlackJack!";
            jugador->ganarBlackJack();
            qDebug() << "Jugador gana con BlackJack, saldo después: " << jugador->getSaldo();
        }
    }
    // Caso 3: Crupier se pasa de 21 (jugador gana)
    else if (puntajeCrupier > 21) {
        resultado = "¡Ganaste! El crupier se pasó de 21.\nTu Puntaje: " + QString::number(puntajeJugador) + "\nPuntaje del Crupier: " + QString::number(puntajeCrupier);
        jugador->ganarApuesta();
        qDebug() << "Jugador gana porque crupier se pasó, saldo después: " << jugador->getSaldo();
    }
    // Caso 4: Jugador tiene mayor puntaje que el crupier
    else if (puntajeJugador > puntajeCrupier) {
        resultado = "¡Ganaste!\nTu Puntaje: " + QString::number(puntajeJugador) + "\nPuntaje del Crupier: " + QString::number(puntajeCrupier);
        jugador->ganarApuesta();
        qDebug() << "Jugador gana con mayor puntaje, saldo después: " << jugador->getSaldo();
    }
    // Caso 5: Crupier tiene mayor puntaje que el jugador
    else if (puntajeCrupier > puntajeJugador) {
        resultado = "¡Perdiste!\nTu Puntaje: " + QString::number(puntajeJugador) + "\nPuntaje del Crupier: " + QString::number(puntajeCrupier);
        qDebug() << "Jugador pierde contra el crupier";
    }
    // Caso 6: Empate
    else {
        resultado = "¡Empate!\nTu Puntaje: " + QString::number(puntajeJugador) + "\nPuntaje del Crupier: " + QString::number(puntajeCrupier);
        jugador->recuperarApuesta();
        qDebug() << "Empate, saldo después: " << jugador->getSaldo();
    }

    ui->labelResultado->setText(resultado);
    ui->labelResultado->setVisible(true);
    ui->btnVolverAJugar->setVisible(true);
    
    // Actualizar el saldo y apuesta
    actualizarSaldoYapuesta();
    
    qDebug() << "Saldo final después de actualizar UI: " << jugador->getSaldo();
}

void mesa::mostrarCartasCrupier() {
    // Limpiar las etiquetas anteriores del crupier
    for (auto label : cartaLabelsCrupier) {
        label->deleteLater();  // Eliminar etiquetas viejas
    }
    cartaLabelsCrupier.clear();  // Limpiar el vector de etiquetas

    // Crear un layout horizontal para las cartas del crupier
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setSpacing(5);  // Espaciado entre las cartas
    layout->setContentsMargins(0, 0, 0, 0);  // Sin márgenes

    // Mostrar las cartas del crupier
    const auto& manoCrupier = crupier->getMano();
    for (const Carta& carta : manoCrupier) {
        QLabel* label = new QLabel(this);
        label->setAlignment(Qt::AlignCenter);
        mostrarCarta(carta, label);
        layout->addWidget(label);
        cartaLabelsCrupier.push_back(label);
    }

    // Crear un widget contenedor para el layout
    QWidget* container = new QWidget(this);
    container->setLayout(layout);
    container->setStyleSheet("background: transparent;");

    if (ui->layoutCartasCrupier->count() > 0) {
        QLayoutItem* item = ui->layoutCartasCrupier->takeAt(0);
        if (item->widget()) {
            item->widget()->deleteLater();
        }
    }

    ui->layoutCartasCrupier->addWidget(container);
    container->adjustSize();

    // Actualizar el puntaje total del crupier
    ui->labelPuntajeCroupier->setText("Puntaje: " + QString::number(crupier->calcularPuntaje()));
    ui->labelPuntajeCroupier->setVisible(true);
    ui->label_CROUPIER->setVisible(true);
}



void mesa::mostrarPrimeraCartaCrupier() {
    // Limpiar etiquetas anteriores
    for (auto label : cartaLabelsCrupier) {
        label->deleteLater();
    }
    cartaLabelsCrupier.clear();

    // Crear layout para la primera carta
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setSpacing(5);
    layout->setContentsMargins(0, 0, 0, 0);

    const auto& manoCrupier = crupier->getMano();

    // Mostrar la primera carta del crupier
    if (!manoCrupier.empty()) {
        QLabel* label = new QLabel(this);
        label->setAlignment(Qt::AlignCenter);
        mostrarCarta(manoCrupier[0], label);
        layout->addWidget(label);
        cartaLabelsCrupier.push_back(label);
    }

    // Agregar una carta oculta como marcador
    QLabel* cartaOculta = new QLabel(this);
    cartaOculta->setPixmap(QPixmap(":/imagenes/fondos/back.png")
                               .scaled(80, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    cartaOculta->setAlignment(Qt::AlignCenter);
    layout->addWidget(cartaOculta);
    cartaLabelsCrupier.push_back(cartaOculta);

    QWidget* container = new QWidget(this);
    container->setLayout(layout);
    container->setStyleSheet("background: transparent;");

    // Limpiar layout anterior y agregar el nuevo contenedor
    if (ui->layoutCartasCrupier->count() > 0) {
        QLayoutItem* item = ui->layoutCartasCrupier->takeAt(0);
        if (item->widget()) {
            item->widget()->deleteLater();
        }
    }
    ui->layoutCartasCrupier->addWidget(container);
    container->adjustSize();
}



QString mesa::obtenerRutaImagen(const Carta& carta) {
    int valor = carta.getValor();  // Valor de la carta (1-13)
    Carta::Palo palo = carta.getPalo(); // Palo de la carta

    // Mapear el palo a su rango correspondiente
    int baseValue = 0;

    switch (palo) {
        case Carta::Palo::PICAS:
            baseValue = 0;
            break;
        case Carta::Palo::CORAZONES:
            baseValue = 13;
            break;
        case Carta::Palo::TREBOLES:
            baseValue = 26;
            break;
        case Carta::Palo::DIAMANTES:
            baseValue = 39;
            break;
    }

    // Ajustar el valor para obtener el índice final en la imagen
    int index = baseValue + (valor - 1);  // Restar 1 porque los valores van de 1 a 13

    // Construir la ruta de la imagen
    QString imagenRuta = ":/imagenes/cards/front-" + QString::number(index) + ".png";
    return imagenRuta;
}



void mesa::actualizarMano() {
    // Limpiar las etiquetas anteriores
    for (auto label : cartaLabels) {
        label->deleteLater();  // Eliminar etiquetas viejas
    }
    cartaLabels.clear();  // Limpiar el vector de etiquetas

    // Crear un layout horizontal para las cartas
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setSpacing(5);  // Espaciado entre las cartas
    layout->setContentsMargins(0, 0, 0, 0);  // Sin márgenes

    // Mostrar las cartas del jugador
    const auto& manoJugador = jugador->getMano();
    for (const Carta& carta : manoJugador) {
        QLabel* label = new QLabel(this);
        label->setAlignment(Qt::AlignCenter);
        mostrarCarta(carta, label);
        layout->addWidget(label);
        cartaLabels.push_back(label);
    }

    // Crear un widget contenedor para el layout
    QWidget* container = new QWidget(this);
    container->setLayout(layout);

    container->setStyleSheet("background: transparent;");

    if (ui->verticalLayout->count() > 0) {
        QLayoutItem* item = ui->verticalLayout->takeAt(0);
        if (item->widget()) {
            item->widget()->deleteLater();
        }
    }

    ui->verticalLayout->addWidget(container);
    container->adjustSize();

    // Mostrar el puntaje del jugador
    ui->labelPuntajeJugador->setText("Puntaje: " + QString::number(jugador->calcularPuntaje()));
    ui->labelPuntajeJugador->setVisible(true);
    ui->label_JUGADOR->setVisible(true);

    // Actualizar la visibilidad del botón de doblar
    qDebug() << "Actualizando botón de doblar. Jugador tiene " << manoJugador.size() << " cartas.";
    actualizarBotonDoblar();

    // Verificar si el jugador tiene BlackJack (21 puntos con solo 2 cartas)
    if (jugador->calcularPuntaje() == 21 && manoJugador.size() == 2) {
        turnoCrupier(true);  // Blackjack
    } else {
        ui->btnPEDIR->setVisible(true);
        ui->btnPLANTARSE->setVisible(true);
    }
}

void mesa::revelarSegundaCartaCrupier() {
    if (cartaLabelsCrupier.size() > 1) {
        const auto& manoCrupier = crupier->getMano();
        if (manoCrupier.size() > 1) {
            QLabel* segundaCarta = cartaLabelsCrupier[1]; // Acceder a la segunda carta
            mostrarCarta(manoCrupier[1], segundaCarta);
        }
    }
}

// Volver a jugar (reiniciar el juego)
void mesa::on_btnVolverAJugar_clicked()
{
    qDebug() << "Volviendo a jugar - Saldo actual: " << jugador->getSaldo();
    
    // Ocultar elementos de resultado
    ui->labelResultado->setVisible(false);
    ui->btnVolverAJugar->setVisible(false);
    
    // Reiniciar el juego
    reiniciarJuego();
    
    // Mostrar elementos para apostar
    ui->btnApostar->setVisible(true);
    ui->lineEditApuesta->setVisible(true);
    
    // Actualizar la interfaz
    actualizarSaldoYapuesta();
    
    qDebug() << "Juego reiniciado - Saldo: " << jugador->getSaldo() << ", Apuesta: " << jugador->getApuesta();
}

// Nuevo método para mostrar una carta en un label (elimina código duplicado)
void mesa::mostrarCarta(const Carta& carta, QLabel* label) {
    if (label) {
        QString imagenRuta = obtenerRutaImagen(carta);
        QPixmap pixmap(imagenRuta);
        if (!pixmap.isNull()) {
            label->setPixmap(pixmap.scaled(80, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            label->setVisible(true);
        }
    }
}

// Implementación del nuevo método para actualizar la visibilidad del botón de doblar
void mesa::actualizarBotonDoblar() {
    QPushButton* btnDoblar = findChild<QPushButton*>("btnDOBLAR");
    if (!btnDoblar) return;
    
    // El botón de doblar solo debe estar visible si el jugador puede doblar su apuesta
    // (tiene exactamente 2 cartas y suficiente saldo)
    if (jugador->puedeDobleApuesta()) {
        btnDoblar->setVisible(true);
        qDebug() << "Botón DOBLAR visible: jugador puede doblar apuesta";
    } else {
        btnDoblar->setVisible(false);
        qDebug() << "Botón DOBLAR oculto: jugador no puede doblar apuesta";
        qDebug() << "Cartas: " << jugador->getMano().size() << ", Saldo: " << jugador->getSaldo() << ", Apuesta: " << jugador->getApuesta();
    }
}

// Implementación del slot para el botón de doblar
void mesa::on_btnDOBLAR_clicked() {
    qDebug() << "Botón DOBLAR clickeado. Jugador tiene " << jugador->getMano().size() << " cartas y apuesta " << jugador->getApuesta();
    
    if (jugador->puedeDobleApuesta()) {
        // Actualizar la interfaz para mostrar la nueva apuesta
        jugador->doblarApuesta();
        actualizarSaldoYapuesta();
        
        qDebug() << "Apuesta doblada a: " << jugador->getApuesta();
        
        // El jugador recibe exactamente una carta más
        jugador->pedirCarta(*mazo);
        actualizarMano();
        
        qDebug() << "Carta adicional repartida. Jugador ahora tiene " << jugador->getMano().size() << " cartas";
        
        // El jugador se planta automáticamente después de doblar
        jugador->plantarse();
        
        // Pasar el turno al crupier
        turnoCrupier(false);
        
        // Ocultar los botones de juego
        ui->btnPEDIR->setVisible(false);
        ui->btnPLANTARSE->setVisible(false);
        
        QPushButton* btnDoblar = findChild<QPushButton*>("btnDOBLAR");
        if (btnDoblar) {
            btnDoblar->setVisible(false);
        }
    } else {
        qDebug() << "ERROR: No se puede doblar la apuesta";
    }
}

// Método para iniciar la animación de reparto de cartas
void mesa::repartirCartasConAnimacion() {
    // Reiniciar las manos antes de repartir nuevas cartas
    jugador->reiniciarMano();
    crupier->reiniciarMano();
    
    // Barajar el mazo antes de repartir
    mazo->barajar();
    
    // Reiniciar la etapa de reparto
    etapaReparto = 0;
    
    // Limpiar las cartas anteriores
    for (auto label : cartaLabels) {
        label->deleteLater();
    }
    cartaLabels.clear();
    
    for (auto label : cartaLabelsCrupier) {
        label->deleteLater();
    }
    cartaLabelsCrupier.clear();
    
    // Mostrar los labels de jugador y crupier
    ui->label_JUGADOR->setVisible(true);
    ui->label_CROUPIER->setVisible(true);
    
    qDebug() << "Iniciando reparto de cartas. Jugador tiene " << jugador->getMano().size() << " cartas.";
    
    // Iniciar el timer para repartir las cartas con un intervalo de 1 segundo
    timerReparto->start(1000);
}

// Slot que se ejecuta cada vez que el timer hace timeout
void mesa::repartirSiguienteCarta() {
    switch (etapaReparto) {
        case 0: // Primera carta al crupier (visible)
            crupier->pedirCarta(*mazo);
            mostrarPrimeraCartaCrupier();
            ui->labelPuntajeCroupier->setText("Puntaje: " + QString::number(crupier->getMano().at(0).getValor()));
            ui->labelPuntajeCroupier->setVisible(true);
            break;
            
        case 1: // Primera carta al jugador
            jugador->pedirCarta(*mazo);
            actualizarMano();
            break;
            
        case 2: // Segunda carta al crupier (oculta)
            crupier->pedirCarta(*mazo);
            mostrarPrimeraCartaCrupier(); // Actualiza mostrando la carta oculta
            break;
            
        case 3: // Segunda carta al jugador
            jugador->pedirCarta(*mazo);
            actualizarMano();
            
            // Verificar si el jugador tiene BlackJack
            if (jugador->calcularPuntaje() == 21) {
                timerReparto->stop();
                turnoCrupier(true);  // Blackjack
            } else {
                // Detener el timer y mostrar los botones de juego
                timerReparto->stop();
                
                // Mostrar los botones para continuar el juego
                ui->btnPEDIR->setVisible(true);
                ui->btnPLANTARSE->setVisible(true);
                
                // Verificar si el jugador puede doblar (tiene 2 cartas)
                actualizarBotonDoblar();
            }
            break;
    }
    
    // Incrementar la etapa para la próxima carta
    etapaReparto++;
}

// Este método ya no es necesario, pero lo mantenemos vacío por compatibilidad
void mesa::on_btnREPARTIR_clicked() {
    // Método vacío - la funcionalidad se ha movido a on_btnApostar_clicked
}

