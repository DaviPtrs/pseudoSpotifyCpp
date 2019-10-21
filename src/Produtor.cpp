#include "Produtor.hpp"
#include "utils.hpp"
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

void Produtor::addProduto(Midia * item){
    insert_sort(this->produtos, item);
}

void Produtor::delProduto(Midia * item){
    for(unsigned int i = 0; i<this->produtos.size(); i++){
        Midia *temp = this->produtos[i];
        if(*temp == *item){
            this->produtos.erase(this->produtos.begin() + i);
            cout << "Midia \"" << item->getNome() << "\" removida!\n";
        }
    }
    cerr << "Inconsistências na entrada" << endl;
}