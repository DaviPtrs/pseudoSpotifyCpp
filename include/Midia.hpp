#pragma once
// #include <iostream>
// #include <string>

// using namespace std;

class Midia {
    private:
        bool explicito;
        void formataDuracao();
    public:
        class Genero{
            private:
                string nome;
                string sigla;
            public:
                Genero();
                Genero(string nome, string sigla);
                string getNome();
                string getSigla();
                void setNome(string nome);
                void setSigla(string sigla);
        };
        static int qtdProdutos;
        Midia();
        Midia(string nome, bool explicito, string genero);
        static void imprimeQtdProdutos(); 
        virtual void imprimeInfoMidia() = 0; 
        virtual void imprimeNoArquivo(ofstream &outfile) = 0;

        Genero* getGenero();
        string getNome();  
        bool isExplicit();
    protected:
        string nome;
        int codigo;
        float duracao;
        int anoLancamento;
        Genero *genero;
};