#include "cuerpo.h"


Fisica *cuerpo::getModefi() const
{
    return modefi;
}

void cuerpo::proyectil()
{
//    rayo * bala;
//    bala = new rayo(modefi->getPx()+110,modefi->getPy()+20,8,0,0);
//    scene()->addItem(bala);
    bala.append(new rayo(modefi->getPx()+110,modefi->getPy()+20,8,0,0));
    scene()->addItem(bala.at(bala.size()-1));
}

cuerpo::cuerpo(float px_,float py_, float vx_, float vy_, int modelo_,QGraphicsScene * scene, QGraphicsItem* carr):QGraphicsPixmapItem(carr)
{
    modelo_=0;
    modefi=new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/nave.png"));
    setPos(px_,py_);
    corazon * heart= new corazon(0);
    scene->addItem(heart);
    energia = new salud(10);
    scene->addItem(energia);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    QTimer * timer = new QTimer();
    vida=energia->getVida();
    connect(timer,SIGNAL(timeout()),this,SLOT(VerColision()));
    timer->start(44);

}

void cuerpo::posicionar()
{
    setPos(modefi->getPx(),modefi->getPy());
    modefi->setVx(0);
    modefi->setVy(0);

}

void cuerpo::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case  Qt::Key_D:{

        if(modefi->getPx()<500){
        modefi->setVx(12);
        modefi->modelos();
        posicionar();
        }
        break;
    }
    case  Qt::Key_A:{
        if(modefi->getPx()>0){
        modefi->setVx(-12);
        modefi->modelos();
        posicionar();
        }
        break;
    }
    case  Qt::Key_S:{
        if(modefi->getPy()<435){
        modefi->setVy(12);
        modefi->modelos();
        posicionar();
        }
        break;
    }
    case  Qt::Key_W:{
        if(modefi->getPy()>5){
        modefi->setVy(-12);
        modefi->modelos();
        posicionar();
        }
        break;
    }
    case  Qt::Key_Space:{
        proyectil();
        //ui->graphicsView->scale(0.5,0.5);
        break;
    }
    case  Qt::Key_L:{
//        Disparar();
//        ui->graphicsView->scale(0.5,0.5);
        break;
    }
    case  Qt::Key_K:{
//        Disparar();
//        ui->graphicsView->scale(1.5,1.5);
        break;
    }
    case  Qt::Key_P:{
        break;
    }
    default: break;
    }
}

void cuerpo::menu()
{

}

void cuerpo::VerColision()
{
    QList<QGraphicsItem *> enemyColision = collidingItems();
    for(int i =0 ; i<enemyColision.size();i++){
        if(typeid (*(enemyColision.at(i)))==typeid (Enemigo_1)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(1);
            return;
        }
        else if(typeid (*(enemyColision.at(i)))==typeid (enemigo_3)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(3);
            qDebug()<<vida;
            return;
        }
        else if(typeid (*(enemyColision.at(i)))==typeid (bomba)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(1);
            return;
        }
        else if(typeid (*(enemyColision.at(i)))==typeid (rayoE)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(1);
            return;
        }
        else if(typeid (*(enemyColision.at(i)))==typeid (enemigo_2)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(4);
            return;
        }
        else if(typeid (*(enemyColision.at(i)))==typeid (Obstaculo)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(3);
            return;
        }
        else if(typeid (*(enemyColision.at(i)))==typeid (rockreb)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(1);
            return;
        }
        else if(typeid (*(enemyColision.at(i)))==typeid (bolafuego)){
            scene()->removeItem(enemyColision.at(i));
            delete enemyColision.at(i);
            energia->dano(1);
            return;
        }
    }
    vida=energia->getVida();
    if (energia==0){
        emit lose();
    }
}

