cmake_minimum_required(VERSION 3.23)
project(SimuladorReservaNatural)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimuladorReservaNatural main.cpp
        Reserva/Reserva.cpp Reserva/Reserva.h
        Animais/Animal.cpp Animais/Animal.h
        Alimentos/Alimento.cpp Alimentos/Alimento.h
        Comandos/Comandos.cpp Comandos/Comandos.h
        Interface/Interface.cpp Interface/Interface.h
        Terminal/Terminal.cpp Terminal/Terminal.h curses.h
        Inicio/Iniciar.cpp Inicio/Iniciar.h
        Animais/Coelho.h
        Animais/Lobo.h
        Animais/Ovelha.h
        Animais/Canguru.h
        Alimentos/Relva.h
        Alimentos/Cenoura.h
        Alimentos/Corpo.h
        Alimentos/Bife.h
        Historico/Historico.cpp Historico/Historico.h
        Alimentos/Batata.h
        Animais/Dragao.h
        Alimentos/OvoDragao.h Store/Store.h)

target_link_libraries(${PROJECT_NAME} D:/Documentos/I.S.E.C/POO/POO_SECONDTRY/PDCurses-3.9/PDCurses-3.9/wincon/pdcurses.a)