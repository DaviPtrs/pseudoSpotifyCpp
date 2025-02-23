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
        void removerFavorito(Midia* favorito);
        bool favExists(Midia* favorito);

        //Printers
        void imprimeFavoritos();

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
        inline bool operator == (const Assinante &obj) const{
            return (this->codigo == obj.codigo);
        }
};