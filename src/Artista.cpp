#include "Artista.hpp"
#include <string>
#include <iostream>

using namespace std;

Artista::Artista() {
    cout << "Artista generico criado!" << endl;
}


Artista::Artista(std::string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    cout << "Artista " << codigo << " criado!" << endl;
}