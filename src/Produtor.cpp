#include "Produtor.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

using namespace std;

Produtor::Produtor() {
    this->qtdFav = 0;
}

Produtor::Produtor(string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    this->qtdFav = 0;
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
    inputError();
}

void Produtor::imprimeProdutosDesenvolvidos(){
    for(Midia *midia: this->produtos){
        if(midia->getTipo() == 'P'){
            cout << "Podcast ";
        }else{
            cout << "Musica ";
        }
        cout << "\"" << midia->getNome() << "\"" << endl;
    }
}

char Produtor::getTipo(){
    return this->tipo;
}

std::vector<Midia *> Produtor::getProdutosDesenvolvidos()
{
    return this->produtos;
}