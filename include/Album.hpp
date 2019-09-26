#pragma once
#include "string"
#include <iostream>
#include <vector>
#include "Musica.hpp"
#include "Artista.hpp"

class Album {
    private:
        std::string nome;
        int duracao;
        int anoLancamento;
        int qtdMusicas;
        std::vector<Musica *> faixas;
        Artista *artista;
    public:
        Album();
        Album(std::string nome, int duracao, int ano, int qtd);
        void imprimeNoArquivo(std::ofstream &outfile);
        int addFaixa(Musica *faixa);
        Musica *delFaixa(Musica *faixa);

        vector<Musica *> getFaixas();
        Artista *getArtista();
        int getQtdMusicas();
        int getAnoLancamento();
        int getDuracao();
        std::string getNome();

        void setArtista(Artista *);
        void setQtdMusicas(int qtdMusicas);
        void setAnoLancamento(int anoLancamento);
        void setDuracao(int duracao);
        void setNome(std::string nome);
};