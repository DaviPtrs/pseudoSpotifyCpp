#include "Midia.hpp"
// #include "Podcaster.hpp"
#pragma once

class Podcast:public Midia {
    private:
        int qtdTemporadas;
    public:
        Podcast();
        Podcast(std::string nome, bool explicito, std::string gen, int qtdTemp);
        void imprimeInfoProduto();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infile);  
        int getQtdTemportadas();
        Podcaster *getPodcaster();
};