#pragma once
#include <string>

class Usuario {
    protected:
        std::string nome;
        int codigo;
        void imprimeNoArquivo(std::ofstream &outfile);
};