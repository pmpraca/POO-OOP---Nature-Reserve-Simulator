//
// Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_CANGURU_H
#define SIMULADORRESERVANATURAL_CANGURU_H

#include <sstream>
#include "Animal.h"

using namespace std;

class Canguru : public Animal {

    int p;
    int peso;
    bool vivo;
    static int saudePDefeito;
    static int dVidaPDefeito;
    int cont;
    int idMae;
    int idFilho;
    bool escondido;
    bool temMae;
    bool temFilho;

public:

    Canguru(int linha, int coluna, int ID) : Animal(linha, coluna, ID, saudePDefeito, dVidaPDefeito), peso(10), p(1), vivo(true), cont(5), escondido(false), temMae(false), temFilho(false) {}

    string info() const override {
        ostringstream oss;

        oss << " Especie            " << getEspecie() << endl;
        oss << Animal::info();
        oss << " Peso              " << peso << endl;

        return oss.str();
    }

    int getPeso() const override {
        return Canguru::peso;
    }

    void setPeso(int Peso) override {
        Canguru::peso = Peso;
    }

    string getEspecie() const override {
        return "Canguru";
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

        // caso passae para o outro lado da reserva
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

        if(getDuracaoVida() == 0){
            setSaude(0);
            return false;
        }

        return true;
    }

    bool isVivo() const override{
        return Canguru::vivo;
    }

    void setVivo(bool Vivo) override{
        Canguru::vivo = Vivo;
    }

    int getIdMae() const override{
        return Canguru::idMae;
    }

    void setIdMae(int IdMae) override{
        Canguru::idMae = IdMae;
    }

    int getCont() const override{
        return Canguru::cont;
    }

    void setCont() override{
        Canguru::cont--;
    }

    bool isEscondido() const override{
        return escondido;
    }

    void setEscondido(bool Escondido) override {
        Canguru::escondido = Escondido; //esta na bolsa na mae se estiver a true
    }

    int getP() const override{
        return Canguru::p;
    }

    bool isTemMae() const override{
        return Canguru::temMae;
    }

    void setTemMae(bool TemMae) override{
        Canguru::temMae = TemMae;
    }

    int getIdFilho() const override{
        return idFilho;
    }

    void setIdFilho(int IdFilho) override{
        Canguru::idFilho = IdFilho;
    }

    bool isTemFilho() const override{
        return temFilho;
    }

    void setTemFilho(bool TemFilho) override{
        Canguru::temFilho = TemFilho;
    }

};

#endif //SIMULADORRESERVANATURAL_CANGURU_H
