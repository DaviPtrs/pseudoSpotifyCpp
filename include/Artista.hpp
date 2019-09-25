#include "Produtor.hpp"
#pragma once

class Artista:public Produtor {
    public:
        Artista();
        void imprimeNoArquivo(ofstream &outfile); //Italico
        void carregaArquivo(ifstream &infline); //Italico
};