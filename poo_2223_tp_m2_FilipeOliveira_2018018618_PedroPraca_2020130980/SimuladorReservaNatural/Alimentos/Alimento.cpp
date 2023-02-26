//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//

#include <sstream>
#include "Alimento.h"

Alimento::Alimento(int lin, int col, int id) :
        linha(lin),
        coluna(col),
        ID(id)
        {}

Alimento::Alimento(int lin, int col, int id, int validade) :
        linha(lin),
        coluna(col),
        ID(id),
        validade(validade)
        {}

int Alimento::getId() const {
    return ID;
}

int Alimento::getLinha() const {
    return linha;
}

int Alimento::getColuna() const {
    return coluna;
}

string Alimento::info() const {
    ostringstream oss;

    oss << " ID:               " << ID << endl;
    oss << " x (linha):        " << linha << endl;
    oss << " y (coluna):       " << coluna << endl;
    oss << " Validade          " << validade << endl;

    return oss.str();
}

string Alimento::infoExtra() const {
    ostringstream oss;

    oss << " ID:               " << ID << endl;
    oss << " x (linha):        " << linha << endl;
    oss << " y (coluna):       " << coluna << endl;

    return oss.str();
}

int Alimento::getValidade() const {
    return Alimento::validade;
}

void Alimento::setValidade(int Validade) {
    Alimento::validade = Validade;
}
