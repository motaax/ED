#ifndef CIRCULO
#define CIRCULO
#include "Ponto.h"

class Circulo {
private:
    Ponto  m_center;
    double m_radius;

public:
    Circulo();

    Circulo(Ponto& p, double radius);

    // setters
    void setRadius(double radius);
    void setCenter(Ponto& p);

    // getters
    Ponto& getCenter(); 
    double getRadius(); 

    double area();

    bool contains(Ponto& p);
};

#endif