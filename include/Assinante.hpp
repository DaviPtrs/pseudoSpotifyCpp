#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#pragma once

using namespace std;

class Assinante:protected Usuario {
    private:
        PlataformaDigital *plataforma;
    public:
        Assinante();
        Assinante(string _nome);
        ~Assinante();
        void imprimeFavoritos();
        void inserirFavorito(Midia* favorito);
        void removerFavorito();
        vector <Midia*> getFavoritos();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infline);
        PlataformaDigital *getPlataforma();
        void setPlataforma(PlataformaDigital *plataforma);
};