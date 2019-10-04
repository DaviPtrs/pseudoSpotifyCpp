#pragma once
#include "Midia.hpp"

class Podcast:public Midia {
    class Podcaster;
    private:
        int qtdTemporadas;
    public:
        Podcast();
        Podcast(std::string nome, bool explicito, std::string gen, int qtdTemp);
        void imprimeInfoProduto();
        void imprimeNoArquivo(std::ofstream &outfile);
        
        int getQtdTemportadas();
        Podcaster *getPodcaster();
        void setQtdTemportadas(int);
};