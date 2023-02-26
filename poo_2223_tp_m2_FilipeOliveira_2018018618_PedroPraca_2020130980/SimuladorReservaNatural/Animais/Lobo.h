//
// Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_LOBO_H
#define SIMULADORRESERVANATURAL_LOBO_H

#include <sstream>
#include "Animal.h"

using namespace std;

class Lobo : public Animal {

    int p;
    int peso;
    int fome;
    bool vivo;
    bool procriou;
    static int dVidaPDefeito;
    static int saudePDefeito;

public:

    Lobo(int linha, int coluna, int ID) : Animal(linha, coluna, ID, saudePDefeito), peso(15), p(1), vivo(true), procriou(false), fome(0) {}

    string info() const override {
        ostringstream oss;

        oss << " Especie            " << getEspecie() << endl;
        oss << Animal::infoExtra();
        oss << " Duracao Vida      " << "N/A" << endl;
        oss << " Peso              " << peso << endl;
        oss << " Fome              " << fome << endl;

        return oss.str();
    }

    int getPeso() const override {
        return Lobo::peso;
    }

    void setPeso(int Peso) override {
        Lobo::peso = Peso;
    }

    int getFome() const override {
        return Lobo::fome;
    }

    void setFome() override {
        Lobo::fome+= 2;
        if(Lobo::fome > 15 && Lobo::fome <= 25){
            setSaude(getSaude()-1);
            Lobo::p=2;
        }else if(Lobo::fome > 25) {
            setSaude(getSaude()-2);
        }
    }

    void setFome(int val) override {
        Lobo::fome = val;
    }

    static void setSaudeDefeito(int saude) {
        saudePDefeito = saude;
    };

    static void setDVidaPDefeito(int dVida) {
        dVidaPDefeito = dVida;
    }

    int getDVidaPDefeito() override {
        return dVidaPDefeito;
    }

    string getEspecie() const override {
        return "Lobo";
    }

    void movimento(int NL, int NC) override{

        int linha, coluna;
        int novaLin, novaCol;

        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(getLinha() - p, getLinha() + p);
        uniform_int_distribution<int> r1(getColuna() - p, getColuna() + p);

        novaLin = r(engine);
        novaCol = r1(engine);

        linha = novaLin;
        coluna = novaCol;

        // passar para o outro lado
        if (novaLin < 0) //linhas
            linha = NL + (getLinha() + novaLin);  // lin->linha atual | novaLin->valor random

        if (novaCol < 0) //colunas
            coluna = NC + (getColuna() + novaCol); // col->col atual | novaCol->valor random

        if (novaLin > NL) //linhas
            linha = (getLinha() - NL) + novaLin;

        if (novaCol > NC) //colunas
            coluna = (getColuna() - NC) + novaCol;

        setLinha(linha);
        setColuna(coluna);
    }
    void moveParaPos(int x, int y)  override {
        setLinha(x);
        setColuna(y);
    }

    bool estaVivo() override{
        if(getSaude() <= 0){
            return false;
        }

        return true;
    }

    int consome(int vNutritivo, int pToxicos) override{

        setSaude(getSaude() + vNutritivo);
        setSaude(getSaude() - pToxicos);

        if(getSaude() <= 0){
            return 0;
        }
        return 1;
    }

    int getP() const override{
        return Lobo::p;
    }

    bool isVivo() const override{
        return Lobo::vivo;
    }

    void setVivo(bool Vivo) override{
        Lobo::vivo = Vivo;
    }

    bool getProcriou() override {
        return Lobo::procriou;
    }

    void setProcriou(bool flag) override {
        Lobo::procriou = flag;
    }
};

#endif //SIMULADORRESERVANATURAL_LOBO_H
