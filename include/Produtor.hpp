#pragma once
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include <string>

class Produtor: protected Usuario {
    protected:
        std::vector<Midia *> produtos;
    public:
        Produtor();
        Produtor(std::string _nome);
        void imprimeNoArquivo(std::ofstream &outfile);  
        void imprimeProdutosDesenvolvidos();
        std::vector<Midia *> getProdutosDesenvolvidos();
};