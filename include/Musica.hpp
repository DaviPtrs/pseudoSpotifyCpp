#pragma once
#include "Midia.hpp"
#include <string>

class Musica:public Midia{
    public:
        Musica();
        Musica(std::string nome, std::string gen, int duracao, int ano);
        void imprimeInfoProduto();
        void imprimeNoArquivo(std::ofstream &outfile);
        int getAnoLancamento();    
        int getDuracao();
};