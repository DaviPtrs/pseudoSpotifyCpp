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

        //Printers
        virtual void imprimeNoArquivo(std::ofstream &outfile);  
        void imprimeProdutosDesenvolvidos();

        //Getters
        std::vector<Midia *> getProdutosDesenvolvidos();
};