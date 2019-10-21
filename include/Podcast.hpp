#pragma once
#include <vector>
#include <string>
#include "Midia.hpp"
#include "Produtor.hpp"

using namespace std;

class Podcast:public Midia {
    class Podcaster;
    private:
        int qtdTemporadas;
        vector<Podcaster *> podcasters;
    public:
        Podcast();
        Podcast(std::string nome, int codigo, std::string gen, int qtdTemp);

        // Printers
        void imprimeInfoProduto();
        // virtual void imprimeNoArquivo(std::ofstream &outfile);
        
        void addPodcaster(Produtor *p);

        // Getters
        int getQtdTemportadas();
        vector<Podcaster *> getPodcasters();
        void setQtdTemportadas(int);

};