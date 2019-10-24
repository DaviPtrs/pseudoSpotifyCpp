#pragma once
#include <string>

class Usuario {
    protected:
        std::string nome;
        int codigo;
    public:
        Usuario();
        Usuario(std::string _nome, int codigo);
};