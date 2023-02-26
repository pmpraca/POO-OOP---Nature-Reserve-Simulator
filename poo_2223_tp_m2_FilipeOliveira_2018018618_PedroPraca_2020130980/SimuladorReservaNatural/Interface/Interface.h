//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//

#ifndef TP_INTERFACE_H
#define TP_INTERFACE_H

#include <sstream>
#include <vector>
#include <string>
#include "../Terminal/Terminal.h"
#include "../Comandos/Comandos.h"
#include "../Reserva/Reserva.h"
#include "../Store/Store.h"

using namespace term;

class Interface {
    Reserva* reserva;
    int x, y; //Coordenadas do Canto Superior Esquerdo
    Terminal *t;
    vector<Store*> stores;

    vector<Comandos> comandos = { {"animal", "<especie> <linha> <coluna>" },  //0
                                 {"animal", " <especie> "},
                                 {"kill", " <linha> <coluna>"},
                                 {"killid", "<id>"},
                                 {"food", "<tipo> <linha> <coluna>"},
                                 {"food", "<tipo>"},
                                 {"feed", "<linha> <coluna>  <pontos nutritivos> <pontos de toxicidade>"},
                                 {"feedid", "<ID> <pontos nutritivos> <pontos de toxicidade>"},
                                 {"nofood", "<linha> <coluna>"},
                                 {"nofood", "<ID>"},
                                 {"empty", "<linha> <coluna>"}, //10
                                 {"see", "<linha> <coluna>"},
                                 {"info", "<ID>"},
                                 {"n", ""},
                                 {"n", "<N>"},
                                 {"n", "<N> <P>"},
                                 {"anim", ""},
                                 {"visanim", ""},
                                 {"store", "<nome>"},
                                 {"restore", "<nome>"},
                                 {"load", "<nome-do-ficheiro>"}, //20
                                 {"slide", "<direcao> <linhas/colunas>"},
                                 {"SCoelho", "<saudeInicial>" },
                                 {"SOvelha", " <saudeInicial> "},
                                 {"SLobo", " <saudeInicial> "},
                                 {"SCanguru", "<saudeInicial>"},
                                 {"VCoelho", "<duracaoDeVida>"},
                                 {"VOvelha", "<duracaoDeVida>"},
                                 {"VCanguru", "<duracaoDeVida>"},
                                 {"VRelva", "<validade>"},
                                 {"VLobo", "<instancias>"}, //30
                                 {"historico", "<id>"},
                                 {"SDragao", "<saudeInicial>"},
                                 {"VDragao", "<instancias>"},
                                 {"exit", ""} };

    /*vector<Comandos> constantes = { {"SCoelho", "<saudeInicial>" },
                                  {"SOvelha", " <saudeInicial> "},
                                  {"SLobo", " <saudeInicial> "},
                                  {"SCanguru", "<saudeInicial>"},
                                  {"VCoelho", "<duracaoDeVida>"},
                                  {"VOvelha", "<duracaoDeVida>"},
                                  {"VCanguru", "<duracaoDeVida>"},
                                  {"VRelva", "<validade>"},
                                  {"exit", ""} };*/

    // Função que verifica se string passa é um numero
    bool isNumber(const string& str);

public:

    string leDoTeclado(string str);
    string leFicheiro(string nameFile);
    string executaComando(vector<string> parametros, int opcao);

    // Mostra a reserva
    void iniciarReserva(const int& l, const int& c);
    string printAreaVisivel();

    // Terminal & Window
    void terminal();
    void redirecionaInfos(string txt);
    void redirecionaInfos2(string txt);
    void mostraEcra(int i);



    // Sai do programa
    void exitPrograma();


};


#endif //TP_INTERFACE_H
