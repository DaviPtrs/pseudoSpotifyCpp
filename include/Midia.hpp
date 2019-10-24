#pragma once
#include <string>
#include <iostream>
#include <vector>
class Midia {
    public:
        class Genero{
            private:
                std::string nome;
                std::string sigla;
                std::vector<Midia*> midias;
            public:
                Genero();
                Genero(std::string nome, std::string sigla);

                //Insert/remove
                void addMidia(Midia * m);

                //Getters
                std::string getNome();
                std::string getSigla();
                int getQtdMidia();
                int getMinsGen();

                //Setters
                void setNome(std::string nome);
                void setSigla(std::string sigla);
        };
        Midia();
        Midia(std::string nome, int codigo, std::string genero);

        static int qtdProdutos;

        //Printers
        static void imprimeQtdProdutos();
        std::string formataDuracao();

        //Getters
        Genero* getGenero();
        std::string getNome();
        int getId();
        char getTipo();
        float getDuracao();
        int getAnoLancamento();
        void fav();
        void unfav();
        int getFavs();

        //Setters
        void setGenero(Midia::Genero*);
        void setDuracao(float n);
        void setAnoLancamento(int n);
        void setTipo(char);

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
        int tipo;
        int codigo;
        float duracao;
        int anoLancamento;
        Genero *genero;
        int favQtd;
};