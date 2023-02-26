//
// Created by Praça on 06/12/2022.
//

#include "Iniciar.h"
#include <iostream>
#include <string>
#include "../Interface/Interface.h"

void Iniciar::iniciar() {
    string str;
    string lin, col;
    int linhas, colunas;
    Interface i;

    do {
        stringstream ss1;
        stringstream ss2;

        cout << "Digite um numero para as linhas e outro para a colunas entre 16 e 500" << endl;
        cout << "Se quiser terminar o programa digite: 666" << endl;

        cin >> lin >> col;

        ss1 << lin;
        ss1 >> linhas;

        if(linhas == 666)
            exit(0);

        ss2 << col;
        ss2 >> colunas;

        if(colunas == 666)
            exit(0);

    } while(!isNumber(lin) || !isNumber(col) || linhas < 16 || linhas > 500 || colunas < 16 || colunas > 500);


    system("cls"); // limpa consola
    i.iniciarReserva(linhas, colunas); //inicia a reserva
    i.leFicheiro("constantes.txt"); //le automaticamente o ficheiro de constantes no inicio do programa

    while(str!="sair"){
        i.terminal(); //inicia terminal
    }
}

bool Iniciar::isNumber(const string &str) {

    for (char const &ch : str) {
        if (isdigit(ch) == 0)
            return false;
    }
    return true;
}
