#pragma once
#include "Midia.hpp"
#include "string"

class Musica:public Midia{
    private:
        int duracao;
        int anoLancamento;
        void formataDuracao();
    public:
        Musica();
        Musica(std::string nome, std::string gen, int duracao, int ano);
        void imprimeInfoProduto();
        void imprimeNoArquivo(std::ofstream &outfile);
        void carregaArquivo(std::ifstream &infile);
        int getAnoLancamento();    
        int getDuracao();
};