#pragma once
#include <string>
#include <iostream>

class Midia {
    public:
        class Genero{
            private:
                std::string nome;
                std::string sigla;
            public:
                Genero();
                Genero(std::string nome, std::string sigla);

                //Getters
                std::string getNome();
                std::string getSigla();

                //Setters
                void setNome(std::string nome);
                void setSigla(std::string sigla);
        };
        Midia();
        Midia(std::string nome, int codigo, std::string genero);

        static int qtdProdutos;

        //Printers
        // virtual void imprimeInfoMidia() = 0; 
        // virtual void imprimeNoArquivo(std::ofstream &outfile) = 0;
        static void imprimeQtdProdutos(); 
        std::string formataDuracao();

        //Getters
        Genero* getGenero();
        std::string getNome();
        int getId();

        //Setters
        void setGenero(Midia::Genero*);
        void setDuracao(int n);
        void setAnoLancamento(int n);

        //Operators
        inline bool operator < (const Midia &obj) const{
            return (this->codigo < obj.codigo);
        }
        inline bool operator > (const Midia &obj) const{
            return (this->codigo > obj.codigo);
        }
        inline bool operator == (const Midia &obj) const{
            return (this->codigo == obj.codigo);
        }
    protected:
        std::string nome;
        int codigo;
        float duracao;
        int anoLancamento;
        Genero *genero;
};