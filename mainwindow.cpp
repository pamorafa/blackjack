#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mesa(nullptr)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/imagenes/icon/icon.png"));
    this->menuBar()->setVisible(false);  // Oculta la barra de menú
    this->statusBar()->setVisible(false);  // Oculta la barra de estado


    // Aplicar el fondo al QMainWindow
    this->setStyleSheet(
        "QMainWindow {"
        "   background-image: url(':/imagenes/fondos/blac.png');"
        "   background-repeat: no-repeat;"
        "   background-position: center;"
        "   background-clip: border;"
        "}"
        );

    // Estilizar el botón "JUGAR"
    ui->btnJUGAR->setStyleSheet(
        "background-color: #333333; "
        "color: #FFD700; "
        "font-size: 18px; "
        "font-weight: bold; "
        "border: 2px solid #FFD700; "
        "border-radius: 5px; "
        "background-image: none; " // Asegura que no se aplique ninguna imagen heredada
        );
    ui->btnJUGAR->setText("JUGAR");
    // Conectar el botón "JUGAR" a la función correspondiente
    connect(ui->btnJUGAR, &QPushButton::clicked, this, &MainWindow::on_btnJUGAR_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnJUGAR_clicked()
{
    if (!mesa) {
        // Crear la ventana 'mesa' como una ventana independiente
        mesa = new class mesa(nullptr);
        mesa->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

        // Conectar la señal 'destroyed' para volver a mostrar la ventana principal
        connect(mesa, &mesa::destroyed, this, [this]() {
            mesa = nullptr;  // Limpiar el puntero cuando la ventana 'mesa' se destruya
            this->show();    // Volver a mostrar la ventana principal
        });
    }
    mesa->show();  // Mostrar la ventana de juego
    this->hide();  // Ocultar la ventana principal mientras se juega
}
