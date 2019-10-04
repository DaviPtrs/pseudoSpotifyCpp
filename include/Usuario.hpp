#include <string>
#pragma once

class Usuario {
    protected:
        std::string nome;
        int codigo;
        void imprimeNoArquivo(std::ofstream &outfile);
};