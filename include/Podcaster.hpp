#pragma once
#include <string>
#include <vector>
#include "Produtor.hpp"
#include "Podcast.hpp"

class Podcaster: public Produtor{
    public:
        Podcaster();
        Podcaster(std::string _nome, int codigo);
        // virtual void imprimeNoArquivo(std::ofstream &outfile); 

        
};