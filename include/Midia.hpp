#pragma once
#include <string>

class Midia {
    class Genero{
        private:
            std::string nome;
            std::string sigla;
        public:
            Genero();
            Genero(std::string nome, std::string sigla);
            std::string getNome();
            std::string getSigla();
    };

    private:
        bool explicito;
    protected:
        std::string nome;
        Genero *genero;
    public:
        static int qtdProdutos;
        Midia();
        Midia(std::string nome, bool explicito, std::string genero);
        static void imprimeQtdProdutos(); 
        virtual void imprimeInfoProduto() = 0;
        virtual void imprimeNoArquivo(std::ofstream &outfile) = 0;

        Genero* getGenero();
        std::string getNome();  
        bool isExplicit();
};