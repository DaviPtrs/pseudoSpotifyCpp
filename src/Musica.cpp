#include "Musica.hpp"

Musica::Musica() {

}

Musica::Musica(std::string nome, int codigo, std::string gen, float duracao, int ano){
    this->setTipo(0);
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = ano;
    Midia::Genero temp;
    temp.setSigla(gen);
    this->setGenero(&temp);
}

// Musica::~Musica() {

// }

// void Musica::formataDuracao(){

// }

// void Musica::imprimeInfoProduto(){

// }

// void Musica::imprimeNoArquivo(std::ofstream &outfile){

// }

// int Musica::getAnoLancamento(){

// }    

// int Musica::getDuracao(){

// }