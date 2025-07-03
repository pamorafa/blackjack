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
    , mazo(nullptr)
    , jugador(new Jugador("Jugador 1", 10000))  // Inicializa el jugador con 10000 de saldo
    , crupier(nullptr)
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




    // Obtener los punteros a los QLabel desde la interfaz
    labelSaldo = ui->labelSaldo;
    labelApuesta = ui->labelApuesta;

    ui->btnVolverAJugar->setVisible(false);
    ui->labelResultado->setVisible(false);
    ui->labelApuestaInvalida->setVisible(false);
    ui->labelmakeBet->setVisible(false);
    ui->labelValorCrupier->setVisible(false);
    ui->labelValorJugador->setVisible(false);

    mazo = new Mazo();
    jugador = new Jugador("Jugador", 10000);
    crupier = new Crupier();

    // Barajar el mazo al inicio
    mazo->barajar();

    actualizarSaldoYapuesta();

}

mesa::~mesa()
{
    delete ui;
    delete mazo;
    delete jugador;
    delete crupier;
}

void mesa::actualizarSaldoYapuesta()
{
    if (labelSaldo && labelApuesta) {  // Verificar que las etiquetas existan
        labelSaldo->setText("Saldo: $ " + QLocale(QLocale::Spanish, QLocale::Chile).toString(jugador->getSaldo()));
        labelApuesta->setText("Apuesta: $ " + QLocale(QLocale::Spanish, QLocale::Chile).toString(jugador->getApuesta()));
    } else {
        qDebug() << "Error: Las etiquetas no están inicializadas correctamente.";
    }
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
        ui->btnApostar->setVisible(false);
        try {
            jugador->apostar(apuesta);  // Llamada al método apostar
            actualizarSaldoYapuesta();  // Actualizar los QLabel con los nuevos valores
            ui->labelmakeBet->setVisible(false);
        } catch (const std::invalid_argument &e) {
            // Mostrar un mensaje de advertencia con un flujo controlado
            QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText(e.what());
            msgBox.setStyleSheet("QMessageBox { background-color: white; }"
                                 "QLabel { color: black; }"
                                 "QPushButton { background-color: lightgray; border: 1px solid black; }");
            msgBox.exec();

            // Detenemos el flujo, pero no cerramos el juego
            return;
        }
    } else {
        ui->lineEditApuesta->setText("");
        ui->labelApuestaInvalida->setVisible(true);
    }
}

void mesa::reiniciarJuego() {
    qDebug() << "Reiniciando juego...";
    jugador->reiniciarMano(); // Reinicia la mano del jugador
    crupier->reiniciarMano(); // Reinicia la mano del crupier
    mazo->resetear();         // Resetea el mazo

    // Ocultar elementos al reiniciar
    ui->labelPuntajeJugador->setVisible(false);
    ui->labelPuntajeCroupier->setVisible(false);
    ui->label_CROUPIER->setVisible(false);
    ui->label_JUGADOR->setVisible(false);
    ui->btnPEDIR->setVisible(false);
    ui->btnPLANTARSE->setVisible(false);

    ui->labelResultado->setVisible(false); // Ocultar el resultado
    ui->btnVolverAJugar->setVisible(false);

    // Actualizar la interfaz
    actualizarMano();
    mostrarCartasCrupier();
    actualizarSaldoYapuesta();
}



void mesa::on_btnPEDIR_clicked() {
    jugador->pedirCarta(*mazo);      // El jugador pide una carta
    actualizarMano();               // Actualiza las cartas en la interfaz

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
    // Revelar la segunda carta del crupier
    revelarSegundaCartaCrupier();

    // Mostrar todas las cartas del crupier
    mostrarCartasCrupier();

    // Lógica del crupier para pedir cartas
    while (crupier->calcularPuntaje() < 17 && jugador->calcularPuntaje() <= 21 && !BlackJack) {
        crupier->pedirCarta(*mazo);
        mostrarCartasCrupier(); // Actualiza la visualización con las nuevas cartas
    }

    // Resto de la lógica para decidir el resultado
    int puntajeJugador = jugador->calcularPuntaje();
    int puntajeCrupier = crupier->calcularPuntaje();

    QString resultado;
    if (puntajeJugador > 21) {
        resultado = "Perdiste, superaste los 21";
    } else if (BlackJack) {
        resultado = "¡BlackJack!";
        jugador->ganarBlackJack();
    } else if ((puntajeCrupier > 21 || puntajeJugador > puntajeCrupier) && puntajeJugador <= 21) {
        resultado = "¡Ganaste!\nTu Puntaje: " + QString::number(puntajeJugador) + "\nPuntaje del Crupier: " + QString::number(puntajeCrupier);
        jugador->ganarApuesta();
    } else if (puntajeCrupier > puntajeJugador) {
        resultado = "¡Perdiste!\nTu Puntaje: " + QString::number(puntajeJugador) + "\nPuntaje del Crupier: " + QString::number(puntajeCrupier);
    } else {
        resultado = "¡Empate!\nTu Puntaje: " + QString::number(puntajeJugador) + "\nPuntaje del Crupier: " + QString::number(puntajeCrupier);
        jugador->recuperarApuesta();
    }

    ui->labelResultado->setText(resultado);
    ui->labelResultado->setVisible(true);
    ui->btnVolverAJugar->setVisible(true);
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

    // Tamaño máximo de las imágenes
    const int maxWidth = 100;
    const int maxHeight = 100;

    // Mostrar las cartas del crupier
    const auto& manoCrupier = crupier->getMano();
    for (const Carta& carta : manoCrupier) {
        QString imagenRuta = obtenerRutaImagen(carta);  // Ruta de las imágenes ajustada
        QPixmap pixmap(imagenRuta);
        if (pixmap.isNull()) {
            qDebug() << "Error al cargar la imagen:" << imagenRuta;
        } else {
            QPixmap scaledPixmap = pixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio);

            QLabel* label = new QLabel(this);
            label->setPixmap(scaledPixmap);  // Establecer la imagen escalada
            label->setAlignment(Qt::AlignCenter);
            layout->addWidget(label);
            cartaLabelsCrupier.push_back(label);
        }
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
}



void mesa::on_btnREPARTIR_clicked() {
    if (jugador->getApuesta() > 0) {
        ui->labelmakeBet->setVisible(false);

        mazo->barajar();

        crupier->pedirCarta(*mazo);  // Primera carta al crupier (visible)
        jugador->pedirCarta(*mazo);  // Primera carta al jugador (visible)
        crupier->pedirCarta(*mazo);  // Segunda carta al crupier (oculta)
        jugador->pedirCarta(*mazo);  // Segunda carta al jugador (visible)

        actualizarMano();
        mostrarPrimeraCartaCrupier();

        ui->btnREPARTIR->setVisible(false);

        // Mostrar elementos necesarios para la ronda
        ui->labelPuntajeJugador->setVisible(true);
        ui->labelPuntajeCroupier->setVisible(true);
        ui->label_CROUPIER->setVisible(true);
        ui->label_JUGADOR->setVisible(true);
        ui->btnPEDIR->setVisible(true);
        ui->btnPLANTARSE->setVisible(true);

        // Actualizar puntajes iniciales
        ui->labelPuntajeJugador->setText("Puntaje: " + QString::number(jugador->calcularPuntaje()));
        ui->labelPuntajeCroupier->setText("Puntaje: " + QString::number(crupier->getMano().at(0).getValor()));

        if(jugador->calcularPuntaje() == 21){
            turnoCrupier(true);
        }
    } else {
        ui->labelmakeBet->setVisible(true);
    }
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

    // Tamaño máximo de las imágenes
    const int maxWidth = 100;
    const int maxHeight = 100;

    const auto& manoCrupier = crupier->getMano();

    // Mostrar la primera carta del crupier
    if (!manoCrupier.empty()) {
        QString imagenRuta = obtenerRutaImagen(manoCrupier[0]);  // Primera carta
        QPixmap pixmap(imagenRuta);

        QLabel* label = new QLabel(this);
        label->setPixmap(pixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio));
        label->setAlignment(Qt::AlignCenter);
        layout->addWidget(label);
        cartaLabelsCrupier.push_back(label);
    }

    // Agregar una carta oculta como marcador
    QLabel* cartaOculta = new QLabel(this);
    cartaOculta->setPixmap(QPixmap(":/imagenes/fondos/back.png") // Imagen de carta oculta
                               .scaled(maxWidth, maxHeight, Qt::KeepAspectRatio));
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
    int valor = carta.getValor();  // Valor de la carta (1-10)
    std::string palo = carta.getPalo(); // Palo de la carta

    // Mapear el palo a su rango correspondiente
    int baseValue = 0;

    if (palo == "Picas") {
        baseValue = 0;
    } else if (palo == "Corazones") {
        baseValue = 13;
    } else if (palo == "Trebol") {
        baseValue = 26;
    } else if (palo == "Diamantes") {
        baseValue = 39;
    }

    // Ajustar el valor para obtener el índice final en la imagen
    int index = baseValue + (valor - 1);  // Restar 1 porque los valores van de 1 a 10

    // Construir la ruta de la imagen
    QString imagenRuta = ":/imagenes/cards/front-" + QString::number(index) + ".png";
    return imagenRuta;
}



void mesa::actualizarMano() {
    // Limpiar las etiquetas anteriores
    for (auto label : cartaLabels) {
        label->deleteLater();
    }
    cartaLabels.clear();

    // Crear un layout horizontal para las cartas
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setSpacing(10);  // Espacio entre las cartas
    layout->setContentsMargins(0, 0, 0, 0);

    // Tamaño máximo de las imágenes
    const int maxWidth = 100;
    const int maxHeight = 100;

    // Mostrar las cartas del jugador
    for (const Carta& carta : jugador->getMano()) {
        QString imagenRuta = obtenerRutaImagen(carta);  // Llamamos a la función que ajusta la imagen

        QPixmap pixmap(imagenRuta);
        if (pixmap.isNull()) {
            qDebug() << "Error al cargar la imagen:" << imagenRuta;
        } else {
            QPixmap scaledPixmap = pixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio);

            QLabel* label = new QLabel(this);
            label->setPixmap(scaledPixmap);
            label->setAlignment(Qt::AlignCenter);
            layout->addWidget(label);
            cartaLabels.push_back(label);
        }
    }

    // Crear un widget contenedor para el layout
    QWidget* container = new QWidget(this);
    container->setLayout(layout);

    // Establecer color de fondo gris para el contenedor
    container->setStyleSheet("background: transparent;");

    // Crear un QScrollArea y agregar el contenedor con el layout
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setStyleSheet("background: transparent; border: none;");


    // Asegurarse de que no haya un nuevo QScrollArea creado cada vez
    if (ui->verticalLayout->count() > 0) {
        QLayoutItem* item = ui->verticalLayout->takeAt(0);
        if (item->widget()) {
            item->widget()->deleteLater();
        }
    }

    // Agregar el QScrollArea al layout principal de la ventana
    ui->verticalLayout->addWidget(scrollArea);

    // Ajuste de tamaño
    container->adjustSize();
}
void mesa::revelarSegundaCartaCrupier() {
    if (cartaLabelsCrupier.size() > 1) {
        const auto& manoCrupier = crupier->getMano();
        if (manoCrupier.size() > 1) {
            QString imagenRuta = obtenerRutaImagen(manoCrupier[1]); // Obtener la segunda carta real
            QPixmap pixmap(imagenRuta);

            QLabel* segundaCarta = cartaLabelsCrupier[1]; // Acceder a la segunda carta
            segundaCarta->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio)); // Actualizar imagen
        }
    }
}

void mesa::on_btnVolverAJugar_clicked()
{
    reiniciarJuego();  // Reinicia el juego
    ui->labelPuntajeJugador->setVisible(false);
    ui->labelPuntajeCroupier->setVisible(false);
    // Ocultar el mensaje y el botón "Volver a jugar" hasta que el jugador esté listo
    ui->labelResultado->clear();  // Limpiar el mensaje
    ui->btnVolverAJugar->setVisible(false);  // Ocultar el botón
    ui->labelResultado->setVisible(false);
    ui->btnApostar->setVisible(true);
    ui->labelmakeBet->setVisible(false);
    ui->btnREPARTIR->setVisible(true);
}

