#ifndef CAIXA_H
#define CAIXA_H

//Classe que modela o TAD Caixa
class Caixa {
private:
    double altura = 1.0;
    double largura = 1.0;
    double comprimento = 1.0;
public:
    Caixa() {} //Construtor default

    Caixa(double a, double l) : Caixa(a, l, 2.0) {} //Reaproveitando construtores

    Caixa(double a, double l, double c) {
        altura = a;
        largura = l;
        comprimento = c;
    }

    double volume() {
        return altura * largura * comprimento;
    }
};

#endif