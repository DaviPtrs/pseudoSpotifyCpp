#pragma once
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include "string"

class Produtor: protected Usuario {
    protected:
        std::string biografia; 
        std::vector<Midia *> produtos;
    public:
        Produtor();
        Produtor(std::string _nome);
        void imprimeNoArquivo(std::ofstream &outfile);  
        void imprimeProdutosDesenvolvidos();

        std::string getBiografia();
        std::vector<Midia *> getProdutosDesenvolvidos();
        void setBiografia(std::string);
        void criaProduto();
};