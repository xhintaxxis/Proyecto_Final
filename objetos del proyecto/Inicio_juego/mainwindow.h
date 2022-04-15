#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <cuerpo.h>
#include "jugador.h"
#include "QKeyEvent"
#include <QDebug>
#include <QTimer>
#include <QList>
#include "rayo.h"
#include <enemigo_1.h>
#include "enemigo_3.h"
#include "bolafuego.h"
#include <time.h>
#include "botton.h"
#include "enemigo_2.h"
#include "corazon.h"
#include <QFont>
#include <QImage>
#include <QBrush>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void moverPruebas();
    void escena_1();
    void pre1();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem * cuadro;
    cuerpo * nave;
    jugador * nave1;
    Enemigo_1 * enemy;
    enemigo_3 * enemy2;
    bolafuego * ball;
    QGraphicsPixmapItem * titulo;

    int nume1=1;
signals:
    void tecla();


};
#endif // MAINWINDOW_H
