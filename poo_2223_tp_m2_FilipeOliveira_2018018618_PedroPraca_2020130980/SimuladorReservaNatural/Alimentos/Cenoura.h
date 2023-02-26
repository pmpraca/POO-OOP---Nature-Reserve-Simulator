//
// Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_CENOURA_H
#define SIMULADORRESERVANATURAL_CENOURA_H

#include <sstream>
#include "Alimento.h"

using namespace std;

class Cenoura : public Alimento {

    int valorNutritivo;
    int toxicidade;
    string cheiros; // "erva","verdura","carne","ketchup"
    bool existe;
    int cont;
    int max;

public:

    Cenoura(int linha, int coluna, int ID) : Alimento(linha, coluna, ID), valorNutritivo(4), toxicidade(0), existe(true), cont(10), max(0) {}

    string info() const override {
        ostringstream oss;

        oss << " Tipo:             " << getTipo() << endl;
        oss << Alimento::infoExtra();
        oss << " Validade:         " << "Infinita" << endl;
        oss << " Valor Nutritivo:  " << valorNutritivo << endl;
        oss << " Toxicidade:       " << toxicidade << endl;
        oss << " Cheiro:           " << getCheiro() << endl;

        return oss.str();
    }

    int getValorNutritivo() const override{
        return Cenoura::valorNutritivo;
    }

    int getToxicidade() const override{
        return Cenoura::toxicidade;
    }

    void setValorNutritivo(int ValorNutritivo) override{
        Cenoura::valorNutritivo = ValorNutritivo;
    }

    void setToxicidade(int Toxicidade) override{
        Cenoura::toxicidade = Toxicidade;
    }

    string getTipo() const override {
        return "Cenoura";
    }

    string getCheiro() const override {
        return "verdura";
    }

    bool isExiste() const override{
        return Cenoura::existe;
    }

    void setExiste(bool Existe) override{
        Cenoura::existe = Existe;
    }

    int getCont() const override{
        return Cenoura::cont;
    }

    void setCont() override{
        Cenoura::cont--;
    }

    void setCont(int val) override{
        Cenoura::cont = val;
    }

    int getMax() const override{
        return Cenoura::max;
    }

    void setMax(int Max) override{
        Cenoura::max = Max;
    }

};

#endif //SIMULADORRESERVANATURAL_CENOURA_H
