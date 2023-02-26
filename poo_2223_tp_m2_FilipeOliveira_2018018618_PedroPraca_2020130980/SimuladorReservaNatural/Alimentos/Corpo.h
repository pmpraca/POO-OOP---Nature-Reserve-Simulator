//
// Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_CORPO_H
#define SIMULADORRESERVANATURAL_CORPO_H

#include <sstream>
#include "Alimento.h"

using namespace std;

class Corpo : public Alimento {

    int valorNutritivo;
    int toxicidade;
    string cheiros; // "erva","verdura","carne","ketchup"
    bool existe;
    int cont;
    int vNutritivoInicial;

public:

    Corpo(int linha, int coluna, int ID) : Alimento(linha, coluna, ID), valorNutritivo(0), toxicidade(0), existe(true), cont(0) {}

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
        return Corpo::valorNutritivo;
    }

    int getToxicidade() const override{
        return Corpo::toxicidade;
    }

    void setValorNutritivo(int ValorNutritivo) override{
        Corpo::valorNutritivo = ValorNutritivo;
    }

    void setToxicidade(int Toxicidade) override{
        Corpo::toxicidade = Toxicidade;
    }

    string getTipo() const override {
        return "Corpo";
    }

    string getCheiro() const override {
        return "carne";
    }

    bool isExiste() const override{
        return Corpo::existe;
    }

    void setExiste(bool Existe) override{
        Corpo::existe = Existe;
    }

    int getCont() const override{
        return Corpo::cont;
    }

    void setCont() override{
        Corpo::cont++;
    }

    void setCont(int val) override{
        Corpo::cont = val;
    }

    int getVNutritivoInicial() const override {
        return Corpo::vNutritivoInicial;
    }

    void setVNutritivoInicial(int VnutritivoInicial) override{
        Corpo::vNutritivoInicial = VnutritivoInicial;
    }

};

#endif //SIMULADORRESERVANATURAL_CORPO_H
