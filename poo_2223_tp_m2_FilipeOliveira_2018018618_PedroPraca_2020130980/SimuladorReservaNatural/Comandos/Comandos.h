//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//

#ifndef TP_COMANDOS_H
#define TP_COMANDOS_H

using namespace std;

#include <vector>
#include <string>

class Comandos {
    string nome, args;

public:
    //CONSTRUTOR
    Comandos(string n, string a = "");

    //GETTERS
    string getNome() const; //nome do comando
};

#endif //TP_COMANDOS_H
