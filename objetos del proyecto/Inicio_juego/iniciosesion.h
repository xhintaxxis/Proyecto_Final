#ifndef INICIOSESION_H
#define INICIOSESION_H

#include <QMainWindow>
#include<QGraphicsScene>
#include <QDebug>
#include <QFile>
namespace Ui {
class inicioSesion;
}

class inicioSesion : public QMainWindow
{
    Q_OBJECT

public:
    explicit inicioSesion(QWidget *parent = nullptr);
    ~inicioSesion();
    QString password;
    QString usuario;
    int nivel=0;
    bool permiso=false;
    bool verificar();

    bool getPermiso() const;

private slots:
    void on_pushButton_clicked();
signals:
    void aceptar();

private:
    Ui::inicioSesion *ui;
    QGraphicsScene *scene;
};

#endif // INICIOSESION_H
