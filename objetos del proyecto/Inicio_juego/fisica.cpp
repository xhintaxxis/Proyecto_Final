#include "fisica.h"

float Fisica::getPx() const
{
    return px;
}

void Fisica::setPx(float newPx)
{
    px = newPx;
}

float Fisica::getPy() const
{
    return py;
}

void Fisica::setPy(float newPy)
{
    py = newPy;
}

float Fisica::getVx() const
{
    return vx;
}

void Fisica::setVx(float newVx)
{
    vx = newVx;
}

float Fisica::getVy() const
{
    return vy;
}

void Fisica::setVy(float newVy)
{
    vy = newVy;
}

void Fisica::modelos()
{
    //rectilineo uniforme
    if (modelo==0){
        px=px+vx;
        py=py+vy;
    }
    //Parabolico
    else if(modelo==1){
        px=px+vx;
        vy=vy+0.2*0.5;
        py=py+vy+(0.2/2)*0.5;
    }
    //Oscilatorio
    else if(modelo==2){
        px=px+3;
        py=(Ampli*cos(px*0.03))+pyi;
    }
    else if(modelo==3){
        static float theta=0.01;
        px=300*cos(theta)+400;
        py=200*sin(theta)+200;
        theta+=0.01;
    }
}

Fisica::Fisica(float px_,float py_, float vx_, float vy_, int modelo_):
    px(px_),py(py_),vx(vx_),vy(vy_),modelo(modelo_)
{

}

Fisica::Fisica(float px_,float py_,float Ampli_):
    px(px_),py(py_),Ampli(Ampli_),pyi(py_)
{
    modelo=2;
}

Fisica::Fisica(){
    modelo=3;
    px=100+400;
    py=200;
}


