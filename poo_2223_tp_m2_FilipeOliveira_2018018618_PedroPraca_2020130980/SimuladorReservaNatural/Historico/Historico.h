//
// Created by Pedro Praça & Filipe Oliveira on 22/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_HISTORICO_H
#define SIMULADORRESERVANATURAL_HISTORICO_H

using namespace std;

#include <string>

class Historico {

    string comida;
    int vNutritivo;
    int pToxicidade;

public:
    Historico();

    string infoHistorico() const; //informçao relativa ao que animal comeu

    void setComida(const string &comida);

    void setVNutritivo(int vNutritivo);

    void setPToxicidade(int pToxicidade);

};


#endif //SIMULADORRESERVANATURAL_HISTORICO_H
