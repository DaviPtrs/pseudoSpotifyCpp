#include "Album.hpp"
#include "Midia.hpp"
#include <string>
#include <iostream>
#include "utils.hpp"
#include "colors.hpp"

using namespace std;

Album::Album() {
    cout << RED("Album generico criado!") << endl;
}

Album::Album(string nome, int codigo, float duracao, int ano, int qtd){
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = ano;
    this->qtdMusicas = qtd;

    cout << CYN("Album (id.:") << codigo << CYN(") criado!") << endl;
}

void Album::addFaixa(Musica *faixa){
    insert_sort(this->faixas, faixa);
    cout << faixa->getNome() << MAG(" inserida no album ") << this->nome << endl;
}

void Album::delFaixa(Musica *faixa){
    int tam = this->faixas.size();
    for(int i = 0; i<tam; i++){
        Musica *obj = this->faixas[i];
        if(*faixa == *obj){
            this->faixas.erase(this->faixas.begin() + i);
            cout << faixa->getNome() << " removida do album " << this->nome << endl;
        }
    }
    inputError();
}

int Album::getId(){
    return this->codigo;
}

std::vector<Musica *> Album::getFaixas(){
    return this->faixas;
}

Artista* Album::getArtista() {
    return this->artista;
}

int Album::getQtdMusicas() {
    return this->qtdMusicas;
}

int Album::getAnoLancamento() {
    return this->anoLancamento;
}

int Album::getDuracao() {
    return this->duracao;
}

std::string Album::getNome() {
    return this->nome;
}

bool Album::isMusicIn(Musica * obj){
    for(Musica *m: this->faixas){
        if(m->getId() == obj->getId()){
            return true;
        }
    }
    return false;
}

void Album::setArtista(Artista* artista) {
    this->artista = artista;
}

void Album::setQtdMusicas(int qtdMusicas) {
    this->qtdMusicas = qtdMusicas;
}

void Album::setAnoLancamento(int anoLancamento) {
    this->anoLancamento = anoLancamento;
}

void Album::setDuracao(float duracao) {
    this->duracao = duracao;
}

void Album::setNome(std::string nome) {
    this->nome = nome;
}