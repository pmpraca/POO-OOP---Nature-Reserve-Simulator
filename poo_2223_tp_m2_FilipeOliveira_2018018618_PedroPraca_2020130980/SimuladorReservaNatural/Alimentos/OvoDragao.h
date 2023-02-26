//
//  Created by Pedro Praça & Filipe Oliveira on 02/01/2023.
//

#ifndef SIMULADORRESERVANATURAL_OVODRAGAO_H
#define SIMULADORRESERVANATURAL_OVODRAGAO_H

#include <sstream>
#include "Alimento.h"

using namespace std;

class OvoDragao : public Alimento {

    int valorNutritivo;
    int toxicidade;
    bool existe;
    int cont;

public:

    OvoDragao(int linha, int coluna, int ID) : Alimento(linha, coluna, ID, 20), valorNutritivo(15), toxicidade(0), existe(true), cont(0) {}

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
        return OvoDragao::valorNutritivo;
    }

    int getToxicidade() const override{
        return OvoDragao::toxicidade;
    }

    void setValorNutritivo(int ValorNutritivo) override{
        OvoDragao::valorNutritivo = ValorNutritivo;
    }

    void setToxicidade(int Toxicidade) override{
        OvoDragao::toxicidade = Toxicidade;
    }

    string getTipo() const override {
        return "OvoDragao";
    }

    string getCheiro() const override {
        return "ovo";
    }

    bool isExiste() const override{
        return OvoDragao::existe;
    }

    void setExiste(bool Existe) override{
        OvoDragao::existe = Existe;
    }

    int getCont() const override{
        return OvoDragao::cont;
    }

    void setCont() override{
        OvoDragao::cont++;
    }

    void setCont(int val) override{
        OvoDragao::cont = val;
    }

};

#endif //SIMULADORRESERVANATURAL_OVODRAGAO_H
