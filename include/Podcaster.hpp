#pragma once
#include "Produtor.hpp"
#include "Podcast.hpp"

class Podcaster: public Produtor{
    public:
        Podcaster();
        void imprimeNoArquivo(std::ofstream &outfile); 
        void carregaArquivo(std::ifstream &infline); 
};