#pragma once
#include "Midia.hpp"
#include <string>

class Musica:public Midia{
    public:
        Musica();
        Musica(std::string nome, std::string gen, int duracao, int ano);

        //Printers
        void imprimeInfoProduto();
        // virtual void imprimeNoArquivo(std::ofstream &outfile);

        //Getters
        int getAnoLancamento();    
        int getDuracao();
};