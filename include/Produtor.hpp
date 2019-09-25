#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include "string"
#pragma once

using namespace std;

class Produtor: protected Usuario {
    protected:
        string biografia; //Virtual? // Italico
        vector<Midia *> produtos;
    public:
        Produtor();
        Produtor(string _nome);
        void criaProduto();
        void imprimeProdutosDesenvolvidos();
        //vector<Midia *> getProdutosDesenvolvidos();
        void imprimeNoArquivo(ofstream &outfile); //Italico
        void carregaArquivo(ifstream &infline); //Italico
};