#include "Usuario.hpp"
#include <iostream>

using namespace std;

Usuario::Usuario(){
    cout << "Usuario generico criado!" << endl;
}

Usuario::Usuario(std::string _nome, int codigo){
    this->nome = _nome;
    this->codigo = codigo;
    cout << "Usuario (id.:" << codigo << ") criado!" << endl;
}