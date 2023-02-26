//
//  Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//

#include <sstream>
#include "Animal.h"

using namespace std;

Animal::Animal(int lin, int col, int id, int saude) :
        linha(lin),
        coluna(col),
        ID(id),
        saude(saude),
        size(0)
        {
            array = new Historico[10];
            size = 0;
            tam = 1;
        }

Animal::Animal(int lin, int col, int id, int saude, int duracaoVida) :
        linha(lin),
        coluna(col),
        ID(id),
        saude(saude),
        duracaoVida(duracaoVida),
        size(0)
        {
            array = new Historico[10];
            size = 0;
            tam = 1;
        }


Animal::~Animal() {
    delete [] array;
}

int Animal::getId() const {
    return ID;
}

int Animal::getLinha() const {
    return linha;
}

int Animal::getColuna() const {
    return coluna;
}

void Animal::setLinha(int l) {
    linha = l;
}

void Animal::setColuna(int c) {
    coluna = c;
}

string Animal::info() const {
    ostringstream oss;

    oss << " ID:               " << ID << endl;
    oss << " x (linha):        " << linha << endl;
    oss << " y (coluna):       " << coluna << endl;
    oss << " Saude             " << saude << endl;
    oss << " Duracao de Vida   " << duracaoVida << endl;

    return oss.str();
}

string Animal::infoExtra() const {
    ostringstream oss;

    oss << " ID:               " << ID << endl;
    oss << " x (linha):        " << linha << endl;
    oss << " y (coluna):       " << coluna << endl;
    oss << " Saude             " << saude << endl;

    return oss.str();
}

int Animal::getSaude() const {
    return saude;
}

void Animal::setSaude(int Saude) {
    Animal::saude = Saude;
}

int Animal::getDuracaoVida() const {
    return duracaoVida;
}

void Animal::setDuracaoVida(int DuracaoVida) {
    Animal::duracaoVida = DuracaoVida;
}

void Animal::adicionaInfo(string comida, int vNutritivo, int pToxicidade) {
    Historico tmp;

    if (size == tam-1){
        Historico *aux = new(nothrow) Historico [tam + 2]; //cria espaço para poder por nova informação

        if(aux == nullptr) //se estiver a null faz exit
            exit(0);

        for(int i=0; i<tam; i++) { //copia toda a informaçao que tinha para o aux
            aux[i] = array[i];
        }

        delete []array;

        array = aux;
        tam += 1;       //incrementa o tamanho
    }

    // insere as novas informações
    tmp.setComida(comida);
    tmp.setVNutritivo(vNutritivo);
    tmp.setPToxicidade(pToxicidade);

    array[size] = tmp; //coloca o objeto na posiçao size do array

    size++; // aumenta o tamanho
}

string Animal::mostraHistorico() const{
    ostringstream oss;

    for(int i=0; i<tam-1; i++){
        oss << array[i].infoHistorico();
    }

    return oss.str();
}

Historico *Animal::getArray() const {
    return array;       // devolve array atual
}

void Animal::setArray(Historico *array1) {

   /* Historico *aux = new Historico [sizeof(array1) + 2];

    for(int i=0; i<sizeof(array1); i++) {
        array[i] = array1[i];
    }

    array = aux;*/

    Historico *aux = new Historico [tam];
    for(int i=0; i<size; i++) {

        aux[i] = array1[i];
    }
    delete []array;

    array=aux;
}
