//
// Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_BIFE_H
#define SIMULADORRESERVANATURAL_BIFE_H

#include <sstream>
#include "Alimento.h"

using namespace std;

class Bife : public Alimento {

    int valorNutritivo;
    int toxicidade;
    bool existe;
    int cont;

public:

    Bife(int linha, int coluna, int ID) : Alimento(linha, coluna, ID, 30), valorNutritivo(10), toxicidade(2), existe(true), cont(0) {}

    string info() const override {
        ostringstream oss;

        oss << " Tipo:             " << getTipo() << endl;
        oss << Alimento::info();
        oss << " Valor Nutritivo:  " << valorNutritivo << endl;
        oss << " Toxicidade:       " << toxicidade << endl;
        oss << " Cheiros:          " << getCheiro() << endl;

        return oss.str();
    }

    int getValorNutritivo() const override{
        return Bife::valorNutritivo;
    }

    int getToxicidade() const override{
        return Bife::toxicidade;
    }

    void setValorNutritivo(int ValorNutritivo) override{
        Bife::valorNutritivo = ValorNutritivo;
    }

    void setToxicidade(int Toxicidade) override{
        Bife::toxicidade = Toxicidade;
    }

    string getTipo() const override {
        return "Bife";
    }

    string getCheiro() const override {
        return "carne,ketchup";
    }

    bool isExiste() const override{
        return Bife::existe;
    }

    void setExiste(bool Existe) override{
        Bife::existe = Existe;
    }

    int getCont() const override{
        return Bife::cont;
    }

    void setCont() override{
        Bife::cont++;
    }

    void setCont(int val) override{
        Bife::cont = val;
    }

};

#endif //SIMULADORRESERVANATURAL_BIFE_H
