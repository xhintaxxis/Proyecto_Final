#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <cuerpo.h>
#include "jugador.h"
#include "QKeyEvent"
#include <QDebug>
#include <QTimer>
#include <enemigo_1.h>
#include "enemigo_3.h"
#include "bolafuego.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void moverPruebas();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem * cuadro;
    cuerpo * nave;
    QTimer * timer;
    QTimer * timer2;
    jugador * nave1;
    Enemigo_1 * enemy;
    enemigo_3 * enemy2;
    bolafuego * ball;


};
#endif // MAINWINDOW_H
