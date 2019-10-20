#include <iostream>
#include "Assinante.hpp"
#include "Usuario.hpp"

using namespace std;

Assinante::Assinante() {}

Assinante::Assinante(string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    cout << "Assinante " << codigo << "criado!" << endl;
}

// void Assinante::imprimeFavoritos(){

// }

// void Assinante::inserirFavorito(Midia* favorito){

// }

// void Assinante::removerFavorito(){

// }

// void Assinante::imprimeNoArquivo(std::ofstream &outfile){

// }

// void Assinante::carregaArquivo(std::ifstream &infline){

// }

string Assinante::getNome(){
    return this->nome;
}

vector <Midia*> Assinante::getFavoritos(){
    return this->favoritos;
}

int Assinante::getId(){
    return this->codigo;
}