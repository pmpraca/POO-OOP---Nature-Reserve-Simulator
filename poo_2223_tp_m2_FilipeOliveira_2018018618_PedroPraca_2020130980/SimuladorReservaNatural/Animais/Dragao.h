//
// Created by Praça on 02/01/2023.
//

#ifndef SIMULADORRESERVANATURAL_DRAGAO_H
#define SIMULADORRESERVANATURAL_DRAGAO_H

#include <sstream>
#include "Animal.h"

using namespace std;

class Dragao : public Animal {

    int p;
    int peso;
    int fome;
    bool procriou;
    bool vivo;
    bool temMae; //bebe dragao
    static int dVidaPDefeito;
    static int saudePDefeito;

public:

    Dragao(int linha, int coluna, int ID) : Animal(linha, coluna, ID, saudePDefeito), peso(50), p(2), vivo(true), temMae(false), procriou(false), fome(0) {}

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
        return Dragao::peso;
    }

    void setPeso(int Peso) override {
        Dragao::peso = Peso;
    }

    int getFome() const override {
        return Dragao::fome;
    }

    void setFome() override {
        Dragao::fome+= 1;
        if(Dragao::fome > 20 && Dragao::fome <= 35){
            setSaude(getSaude()-1);
            Dragao::p=3;
        }else if(Dragao::fome > 35) {
            setSaude(getSaude()-2);
            Dragao::p=6;
        }
    }

    void setFome(int val) override {
        Dragao::fome = val;
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
        return "Dragao";
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
        return Dragao::p;
    }

    bool isVivo() const override{
        return Dragao::vivo;
    }

    void setVivo(bool Vivo) override{
        Dragao::vivo = Vivo;
    }

    bool isTemMae() const override{
        return Dragao::temMae;
    }

    void setTemMae(bool TemMae) override{
        Dragao::temMae = TemMae;
    }

    bool getProcriou() override {
        return Dragao::procriou;
    }

    void setProcriou(bool flag) override {
        Dragao::procriou = flag;
    }

};

#endif //SIMULADORRESERVANATURAL_DRAGAO_H
