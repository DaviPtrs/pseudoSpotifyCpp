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
        Assinante(std::string _nome, int codigo);

        //Insert/Remove
        void inserirFavorito(Midia* favorito);
        void removerFavorito();

        //Printers
        void imprimeFavoritos();
        // virtual void imprimeNoArquivo(std::ofstream &outfile);

        //Getters
        std::vector <Midia*> getFavoritos();
        std::string getNome();
        int getId();
        
        //Operators
        inline bool operator < (const Assinante &obj) const{
            return (this->codigo < obj.codigo);
        }
        inline bool operator > (const Assinante &obj) const{
            return (this->codigo > obj.codigo);
        }
        // inline bool operator == (Assinante *obj){
        //     return (codigo == obj->codigo);
        // }
};