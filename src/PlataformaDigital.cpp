#include <iostream>
#include "PlataformaDigital.hpp"

PlataformaDigital::PlataformaDigital() {
    std::cout << "Objeto PlataformaDigital criado!\n";
}

PlataformaDigital::PlataformaDigital(std::string _nome) {
    this->nome = _nome;
    std::cout << "Objeto PlataformaDigital (" << _nome <<") criado!\n";
}

std::string PlataformaDigital::getNome(){
    return this->nome;
}

std::vector<Midia *> PlataformaDigital::getProdutosCadastrados(){
    return this->produtosCadastrados;
}

std::vector<Assinante *> PlataformaDigital::getAssinantes(){
    return this->assinantes;
}

void PlataformaDigital::imprimeProdutos(std::string genero){
    
}

void PlataformaDigital::imprimeAssinantes(){

}

void PlataformaDigital::inserirAssinante(Assinante *){

}

Assinante * PlataformaDigital::removerAssinante(std::string nome){

}

int PlataformaDigital::inserirProduto(Midia *novoProduto, std::string nomeProdutor){

}

int PlataformaDigital::selecionaAssinante(){

}

void PlataformaDigital::inserirProdutoAssinante(){

}

void PlataformaDigital::imprimeNoArquivo(std::ofstream &outfile){

}

void PlataformaDigital::carregaArquivo(std::ifstream &infline){

}

void PlataformaDigital::exportarBiblioteca(){

}

void PlataformaDigital::gerarRelatorios(){

}
