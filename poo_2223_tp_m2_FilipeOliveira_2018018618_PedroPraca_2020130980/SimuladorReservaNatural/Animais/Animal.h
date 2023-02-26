//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//

#ifndef TP_ANIMAL_H
#define TP_ANIMAL_H

#include <string>
#include <random>
#include "../Historico/Historico.h"

using namespace std;

class Animal {

    int ID;
    int linha, coluna;
    int saude, duracaoVida;
    Historico * array;
    int size, tam;

public:

    Animal(int linha, int coluna, int ID, int saude);
    Animal(int linha, int coluna, int ID, int saude, int duracaoVida);

    virtual ~Animal();

    // Métodos - historico
    string mostraHistorico() const;
    void adicionaInfo(string comida, int vNutritivo, int pToxicidade);

    Historico *getArray() const;
    void setArray(Historico *array);

    // Getters & Setters - classe base
    int getId() const;
    int getLinha() const;
    int getColuna() const;
    void setLinha(int l);
    void setColuna(int c);
    int getSaude() const;
    void setSaude(int saude);
    int getDuracaoVida() const;
    void setDuracaoVida(int duracaoVida);

    // Métodos Virtuais
    virtual string info() const;
    virtual string infoExtra() const;
    virtual int getPeso() const { return 0; };
    virtual void setPeso(int peso) {};
    virtual int getFome() const { return 0; };
    virtual void setFome() {};
    virtual void setFome(int val) {};
    virtual string getEspecie() const = 0;

    // Métodos Interaçao Animal
    virtual void moveParaPos(int x, int y) {};
    virtual void movimento(int NL, int NC){};
    virtual bool estaVivo() { return 0;};
    virtual int consome(int vNutritivo, int pToxicos) {return 0;};
    virtual int getDVidaPDefeito(){return 0;};
    virtual bool getProcriou() {return 0;};
    virtual void setProcriou(bool flag) {};
    virtual int getP() const {return 0;};
    virtual int getIdMae() const {return 0;};
    virtual void setIdMae(int idMae){};
    virtual int getCont() const {return 0;};
    virtual void setCont() {};
    virtual bool isEscondido() const {return 0;};
    virtual void setEscondido(bool escondido) {};
    virtual bool isVivo() const {return 0;};
    virtual void setVivo(bool vivo) {};
    virtual bool isTemMae() const {return 0;};
    virtual void setTemMae(bool temMae) {};
    virtual int getIdFilho() const {return 0;};
    virtual void setIdFilho(int idFilho) {};
    virtual bool isTemFilho() const {return 0;};
    virtual void setTemFilho(bool temFilho) {};
    //virtual Animal duplica { return};

};


#endif //TP_ANIMAL_H
