//
//  Created by Pedro Praça & Filipe Oliveira on 02/01/2023.
//

#ifndef SIMULADORRESERVANATURAL_BATATA_H
#define SIMULADORRESERVANATURAL_BATATA_H

#include <sstream>
#include "Alimento.h"

using namespace std;

class Batata : public Alimento {

    int valorNutritivo;
    int toxicidade;
    bool existe;
    int cont;
    string cheiro;
    bool batataFrita;

public:

    Batata(int linha, int coluna, int ID) : Alimento(linha, coluna, ID, 30), valorNutritivo(5), toxicidade(0), existe(true), cont(0), batataFrita(false), cheiro("batata,verdura") {}

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
        return Batata::valorNutritivo;
    }

    int getToxicidade() const override{
        return Batata::toxicidade;
    }

    void setValorNutritivo(int ValorNutritivo) override{
        Batata::valorNutritivo = ValorNutritivo;
    }

    void setToxicidade(int Toxicidade) override{
        Batata::toxicidade = Toxicidade;
    }

    string getTipo() const override {
        return "Batata";
    }

    string getCheiro() const override {
        return cheiro;
    }

    void setCheiro(string str) override {
        cheiro = str;
    }

    bool isExiste() const override{
        return Batata::existe;
    }

    void setExiste(bool Existe) override{
        Batata::existe = Existe;
    }

    int getCont() const override{
        return Batata::cont;
    }

    void setCont() override{
        Batata::cont++;
    }

    void setCont(int val) override{
        Batata::cont = val;
    }

    bool isBatataFrita() const override{
        return batataFrita;
    }

    void setBatataFrita(bool BatataFrita) override{
        Batata::batataFrita = BatataFrita;
    }

};

#endif //SIMULADORRESERVANATURAL_BATATA_H
