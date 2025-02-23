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

        //Insert/remove        
        void addPodcaster(Produtor *p);

        // Getters
        int getQtdTemporadas();
        vector<Podcaster *> getPodcasters();
};