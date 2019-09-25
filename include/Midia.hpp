#include <string>
#pragma once

using namespace std;

class Midia {
    class Genero{
        private:
            string nome;
            string sigla;
        public:
            Genero();
            Genero(string nome, string sigla);
    };

    private:
        bool explicito;
    protected:
        string nome;
        Genero *genero;
    public:
        static int qtdProdutos;
        Midia();
        Midia(string nome, bool explicito, string genero);
        static void imprimeQtdProdutos(); // 
        virtual void imprimeInfoProduto() = 0;
        virtual void imprimeNoArquivo(ofstream &outfile) = 0;
        virtual void carregaArquivo(ifstream &infile) = 0;
};