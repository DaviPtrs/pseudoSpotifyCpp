#include <iostream>
#include "Assinante.hpp"
#include "Usuario.hpp"

using namespace std;

// Assinante::Assinante() {

// }

// Assinante::Assinante(string _nome) {

// }

void Assinante::imprimeFavoritos(){

}

void Assinante::inserirFavorito(Midia* favorito){

}

void Assinante::removerFavorito(){

}

// void Assinante::imprimeNoArquivo(std::ofstream &outfile){

// }

// void Assinante::carregaArquivo(std::ifstream &infline){

// }

std::string Assinante::getNome(){
    return this->nome;
}

std::vector <Midia*> Assinante::getFavoritos(){
    return this->favoritos;
}
