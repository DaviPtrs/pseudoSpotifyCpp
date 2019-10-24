#include "Podcast.hpp"
#include "Podcaster.hpp"
#include "utils.hpp"

Podcast::Podcast(){}

Podcast::Podcast(std::string nome, int codigo, std::string gen, int qtdTemp){
    this->setTipo('P');
    this->nome = nome;
    this->codigo = codigo;
    this->qtdTemporadas = qtdTemp;
    Midia::Genero temp; //cria um objeto genero temporario
    temp.setSigla(gen);
    this->setGenero(&temp);
}

void Podcast::addPodcaster(Produtor *p){
    this->podcasters.push_back((Podcaster *)p);
}

vector<Podcast::Podcaster *> Podcast::getPodcasters(){
    return this->podcasters;
}

int Podcast::getQtdTemporadas(){
    return this->qtdTemporadas;
}
