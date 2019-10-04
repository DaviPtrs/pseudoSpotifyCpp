#pragma once
#include <string>

class Midia {

    private:
        bool explicito;
    public:
        class Genero{
            private:
                std::string nome;
                std::string sigla;
            public:
                Genero();
                Genero(std::string nome, std::string sigla);
                std::string getNome();
                std::string getSigla();
            static int qtdProdutos;
        };
        Midia();
        Midia(std::string nome, bool explicito, std::string genero);
        static void imprimeQtdProdutos(); 
        virtual void imprimeInfoProduto() = 0; 
        virtual void imprimeNoArquivo(std::ofstream &outfile) = 0;

        Genero* getGenero();
        std::string getNome();  
        bool isExplicit();
        protected:
            std::string nome;
            Genero *genero;
};