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
    QLineEdit *lineEdit;
    QPushButton *btnVOLVER;
    QPushButton *btnREPARTIR;
    QLabel *labelJugador;
    QLabel *labelCrupier;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelSaldo;
    QLabel *labelApuesta;
    QLineEdit *lineEditApuesta;
    QPushButton *btnApostar;
    QPushButton *btnPLANTARSE;
    QPushButton *btnPEDIR;
    QWidget *verticalWidget1;
    QVBoxLayout *layoutCartasCrupier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mesa)
    {
        if (mesa->objectName().isEmpty())
            mesa->setObjectName("mesa");
        mesa->resize(925, 600);
        mesa->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/a2.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        centralwidget = new QWidget(mesa);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(400, 100, 113, 26));
        lineEdit->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;\n"
""));
        btnVOLVER = new QPushButton(centralwidget);
        btnVOLVER->setObjectName("btnVOLVER");
        btnVOLVER->setGeometry(QRect(690, 460, 191, 31));
        btnVOLVER->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        btnREPARTIR = new QPushButton(centralwidget);
        btnREPARTIR->setObjectName("btnREPARTIR");
        btnREPARTIR->setGeometry(QRect(40, 470, 121, 29));
        btnREPARTIR->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        labelJugador = new QLabel(centralwidget);
        labelJugador->setObjectName("labelJugador");
        labelJugador->setGeometry(QRect(510, 220, 151, 111));
        labelJugador->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;\n"
""));
        labelCrupier = new QLabel(centralwidget);
        labelCrupier->setObjectName("labelCrupier");
        labelCrupier->setGeometry(QRect(540, 370, 161, 20));
        labelCrupier->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setGeometry(QRect(380, 400, 160, 121));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName("verticalLayout");
        labelSaldo = new QLabel(centralwidget);
        labelSaldo->setObjectName("labelSaldo");
        labelSaldo->setGeometry(QRect(30, 120, 81, 51));
        labelSaldo->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        labelApuesta = new QLabel(centralwidget);
        labelApuesta->setObjectName("labelApuesta");
        labelApuesta->setGeometry(QRect(20, 170, 101, 41));
        labelApuesta->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        lineEditApuesta = new QLineEdit(centralwidget);
        lineEditApuesta->setObjectName("lineEditApuesta");
        lineEditApuesta->setGeometry(QRect(10, 220, 113, 28));
        lineEditApuesta->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.png');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        btnApostar = new QPushButton(centralwidget);
        btnApostar->setObjectName("btnApostar");
        btnApostar->setGeometry(QRect(20, 260, 83, 29));
        btnApostar->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        btnPLANTARSE = new QPushButton(centralwidget);
        btnPLANTARSE->setObjectName("btnPLANTARSE");
        btnPLANTARSE->setGeometry(QRect(250, 380, 83, 29));
        btnPLANTARSE->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        btnPEDIR = new QPushButton(centralwidget);
        btnPEDIR->setObjectName("btnPEDIR");
        btnPEDIR->setGeometry(QRect(550, 380, 83, 29));
        btnPEDIR->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        verticalWidget1 = new QWidget(centralwidget);
        verticalWidget1->setObjectName("verticalWidget1");
        verticalWidget1->setGeometry(QRect(290, 140, 321, 121));
        verticalWidget1->setStyleSheet(QString::fromUtf8("background-image: url('C:/Users/Alan Montero/Downloads/proyecto_seminario/b.jpg');\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        layoutCartasCrupier = new QVBoxLayout(verticalWidget1);
        layoutCartasCrupier->setObjectName("layoutCartasCrupier");
        mesa->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mesa);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 925, 25));
        mesa->setMenuBar(menubar);
        statusbar = new QStatusBar(mesa);
        statusbar->setObjectName("statusbar");
        mesa->setStatusBar(statusbar);

        retranslateUi(mesa);

        QMetaObject::connectSlotsByName(mesa);
    } // setupUi

    void retranslateUi(QMainWindow *mesa)
    {
        mesa->setWindowTitle(QCoreApplication::translate("mesa", "MainWindow", nullptr));
        lineEdit->setText(QCoreApplication::translate("mesa", "Crupier", nullptr));
        btnVOLVER->setText(QCoreApplication::translate("mesa", "Volver a pagina principal", nullptr));
        btnREPARTIR->setText(QCoreApplication::translate("mesa", "Repartir Cartas", nullptr));
        labelJugador->setText(QString());
        labelCrupier->setText(QString());
        labelSaldo->setText(QCoreApplication::translate("mesa", "TextLabel", nullptr));
        labelApuesta->setText(QCoreApplication::translate("mesa", "TextLabel", nullptr));
        btnApostar->setText(QCoreApplication::translate("mesa", "Apostar", nullptr));
        btnPLANTARSE->setText(QCoreApplication::translate("mesa", "Plantarse", nullptr));
        btnPEDIR->setText(QCoreApplication::translate("mesa", "Pedir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mesa: public Ui_mesa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESA_H
