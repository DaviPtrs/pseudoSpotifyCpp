#include <iostream>
#include "Assinante.hpp"
#include "Usuario.hpp"

using namespace std;

Assinante::Assinante() {
    cout << "Assinante generico criado!" << endl;
}

Assinante::Assinante(string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    cout << "Assinante " << codigo << "criado!" << endl;
}

string Assinante::getNome(){
    return this->nome;
}

vector <Midia*> Assinante::getFavoritos(){
    return this->favoritos;
}

int Assinante::getId(){
    return this->codigo;
}