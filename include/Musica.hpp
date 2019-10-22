#pragma once
#include "Midia.hpp"
#include <string>

class Musica:public Midia{
    public:
        Musica();
        Musica(std::string nome, int codigo, std::string gen, float duracao, int ano);

        //Printers
        void imprimeInfoProduto();
        // virtual void imprimeNoArquivo(std::ofstream &outfile);

};