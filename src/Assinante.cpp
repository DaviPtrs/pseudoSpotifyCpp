#include <iostream>
#include "Assinante.hpp"
#include "Usuario.hpp"
#include "utils.hpp"
#include "colors.hpp"

using namespace std;

Assinante::Assinante() {}

Assinante::Assinante(string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    cout << YEL("Assinante ") << codigo << YEL(" criado!") << endl;
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

void Assinante::inserirFavorito(Midia* favorito){
    insert_sort(this->favoritos, favorito);
    favorito->fav();
    cout << GRN("Midia id:") << favorito->getId() << GRN(" adicionada aos favoritos de usuario id:") << this->getId() << endl;
}

void Assinante::removerFavorito(Midia* favorito){
    vector<Midia *>::iterator it;
    it = find(this->favoritos.begin(), this->favoritos.end(), favorito);
    if(it != this->favoritos.end()){
        this->favoritos.erase(it);
    }else{
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    }
    favorito->unfav();
}