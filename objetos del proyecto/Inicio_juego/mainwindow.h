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
#include <jefe1.h>
#include <jefe2.h>
#include <obstaculo.h>
#include <QFile>
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
    void enemigosS1();
    void enemigosS2();
    void gameOver();
    void menu();
    void scenaBoss1();
    void scenaBoss2();
    void saveScene();
    void pre2();
    void escena_2();
    void save();
    void cargar();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem * cuadro;
    cuerpo * nave;
    jugador * nave1;
    Enemigo_1 * enemy;
    Enemigo_1 * enemy12;
    enemigo_2 * enemy2;
    enemigo_3 * enemy3;
    bolafuego * ball;
    QGraphicsPixmapItem * titulo;
    QGraphicsPixmapItem  * stage1;
    botton * comenzar;
    QTimer * scen1;
    QTimer * lose;
    QTimer * jefe1timer;
    int cambio=1;
    int nume1=1;
    jefe1 * boss1;
    jefe2 * boss2;
    int passBoss ;
    botton * guardar;
    botton * next_level;
    QGraphicsPixmapItem  * completado;

signals:
    void tecla();


};
#endif // MAINWINDOW_H
