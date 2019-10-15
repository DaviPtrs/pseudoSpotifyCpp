#pragma once
#include "Midia.hpp"

using namespace std;

class Podcast:public Midia {
    class Podcaster;
    private:
        int qtdTemporadas;
    public:
        Podcast();
        Podcast(string nome, bool explicito, string gen, int qtdTemp);
        void imprimeInfoProduto();
        void imprimeNoArquivo(std::ofstream &outfile);
        
        int getQtdTemportadas();
        Podcaster *getPodcaster();
        void setQtdTemportadas(int);
};