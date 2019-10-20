#include "Produtor.hpp"
#include <iostream>
#include <string>

using namespace std;

Produtor::Produtor() {
    cout << "Produtor criado generico criado!" << endl;
}

Produtor::Produtor(string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    cout << "Produtor " << codigo << "criado!" << endl;
}

string Produtor::getNome(){
    return this->nome;
}

int Produtor::getId(){
    return this->codigo;
}
