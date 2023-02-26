//
// Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_RELVA_H
#define SIMULADORRESERVANATURAL_RELVA_H

#include <sstream>
#include "Alimento.h"

using namespace std;

class Relva : public Alimento {

    int valorNutritivo;
    int toxicidade;
    string cheiros; // "erva","verdura","carne","ketchup"
    static int validadePDefeito;
    bool existe;
    bool procriou;

public:

    Relva(int linha, int coluna, int ID) : Alimento(linha, coluna, ID, validadePDefeito), valorNutritivo(3), toxicidade(0), existe(true), procriou(false) {}

    string info() const override {
        ostringstream oss;

        oss << " Tipo:             " << getTipo() << endl;
        oss << Alimento::info();
        oss << " Valor Nutritivo:  " << valorNutritivo << endl;
        oss << " Toxicidade:       " << toxicidade << endl;
        oss << " Cheiro:           " << getCheiro() << endl;

        return oss.str();
    }

    static void setValidadePDefeito(int dVida) {
        validadePDefeito = dVida;
    }

    int getValidadePDefeito() override{
        return validadePDefeito;
    }

    int getValorNutritivo() const override{
        return Relva::valorNutritivo;
    }

    int getToxicidade() const override{
        return Relva::toxicidade;
    }

    void setValorNutritivo(int ValorNutritivo) override{
        Relva::valorNutritivo = ValorNutritivo;
    }

    void setToxicidade(int Toxicidade) override{
        Relva::toxicidade = Toxicidade;
    }

    string getTipo() const override {
        return "Relva";
    }

    string getCheiro() const override {
        return "erva,verdura";
    }

    bool isExiste() const override {
        return Relva::existe;
    }

    void setExiste(bool Existe) override{
        Relva::existe = Existe;
    }

    bool isProcriou() const override{
        return Relva::procriou;
    }

    void setProcriou(bool Procriou) override{
        Relva::procriou = Procriou;
    }

};

#endif //SIMULADORRESERVANATURAL_RELVA_H
