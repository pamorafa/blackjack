/********************************************************************************
** Form generated from reading UI file 'mesa.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESA_H
#define UI_MESA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mesa
{
public:
    QWidget *centralwidget;
    QPushButton *btnVOLVER;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnPLANTARSE;
    QPushButton *btnPEDIR;
    QWidget *verticalWidget_2;
    QVBoxLayout *layoutCartasCrupier;
    QLabel *labelResultado;
    QPushButton *btnVolverAJugar;
    QLabel *labelValorJugador;
    QLabel *labelValorCrupier;
    QLabel *label_CROUPIER;
    QLabel *label_JUGADOR;
    QLabel *labelPuntajeJugador;
    QLabel *labelPuntajeCroupier;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *labelmakeBet;
    QPushButton *btnREPARTIR;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *btnApostar;
    QLineEdit *lineEditApuesta;
    QLabel *labelApuesta;
    QLabel *labelSaldo;
    QLabel *labelApuestaInvalida;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mesa)
    {
        if (mesa->objectName().isEmpty())
            mesa->setObjectName("mesa");
        mesa->resize(1048, 690);
        centralwidget = new QWidget(mesa);
        centralwidget->setObjectName("centralwidget");
        btnVOLVER = new QPushButton(centralwidget);
        btnVOLVER->setObjectName("btnVOLVER");
        btnVOLVER->setGeometry(QRect(760, 620, 91, 40));
        btnVOLVER->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(260, 420, 401, 121));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName("verticalLayout");
        btnPLANTARSE = new QPushButton(centralwidget);
        btnPLANTARSE->setObjectName("btnPLANTARSE");
        btnPLANTARSE->setGeometry(QRect(240, 560, 83, 29));
        btnPLANTARSE->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        btnPEDIR = new QPushButton(centralwidget);
        btnPEDIR->setObjectName("btnPEDIR");
        btnPEDIR->setGeometry(QRect(580, 560, 83, 29));
        btnPEDIR->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        verticalWidget_2 = new QWidget(centralwidget);
        verticalWidget_2->setObjectName("verticalWidget_2");
        verticalWidget_2->setGeometry(QRect(260, 130, 401, 121));
        layoutCartasCrupier = new QVBoxLayout(verticalWidget_2);
        layoutCartasCrupier->setObjectName("layoutCartasCrupier");
        labelResultado = new QLabel(centralwidget);
        labelResultado->setObjectName("labelResultado");
        labelResultado->setGeometry(QRect(720, 360, 180, 91));
        labelResultado->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        btnVolverAJugar = new QPushButton(centralwidget);
        btnVolverAJugar->setObjectName("btnVolverAJugar");
        btnVolverAJugar->setGeometry(QRect(740, 460, 121, 29));
        btnVolverAJugar->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        labelValorJugador = new QLabel(centralwidget);
        labelValorJugador->setObjectName("labelValorJugador");
        labelValorJugador->setGeometry(QRect(370, 370, 171, 20));
        labelValorJugador->setAutoFillBackground(false);
        labelValorJugador->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        labelValorCrupier = new QLabel(centralwidget);
        labelValorCrupier->setObjectName("labelValorCrupier");
        labelValorCrupier->setGeometry(QRect(370, 260, 171, 20));
        labelValorCrupier->setAutoFillBackground(false);
        labelValorCrupier->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        label_CROUPIER = new QLabel(centralwidget);
        label_CROUPIER->setObjectName("label_CROUPIER");
        label_CROUPIER->setGeometry(QRect(420, 100, 61, 20));
        label_JUGADOR = new QLabel(centralwidget);
        label_JUGADOR->setObjectName("label_JUGADOR");
        label_JUGADOR->setGeometry(QRect(420, 380, 61, 20));
        labelPuntajeJugador = new QLabel(centralwidget);
        labelPuntajeJugador->setObjectName("labelPuntajeJugador");
        labelPuntajeJugador->setGeometry(QRect(260, 380, 49, 16));
        labelPuntajeCroupier = new QLabel(centralwidget);
        labelPuntajeCroupier->setObjectName("labelPuntajeCroupier");
        labelPuntajeCroupier->setGeometry(QRect(260, 100, 49, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 390, 196, 240));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        labelmakeBet = new QLabel(layoutWidget);
        labelmakeBet->setObjectName("labelmakeBet");
        labelmakeBet->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));

        gridLayout_3->addWidget(labelmakeBet, 0, 0, 1, 1);

        btnREPARTIR = new QPushButton(layoutWidget);
        btnREPARTIR->setObjectName("btnREPARTIR");
        btnREPARTIR->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));

        gridLayout_3->addWidget(btnREPARTIR, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btnApostar = new QPushButton(layoutWidget);
        btnApostar->setObjectName("btnApostar");
        btnApostar->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));

        gridLayout->addWidget(btnApostar, 3, 0, 1, 1);

        lineEditApuesta = new QLineEdit(layoutWidget);
        lineEditApuesta->setObjectName("lineEditApuesta");
        lineEditApuesta->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));

        gridLayout->addWidget(lineEditApuesta, 2, 0, 1, 1);

        labelApuesta = new QLabel(layoutWidget);
        labelApuesta->setObjectName("labelApuesta");
        labelApuesta->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        labelApuesta->setFrameShape(QFrame::Shape::WinPanel);
        labelApuesta->setFrameShadow(QFrame::Shadow::Plain);

        gridLayout->addWidget(labelApuesta, 1, 0, 1, 1);

        labelSaldo = new QLabel(layoutWidget);
        labelSaldo->setObjectName("labelSaldo");
        labelSaldo->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        labelSaldo->setFrameShape(QFrame::Shape::WinPanel);

        gridLayout->addWidget(labelSaldo, 0, 0, 1, 1);

        labelApuestaInvalida = new QLabel(layoutWidget);
        labelApuestaInvalida->setObjectName("labelApuestaInvalida");
        labelApuestaInvalida->setStyleSheet(QString::fromUtf8("background-image: url(':/imagenes/fondos/b1.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));

        gridLayout->addWidget(labelApuestaInvalida, 4, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 1);

        mesa->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mesa);
        menubar->setObjectName("menubar");
        menubar->setEnabled(false);
        menubar->setGeometry(QRect(0, 0, 1048, 26));
        mesa->setMenuBar(menubar);
        statusbar = new QStatusBar(mesa);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(false);
        mesa->setStatusBar(statusbar);

        retranslateUi(mesa);

        QMetaObject::connectSlotsByName(mesa);
    } // setupUi

    void retranslateUi(QMainWindow *mesa)
    {
        mesa->setWindowTitle(QCoreApplication::translate("mesa", "Blackjack", nullptr));
        btnVOLVER->setText(QCoreApplication::translate("mesa", "Salir", nullptr));
        btnPLANTARSE->setText(QCoreApplication::translate("mesa", "Plantarse", nullptr));
        btnPEDIR->setText(QCoreApplication::translate("mesa", "Pedir", nullptr));
        labelResultado->setText(QString());
        btnVolverAJugar->setText(QCoreApplication::translate("mesa", "Volver a Jugar", nullptr));
        labelValorJugador->setText(QString());
        labelValorCrupier->setText(QString());
        label_CROUPIER->setText(QCoreApplication::translate("mesa", "CROUPIER", nullptr));
        label_JUGADOR->setText(QCoreApplication::translate("mesa", "JUGADOR", nullptr));
        labelPuntajeJugador->setText(QCoreApplication::translate("mesa", "Puntaje: ", nullptr));
        labelPuntajeCroupier->setText(QCoreApplication::translate("mesa", "Puntaje: ", nullptr));
        labelmakeBet->setText(QCoreApplication::translate("mesa", "Por favor, realice una apuesta", nullptr));
        btnREPARTIR->setText(QCoreApplication::translate("mesa", "Repartir Cartas", nullptr));
        btnApostar->setText(QCoreApplication::translate("mesa", "Apostar", nullptr));
        labelApuesta->setText(QCoreApplication::translate("mesa", "TextLabel", nullptr));
        labelSaldo->setText(QCoreApplication::translate("mesa", "TextLabel", nullptr));
        labelApuestaInvalida->setText(QCoreApplication::translate("mesa", "Apuesta inv\303\244lida\n"
"Intentelo nuevamente", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mesa: public Ui_mesa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESA_H
