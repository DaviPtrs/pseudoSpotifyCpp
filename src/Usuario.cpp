#include "Usuario.hpp"
#include <iostream>

using namespace std;

Usuario::Usuario(){}

Usuario::Usuario(std::string _nome, int codigo){
    this->nome = _nome;
    this->codigo = codigo;
    cout << "Usuario generico (id.:" << codigo << ") criado!" << endl;
}