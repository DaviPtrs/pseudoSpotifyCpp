#pragma once
#include <string>

class Midia {
    private:
        bool explicito;
        void formataDuracao();
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
                void setNome(std::string nome);
                void setSigla(std::string sigla);
        };
        static int qtdProdutos;
        Midia();
        Midia(std::string nome, bool explicito, std::string genero);
        static void imprimeQtdProdutos(); 
        virtual void imprimeInfoMidia() = 0; 
        virtual void imprimeNoArquivo(std::ofstream &outfile) = 0;

        Genero* getGenero();
        std::string getNome();  
        bool isExplicit();
    protected:
        std::string nome;
        int codigo;
        float duracao;
        int anoLancamento;
        Genero *genero;
};