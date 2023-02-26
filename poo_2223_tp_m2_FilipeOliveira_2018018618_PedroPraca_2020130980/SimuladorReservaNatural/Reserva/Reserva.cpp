//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//


#include <iostream>
#include <random>
#include "Reserva.h"
#include "../Animais/Coelho.h"
#include "../Animais/Ovelha.h"
#include "../Animais/Lobo.h"
#include "../Animais/Canguru.h"
#include "../Alimentos/Relva.h"
#include "../Alimentos/Cenoura.h"
#include "../Alimentos/Bife.h"
#include "../Alimentos/Corpo.h"
#include "../Alimentos/Batata.h"
#include "../Animais/Dragao.h"
#include "../Alimentos/OvoDragao.h"


// Contadores
//int Reserva::contInstancia = 0;
//int Reserva::contAnimal = 0;
//int Reserva::contAlimento = 0;

// Constantes do Animais/Alimento
int Coelho::saudePDefeito = 20;
int Coelho::dVidaPDefeito = 30;
int Ovelha::saudePDefeito = 30;
int Ovelha::dVidaPDefeito = 35;
int Lobo::saudePDefeito = 25;
int Lobo::dVidaPDefeito = 40;
int Canguru::saudePDefeito = 20;
int Canguru::dVidaPDefeito = 70;
int Relva::validadePDefeito = 20;
int Dragao::saudePDefeito = 100;
int Dragao::dVidaPDefeito = 100;

Reserva::Reserva() : IDglobal(1), contAlimento(0), contAnimal(0), contInstancia(0) {}

void Reserva::setNL(int nl) {
    NL = nl;
}

int &Reserva::getNL() {
    return NL;
}

void Reserva::setNC(int nc) {
    NC = nc;
}

int &Reserva::getNC() {
    return NC;
}

string Reserva::listaIdAnimais() const { // anim

    ostringstream oss;

    for(auto it = animais.begin(); it != animais.end(); it++){
            oss << "ID: " << (*it)->getId() << endl;
            oss << "Especie: " << (*it)->getEspecie() << endl;
            oss << "Saude: " << (*it)->getSaude() << endl;
            oss << "Peso: " << (*it)->getPeso() << endl << endl;
        }

    if(oss.tellp() == 0) //if (oss.str().empty()) // tellp diz o indice do array (buffer interno)
        oss << "Nao existem animais";

    return oss.str();
}

string Reserva::obtemInfo(const int& id) const{

    for(auto it = animais.begin(); it != animais.end(); it++){
        if(id == (*it)->getId()){
            return (*it)->info();
        }
    }

    for(auto it = alimentos.begin(); it != alimentos.end(); it++){
        if(id == (*it)->getId() ){
           return (*it)->info();
        }

    }

    return "Nao existem nenhum animal ou alimento com esse ID";
}

string Reserva::criaAnimal(const string& especie, int lin, int col) {

    if (especie == "c") {

        Animal* ponteiroParaAnimal = new Coelho(lin, col, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[lin][col] = "C";
        ++IDglobal;
        ++contAnimal;

        } else if (especie == "o") {
            Animal* ponteiroParaAnimal = new Ovelha(lin, col, getIDglobal());
            animais.emplace_back(ponteiroParaAnimal);
            arrayReserva[lin][col] = "O";
            ++IDglobal;
            ++contAnimal;

        } else if (especie == "l") {
            Animal* ponteiroParaAnimal = new Lobo(lin, col, getIDglobal());
            animais.emplace_back(ponteiroParaAnimal);
            arrayReserva[lin][col] = "L";
            ++IDglobal;
            ++contAnimal;

        } else if (especie == "g") {
            Animal* ponteiroParaAnimal = new Canguru(lin, col, getIDglobal());
            animais.emplace_back(ponteiroParaAnimal);
            arrayReserva[lin][col] = "G";
            ++IDglobal;
            ++contAnimal;
        } else if (especie == "m") {
            Animal* ponteiroParaAnimal = new Dragao(lin, col, getIDglobal());
            animais.emplace_back(ponteiroParaAnimal);
            arrayReserva[lin][col] = "M";
            ++IDglobal;
            ++contAnimal;
        }

    return "Animal Criado! ";
}

string Reserva::criaAnimal(const string &especie) {

    int lin = randomLinha();
    int col = randomColuna();

    if (especie == "c") {

        Animal* ponteiroParaAnimal = new Coelho(lin, col, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[lin][col] = "C";
        ++IDglobal;
        ++contAnimal;

    } else if (especie == "o") {
        Animal* ponteiroParaAnimal = new Ovelha(lin, col, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[lin][col] = "O";
        ++IDglobal;
        ++contAnimal;

    } else if (especie == "l") {
        Animal* ponteiroParaAnimal = new Lobo(lin, col, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[lin][col] = "L";
        ++IDglobal;
        ++contAnimal;

    } else if (especie == "g") {
        Animal* ponteiroParaAnimal = new Canguru(lin, col, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[lin][col] = "G";
        ++IDglobal;
        ++contAnimal;
    } else if (especie == "m") {
        Animal* ponteiroParaAnimal = new Dragao(lin, col, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[lin][col] = "M";
        ++IDglobal;
        ++contAnimal;
    }

    return "Animal Criado! ";
}

string Reserva::criaAlimento(const string &tipo, int lin, int col) {

    if(alimentoExiste(lin,col))
        return "Ja existe um Alimento nessa posicao! ";

    if (tipo == "r") {
        Alimento* ponteiroParaAlimento = new Relva(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    } else if (tipo == "t") {
        Alimento* ponteiroParaAlimento = new Cenoura(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    } else if (tipo == "p") {
        Alimento* ponteiroParaAlimento = new Corpo(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    } else if (tipo == "b") {
        Alimento* ponteiroParaAlimento = new Bife(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;
    } else if (tipo == "a") {
        Alimento* ponteiroParaAlimento = new Batata(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;
    } else if (tipo == "e") {
        Alimento* ponteiroParaAlimento = new OvoDragao(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    }

    return "Alimento Criado! ";
}

string Reserva::criaAlimento(const string &tipo) {

    int lin = randomLinha();
    int col = randomColuna();

    if(alimentoExiste(lin,col))
        return "Ja existe um Alimento nessa posicao! ";

    if (tipo == "r") {
        Alimento* ponteiroParaAlimento = new Relva(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    } else if (tipo == "t") {
        Alimento* ponteiroParaAlimento = new Cenoura(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    } else if (tipo == "p") {
        Alimento* ponteiroParaAlimento = new Corpo(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    } else if (tipo == "b") {
        Alimento* ponteiroParaAlimento = new Bife(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;
    } else if (tipo == "a") {
        Alimento* ponteiroParaAlimento = new Batata(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;
    } else if (tipo == "e") {
        Alimento* ponteiroParaAlimento = new OvoDragao(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = tipo;
        ++IDglobal;
        ++contAlimento;

    }

    return "Alimento Criado! ";
}

string Reserva::matarAnimal(int lin, int col) { // matar através das coordenadas

    ostringstream oss;

    for(auto it = animais.begin(); it != animais.end(); ){
        if(lin == (*it)->getLinha() && col == (*it)->getColuna() ) {
            arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            delete *it;
            it = animais.erase(it);
            --contAnimal;
            oss << "Animal na linha " << lin << " e na coluna " << col << " foi morto! " << endl;
        }
        else
            it++;
    }

    if(oss.tellp() == 0)
        oss << "Nao existe nenhum animal na linha " << lin << " e na coluna " << col << endl;

    return oss.str();
}

string Reserva::matarAnimal(const int &id) { // matar através do ID

    ostringstream oss;
    for(auto it = animais.begin(); it != animais.end(); ){
        if(id == (*it)->getId()){
            arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            delete *it;
            it = animais.erase(it);
            --contAnimal;
            oss << "Animal com o id " << id << " foi morto! " << endl;
        }
        else
            it++;
    }
    
    if(oss.tellp() == 0)
        oss << "Nao existe nenhum animal com o id " << id << endl;

    return oss.str();
}

string Reserva::alimentaAnimal(int lin, int col, int pNutritivos, int pToxicidade) {

    ostringstream oss;

    for(auto it = animais.begin(); it != animais.end(); it++){
        if(lin == (*it)->getLinha() && col == (*it)->getColuna()){
            if((*it)->getEspecie() == "Canguru") {
                oss << "Este animal nao pode ser alimentado!" << endl;
            } else {
                (*it)->setSaude((*it)->getSaude() + pNutritivos);
                (*it)->setSaude((*it)->getSaude() - pToxicidade);

                oss << "Animal na linha " << lin << " e na coluna " << col << " foi alimentado! " << endl;
            }

        }
    }

    if(oss.tellp() == 0)
        oss << "Nao existe nenhum animal nessa posicao! " << endl;

    return oss.str();
}

string Reserva::alimentaAnimalID(int id, int pNutritivos, int pToxicidade) {
    ostringstream oss;

    for(auto it = animais.begin(); it != animais.end(); it++){
        if( id == (*it)->getId()){
            if((*it)->getEspecie() == "Canguru") {
                oss << "Este animal nao pode ser alimentado!" << endl;
            } else {
                (*it)->setSaude((*it)->getSaude() - pToxicidade);
                (*it)->setSaude((*it)->getSaude() + pNutritivos);
                oss << "Animal com o id " << id << " foi alimentado! ";
            }
        }
    }

    if(oss.tellp() == 0)
        oss << "Nao existe nenhum animal com esse ID! " << endl;

    return oss.str();
}

string Reserva::removeAlimento(int lin, int col) {
    ostringstream oss;

    for(auto it = alimentos.begin(); it != alimentos.end(); ) {
        if (lin == (*it)->getLinha() && col == (*it)->getColuna()) {
            arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            delete *it;
            alimentos.erase(it);
            --contAlimento;
            oss << "Alimento Removido " << endl << "da linha " << lin << " e coluna " << col;
        } else {
            it++;
        }
    }

    if(oss.tellp() == 0)
        oss << "Nao existe nenhum alimento na linha " << lin << " e na coluna " << col << endl;

    return oss.str();
}

string Reserva::removeAlimento(const int &id) {
    ostringstream oss;

    for(auto it = alimentos.begin(); it != alimentos.end(); ) {
        if (id == (*it)->getId()) {
            arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            delete *it;
            alimentos.erase(it);
            --contAlimento;
            oss << "Alimento com o id " << id << " foi removido!";
        } else {
            it++;
        }
    }

    if(oss.tellp() == 0)
        oss << "Nao existe nenhum alimento com o id " << id << endl;

    return oss.str();
}

string Reserva::removeAlimento2(const int &id) { //serva apenas para nao tirar o limpar o caracter do ecra
    ostringstream oss;

    for(auto it = alimentos.begin(); it != alimentos.end(); ) {
        if (id == (*it)->getId()) {
            delete *it;
            alimentos.erase(it);
            --contAlimento;
            oss << "Alimento com o id " << id << " foi removido!";
        } else {
            it++;
        }
    }

    if(oss.tellp() == 0)
        oss << "Nao existe nenhum alimento com o id " << id << endl;

    return oss.str();
}

string Reserva::limpaCelula(int lin, int col) {

    ostringstream oss;

    for(auto it = animais.begin(); it != animais.end(); ){
        if(lin == (*it)->getLinha() && col == (*it)->getColuna() ) {
            arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            delete *it;
            it = animais.erase(it);
            --contAnimal;
            oss << "Animal Removido na linha " << lin << " e na coluna " << col << endl;
        }
        else
            it++;
    }

    for(auto it = alimentos.begin(); it != alimentos.end(); ) {
        if (lin == (*it)->getLinha() && col == (*it)->getColuna()) {
            arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            delete *it;
            alimentos.erase(it);
            --contAlimento;
            oss << "Alimento Removido na linha " << lin << " e na coluna " << col;
        } else {
            it++;
        }
    }

    if(oss.tellp() == 0)
        oss << "Nao existe nenhum alimento nem animal nessa posicao! " << endl;

    return oss.str();
}

string Reserva::infoSee(int lin, int col) { // comando "see"
    bool existeAnimal = false;
    bool existeAlimento = false;
    ostringstream oss;

    oss << "\nNas posicoes linha: "<< lin << " e coluna: "<< col << "\nExistem: "<< endl;

    for(auto it = animais.begin(); it != animais.end(); it++){
        if(lin == (*it)->getLinha() && col == (*it)->getColuna()){
            oss << "\nOs animais/animal: \n" << (*it)->info();
            existeAnimal = true;
        }
    }

    for(auto it = alimentos.begin(); it != alimentos.end(); it++){
        if(lin == (*it)->getLinha() && col == (*it)->getColuna()){
            existeAlimento = true;
            oss << "\nOs alimentos/alimento: \n" << (*it)->info();
        }
    }

    if (!existeAlimento && !existeAnimal) {
        oss.str("");
        oss << "\nA posicao com linha: "<< lin << " e com coluna: " << col <<" encontra-se vazia! " << endl;
    }

    return oss.str();
}

string Reserva::obtemAnimalVisivel() {
    bool existe = false;
    ostringstream oss;

    for(auto it = animais.begin(); it != animais.end(); it++){
        if((*it)->getLinha() >= xAreaVisivel && (*it)->getLinha() <= (xAreaVisivel-1 + wAreaVisivel)
        && (*it)->getColuna() >= yAreaVisivel && (*it)->getColuna() <= (yAreaVisivel-1 + hAreaVisivel)) {
            oss << "ID: "<< (*it)->getId() << endl;
            oss << "Especie: " << (*it)->getEspecie() << endl;
            oss << "Saude: " << (*it)->getSaude() << endl;

            existe = true;
        }
    }

    if(existe)
        return oss.str();

    oss << "Nao existem animais na area visivel da reserva!";
    return oss.str();
}

string Reserva::obtemHistorico(int id) {

    for(auto it = animais.begin(); it != animais.end(); it++){
        if((*it)->getId() == id) {
            return (*it)->mostraHistorico();
        }
    }

    return "Este animal ainda nao tem historico de alimentos";
}

string Reserva::setConstantes(string opt, int sI) {

    if(opt == "SCoelho"){
        Coelho::setSaudeDefeito(sI);
    } else if (opt == "SCanguru") {
        Canguru::setSaudeDefeito(sI);
    } else if (opt == "SOvelha") {
        Ovelha::setSaudeDefeito(sI);
    } else if (opt == "SLobo") {
        Lobo::setSaudeDefeito(sI);
    } else if (opt == "VCoelho") {
        Coelho::setDVidaPDefeito(sI);
    } else if (opt == "VOvelha") {
        Ovelha::setDVidaPDefeito(sI);
    } else if (opt == "VRelva") {
        Relva::setValidadePDefeito(sI);
    } else if (opt == "VCanguru") {
        Canguru::setDVidaPDefeito(sI);
    } else if (opt == "VLobo") {
        Lobo::setDVidaPDefeito(sI);
    }  else if (opt == "SDragao") {
        Dragao::setSaudeDefeito(sI);
    } else if (opt == "VDragao") {
        Dragao::setDVidaPDefeito(sI);
    }

    return "Sucesso! ";
}

bool Reserva::alimentoExiste(int lin, int col) { // verifica se existe mais que um alimento na mesma celula
    for(auto it = alimentos.begin(); it != alimentos.end(); it++){
        if(lin == (*it)->getLinha() && col == (*it)->getColuna()){
            return true;
        }
    }
    return false;
}

//Store e Restore
const vector<Animal *> &Reserva::getAnimais() const {
    return animais;
}

void Reserva::setAnimais(const vector<Animal *> &Animais) {
    Reserva::animais = Animais;
}

const vector<Alimento *> &Reserva::getAlimentos() const {
    return alimentos;
}

void Reserva::setAlimentos(const vector<Alimento *> &Alimentos) {
    Reserva::alimentos = Alimentos;
}

string **Reserva::getArrayReserva() const {
    return arrayReserva;
}

void Reserva::setArrayReserva(string **ArrayReserva) {
    Reserva::arrayReserva = ArrayReserva;
}

int Reserva::getIDglobal() {
    return IDglobal;
}

int Reserva::getContAnimal() {
    return contAnimal;
}

int Reserva::getContAlimento() {
    return contAlimento;
}

int Reserva::getContInstancia() {
    return contInstancia;
}

int Reserva::randomLinha() {

    random_device device;
    default_random_engine engine(device());
    uniform_int_distribution<int> r(0, getNL());

    int nrRand = r(engine);
    return nrRand;
}

int Reserva::randomColuna() {

    random_device device;
    default_random_engine engine(device());
    uniform_int_distribution<int> r(0, getNC());

    int nrRand = r(engine);
    return nrRand;
}

void Reserva::criaReserva() {

    arrayReserva = new string*[NL];

    for (int i = 0; i < NL; i++) {
        arrayReserva[i] = new string[NC];
    }

    for (int i = 0; i < NL; i++) {
        for (int j = 0; j < NC; j++) {
            arrayReserva[i][j] = " ";

        }
    }
}

string Reserva::mostraReservaVisivel() const {
    ostringstream oss;

    for (int i = yAreaVisivel; i < yAreaVisivel+hAreaVisivel; i++) {
        for (int j = xAreaVisivel; j < xAreaVisivel+wAreaVisivel; j++) {
            oss << arrayReserva[i][j] ;
        }
        oss << endl ;
    }

    return oss.str();
}

Reserva &Reserva::operator++() {
    IDglobal++;

    return *this;
}


void Reserva::setXAreaVisivel(int xAV) {
    Reserva::xAreaVisivel = xAV;
}

void Reserva::setYAreaVisivel(int yAV) {
    Reserva::yAreaVisivel = yAV;
}

int Reserva::getHAreaVisivel() const {
    return hAreaVisivel;
}

void Reserva::setHAreaVisivel(int hAV) {
    Reserva::hAreaVisivel = hAV;
}

int Reserva::getWAreaVisivel() const {
    return wAreaVisivel;
}

void Reserva::setWAreaVisivel(int wAV) {
    Reserva::wAreaVisivel = wAV;
}

string Reserva::avanca() {

    int m = 0;
    int animalAMatar = 0;
    int aPerseguir;
    int maisPesado = 0;
    int canguruBebeAMatar = 0;
    int maior = 0;
    ++contInstancia;

    ostringstream oss;

    vector<int> aEliminar;

    vector<vector<string>> aProcriar;
    vector<string> dados;

    vector<vector<string>> aProcriarOvelha;
    vector<string> dadosOvelha;

    vector<vector<string>> aProcriarRelva;
    vector<string> dadosRelva;

    vector<vector<string>> criaCorpos;
    vector<string> dadosCorpos;
    vector<string> dadosCorpoBebeCanguru;



    //FOR dos alimentos
    // - RELVA -

    for (auto it = alimentos.begin(); it != alimentos.end(); it++) {

        if ((*it)->getTipo() == "Relva") {

            (*it)->setValidade((*it)->getValidade() - 1);

            if((*it)->getValidade() == 0) {
                (*it)->setExiste(false);
                aEliminar.emplace_back((*it)->getId());
                arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            }
            
           //se a posicao em que a relva fica não estiver ocupada e tiver passado 75% da sua duração faz spawn de uma relva 
           if(!(*it)->isProcriou() && (100 - (((*it)->getValidade() * 100) / (*it)->getValidadePDefeito())) >= 75 ) {
               dadosRelva = {"r", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string((*it)->getId())};
               aProcriarRelva.emplace_back(dadosRelva);
           }

        }

        // - CENOURA -
        if ((*it)->getTipo() == "Cenoura") {
            (*it)->setCont(); // decrementa o contador

            if ((*it)->getCont() == 0 && (*it)->getMax() < 3){
                (*it)->setToxicidade((*it)->getToxicidade() + 1);
                (*it)->setMax((*it)->getMax()+1);
                (*it)->setCont(10);
            }

        }

        // - CORPO -
        if ((*it)->getTipo() == "Corpo") {

            (*it)->setCont(); // aumenta contador

            if ((2 * (*it)->getVNutritivoInicial()) <= (*it)->getCont()) {
                (*it)->setValorNutritivo((*it)->getValorNutritivo() - 1);
            } else {
                (*it)->setValorNutritivo((*it)->getValorNutritivo() - 1);
                (*it)->setToxicidade((*it)->getToxicidade() + 1);
            }

        }

        // - BIFE -
        if ((*it)->getTipo() == "Bife") {
            (*it)->setCont();

            if((*it)->getCont() == 30) {
                (*it)->setExiste(false);
                aEliminar.emplace_back((*it)->getId());
                arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
            }

            if ((*it)->getValorNutritivo() > 0) {
                (*it)->setValorNutritivo((*it)->getValorNutritivo() - 1);
            }
        }

        if ((*it)->getTipo() == "Batata") {

            arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "a";

            if(!(*it)->isBatataFrita()) {
                (*it)->setCont();

                if ((*it)->getCont() == 30) {
                    (*it)->setExiste(false);
                    aEliminar.emplace_back((*it)->getId());
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                }

                if ((*it)->getValorNutritivo() > 0) {
                    (*it)->setValorNutritivo((*it)->getValorNutritivo() - 1);
                }

                if ((*it)->getValorNutritivo() == 0 && (*it)->getToxicidade() <= 10) {
                    (*it)->setToxicidade((*it)->getToxicidade() + 1);
                }

            } else {
                (*it)->setCont();

                if ((*it)->getCont() == 30) {
                    (*it)->setExiste(false);
                    aEliminar.emplace_back((*it)->getId());
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                }

                if ((*it)->getValorNutritivo() > 0) {
                    (*it)->setValorNutritivo((*it)->getValorNutritivo() - 3);
                }

                if ((*it)->getValorNutritivo() <= 0 && (*it)->getToxicidade() <= 20) {
                    (*it)->setToxicidade((*it)->getToxicidade() + 2);
                }
            }


        }

        if ((*it)->getTipo() == "OvoDragao") {

            (*it)->setCont();

            if((*it)->getCont() == 20) {
                (*it)->setExiste(false);
                aEliminar.emplace_back((*it)->getId());
                arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                //nasce dragao
                dadosRelva = {"m", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(20)};
                aProcriarRelva.emplace_back(dadosRelva);
            }

            if ((*it)->getValorNutritivo() > 0) {
                (*it)->setValorNutritivo((*it)->getValorNutritivo() - 1);
            }

            if((*it)->getCont() > 15 && (*it)->getCont() < 20 ) {
                (*it)->setToxicidade((*it)->getToxicidade() + 1);
                (*it)->setValorNutritivo((*it)->getValorNutritivo() - 1);
            }


        }
    }

    for (auto it = animais.begin(); it != animais.end(); it++) { // percorre animais

        // - COELHO -
        if ((*it)->getEspecie() == "Coelho") {
            (*it)->setFome();
            if (!(*it)->estaVivo()) {           // verifica se animal está morto
                aEliminar.emplace_back((*it)->getId());
                (*it)->setVivo(false);
            } else {

                // Sempre que passar 8 instantes do coelho, ele procria
                if (((*it)->getDVidaPDefeito() - (*it)->getDuracaoVida()) % 8 == 0) {

                    random_device device;
                    default_random_engine engine(device());
                    uniform_int_distribution<int> r(0, 1);

                    if (r(engine) == 1) {
                        dados = {"C", to_string((*it)->getLinha()), to_string((*it)->getColuna())};
                        aProcriar.emplace_back(dados);
                    }
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (alimento->getCheiro() == "verdura" || alimento->getCheiro() == "erva,verdura") && alimento->isExiste()) {
                        if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0)
                            aEliminar.emplace_back((*it)->getId());
                        (*it)->setFome((*it)->getFome() + 2);
                        (*it)->adicionaInfo(alimento->getTipo(),alimento->getValorNutritivo(),alimento->getToxicidade());
                        aEliminar.emplace_back(alimento->getId());
                        alimento->setExiste(false);
                    }
                }

                // foge dos animais com > 10 peso
                if (m == 0) {
                    for (int i = (*it)->getLinha() - 4; i < (*it)->getLinha() + 4; i++) {
                        for (int j = (*it)->getColuna() - 4; j < (*it)->getColuna() + 4; j++) {
                            for (auto &animai: animais) {
                                if (animai->getLinha() == i && animai->getColuna() == j &&
                                    (*it)->getId() != animai->getId() && animai->getPeso() > 10 && animai->isVivo()) {

                                    //Calcula numero de passos a andar consoante a fome
                                    int nMov;
                                    nMov = (*it)->getP();

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                                    int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                                    //Vê linha
                                    if ((*it)->getLinha() != i) {
                                        nL = (*it)->getLinha() + ((*it)->getLinha() > i ? nMov : -nMov);
                                    }
                                    //Vê coluna
                                    if ((*it)->getColuna() != j) {
                                        // Vê se a distancia entre colunas é superior a 1
                                        nC = (*it)->getColuna() + ((*it)->getColuna() > j ? nMov : -nMov);
                                    }

                                    (*it)->moveParaPos(nL, nC);

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "C";
                                    m = 1;
                                    break;
                                }
                            }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                }

                // encontra cheiro e vai para a posicao
                if (m == 0) {
                    for (int i = (*it)->getLinha() - 4; i < (*it)->getLinha() + 4; i++) {
                        for (int j = (*it)->getColuna() - 4; j < (*it)->getColuna() + 4; j++) {
                            for (auto &alimento: alimentos) {
                                if (alimento->getLinha() == i && alimento->getColuna() == j &&
                                        (alimento->getCheiro() == "erva,verdura" || alimento->getCheiro() == "verdura") && alimento->isExiste()) {

                                    //Calcula numero de passos a andar consoante a fome
                                    int nMov;
                                    nMov = (*it)->getP();

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                                    int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                                    //Vê linha
                                    // Vê se a distancia entre linhas é superior a 1
                                    if (abs((*it)->getLinha() - i) >
                                        1) //se for, desloca-se nMov linhas em direçao ao animal
                                        nL = (*it)->getLinha() + ((*it)->getLinha() > i ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nL = i;

                                    //Vê coluna

                                    // Vê se a distancia entre colunas é superior a 1
                                    if (abs((*it)->getColuna() - j) >
                                        1) //se for, desloca-se nMov linhas em direçao ao animal
                                        nC = (*it)->getColuna() + ((*it)->getColuna() > j ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nC = j;
                                    (*it)->moveParaPos(nL, nC);

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "C";

                                    m = 1;
                                    break;
                                }
                            }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (alimento->getCheiro() == "verdura" || alimento->getCheiro() == "erva,verdura") && alimento->isExiste()) {
                        if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0)
                            aEliminar.emplace_back((*it)->getId());
                        (*it)->setFome((*it)->getFome() + 2);
                        (*it)->adicionaInfo(alimento->getTipo(),alimento->getValorNutritivo(),alimento->getToxicidade());
                        aEliminar.emplace_back(alimento->getId());
                        alimento->setExiste(false);
                    }
                }

                if (m == 0) {

                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " "; //limpa "c"
                    (*it)->movimento(NL, NC);
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "C";
                }
            }

            m = 0;
        }

        // - OVELHA -
        if ((*it)->getEspecie() == "Ovelha") {
            (*it)->setFome();
            if (!(*it)->estaVivo()) {           // verifica se animal está morto
                aEliminar.emplace_back((*it)->getId());
                dadosCorpos = {"o", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                               to_string((*it)->getPeso()), to_string(0)};
                criaCorpos.emplace_back(dadosCorpos);
                (*it)->setVivo(false);
            } else {

                // Sempre que passar 15 instantes do coelho, ele procria
                if (((*it)->getDVidaPDefeito() - (*it)->getDuracaoVida()) % 15 == 0) {
                    dadosOvelha = {"o", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                   to_string((*it)->getSaude())};
                    aProcriarOvelha.emplace_back(dadosOvelha);
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (alimento->getCheiro() == "erva,verdura" || alimento->getCheiro() == "batata,verdura") && alimento->isExiste()) {
                        if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0) {
                            aEliminar.emplace_back((*it)->getId()); // elimina animal
                            dadosCorpos = {"o", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                           to_string((*it)->getPeso()), to_string(0)};
                            criaCorpos.emplace_back(dadosCorpos);
                        }
                        (*it)->setFome((*it)->getFome() + 2);
                        (*it)->adicionaInfo(alimento->getTipo(),alimento->getValorNutritivo(),alimento->getToxicidade());
                        aEliminar.emplace_back(alimento->getId());
                        alimento->setExiste(false);
                    }
                }

                // foge dos animais com > 15 peso
                if (m == 0) {
                    for (int i = (*it)->getLinha() - 3; i < (*it)->getLinha() + 3; i++) {
                        for (int j = (*it)->getColuna() - 3; j < (*it)->getColuna() + 3; j++) {
                            for (auto &animai: animais) {
                                if (animai->getLinha() == i && animai->getColuna() == j &&
                                    (*it)->getId() != animai->getId() && animai->getPeso() > 15 && animai->isVivo()) {

                                    //Calcula numero de passos a andar consoante a fome
                                    int nMov;
                                    nMov = (*it)->getP();

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                                    int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                                    //Vê linha
                                    if ((*it)->getLinha() != i) {
                                        nL = (*it)->getLinha() + ((*it)->getLinha() > i ? nMov : -nMov);
                                    }
                                    //Vê coluna
                                    if ((*it)->getColuna() != j) {
                                        // Vê se a distancia entre colunas é superior a 1
                                        nC = (*it)->getColuna() + ((*it)->getColuna() > j ? nMov : -nMov);
                                    }

                                    (*it)->moveParaPos(nL, nC);

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "O";
                                    m = 1;
                                    break;
                                }
                            }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                }

                // encontra cheiro e vai para a posicao
                if (m == 0) {
                    for (int i = (*it)->getLinha() - 3; i < (*it)->getLinha() + 3; i++) {
                        for (int j = (*it)->getColuna() - 3; j < (*it)->getColuna() + 3; j++) {
                            for (auto &alimento: alimentos) {
                                if (alimento->getLinha() == i && alimento->getColuna() == j &&
                                    alimento->getCheiro() == "erva,verdura" && alimento->isExiste()) {

                                    //Calcula numero de passos a andar consoante a fome
                                    int nMov;
                                    nMov = (*it)->getP();

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                                    int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                                    //Vê linha
                                    // Vê se a distancia entre linhas é superior a 1
                                    if (abs((*it)->getLinha() - i) >
                                        1) //se for, desloca-se nMov linhas em direçao ao cheiro
                                        nL = (*it)->getLinha() + ((*it)->getLinha() > i ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nL = i;

                                    //Vê coluna

                                    // Vê se a distancia entre colunas é superior a 1
                                    if (abs((*it)->getColuna() - j) >
                                        1) //se for, desloca-se nMov linhas em direçao ao animal
                                        nC = (*it)->getColuna() + ((*it)->getColuna() > j ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nC = j;
                                    (*it)->moveParaPos(nL, nC);

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "O";

                                    m = 1;
                                    break;
                                }
                            }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (alimento->getCheiro() == "erva,verdura" || alimento->getCheiro() == "batata,verdura") && alimento->isExiste()) {
                        if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0 ) {
                            aEliminar.emplace_back((*it)->getId()); // elimina animal
                            dadosCorpos = {"o", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                           to_string((*it)->getPeso()), to_string(0)};
                            criaCorpos.emplace_back(dadosCorpos);
                        }
                        (*it)->setFome((*it)->getFome() + 2);
                        (*it)->adicionaInfo(alimento->getTipo(),alimento->getValorNutritivo(),alimento->getToxicidade());
                        aEliminar.emplace_back(alimento->getId());
                        alimento->setExiste(false);
                    }
                }

                if (m == 0) {

                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                    (*it)->movimento(NL, NC);
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "O";
                }
            }

            m = 0;
        }

        // - LOBO -
        if ((*it)->getEspecie() == "Lobo") {
            (*it)->setFome();
            if (!(*it)->estaVivo()) {           // verifica se animal está morto
                aEliminar.emplace_back((*it)->getId());
                dadosCorpos = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(10),
                               to_string(0)};
                criaCorpos.emplace_back(dadosCorpos);
                (*it)->setVivo(false);
            } else {

                random_device device;
                default_random_engine engine(device());
                uniform_int_distribution<int> r(5, (*it)->getDVidaPDefeito());
                int instanciaNascimento = r(engine);

                // Lobo procria
                if (instanciaNascimento == contInstancia && !(*it)->getProcriou()) {
                    dados = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna())};
                    aProcriar.emplace_back(dados);
                    (*it)->setProcriou(true);
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (alimento->getCheiro() == "carne" || alimento->getCheiro() == "carne,ketchup" || alimento->getCheiro() == "ovo") && alimento->isExiste() ) {
                        if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0) {
                            aEliminar.emplace_back((*it)->getId());
                            dadosCorpos = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(10),
                                           to_string(0)};
                            criaCorpos.emplace_back(dadosCorpos);
                        }
                        (*it)->setFome((*it)->getFome() - (alimento->getValorNutritivo() - alimento->getToxicidade()));
                        (*it)->adicionaInfo(alimento->getTipo(),alimento->getValorNutritivo(),alimento->getToxicidade());
                        aEliminar.emplace_back(alimento->getId());
                        alimento->setExiste(false);
                    }
                }

                for (int i = (*it)->getLinha() - 1; i < (*it)->getLinha() + 1; i++) {
                    for (int j = (*it)->getColuna() - 1; j < (*it)->getColuna() + 1; j++) {
                        for (auto &animai: animais) {
                            if (animai->getLinha() == i && animai->getColuna() == j &&
                                (*it)->getId() != animai->getId() && animai->isVivo()) {
                                if (maior <= animai->getPeso()) {
                                    maior = animai->getPeso();
                                    animalAMatar = animai->getId();

                                    if (animai->getEspecie() == "Coelho")
                                        dadosCorpos = {"c", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string(5), to_string(0)};
                                    else if (animai->getEspecie() == "Ovelha")
                                        dadosCorpos = {"o", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string((*it)->getPeso()), to_string(0)};
                                    else if (animai->getEspecie() == "Lobo")
                                        dadosCorpos = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string(10), to_string(0)};
                                    else if (animai->getEspecie() == "Canguru") {
                                        dadosCorpos = {"g", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string(15), to_string(5)};
                                        for(auto & anima : animais){
                                            if(animai->isTemFilho()) {
                                                if(anima->getId() == animai->getIdFilho() ){
                                                    if(anima->isEscondido() && anima->isVivo()) {
                                                        canguruBebeAMatar = anima->getId();
                                                        dadosCorpoBebeCanguru = {"g", to_string(anima->getLinha()), to_string(anima->getColuna()), to_string(15), to_string(5)};
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                if (maior > 0) { //existe animais nas celulas adjacentes ou na msm posicao
                    m = 1;
                    int random;

                    if ((*it)->getPeso() > maior) {
                        aEliminar.emplace_back(animalAMatar);
                        criaCorpos.emplace_back(dadosCorpos);
                        for(auto & anima : animais){
                            if(anima->getId() == animalAMatar)
                                anima->setVivo(false);
                        }

                    } else if ((*it)->getPeso() <= maior) {


                        uniform_int_distribution<int> r3(0, 1);

                        random = r3(engine);

                        if (random == 0) { // lobo morre
                            aEliminar.emplace_back((*it)->getId());
                            dadosCorpos = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                           to_string(10), to_string(0)};
                            criaCorpos.emplace_back(dadosCorpos);
                            (*it)->setVivo(false);
                        } else if (random == 1) { // o outro animal morre -> lobo vive
                            if(dadosCorpos[0] == "g" && dadosCorpoBebeCanguru[0] == "g") {
                                aEliminar.emplace_back(animalAMatar);
                                criaCorpos.emplace_back(dadosCorpos);
                                for(auto & anima : animais){
                                    if(anima->getId() == animalAMatar)
                                        anima->setVivo(false);
                                }
                                aEliminar.emplace_back(canguruBebeAMatar);
                                criaCorpos.emplace_back(dadosCorpoBebeCanguru);
                                for(auto & anim : animais){
                                    if(anim->getId() == animalAMatar)
                                        anim->setVivo(false);
                                }
                            } else {
                                aEliminar.emplace_back(animalAMatar);
                                criaCorpos.emplace_back(dadosCorpos);
                                for(auto & ani : animais){
                                    if(ani->getId() == animalAMatar)
                                        ani->setVivo(false);
                                }
                            }
                        }
                    }

                }


                // Se não encontrou nenhum animal perto dele para lutar vai atras do mais pesado que esteja à volta dele
                if (maior == 0 && m == 0) {
                    for (int i = (*it)->getLinha() - 5; i < (*it)->getLinha() + 5; i++) {
                        for (int j = (*it)->getColuna() - 5; j < (*it)->getColuna() + 5; j++) {
                            for (auto &animai: animais) {
                                if (animai->getLinha() == i && animai->getColuna() == j &&
                                    (*it)->getId() != animai->getId() && animai->isVivo()) {
                                    if (maisPesado <= animai->getPeso()) {
                                        maisPesado = animai->getPeso();
                                        aPerseguir = animai->getId();
                                        m = 1;
                                    }
                                }
                            }
                        }
                    }
                    if (m == 1) {
                        //Calcula numero de passos a andar consoante a fome
                        int nMov;
                        if ((*it)->getFome() <= 15)
                            nMov = 2;
                        else
                            nMov = 3;

                        arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                        int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                        int linAnimal, colAnimal;

                        for (auto itt = animais.begin(); itt != animais.end(); itt++) {
                            if ((*itt)->getId() == aPerseguir) {
                                linAnimal = (*itt)->getLinha();
                                colAnimal = (*itt)->getColuna();
                            }
                        }

                        // Se lobo e animal não estiverem na mesma linha
                        //Vê linha
                            // Vê se a distancia entre linhas é superior a 1
                            if (abs((*it)->getLinha() - linAnimal) > nMov) //se for, desloca-se nMov linhas em direçao ao animal
                                nL = (*it)->getLinha() + ((*it)->getLinha() > linAnimal ? -nMov : nMov);
                            else
                                //Se for <= 1 desloca-se 0 ou 1 linha
                                nL = linAnimal;

                        //Vê coluna
                            // Vê se a distancia entre colunas é superior a 1
                            if (abs((*it)->getColuna() - colAnimal) > nMov) //se for, desloca-se nMov linhas em direçao ao animal
                                nC = (*it)->getColuna() + ((*it)->getColuna() > colAnimal ? -nMov : nMov);
                            else
                                //Se for <= 1 desloca-se 0 ou 1 linha
                                nC = colAnimal;

                        (*it)->moveParaPos(nL, nC);

                        arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "L";
                    }
                }

                // encontra cheiro e vai para a posicao
                if (maior == 0 && m == 0) {
                    for (int i = (*it)->getLinha() - 5; i < (*it)->getLinha() + 5; i++) {
                        for (int j = (*it)->getColuna() - 5; j < (*it)->getColuna() + 5; j++) {
                            for (auto &alimento: alimentos) {
                                if (alimento->getLinha() == i && alimento->getColuna() == j &&
                                    (alimento->getCheiro() == "carne" || alimento->getCheiro() == "carne,ketchup" || alimento->getCheiro() == "ovo") && alimento->isExiste() ) {

                                    //Calcula numero de passos a andar consoante a fome
                                    int nMov;
                                    nMov = (*it)->getP();

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                                    int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                                    //Vê linha
                                    // Vê se a distancia entre linhas é superior a 1
                                    if (abs((*it)->getLinha() - i) > 1) //se for, desloca-se nMov linhas em direçao ao animal
                                        nL = (*it)->getLinha() + ((*it)->getLinha() > i ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nL = i;

                                    //Vê coluna

                                    // Vê se a distancia entre colunas é superior a 1
                                    if (abs((*it)->getColuna() - j) > 1) //se for, desloca-se nMov linhas em direçao ao animal
                                        nC = (*it)->getColuna() + ((*it)->getColuna() > j ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nC = j;
                                    (*it)->moveParaPos(nL, nC);

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "L";

                                    m = 1;
                                    break;
                                }
                            }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (alimento->getCheiro() == "carne" || alimento->getCheiro() == "carne,ketchup" || alimento->getCheiro() == "ovo") && alimento->isExiste() ) {
                        if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0) {
                            aEliminar.emplace_back((*it)->getId());
                            dadosCorpos = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(10),
                                           to_string(0)};
                            criaCorpos.emplace_back(dadosCorpos);
                        }

                        (*it)->setFome((*it)->getFome() - (alimento->getValorNutritivo() - alimento->getToxicidade()));
                        (*it)->adicionaInfo(alimento->getTipo(),alimento->getValorNutritivo(),alimento->getToxicidade());
                        aEliminar.emplace_back(alimento->getId());
                        alimento->setExiste(false);
                    }
                }

                if (maior == 0 && m == 0) {

                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " "; //limpa "c"
                    (*it)->movimento(NL, NC);
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "L";
                }
            }

            m = 0;
            maior = 0;
        }

        // - CANGURU -
        if ((*it)->getEspecie() == "Canguru") {

            if (!(*it)->estaVivo()) {           // verifica se animal está morto
                aEliminar.emplace_back((*it)->getId());
                dadosCorpos = {"g", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(15),
                               to_string(5)};
                criaCorpos.emplace_back(dadosCorpos);
                (*it)->setVivo(false);

                for(auto & animai : animais){
                    if((*it)->isTemFilho()) {
                        if(animai->getId() == (*it)->getIdFilho() ){
                            if(animai->isEscondido()) {
                                aEliminar.emplace_back(animai->getId());
                                dadosCorpos = {"g", to_string(animai->getLinha()), to_string(animai->getColuna()), to_string(15), to_string(5)};
                                criaCorpos.emplace_back(dadosCorpos);
                            }
                        }
                    }
                }

            } else {

                //torna-se adulto
                if(((*it)->getDVidaPDefeito() - (*it)->getDuracaoVida()) >= 20 ){
                    (*it)->setPeso(20);
                }

                //Procria
                if (((*it)->getDVidaPDefeito() - (*it)->getDuracaoVida()) % 30 == 0) {
                    (*it)->setTemFilho(true);
                    dadosRelva = {"g", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string((*it)->getId())};
                    aProcriarRelva.emplace_back(dadosRelva);
                }

                //instantes dentro da bolsa da mae
                if((*it)->getCont() == 0) {
                    (*it)->setEscondido(false);
                    arrayReserva[(*it)->getLinha()+2][(*it)->getColuna()+2] = "G";
                    (*it)->movimento((*it)->getLinha()+2, (*it)->getColuna()+2);

                    m=1;
                }

                //se estiver ma bolsa da mae
                if ((*it)->isEscondido()) {
                    int linMae, colMae;

                    (*it)->setCont(); //decrementa o contador do canguru (tempo que ainda tem dentro da bolsa da mae)

                    for(auto itt = animais.begin(); itt != animais.end(); itt++){
                        if((*itt)->getId() == (*it)->getIdMae() && (*itt)->isVivo()){
                            linMae = (*itt)->getLinha();
                            colMae = (*itt)->getColuna();
                        }
                    }
                    (*it)->movimento(linMae, colMae); //acompanha o movimento da mae
                    arrayReserva[linMae][colMae] = "G";
                    m = 1;
                }

                //Se tiver menos que 10 instantes de idade desloca-se sempre de forma a ficar perto do canguru que o originou
                if((*it)->isTemMae() && m == 0 && ((*it)->getDVidaPDefeito() - (*it)->getDuracaoVida()) < 10){
                    bool existeAnimalPerto = false;
                    // Verifica se existem animais à sua volta
                    for (int i = (*it)->getLinha() - 7; i < (*it)->getLinha() + 7; i++) {
                        for (int j = (*it)->getColuna() - 7; j < (*it)->getColuna() + 7; j++) {
                            for (auto &animai: animais) {
                                //se existirem animais
                                if (animai->getLinha() == i && animai->getColuna() == j && (*it)->getId() != animai->getId() && animai->getId() != (*it)->getIdMae() && animai->isVivo() ) {
                                    existeAnimalPerto = true;
                                    m = 1;
                                }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                    //se existirem animais à volta movimenta-se em direçao à mae com P(posicoes/por instante) = 2
                    if (existeAnimalPerto) {
                        int linMae, colMae;
                        int nMov;
                        nMov = 2;

                        for(auto itt = animais.begin(); itt != animais.end(); itt++){
                            if((*itt)->getId() == (*it)->getIdMae() && (*itt)->isVivo() ){
                                linMae = (*itt)->getLinha();
                                colMae = (*itt)->getColuna();
                            }
                        }

                        arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                        int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                        // Se lobo e animal não estiverem na mesma linha

                        //Vê linha
                        // Vê se a distancia entre linhas é superior a 1
                        if (abs((*it)->getLinha() - linMae) >
                            1) //se for, desloca-se nMov linhas em direçao ao animal
                            nL = (*it)->getLinha() + ((*it)->getLinha() > linMae ? -nMov : nMov);
                        else
                            //Se for <= 1 desloca-se 0 ou 1 linha
                            nL = linMae;

                        //Vê coluna
                        // Vê se a distancia entre colunas é superior a 1
                        if (abs((*it)->getColuna() - colMae) >
                            1) //se for, desloca-se nMov linhas em direçao ao animal
                            nC = (*it)->getColuna() + ((*it)->getColuna() > colMae ? -nMov : nMov);
                        else
                            //Se for <= 1 desloca-se 0 ou 1 linha
                            nC = colMae;

                        (*it)->moveParaPos(nL, nC);
                        //Se estiver na posicao da mae, fica na bolsa
                        if ((*it)->getLinha() == linMae && (*it)->getColuna() == colMae) {
                            (*it)->setEscondido(true);
                        }

                        arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "G";
                        m = 1;
                        break;

                    } else { //Anda normalmente em direçao à sua mae

                        int linMae, colMae;
                        int nMov;
                        nMov = (*it)->getP();

                        for(auto itt = animais.begin(); itt != animais.end(); itt++){
                            if((*itt)->getId() == (*it)->getIdMae() && (*itt)->isVivo() ){
                                linMae = (*itt)->getLinha();
                                colMae = (*itt)->getColuna();
                            }
                        }

                        arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                        int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                        //Vê linha

                        // Vê se a distancia entre linhas é superior a 1
                        if (abs((*it)->getLinha() - linMae) > 1) //se for, desloca-se nMov linhas em direçao ao animal
                            nL = (*it)->getLinha() + ((*it)->getLinha() > linMae ? -nMov : nMov);
                        else
                            //Se for <= 1 desloca-se 0 ou 1 linha
                            nL = linMae;

                        //Vê coluna

                        // Vê se a distancia entre colunas é superior a 1
                        if (abs((*it)->getColuna() - colMae) > 1) //se for, desloca-se nMov linhas em direçao ao animal
                            nC = (*it)->getColuna() + ((*it)->getColuna() > colMae ? -nMov : nMov);
                        else
                            //Se for <= 1 desloca-se 0 ou 1 linha
                            nC = colMae;

                        (*it)->moveParaPos(nL, nC);

                        arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "G";
                        m = 1;
                        break;
                    }
                }
            }

                if (m == 0) {
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                    (*it)->movimento(NL, NC);
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "g";
                }
            }

            m = 0;
        }

        // - DRAGAO -
        if ((*it)->getEspecie() == "Dragao") {
            (*it)->setFome();

            if (!(*it)->estaVivo()) {           // verifica se animal está morto
                aEliminar.emplace_back((*it)->getId());
                dadosCorpos = {"m", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(25),
                               to_string(0)};
                criaCorpos.emplace_back(dadosCorpos);
                (*it)->setVivo(false);
            } else {

                if((*it)->getPeso() >= 50)
                    (*it)->setTemMae(false); // ja não é bebe

                if((*it)->isTemMae()) {
                    (*it)->setPeso((*it)->getPeso() + 2);
                }



                // Dragao procria
                if (((*it)->getDVidaPDefeito() - (*it)->getDuracaoVida()) % 5 == 0) {

                    random_device device;
                    default_random_engine engine(device());
                    uniform_int_distribution<int> r(0, 4);

                    if (r(engine) == 1) {
                        dadosRelva = {"e", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(1)};
                        aProcriarRelva.emplace_back(dadosRelva);
                        (*it)->setProcriou(true);
                    }
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (  ((alimento->getCheiro() == "carne" || alimento->getCheiro() == "carne,ketchup") && !(*it)->isTemMae())
                           ||
                           (alimento->getCheiro() == "batataFrita"  && (*it)->isTemMae())
                        )
                        && alimento->isExiste()) {

                        if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0 ) {
                            aEliminar.emplace_back((*it)->getId());
                            dadosCorpos = {"m", to_string((*it)->getLinha()), to_string((*it)->getColuna()), to_string(25),
                                           to_string(0)};
                            criaCorpos.emplace_back(dadosCorpos);
                        }
                        (*it)->setFome((*it)->getFome() - (alimento->getValorNutritivo() - alimento->getToxicidade()));
                        (*it)->adicionaInfo(alimento->getTipo(),alimento->getValorNutritivo(),alimento->getToxicidade());
                        aEliminar.emplace_back(alimento->getId());
                        alimento->setExiste(false);
                    }
                }

                // Verifica esta em cima de uma batata
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() && (alimento->getCheiro() == "batata,verdura")) {
                        alimento->setBatataFrita(true); // dragao cuspe fogo e torna a batata em batata frita
                        alimento->setValorNutritivo(20);
                        alimento->setToxicidade(0);
                        alimento->setCont(0);
                        alimento->setCheiro("batataFrita");
                    }
                }

                for (int i = (*it)->getLinha() - 1; i < (*it)->getLinha() + 1; i++) {
                    for (int j = (*it)->getColuna() - 1; j < (*it)->getColuna() + 1; j++) {
                        for (auto &animai: animais) {
                            if (animai->getLinha() == i && animai->getColuna() == j &&
                                (*it)->getId() != animai->getId() && animai->isVivo()) {
                                if (maior <= animai->getPeso()) {
                                    maior = animai->getPeso();
                                    animalAMatar = animai->getId();

                                    if (animai->getEspecie() == "Coelho")
                                        dadosCorpos = {"c", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string(5), to_string(0)};
                                    else if (animai->getEspecie() == "Ovelha")
                                        dadosCorpos = {"o", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string((*it)->getPeso()), to_string(0)};
                                    else if (animai->getEspecie() == "Lobo")
                                        dadosCorpos = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string(10), to_string(0)};
                                    else if (animai->getEspecie() == "Canguru") {
                                        dadosCorpos = {"g", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                       to_string(15), to_string(5)};
                                        for(auto & anima : animais){
                                            if(animai->isTemFilho()) {
                                                if(anima->getId() == animai->getIdFilho() ){
                                                    if(anima->isEscondido() && anima->isVivo()) {
                                                        canguruBebeAMatar = anima->getId();
                                                        dadosCorpoBebeCanguru = {"g", to_string(anima->getLinha()), to_string(anima->getColuna()), to_string(15), to_string(5)};
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                if (maior > 0) { //existe animais nas celulas adjacentes ou na msm posicao
                    m = 1;
                    int random;

                    if ((*it)->getPeso() > maior) {
                        aEliminar.emplace_back(animalAMatar);
                        criaCorpos.emplace_back(dadosCorpos);
                        for(auto & anima : animais){
                            if(anima->getId() == animalAMatar)
                                anima->setVivo(false);
                        }

                    } else if ((*it)->getPeso() <= maior) {

                        random_device device;
                        default_random_engine engine(device());
                        uniform_int_distribution<int> r3(0, 1);

                        random = r3(engine);

                        if (random == 0) { // lobo morre
                            aEliminar.emplace_back((*it)->getId());
                            dadosCorpos = {"l", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                           to_string(10), to_string(0)};
                            criaCorpos.emplace_back(dadosCorpos);
                            (*it)->setVivo(false);
                        } else if (random == 1) { // o outro animal morre -> lobo vive
                            if(dadosCorpos[0] == "g" && dadosCorpoBebeCanguru[0] == "g") {
                                aEliminar.emplace_back(animalAMatar);
                                criaCorpos.emplace_back(dadosCorpos);
                                for(auto & anima : animais){
                                    if(anima->getId() == animalAMatar)
                                        anima->setVivo(false);
                                }
                                aEliminar.emplace_back(canguruBebeAMatar);
                                criaCorpos.emplace_back(dadosCorpoBebeCanguru);
                                for(auto & anim : animais){
                                    if(anim->getId() == animalAMatar)
                                        anim->setVivo(false);
                                }
                            } else {
                                aEliminar.emplace_back(animalAMatar);
                                criaCorpos.emplace_back(dadosCorpos);
                                for(auto & ani : animais){
                                    if(ani->getId() == animalAMatar)
                                        ani->setVivo(false);
                                }
                            }
                        }
                    }

                }


                // Verifica se existem animais à sua volta
                if (maior == 0 && m == 0) {
                    for (int i = (*it)->getLinha() - 8; i < (*it)->getLinha() + 8; i++) {
                        for (int j = (*it)->getColuna() - 8; j < (*it)->getColuna() + 8; j++) {
                            for (auto &animai: animais) {
                                if (animai->getLinha() == i && animai->getColuna() == j &&
                                    (*it)->getId() != animai->getId() && animai->getPeso() < (*it)->getPeso() && animai->isVivo() ) {

                                    //Calcula numero de passos a andar consoante a fome
                                    int nMov;
                                    if ((*it)->getFome() <= 20)
                                        nMov = 2;
                                    else
                                        nMov = 3;

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                                    int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                                    //calcula nova posicao

                                    // Se lobo e animal não estiverem na mesma linha

                                    //Vê linha
                                    if ((*it)->getLinha() != i) {
                                        // Vê se a distancia entre linhas é superior a 1
                                        if (abs((*it)->getLinha() - i) >
                                            1) //se for, desloca-se nMov linhas em direçao ao animal
                                            nL = (*it)->getLinha() + ((*it)->getLinha() > i ? -nMov : nMov);
                                        else
                                            //Se for <= 1 desloca-se 0 ou 1 linha
                                            nL = (*it)->getLinha() -
                                                 ((*it)->getLinha() != i ? 0 : ((*it)->getLinha() - i));
                                    }
                                    //Vê coluna
                                    if ((*it)->getColuna() != j) {
                                        // Vê se a distancia entre colunas é superior a 1
                                        if (abs((*it)->getColuna() - j) >
                                            1) //se for, desloca-se nMov linhas em direçao ao animal
                                            nC = (*it)->getColuna() + ((*it)->getColuna() > j ? -nMov : nMov);
                                        else
                                            //Se for <= 1 desloca-se 0 ou 1 linha
                                            nC = (*it)->getColuna() -
                                                 ((*it)->getColuna() != j ? 0 : ((*it)->getColuna() - j));
                                    }

                                    (*it)->moveParaPos(nL, nC);

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "M";
                                    m = 1;
                                    break;
                                }
                            }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                }


                // encontra cheiro e vai para a posicao
                if (maior == 0 && m == 0) {
                    for (int i = (*it)->getLinha() - 8; i < (*it)->getLinha() + 8; i++) {
                        for (int j = (*it)->getColuna() - 8; j < (*it)->getColuna() + 8; j++) {
                            for (auto &alimento: alimentos) {
                                if (alimento->getLinha() == i && alimento->getColuna() == j &&
                                        ( ((alimento->getCheiro() == "carne" || alimento->getCheiro() == "carne,ketchup" || alimento->getCheiro() == "batata,verdura") && !(*it)->isTemMae())
                                        ||
                                          (alimento->getCheiro() == "batataFrita"  && (*it)->isTemMae())
                                        )
                                        && alimento->isExiste()) {

                                    //Calcula numero de passos a andar consoante a fome
                                    int nMov;
                                    nMov = (*it)->getP();

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " ";
                                    int nL = (*it)->getLinha(), nC = (*it)->getColuna();

                                    //Vê linha
                                    // Vê se a distancia entre linhas é superior a 1
                                    if (abs((*it)->getLinha() - i) > 1) //se for, desloca-se nMov linhas em direçao ao animal
                                        nL = (*it)->getLinha() + ((*it)->getLinha() > i ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nL = i;

                                    //Vê coluna

                                    // Vê se a distancia entre colunas é superior a 1
                                    if (abs((*it)->getColuna() - j) > 1) //se for, desloca-se nMov linhas em direçao ao animal
                                        nC = (*it)->getColuna() + ((*it)->getColuna() > j ? -nMov : nMov);
                                    else
                                        //Se for <= 1 desloca-se 0 ou 1 linha
                                        nC = j;
                                    (*it)->moveParaPos(nL, nC);

                                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "M";

                                    m = 1;
                                    break;
                                }
                            }
                            if (m == 1)
                                break;
                        }
                        if (m == 1)
                            break;
                    }
                }

                // Verifica se tem alimento no sitio
                for (auto &alimento: alimentos) {
                    if (alimento->getLinha() == (*it)->getLinha() && alimento->getColuna() == (*it)->getColuna() &&
                        (  ((alimento->getCheiro() == "carne" || alimento->getCheiro() == "carne,ketchup" || alimento->getCheiro() == "batata,verdura" ) && !(*it)->isTemMae())
                        ||
                           (alimento->getCheiro() == "batataFrita"  && (*it)->isTemMae())
                        )
                        && alimento->isExiste()) {

                            if(alimento->getCheiro() == "batata,verdura") {
                                alimento->setBatataFrita(true); // dragao cuspe fogo e torna a batata em batata frita
                                alimento->setValorNutritivo(20);
                                alimento->setToxicidade(0);
                                alimento->setCont(0);
                                alimento->setCheiro("batataFrita");
                            } else {

                                if ((*it)->consome(alimento->getValorNutritivo(), alimento->getToxicidade()) == 0) {
                                    aEliminar.emplace_back((*it)->getId());
                                    dadosCorpos = {"m", to_string((*it)->getLinha()), to_string((*it)->getColuna()),
                                                   to_string(25),
                                                   to_string(0)};
                                    criaCorpos.emplace_back(dadosCorpos);
                                }
                                (*it)->setFome((*it)->getFome() - (alimento->getValorNutritivo() - alimento->getToxicidade()));
                                (*it)->adicionaInfo(alimento->getTipo(), alimento->getValorNutritivo(),
                                                    alimento->getToxicidade());
                                aEliminar.emplace_back(alimento->getId());
                                alimento->setExiste(false);
                            }
                    }
                }

                if (maior == 0 && m == 0) {

                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = " "; //limpa "c"
                    (*it)->movimento(NL, NC);
                    arrayReserva[(*it)->getLinha()][(*it)->getColuna()] = "M";
                }
            }

            m = 0;
            maior = 0;
        }


    }

    if(!aEliminar.empty()) {

        //Mata tudo que há para matar
        for (int & i : aEliminar) {
            matarAnimal(i);
            removeAlimento2(i);
        }
        aEliminar.clear();
    }

    if(!aProcriar.empty()) {

        //Cria tudo que há para criar
        for (auto & i : aProcriar) {
            procriar(i[0], stoi(i[1]),stoi(i[2]));
            criaAlimento(i[0],stoi(i[1]),stoi(i[2]));
        }
        dados.clear();
        aProcriar.clear();
    }

    if(!aProcriarOvelha.empty()) {

        //Cria tudo que há para criar
        for (auto & i : aProcriarOvelha) {
            procriaOvelha(i[0], stoi(i[1]),stoi(i[2]), stoi(i[3]));
        }
        dadosOvelha.clear();
        aProcriarOvelha.clear();
    }

    if(!aProcriarRelva.empty()) {

        //Cria tudo que há para criar
        for (auto & i : aProcriarRelva) {
            procriarRelva(i[0], stoi(i[1]),stoi(i[2]), stoi(i[3]));
        }
        dadosRelva.clear();
        aProcriarRelva.clear();
    }

    if(!criaCorpos.empty()) {

        //Cria tudo que há para criar
        for (auto & i : criaCorpos) {
            criaCorpo(i[0], stoi(i[1]),stoi(i[2]), stoi(i[3]), stoi(i[4]));
        }
        dadosCorpos.clear();
        dadosCorpoBebeCanguru.clear();
        criaCorpos.clear();
    }

    return "Pressione <Enter>";

}

void Reserva::procriar(const string& especie, int lin, int col) {

    int linha, coluna;
    int novaLin, novaCol;

    if (especie == "c") {
        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(lin - 10, lin + 10);
        uniform_int_distribution<int> r1(col - 10, col + 10);

        novaLin = r(engine);
        novaCol = r1(engine);

        linha = novaLin;
        coluna = novaCol;

        // passar para o outro lado
        if (novaLin < 0) //linhas
            linha = getNL() + (lin + novaLin);  // lin->linha atual | novaLin->valor random

        if (novaCol < 0) //colunas
            coluna = getNC() + (col + novaCol); // col->col atual | novaCol->valor random

        if (novaLin > getNL()) //linhas
            linha = (lin - getNL()) + novaLin;

        if (novaCol > getNC()) //colunas
            coluna = (col - getNC()) + novaCol;

        criaAnimal(especie, linha, coluna);
    }

    if (especie == "l") {

        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(lin - 15, lin + 15);
        uniform_int_distribution<int> r1(col - 15, col + 15);

        novaLin = r(engine);
        novaCol = r1(engine);

        linha = novaLin;
        coluna = novaCol;

        // passar para o outro lado
        if (novaLin < 0) //linhas
            linha = getNL() + (lin + novaLin);  // lin->linha atual | novaLin->valor random

        if (novaCol < 0) //colunas
            coluna = getNC() + (col + novaCol); // col->col atual | novaCol->valor random

        if (novaLin > getNL()) //linhas
            linha = (lin - getNL()) + novaLin;

        if (novaCol > getNC()) //colunas
            coluna = (col - getNC()) + novaCol;

        criaAnimal(especie, linha, coluna);

    }

}
void Reserva::procriarRelva(const string& especie, int lin, int col, int id) {
    int linha, coluna;
    int novaLin, novaCol;

    if (especie == "r") {

        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(lin - 4, lin + 8);
        uniform_int_distribution<int> r1(col - 4, col + 8);

        novaLin = r(engine);
        novaCol = r1(engine);

        linha = novaLin;
        coluna = novaCol;

        // passar para o outro lado
        if (novaLin < 0) //linhas
            linha = getNL() + (lin + novaLin);  // lin->linha atual | novaLin->valor random

        if (novaCol < 0) //colunas
            coluna = getNC() + (col + novaCol); // col->col atual | novaCol->valor random

        if (novaLin > getNL()) //linhas
            linha = (lin - getNL()) + novaLin;

        if (novaCol > getNC()) //colunas
            coluna = (col - getNC()) + novaCol;

        //se posicao livre
        if (!alimentoExiste(linha, coluna)){
            criaAlimento(especie, linha, coluna);
            for(auto & alimento : alimentos){
                if(id == alimento->getId()){
                    alimento->setProcriou(true);
                }
            }
        }

    } else if (especie == "g") {
        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(lin - 3, lin + 3);
        uniform_int_distribution<int> r1(col - 3, col + 3);

        novaLin = r(engine);
        novaCol = r1(engine);

        linha = novaLin;
        coluna = novaCol;

        // passar para o outro lado
        if (novaLin < 0) //linhas
            linha = getNL() + (lin + novaLin);  // lin->linha atual | novaLin->valor random

        if (novaCol < 0) //colunas
            coluna = getNC() + (col + novaCol); // col->col atual | novaCol->valor random

        if (novaLin > getNL()) //linhas
            linha = (lin - getNL()) + novaLin;

        if (novaCol > getNC()) //colunas
            coluna = (col - getNC()) + novaCol;

        Animal* ponteiroParaAnimal = new Canguru(linha, coluna, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[linha][coluna] = "G";
        ++IDglobal;
        ++contAnimal;
        ponteiroParaAnimal->setIdMae(id);
        ponteiroParaAnimal->setTemMae(true);

        for(auto & animai : animais){
            if(animai->getId() == id ){
                animai->setIdFilho(ponteiroParaAnimal->getId());
            }
        }
    }
    else if (especie == "m") {
        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(lin - 1, lin + 1);
        uniform_int_distribution<int> r1(col - 1, col + 1);

        novaLin = r(engine);
        novaCol = r1(engine);

        linha = novaLin;
        coluna = novaCol;

        // passar para o outro lado
        if (novaLin < 0) //linhas
            linha = getNL() + (lin + novaLin);  // lin->linha atual | novaLin->valor random

        if (novaCol < 0) //colunas
            coluna = getNC() + (col + novaCol); // col->col atual | novaCol->valor random

        if (novaLin > getNL()) //linhas
            linha = (lin - getNL()) + novaLin;

        if (novaCol > getNC()) //colunas
            coluna = (col - getNC()) + novaCol;

        Animal* ponteiroParaAnimal = new Dragao(linha, coluna, getIDglobal());
        animais.emplace_back(ponteiroParaAnimal);
        arrayReserva[linha][coluna] = "M";
        ++IDglobal;
        ++contAnimal;
        ponteiroParaAnimal->setPeso(id);
        ponteiroParaAnimal->setTemMae(true);

    } else if (especie == "e") {
        random_device device;
        default_random_engine engine(device());
        uniform_int_distribution<int> r(lin - 3, lin + 3);
        uniform_int_distribution<int> r1(col - 3, col + 3);

        novaLin = r(engine);
        novaCol = r1(engine);

        linha = novaLin;
        coluna = novaCol;

        // passar para o outro lado
        if (novaLin < 0) //linhas
            linha = getNL() + (lin + novaLin);  // lin->linha atual | novaLin->valor random

        if (novaCol < 0) //colunas
            coluna = getNC() + (col + novaCol); // col->col atual | novaCol->valor random

        if (novaLin > getNL()) //linhas
            linha = (lin - getNL()) + novaLin;

        if (novaCol > getNC()) //colunas
            coluna = (col - getNC()) + novaCol;

        Alimento* ponteiroParaAlimento = new OvoDragao(linha, coluna, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[linha][coluna] = especie;
        ++IDglobal;
        ++contAlimento;

    }
}


void Reserva::procriaOvelha(const string& especie, int lin, int col, int saude) {

    int linha, coluna;
    int novaLin, novaCol;

    random_device device;
    default_random_engine engine(device());
    uniform_int_distribution<int> r(lin - 12, lin + 12);
    uniform_int_distribution<int> r1(col - 12, col + 12);

    novaLin = r(engine);
    novaCol = r1(engine);

    linha = novaLin;
    coluna = novaCol;

    // passar para o outro lado
    if (novaLin < 0) //linhas
        linha = getNL() + (lin + novaLin);  // lin->linha atual | novaLin->valor random

    if (novaCol < 0) //colunas
        coluna = getNC() + (col + novaCol); // col->col atual | novaCol->valor random

    if (novaLin > getNL()) //linhas
        linha = (lin - getNL()) + novaLin;

    if (novaCol > getNC()) //colunas
        coluna = (col - getNC()) + novaCol;

    Animal* ponteiroParaAnimal = new Ovelha(linha, coluna, getIDglobal());
    animais.emplace_back(ponteiroParaAnimal);
    arrayReserva[linha][coluna] = "O";
    ++IDglobal;
    ++contAnimal;
    ponteiroParaAnimal->setSaude(saude);

}

void Reserva::criaCorpo(const string &especie, int lin, int col, int vNutritivo, int pToxicidade) {

    bool encontra = false;

    for (int i = lin - 1; i < lin + 1; i++) {
        for (int j = col - 1; j < col + 1; j++) {
            if (lin != i && col != j && !alimentoExiste(i,j)) {
                    lin = i;
                    col = j;
                    encontra = true;
                    break;
            }
        }

        if(encontra)
            break;
    }


    if (especie == "o"){

        Alimento* ponteiroParaAlimento = new Corpo(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = "p";
        ++IDglobal;
        ++contAlimento;
        ponteiroParaAlimento->setValorNutritivo(vNutritivo);
        ponteiroParaAlimento->setToxicidade(pToxicidade);
        ponteiroParaAlimento->setVNutritivoInicial(vNutritivo);

    } else if (especie == "l"){

        Alimento* ponteiroParaAlimento = new Corpo(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = "p";
        ++IDglobal;
        ++contAlimento;
        ponteiroParaAlimento->setValorNutritivo(vNutritivo);
        ponteiroParaAlimento->setToxicidade(pToxicidade);
        ponteiroParaAlimento->setVNutritivoInicial(vNutritivo);

    } else if (especie == "g"){

        Alimento* ponteiroParaAlimento = new Corpo(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = "p";
        ++IDglobal;
        ++contAlimento;
        ponteiroParaAlimento->setValorNutritivo(vNutritivo);
        ponteiroParaAlimento->setToxicidade(pToxicidade);
        ponteiroParaAlimento->setVNutritivoInicial(vNutritivo);

    }  else if(especie == "m"){

        Alimento* ponteiroParaAlimento = new Corpo(lin, col, getIDglobal());
        alimentos.emplace_back(ponteiroParaAlimento);
        arrayReserva[lin][col] = "p";
        ++IDglobal;
        ++contAlimento;
        ponteiroParaAlimento->setValorNutritivo(vNutritivo);
        ponteiroParaAlimento->setToxicidade(pToxicidade);
        ponteiroParaAlimento->setVNutritivoInicial(vNutritivo);
    }

}








