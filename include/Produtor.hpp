#pragma once
#include "Usuario.hpp"
#include "Midia.hpp"
#include <vector>
#include <string>

class Produtor: protected Usuario {
    protected:
        std::vector<Midia *> produtos;
    public:
        int qtdFav;
        
        Produtor();
        Produtor(std::string _nome, int codigo);

        //Printers
        // virtual void imprimeNoArquivo(std::ofstream &outfile);  
        void imprimeProdutosDesenvolvidos();

        //Insert/remove
        void addProduto(Midia * item);
        void delProduto(Midia * item);

        //Getters
        std::string getNome();
        int getId();
        std::vector<Midia *> getProdutosDesenvolvidos();

        inline bool operator < (const Produtor &obj) const{
            return (nome.compare(obj.nome) < 0);
        }

        inline bool operator > (const Produtor &obj) const{
            return (nome.compare(obj.nome) > 0);
        }

        inline bool operator == (const Produtor &obj) const{
            return (nome.compare(obj.nome) == 0);
        }
};