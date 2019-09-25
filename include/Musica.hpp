#include "Midia.hpp"
#include "string"
#pragma once

class Musica:public Midia{
    private:
        int duracao;
        int anoLancamento;
        void formataDuracao();
    public:
        Musica();
        Musica(std::string nome, std::string gen, int duracao, int ano);
        void imprimeInfoProduto();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);
        int getAnoLancamento();    
        int getDuracao();
        
};