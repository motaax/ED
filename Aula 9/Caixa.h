#ifndef CAIXA_H
#define CAIXA_H

//Classe que modela o TAD Caixa
class Caixa {
    
private:
    double altura = 1.0;
    double largura = 1.0;
    double comprimento = 1.0;

public:
    double volume() {
        return altura * largura * comprimento;
    }
};

#endif