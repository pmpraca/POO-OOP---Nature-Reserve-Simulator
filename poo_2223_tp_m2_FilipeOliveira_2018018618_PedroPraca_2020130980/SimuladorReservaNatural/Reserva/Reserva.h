//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//
#ifndef TP_RESERVA_H
#define TP_RESERVA_H

#include "../Animais/Animal.h"
#include "../Alimentos/Alimento.h"
#include "../curses.h"

using namespace std;

class Reserva{

    int NL, NC;                     //nr linha | nr colunas
    int IDglobal;
    int contAnimal;
    int contAlimento;
    int contInstancia;
    vector<Animal*> animais;
    vector<Alimento*> alimentos;
    string **arrayReserva;
    int xAreaVisivel,yAreaVisivel, hAreaVisivel, wAreaVisivel;

    bool alimentoExiste(int lin, int col);

public:
    Reserva();

    void setNL(int nl);
    int &getNL ();
    void setNC(int nc);
    int &getNC ();

    //Métodos dos Comandos
    string listaIdAnimais() const;

    string criaAnimal(const string& especie);
    string criaAnimal(const string& especie, int lin, int col);

    string criaAlimento(const string& tipo, int lin, int col);
    string criaAlimento(const string& tipo);

    string matarAnimal(int lin, int col);
    string matarAnimal(const int &id);

    string alimentaAnimal(int lin, int col, int pNutritivos, int pToxicidade);
    string alimentaAnimalID(int id, int pNutritivos, int pToxicidade);

    string removeAlimento(int lin, int col);
    string removeAlimento2(const int &id);
    string removeAlimento(const int &id);

    string limpaCelula(int lin, int col);

    string obtemInfo(const int &id) const;
    string infoSee(int lin, int col);
    string obtemAnimalVisivel();

    string setConstantes(string opt, int sI);

    //criar reserva
    void criaReserva();
    string mostraReservaVisivel() const;

    //Getters e setters contadores
    int getContAnimal();
    int getContAlimento();
    int getContInstancia();
    int getIDglobal();

    //Setters e Getters para a AreaVisivel
    void setXAreaVisivel(int xAreaVisivel);
    void setYAreaVisivel(int yAreaVisivel);
    int getHAreaVisivel() const;
    void setHAreaVisivel(int hAreaVisivel);
    int getWAreaVisivel() const;
    void setWAreaVisivel(int wAreaVisivel);

    //Historico
    string obtemHistorico(int id);

    //Jogo em si (movimentos, percecoes, etc...)
    string avanca();
    void procriar(const string &especie, int lin, int col);
    void procriaOvelha(const string &especie, int lin, int col, int saude);
    void procriarRelva(const string& especie, int lin, int col, int id);
    void criaCorpo(const string &especie, int lin, int col, int vNutritivo, int pToxicidade);

    //Store e Restore
    const vector<Animal *> &getAnimais() const;
    void setAnimais(const vector<Animal *> &animais);
    const vector<Alimento *> &getAlimentos() const;
    void setAlimentos(const vector<Alimento *> &alimentos);
    string **getArrayReserva() const;
    void setArrayReserva(string **arrayReserva);
    Reserva & operator++();

    //Randoms
    int randomLinha();
    int randomColuna();
};

#endif //TP_RESERVA_H
