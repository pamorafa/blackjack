#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mesa.h"
#include "jugador.h"  // Incluye la clase Jugador

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnJUGAR_clicked();

private:
    Ui::MainWindow *ui;
    mesa *mesa;
    Jugador *jugador; // Declarar jugador como un puntero
};
#endif // MAINWINDOW_H
