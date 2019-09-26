#include "Produtor.hpp"
#include "Podcast.hpp"
#pragma once

class Podcaster: public Produtor{
    private:
        vector<Podcast *> podcasts;
    public:
        Podcaster();
        void imprimeNoArquivo(ofstream &outfile); //Italico
        void carregaArquivo(ifstream &infline); //Italico
};