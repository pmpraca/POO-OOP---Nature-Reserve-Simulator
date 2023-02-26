//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//

#ifndef TP_ALIMENTO_H
#define TP_ALIMENTO_H

using namespace std;

#include <vector>
#include <string>

class Alimento {

    int ID;
    int linha, coluna;
    int validade;
    string empty;

public:

    Alimento(int linha, int coluna, int ID);
    Alimento(int linha, int coluna, int ID, int validade);

    virtual ~Alimento() = default;

    //Getters & Setters - classe base
    int getId() const;
    int getLinha() const;
    int getColuna() const;
    int getValidade() const;
    void setValidade(int validade);

    // Métodos Virtuais
    virtual string info() const;
    virtual string infoExtra() const;
    virtual string getCheiro() const = 0;
    virtual void setCheiro(string str) {};
    virtual string getTipo() const = 0;
    virtual int getValorNutritivo() const { return 0;};
    virtual int getToxicidade() const { return 0;};
    virtual void setValorNutritivo(int valorNutritivo) {};
    virtual void setToxicidade(int toxicidade) {};
    virtual int getValidadePDefeito() {return 0;};
    virtual bool isExiste() const {return 0;};
    virtual void setExiste(bool existe) {};
    virtual bool isProcriou() const {return 0;};
    virtual void setProcriou(bool procriou) {};
    virtual int getCont() const {return 0;};
    virtual void setCont() {};
    virtual void setCont(int val) {};
    virtual int getMax() const {return 0;};
    virtual void setMax(int max) {};
    virtual int getVNutritivoInicial() const {return 0;};
    virtual void setVNutritivoInicial(int vNutritivoInicial) {};
    virtual bool isBatataFrita() const {return 0;};
    virtual void setBatataFrita(bool batataFrita) {};

};

#endif //TP_ALIMENTO_H
