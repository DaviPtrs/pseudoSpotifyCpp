#include "string"
#include <iostream>
#include <vector>
#include "Musica.hpp"
#include "Artista.hpp"
#pragma once

class Album {
    private:
        std::string nome;
        int duracao;
        int anoLancamento;
        int qtdMusicas;
        vector<Musica *> faixas;
        Artista *artista;
    public:
        Album();
        Album(std::string nome, int duracao, int ano, int qtd);
        void imprimeNoArquivo(std::ofstream &outfile);
        vector<Musica *> getFaixas();
        Artista *getArtista();
};