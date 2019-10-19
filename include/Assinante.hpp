#pragma once
#include <string>
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>

class Assinante:protected Usuario {
    private:
        std::vector<Midia *> favoritos;
    public:
        Assinante();
        Assinante(std::string _nome);

        //Insert/Remove
        void inserirFavorito(Midia* favorito);
        void removerFavorito();

        //Printers
        void imprimeFavoritos();
        virtual void imprimeNoArquivo(std::ofstream &outfile);

        //Getters
        std::vector <Midia*> getFavoritos();
        std::string getNome();
        
        //Operators
        bool operator < (const Assinante obj) const{
            return (nome.compare(obj.nome) < 0);
        }
};