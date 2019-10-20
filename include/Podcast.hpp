#pragma once
#include <string>
#include "Midia.hpp"

using namespace std;

class Podcast:public Midia {
    class Podcaster;
    private:
        int qtdTemporadas;
        Podcaster *podcaster;
    public:
        Podcast();
        Podcast(std::string nome, bool explicito, std::string gen, int qtdTemp);

        // Printers
        void imprimeInfoProduto();
        // virtual void imprimeNoArquivo(std::ofstream &outfile);
        
        // Getters
        int getQtdTemportadas();
        Podcaster *getPodcaster();
        void setQtdTemportadas(int);
};