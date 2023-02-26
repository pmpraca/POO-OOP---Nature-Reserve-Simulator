//
// Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_OVELHA_H
#define SIMULADORRESERVANATURAL_OVELHA_H

#include <sstream>
#include "Animal.h"

using namespace std;

class Ovelha : public Animal {

    int p;
    int peso;
    int fome;
    bool vivo;
    static int saudePDefeito;
    static int dVidaPDefeito;

public:


    Ovelha(int linha, int coluna, int ID) : Animal(linha, coluna, ID, saudePDefeito, dVidaPDefeito), p(1), vivo(true), fome(0) {
        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(4, 8);

        this->peso = r(engine);
    }

    string info() const override {
        ostringstream oss;

        oss << " Especie            " << getEspecie() << endl;
        oss << Animal::info();
        oss << " Peso              " << peso << endl;
        oss << " Fome              " << fome << endl;

        return oss.str();
    }

    int getPeso() const override {
        return peso;
    }

    void setPeso(int Peso) override {
        Ovelha::peso = Peso;
    }

    int getFome() const override {
        return Ovelha::fome;
    }

    void setFome() override {
        ++fome;
        if(Ovelha::fome > 15 && Ovelha::fome <= 20){
            setSaude(getSaude()-1);
            Ovelha::p=2;
        }else if(Ovelha::fome > 20) {
            setSaude(getSaude()-2);
        }
    }

    void setFome(int val) override {
        Ovelha::fome = val;
    }

    string getEspecie() const override {
        return "Ovelha";
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
        setDuracaoVida(getDuracaoVida()-1);

        if(getSaude() <= 0 || getDuracaoVida() == 0){
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
        return Ovelha::p;
    }

    bool isVivo() const override{
        return Ovelha::vivo;
    }

    void setVivo(bool Vivo) override{
        Ovelha::vivo = Vivo;
    }

};

#endif //SIMULADORRESERVANATURAL_OVELHA_H
