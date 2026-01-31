cmake_minimum_required(VERSION 4.1)
project(ExamenC__)

set(CMAKE_CXX_STANDARD 20)

add_executable(ExamenC__ main.cpp
        Personnes.cpp
        Personnes.h
        Tissu.cpp
        Tissu.h
        Commande.cpp
        Commande.h
        habilleTermine.cpp
        habilleTermine.h
        Atelier.cpp
        Atelier.h)
