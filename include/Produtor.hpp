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
        virtual void imprimeNoArquivo(std::ofstream &outfile) = 0;
        virtual void carregaArquivo(std::ifstream &infline) = 0; 
        void imprimeProdutosDesenvolvidos();

        std::string getBiografia();
        std::vector<Midia *> getProdutosDesenvolvidos();
        void setBiografia(std::string);
        void criaProduto();
};