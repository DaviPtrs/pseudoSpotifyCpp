#pragma once
#include <string>
#include "Midia.hpp"

using namespace std;

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