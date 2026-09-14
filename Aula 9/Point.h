#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>

//Classe que modela o TAD Point
class Point {

private:
    double x, y;
public:
    // Construtor padrão adicionado para permitir a criação de vetores sem valores iniciais
    Point() {
        this->x = 0.0;
        this->y = 0.0;
    }

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() {
        return this->x;
    }

    double getY() {
        return this->y;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    double dist(Point q) {
        return hypot(q.x-this->x, q.y-this->y);
    }
    
    //Destrutor
    ~Point() {};
    
};

#endif