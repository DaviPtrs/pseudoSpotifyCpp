#pragma once
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>

class Assinante:protected Usuario {
    private:
        std::vector<Midia *> favoritos;
    public:
        Assinante();
        Assinante(std::string _nome);
        ~Assinante();
        void imprimeFavoritos();
        void inserirFavorito(Midia* favorito);
        void removerFavorito();
        std::vector <Midia*> getFavoritos();
        void imprimeNoArquivo(std::ofstream &outfile);
        void carregaArquivo(std::ifstream &infline);

        std::string getNome();
};