#ifndef FISICA_H
#define FISICA_H
#include <math.h>
#define dt 1

class Fisica
{
private:
    float px;
    float py;
    float vx;
    float vy;
    float ax;
    float ay;
    int modelo;
    float Ampli=0;
    float pyi=0;
    float Amplix=0;
    float Ampliy=0;
    float cx=0;
    float cy=0;
public:
    Fisica(float px_,float py_, float vx_, float vy_,int modelo_);
    Fisica(float px_,float py_,float Ampli_);
    Fisica();
    float getPx() const;
    void setPx(float newPx);
    float getPy() const;
    void setPy(float newPy);
    float getVx() const;
    void setVx(float newVx);
    float getVy() const;
    void setVy(float newVy);
    void modelos();
};

#endif // FISICA_H
