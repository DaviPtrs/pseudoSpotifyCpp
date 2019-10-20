#include "Podcast.hpp"
#include "Podcaster.hpp"

Podcast::Podcast() {

}

Podcast::Podcast(std::string nome, int codigo, std::string gen, int qtdTemp){
    this->nome = nome;
    this->codigo = codigo;
    this->qtdTemporadas = qtdTemp;
    Midia::Genero temp;
    temp.setSigla(gen);
    this->setGenero(&temp);
}
// void Podcast::imprimeInfoProduto(){

// }

// void Podcast::imprimeNoArquivo(std::ofstream &outfile){

// }

// int Podcast::getQtdTemportadas(){

// }

// Podcast::Podcaster *Podcast::getPodcaster(){

// }

// void Podcast::setQtdTemportadas(int){

// }
