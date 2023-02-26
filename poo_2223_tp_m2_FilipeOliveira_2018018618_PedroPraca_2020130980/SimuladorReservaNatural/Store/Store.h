//
// Created by Praça on 06/01/2023.
//

#ifndef SIMULADORRESERVANATURAL_STORE_H
#define SIMULADORRESERVANATURAL_STORE_H

#include "../Reserva/Reserva.h"

class Store{

    string nome;
    Reserva reserva;
    vector<Animal*> animais;
    vector<Alimento*> alimentos;
    string **arrayReserva;

public:

    Store(Reserva& m, string n="save") : nome(n), reserva(m) {
        animais = m.getAnimais();
        alimentos = m.getAlimentos();
        arrayReserva = m.getArrayReserva();

        string **arrayReservaAux;
        arrayReservaAux = new string*[m.getNL()];

        for (int i = 0; i < m.getNL(); i++) {
            arrayReservaAux[i] = new string[m.getNC()];
        }


        for (int i = 0; i < m.getNL(); i++) {
            for (int j = 0; j < m.getNC(); j++) {
                arrayReservaAux[i][j] = arrayReserva[i][j];
            }
        }
        m.setArrayReserva(arrayReservaAux);

        vector<Animal*> animaisAux;

        for(auto it = animais.begin(); it != animais.end(); it++){
            animaisAux.emplace_back(*it);

            for(auto itt = animaisAux.begin(); itt != animaisAux.end(); itt++) {
                if(itt+1 == animaisAux.end()){
                    (*itt)->setArray((*it)->getArray());
                }
            }

        }
        m.setAnimais(animaisAux);

        vector<Alimento*> alimentosAux;

        for(auto it = alimentos.begin(); it != alimentos.end(); it++){
            alimentosAux.emplace_back(*it);
        }
        m.setAlimentos(alimentosAux);

    }

    ~Store(){}

    string getNome() const { return nome; }

    Reserva getReserva() const { return reserva; }
};

#endif //SIMULADORRESERVANATURAL_STORE_H
