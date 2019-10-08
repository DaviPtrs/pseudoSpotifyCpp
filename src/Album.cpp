#include "Album.hpp"

Album::Album() {
    std::cout << "Objeto album criado!" << std::endl;
}

Album::Album(std::string nome, int duracao, int ano, int qtd){
    this->nome = nome;
    this->duracao = duracao;
    this->anoLancamento = ano;
    this->qtdMusicas = qtd;
    //Falta setar as musicas
}


void Album::imprimeNoArquivo(std::ofstream &outfile){

}

int Album::addFaixa(Musica *faixa){

}

Musica *Album::delFaixa(Musica *faixa){

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

void Album::setArtista(Artista* artista) {
    this->artista = artista;
}

void Album::setQtdMusicas(int qtdMusicas) {
    this->qtdMusicas = qtdMusicas;
}

void Album::setAnoLancamento(int anoLancamento) {
    this->anoLancamento = anoLancamento;
}

void Album::setDuracao(int duracao) {
    this->duracao = duracao;
}

void Album::setNome(std::string nome) {
    this->nome = nome;
}