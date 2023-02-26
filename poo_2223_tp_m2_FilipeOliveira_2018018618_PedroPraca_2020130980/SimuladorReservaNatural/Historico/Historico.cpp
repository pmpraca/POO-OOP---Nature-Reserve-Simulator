//
// Created by Pedro Praça & Filipe Oliveira on 22/12/2022.
//

#include <sstream>
#include "Historico.h"

Historico::Historico() {}

void Historico::setComida(const string &Comida) {
    Historico::comida = Comida;
}

void Historico::setVNutritivo(int Vnutritivo) {
    Historico::vNutritivo = Vnutritivo;
}

void Historico::setPToxicidade(int Ptoxicidade) {
    Historico::pToxicidade = Ptoxicidade;
}

string Historico::infoHistorico() const {
    ostringstream oss;

    oss << "Comeu:           " << comida << endl;
    oss << "Valor Nutritivo: " << vNutritivo << endl;
    oss << "Pontos Toxicos:  " << pToxicidade << endl << endl;

    return oss.str();
}

