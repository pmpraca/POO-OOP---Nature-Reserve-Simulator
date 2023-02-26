//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//

#include "Comandos.h"

Comandos::Comandos(string Nome, string Args) : nome(Nome), args(Args) {}

string Comandos::getNome() const {
    return nome;
}
