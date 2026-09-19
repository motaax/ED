#include <cmath>
#include "Circulo.h"

// Construtor sem argumentos
Circulo::Circulo(): m_center(0.0, 0.0), m_radius(1.0){};

//Construtor com argumentos
Circulo::Circulo(Ponto &p, double radius){
    m_center = p;
    m_radius = radius;
}

void Circulo::setRadius(double radius) {
    m_radius = radius;
}

void Circulo::setCenter(Ponto &p) {
    m_center = p;
}

Ponto& Circulo::getCenter() {
    return m_center;
}

double Circulo::getRadius() {
    return m_radius;
}

// Area do circulo
double Circulo::area() {
    return M_PI * m_radius * m_radius;
}

//Verifica se o "p" está no circulo
bool Circulo::contains(Ponto& p) {
    return m_center.distance(p) <= m_radius;
}