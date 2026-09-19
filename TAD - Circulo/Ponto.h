#ifndef PONTO
#define PONTO

class Ponto {
private:
    double m_x, m_y;

public:
    Ponto();

    Ponto(double X, double Y);
    
    // Setters
    void setX(double x);
    void setY(double y);
    
    // Getters
    double getX();
    double getY();
    
    double distance(Ponto& p);
    
    void print();
};

#endif