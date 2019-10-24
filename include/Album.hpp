#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Musica.hpp"
#include "Artista.hpp"

class Album {
    private:
        std::string nome;
        float duracao;
        int codigo;
        int anoLancamento;
        int qtdMusicas;
        Artista *artista;
        std::vector<Musica *> faixas;
    public:
        Album();
        Album(std::string nome, int codigo, float duracao, int ano, int qtd);

        //Insert/remove
        void addFaixa(Musica *faixa);
        void delFaixa(Musica *faixa);

        //Getters
        std::vector<Musica *> getFaixas();
        Artista *getArtista();
        int getQtdMusicas();
        int getAnoLancamento();
        int getDuracao();
        std::string getNome();
        int getId();
        bool isMusicIn(Musica *);

        //Setters
        void setArtista(Artista *);
        void setQtdMusicas(int qtdMusicas);
        void setAnoLancamento(int anoLancamento);
        void setDuracao(float duracao);
        void setNome(std::string nome);

};