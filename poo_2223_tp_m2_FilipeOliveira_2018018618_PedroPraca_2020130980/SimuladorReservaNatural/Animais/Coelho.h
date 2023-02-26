//
//Created by Pedro Praça & Filipe Oliveira on 12/12/2022.
//

#ifndef SIMULADORRESERVANATURAL_COELHO_H
#define SIMULADORRESERVANATURAL_COELHO_H

#include <sstream>
#include "Animal.h"

class Coelho : public Animal {

    int p;                      // p-> posicoes do animal (qts posicoes)
    int peso;
    int fome;
    bool vivo;
    static int saudePDefeito;
    static int dVidaPDefeito;

public:
    Coelho(int linha, int coluna, int ID) : Animal(linha, coluna, ID, saudePDefeito, dVidaPDefeito), p(2), fome(0), vivo(true) {
        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(1, 4);

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
        return Coelho::peso;
    }

    void setPeso(int Peso) override {
        Coelho::peso = Peso;
    }

    int getFome() const override {
        return Coelho::fome;
    }

    void setFome(int val) override {
        Coelho::fome = val;
    }

    void setFome() override {
        ++fome;
        if(fome > 10 && Coelho::fome <= 20){
            setSaude(getSaude()-1);
            p = 3;
        }else if(Coelho::fome > 20) {
            p = 4;
            setSaude(getSaude()-2);
        }
    }

    static void setSaudeDefeito(int saude) {
        saudePDefeito = saude;
    }

    static void setDVidaPDefeito(int dVida) {
        dVidaPDefeito = dVida;
    }

    int getDVidaPDefeito() override {
        return dVidaPDefeito;
    }

    string getEspecie() const override {
        return "Coelho";
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

        int pTmp;

        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(-p, p);

        pTmp = r(engine);

        return pTmp;
    }

    bool isVivo() const override{
        return Coelho::vivo;
    }

    void setVivo(bool Vivo) override{
        Coelho::vivo = Vivo;
    }

};



#endif //SIMULADORRESERVANATURAL_COELHO_H
