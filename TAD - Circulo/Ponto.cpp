#include <iostream>
#include <cmath>
#include "Ponto.h"
using namespace std;

Ponto::Ponto() { 
    m_x = m_y = 0.0; 
}

Ponto::Ponto(double X, double Y) 
    : m_x(X), m_y(Y) { }

void Ponto::setX(double x) { 
    m_x = x; 
}

void Ponto::setY(double y) { 
    m_y = y; 
}

double Ponto::getX() { 
    return m_x; 
}

double Ponto::getY() { 
    return m_y; 
}

double Ponto::distance(Ponto& p) {
    double dx = this->m_x - p.m_x;
    double dy = this->m_y - p.m_y;
    return sqrt(dx*dx + dy*dy);
}

void Ponto::print() { 
    cout << "Ponto(" << m_x << "," << m_y << ")"; 
}