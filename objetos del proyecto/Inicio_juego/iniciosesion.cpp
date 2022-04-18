#include "iniciosesion.h"
#include "ui_iniciosesion.h"

inicioSesion::inicioSesion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicioSesion)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/oceno.gif"))));
}

inicioSesion::~inicioSesion()
{
    delete ui;
}

bool inicioSesion::getPermiso() const
{
    return permiso;
}

bool inicioSesion::verificar()
{
    QString nombre;
    QString pass;
    QString info;
    QString stage;
    QFile file(":/texto/usuarios.txt");
    file.open(QIODevice::ReadOnly);
    while(true){
    info = file.readLine();
    if(info!=""){
//        qDebug()<<"szs";
//        qDebug()<<info.size();
        int n=0;
        while(true){
            nombre.append(info.at(n));
            n++;
            if (info.at(n)==char(44)){
                break;
            }
        }
        n=n+1;
        while(true){
            pass.append(info.at(n));
            n++;
            if (info.at(n)==char(44)){
                break;
            }
        }
        stage=info.at(n+1);
        int area=stage.toInt();
        nivel=area;
//        qDebug()<<nombre;
//        qDebug()<<pass;
//        qDebug()<<area;
        if(nombre==usuario and pass==password){
            file.close();
            return true;
        }
        nombre.clear();
        pass.clear();
        stage.clear();
    }
    else{
        file.close();
        return false;
    }
    }
}

void inicioSesion::on_pushButton_clicked()
{
    usuario.clear();
    password.clear();
    usuario = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    permiso=verificar();
    if (permiso==true){
        emit aceptar();
    }
}

