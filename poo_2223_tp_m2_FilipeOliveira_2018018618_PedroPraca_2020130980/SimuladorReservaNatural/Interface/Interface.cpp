//
// Created by Pedro Praça & Filipe Oliveira on 03/11/2022.
//


#include "Interface.h"
#include <fstream>
#include <iterator>
#include <thread>

using namespace std;

int width = 50;
int height = 12;

bool veioDoFicheiro = false;

string Interface::leDoTeclado(string txt) {

    int numPalavras=0, i;
    vector<string> parametros;

    istringstream iss(txt);

    //Percorrer o texto com o iterator e separa-lo, este método só pode dividir strings por espaços (delimitador default
    //do istream_iterator), e copia as strings extraídas para o vector, usando o algoritmo copy.
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(parametros));

    //contar o numero de palavras
    for (const auto &str : parametros)
        numPalavras++;

    //Percorre os comandos todos e confirma se existe algum igual ao que o utilizador introduziu
    for (i = 0; i < comandos.size(); i++)
        if (comandos[i].getNome() == parametros[0])
            break;

    //Caso o comando escrito nao exista no vector
    if (i == comandos.size())
        redirecionaInfos("Comando Desconhecido!");


    if(parametros[0] == "load") {
        if (parametros.size() != 2)
            redirecionaInfos(" Numero de argumentos errado! ");
        else{
            veioDoFicheiro = true;
            return leFicheiro(parametros[1]);
        }
    }

    return executaComando(parametros, i);
}

string Interface::leFicheiro(string fileName){

    int numPalavras;
    int i, nLinha=0;
    vector<string> parametros;
    string comandoNome,linha;

    //Abrir o ficheiro
    ifstream ficheiro(fileName);

    if(ficheiro.is_open() && ficheiro.good()) {

        while (getline(ficheiro, linha)) {
            if(linha.empty()) continue;

            nLinha++; // Incrementa num de linhas

            numPalavras = 0; //Inicialização das variaveis a cada comando

            parametros.clear(); //Limpar o comando que foi escrito anteriormente

            istringstream iss(linha);

            /* Percorrer o texto com o iterator e separa-lo, este método só pode dividir strings por espaços (delimitador default
             * do istream_iterator), e copia as strings extraídas para o vector, usando o algoritmo método copy. */

            copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(parametros));

            //contar o numero de palavras
            for (const auto &str: parametros)
                numPalavras++;

            //Percorre os comandos todos e confirma se existe algum igual ao que o utilizador introduziu
            for (i = 0; i < comandos.size(); i++)
                if (comandos[i].getNome() == parametros[0])
                    break;

            //Caso o comando escrito nao existe no vetor
            if (i == comandos.size())
                redirecionaInfos("Comando Desconhecido!");

            if (executaComando(parametros, i) == "Exit") { // i -> simboliza a opção a tomar no "case"
                ficheiro.close();
                exitPrograma();
            }
        }
    }

    ficheiro.close();
    veioDoFicheiro = false;

    return "oi";
}

string Interface::executaComando(vector<string> parametros, int opcao) {

    switch (opcao) {
        case 0: {//"animal", "<especie> <linha> <coluna>" ou //"animal", " <especie> "
            if(((parametros.size() != 4 && parametros.size() != 2) ) || (parametros[1] != "c" && parametros[1] != "o" && parametros[1] != "l" && parametros[1] != "g" && parametros[1] != "m" ))
                redirecionaInfos("Erro na introducao do comando!");

            else if(parametros.size() == 2 && !veioDoFicheiro) {
                redirecionaInfos(reserva->criaAnimal(parametros[1]));
                return "oi";

            } else if(parametros.size() == 2 && veioDoFicheiro) {
                redirecionaInfos2(reserva->criaAnimal(parametros[1]));
                return "oi";
            }

            else if (parametros.size() == 4){
                if((stoi(parametros[2]) > reserva->getNL()-1) || (stoi(parametros[2]) < 0) || (stoi(parametros[3]) > reserva->getNC()-1) || (stoi(parametros[3]) < 0) || !isNumber(parametros[2]) || !isNumber(parametros[3]))
                    redirecionaInfos("Erro na introducao do comando!");
                else {
                    if(!veioDoFicheiro) {
                        redirecionaInfos(reserva->criaAnimal(parametros[1], stoi(parametros[2]), stoi(parametros[3])));
                        return "oi";
                    }
                    else {
                        redirecionaInfos2( reserva->criaAnimal(parametros[1], stoi(parametros[2]), stoi(parametros[3])));
                        return "oi";
                    }
                }
            }
            break;
        }

        case 2: { //kill", " <linha> <coluna>
            if((parametros.size() != 3) || (stoi(parametros[1]) > reserva->getNL() || stoi(parametros[1]) < 0 || stoi(parametros[2]) > reserva->getNC() || stoi(parametros[2]) < 0) || !isNumber(parametros[1]) || !isNumber(parametros[2]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->matarAnimal(stoi(parametros[1]), stoi(parametros[2])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->matarAnimal(stoi(parametros[1]), stoi(parametros[2])));
                    return "oi";
                }
            }
            break;
        }
        case 3: { //killid", "<id>"
            if((parametros.size() != 2) || !isNumber(parametros[1]) || stoi(parametros[1]) < 1)
                redirecionaInfos("Erro na introducao do comando!");
            else {

                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->matarAnimal(stoi(parametros[1])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->matarAnimal(stoi(parametros[1])));
                    return "oi";
                }
            }
            break;
        }
        case 4: { //food", "<tipo> <linha> <coluna>" ou food", "<tipo>"
            if((parametros.size() != 4 && parametros.size() != 2) || (parametros[1] != "r" && parametros[1] != "t" && parametros[1] != "p" && parametros[1] != "b" && parametros[1] != "a" && parametros[1] != "e"))
                redirecionaInfos("Erro na introducao do comando!");

            else if(parametros.size() == 2){
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->criaAlimento(parametros[1]));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->criaAlimento(parametros[1]));
                    return "oi";
                }
            }

            else if (parametros.size() == 4){
                if((stoi(parametros[2]) > reserva->getNL()-1) || (stoi(parametros[2]) < 0) || (stoi(parametros[3]) > reserva->getNC()-1) || (stoi(parametros[3]) < 0) || !isNumber(parametros[2]) || !isNumber(parametros[3]))
                    redirecionaInfos("Erro na introducao do comando!");
                else {
                    if(!veioDoFicheiro) {
                        redirecionaInfos(reserva->criaAlimento(parametros[1], stoi(parametros[2]), stoi(parametros[3])));
                        return "oi";
                    }else{
                        redirecionaInfos2(reserva->criaAlimento(parametros[1], stoi(parametros[2]), stoi(parametros[3])));
                        return "oi";
                    }
                }
            }
            break;
        }
        case 6: { //feed", "<linha> <coluna>  <pontos nutritivos> <pontos de toxicidade
            if( parametros.size() != 5 || stoi(parametros[1]) > reserva->getNL() || stoi(parametros[1]) < 0 || (stoi(parametros[2]) > reserva->getNC()) || (stoi(parametros[2]) < 0) || !isNumber(parametros[1]) || !isNumber(parametros[2]) || !isNumber(parametros[3]) || !isNumber(parametros[4])) // confirmar verificaçao dos pontos nutritivos etc...
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->alimentaAnimal(stoi(parametros[1]), stoi(parametros[2]), stoi(parametros[3]), stoi(parametros[4])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->alimentaAnimal(stoi(parametros[1]), stoi(parametros[2]), stoi(parametros[3]), stoi(parametros[4])));
                    return "oi";
                }
            }

            break;
        }
        case 7: { //feedid", "<ID> <pontos nutritivos> <pontos de toxicidade>"}
            if((parametros.size() != 4) || !isNumber(parametros[1]) || !isNumber(parametros[2]) || !isNumber(parametros[3]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->alimentaAnimalID(stoi(parametros[1]), stoi(parametros[2]), stoi(parametros[3])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->alimentaAnimalID(stoi(parametros[1]), stoi(parametros[2]), stoi(parametros[3])));
                    return "oi";
                }
            }
            break;
        }
        case 8: { //nofood", "<linha> <coluna>" ou  nofood", "<ID>
            if((parametros.size() != 3 && parametros.size() != 2))
                redirecionaInfos("Erro na introducao do comando!");

            if(parametros.size() == 2 || !isNumber(parametros[1])) {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->removeAlimento(stoi(parametros[1])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->removeAlimento(stoi(parametros[1])));
                    return "oi";
                }
            }

            else if (parametros.size() == 3){
                if((stoi(parametros[1]) > reserva->getNL()) || (stoi(parametros[1]) < 0) || (stoi(parametros[2]) > reserva->getNC()) || (stoi(parametros[2]) < 0) || !isNumber(parametros[1]) || !isNumber(parametros[2]))
                    redirecionaInfos("Erro na introducao do comando!");
                else {
                    if(!veioDoFicheiro) {
                        redirecionaInfos(reserva->removeAlimento(stoi(parametros[1]), stoi(parametros[2])));
                        return "oi";
                    }else{
                        redirecionaInfos2(reserva->removeAlimento(stoi(parametros[1]), stoi(parametros[2])));
                        return "oi";
                    }
                }
            }
            break;
        }
        case 10: { //"empty", "<linha> <coluna>"
            if((parametros.size() != 3) || (stoi(parametros[1]) > reserva->getNL()) || (stoi(parametros[1]) < 0) || (stoi(parametros[2]) > reserva->getNC()) || (stoi(parametros[2]) < 0) || !isNumber(parametros[1]) || !isNumber(parametros[2]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->limpaCelula(stoi(parametros[1]), stoi(parametros[2])));
                    return "oi";
                }else{
                    redirecionaInfos(reserva->limpaCelula(stoi(parametros[1]), stoi(parametros[2])));
                    return "oi";
                }
            }

            break;
        }
        case 11: { //"see", "<linha> <coluna>"
            if((parametros.size() != 3) || (stoi(parametros[1]) > reserva->getNL()) || (stoi(parametros[1]) < 0) || (stoi(parametros[2]) > reserva->getNC()) || (stoi(parametros[2]) < 0) || !isNumber(parametros[1]) || !isNumber(parametros[2]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->infoSee(stoi(parametros[1]), stoi(parametros[2])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->infoSee(stoi(parametros[1]), stoi(parametros[2])));
                    return "oi";
                }
            }

            break;
        }
        case 12: { //"info", "<ID>"
            if((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->obtemInfo(stoi(parametros[1])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->obtemInfo(stoi(parametros[1])));
                    return "oi";
                }
            }
            break;
        }
        case 13: { //"n", "" ou  "n", "<N>" ou "n", "<N> <P>"
            if ((parametros.size() != 1 && parametros.size() != 2 && parametros.size() != 3) || parametros[0] != "n")
                redirecionaInfos("Erro na introducao do comandoa!");

            else if (parametros.size() == 1) {
                redirecionaInfos(reserva->avanca());
                return "oi";
            }

            else if (parametros.size() == 2) {
                if (!isNumber(parametros[1]))
                    redirecionaInfos("Erro na introducao do comando!");

                else {
                    for (int i = 0; i < stoi(parametros[1]); i++) {
                        reserva->avanca();
                        mostraEcra(0);
                    }
                }
            } else if (parametros.size() == 3) {
                if (!isNumber(parametros[1]) && !isNumber(parametros[2]))
                    redirecionaInfos("Erro na introducao do comando!");

                else {
                    for (int i = 0; i < stoi(parametros[1]); i++) {
                        reserva->avanca();
                        mostraEcra(stoi(parametros[2]));

                    }
                }
            }
            break;
        }
        case 16: { //"anim", ""
            if((parametros.size() != 1))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->listaIdAnimais());
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->listaIdAnimais());
                    return "oi";
                }
            }

            break;
        }
        case 17: { //"visanim", ""
            if((parametros.size() != 1))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->obtemAnimalVisivel());
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->obtemAnimalVisivel());
                    return "oi";
                }

            }
            break;
        }

        case 18: { //"store", "<nome>"
            if((parametros.size() != 2))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                int f=0;
                for (auto it = stores.begin(); it != stores.end(); it++) {
                    if ((*it)->getNome() == parametros[1]) {
                        redirecionaInfos("Ja existe esse nome");
                        f=1;
                    }
                }
                if(f == 0) {
                    stores.emplace_back(new Store(*reserva, parametros[1]));
                    redirecionaInfos("Store efetuado com sucesso!");
                    return "oi";
                }
            }
            break;
        }
        case 19: { //"restore", "<nome>"
            if((parametros.size() != 2))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                for (auto it = stores.begin(); it != stores.end(); it++) {
                     if ((*it)->getNome() == parametros[1]) {
                         *reserva = (*it)->getReserva();
                         redirecionaInfos("Restore efetuado com sucesso!");
                         return "oi";

                     }
                }
            }
            break;
        }
        case 20: { //"load", "<nome-do-ficheiro>"
            if((parametros.size() != 2))
                break;
        }
        case 21: { //"slide", "<direcao> <linhas/colunas>"
            if((parametros.size() != 3) || !isNumber(parametros[2]))
                break;
        }
        case 22: { //"SCoelho", "<saudeInicial>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 23: { //"SOvelha", " <saudeInicial> "
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 24: { //"SLobo", " <saudeInicial> "
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 25: { //"SCanguru", "<saudeInicial>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;

        }
        case 26: { //"VCoelho", "<duracaoDeVida>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 27: { //"VOvelha", "<duracaoDeVida>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 28: { //"VCanguru", "<duracaoDeVida>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 29: { //"VRelva", "<validade>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 30: { //"VLobo", "instantes"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 31: { //"historico", "id"
            if((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                if(!veioDoFicheiro) {
                    redirecionaInfos(reserva->obtemHistorico(stoi(parametros[1])));
                    return "oi";
                }else{
                    redirecionaInfos2(reserva->obtemHistorico(stoi(parametros[1])));
                    return "oi";
                }
            }
            break;
        }
        case 32: { //"SDragao", "<SaudeInicial>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 33: { //"VDragao", "<instantes>"
            if ((parametros.size() != 2) || !isNumber(parametros[1]))
                redirecionaInfos("Erro na introducao do comando!");
            else {
                redirecionaInfos(reserva->setConstantes(parametros[0], stoi(parametros[1])));
                return "oi";
            }
            break;
        }
        case 34: { //"exit", ""
            if (parametros.size() != 1)
                redirecionaInfos("Erro na introducao do comando!");

            else if(veioDoFicheiro)
                return "Exit";

            exitPrograma();
            break;
        }
    }
    return "oi";
}

bool Interface::isNumber(const string &str) {

    for (char const &ch : str) {
        if (isdigit(ch) == 0)
            return false;
    }
    return true;
}

void Interface::exitPrograma() {
    exit(0);
}

void Interface::iniciarReserva(const int &l, const int &c) {
    Reserva *aux = new Reserva();
    reserva = aux;

    reserva->setNL(l+1);
    reserva->setNC(c+1);

    reserva->criaReserva();
}

void Interface::terminal() {

    t = new Terminal();

    t->init_color(1,COLOR_BLACK, 0);
    t->init_color(2,COLOR_RED, 0);
    t->init_color(3,COLOR_BLUE, 0);
    t->init_color(4,COLOR_GREEN, 0);

    *t << move_to(0, 0) ;
    //*t << resize_term(reserva.getNL(),120);
    //posiçoes iniciais da area visivel
    x = 0; // y do CSE
    y = 0; // x do CSE
    int width1 = 50;
    int height1 = 12;

    if (reserva->getNC() < width1)
        width1 = reserva->getNC()+3;

    reserva->setWAreaVisivel(width1-3);
    reserva->setHAreaVisivel(height1-2);

    string str_in;

    do {
        reserva->setXAreaVisivel(x);
        reserva->setYAreaVisivel(y);

        *t << move_to(1,0) ;
        *t  <<  set_color(4) << "- Simulador Reserva -\n" << set_color(1);

        Window window = Window(0, 1, width1, height1);
        window << set_color(3) << move_to(0,0);

        window << printAreaVisivel(); //passar w h

        Window windowInfo = Window(0, 16, 50, 8);
        windowInfo << set_color(3) << move_to(0, 0);

        *t << move_to(1,15) ;
        *t  <<  set_color(4) << "- Informacao Simulador -\n" << set_color(1);

        windowInfo << move_to(1,18) ;
        windowInfo  <<  set_color(3) << " CSE(" << y << "," << x << ") CSD(" << y << "," << x+width1-4 << ")" << set_color(1);

        windowInfo << move_to(1,19) ;
        windowInfo  <<  set_color(3) << " CIE(" << y+height1-3 << "," << x << ") CID(" << y+height1-3 << "," << x+width1-4 << ")\n" << set_color(1);

        windowInfo << move_to(1,20) ;
        windowInfo  <<  set_color(3) << "\n Instancia:            " << reserva->getContInstancia() << "\n" << set_color(1);

        windowInfo << move_to(1,21) ;
        windowInfo  <<  set_color(3) << " Animais vivos:        " << reserva->getContAnimal() << "\n" << set_color(1);

        windowInfo << move_to(1,22) ;
        windowInfo  <<  set_color(3) << " Alimentos existentes: " << reserva->getContAlimento() << "\n" << set_color(1);

        Window windowInput = Window(73, 0, 45, 3);
        windowInput << set_color(3) << move_to(0, 0);

        windowInput << move_to(80, 0) << "";
        windowInput << set_color(3) << "Introduza um comando: " ;
        windowInput >> str_in;

        if(str_in == "exit")
            exitPrograma();

        if(str_in.size()>=1 && str_in != "KEY_UP" && str_in != "KEY_DOWN" && str_in != "KEY_LEFT" && str_in != "KEY_RIGHT") {
            leDoTeclado(str_in);
            continue;
        }

        if (str_in == "KEY_UP") {
            if( y>0 ) y--;
            reserva->setXAreaVisivel(y);
            continue;
        }
        if (str_in == "KEY_DOWN") {
            if( y<reserva->getNC()-reserva->getHAreaVisivel() ) y++;
            reserva->setXAreaVisivel(y);
            continue;
        }
        if (str_in == "KEY_LEFT") {
            if( x>0 ) x--;
            reserva->setXAreaVisivel(x);
            continue;
        }
        if(width1 >= 50) {
            if (str_in == "KEY_RIGHT") {
                if (x < reserva->getNL() - reserva->getWAreaVisivel()) x++;
                reserva->setXAreaVisivel(x);
                continue;
            }
        }
    } while(true);
}

string Interface::printAreaVisivel() {
    return reserva->mostraReservaVisivel();
}

void Interface::redirecionaInfos(string txt) {

    Window w2 = Window(73, 3, 45, 27);
    w2 << set_color(4) << move_to(0, 0);

    string s;
    w2 << txt;
    w2 >> s;

}

void Interface::redirecionaInfos2(string txt) {

    Window w2 = Window(73, 3, 45, 27);
    w2 << set_color(4) << move_to(0, 0);

    string s;
    w2 << txt;
}

void Interface::mostraEcra(int i) {
    t->init_color(1,COLOR_BLACK, 0);
    t->init_color(2,COLOR_RED, 0);
    t->init_color(3,COLOR_BLUE, 0);
    t->init_color(4,COLOR_GREEN, 0);

    Window window = Window(0, 1, width, height);
    window << set_color(3) << move_to(0,0);

    window << printAreaVisivel(); //passar w h

    Window windowInfo = Window(0, 16, 50, 8);
    windowInfo << set_color(3) << move_to(0, 0);

    *t << move_to(1,15) ;
    *t  <<  set_color(4) << "- Informacao Simulador -\n" << set_color(1);

    windowInfo << move_to(1,18) ;
    windowInfo  <<  set_color(3) << " CSE(" << y << "," << x << ") CSD(" << y << "," << x+width-4 << ")" << set_color(1);

    windowInfo << move_to(1,19) ;
    windowInfo  <<  set_color(3) << " CIE(" << y+height-3 << "," << x << ") CID(" << y+height-3 << "," << x+width-4 << ")\n" << set_color(1);

    windowInfo << move_to(1,20) ;
    windowInfo  <<  set_color(3) << "\n Instancia:            " << reserva->getContInstancia() << "\n" << set_color(1);

    windowInfo << move_to(1,21) ;
    windowInfo  <<  set_color(3) << " Animais vivos:        " << reserva->getContAnimal() << "\n" << set_color(1);

    windowInfo << move_to(1,22) ;
    windowInfo  <<  set_color(3) << " Alimentos existentes: " << reserva->getContAlimento() << "\n" << set_color(1);


    if (i == 0) {
        string s;
        windowInfo >> s;

    }else {
        this_thread::sleep_for(chrono::milliseconds((i * 1000)));
    }
}


