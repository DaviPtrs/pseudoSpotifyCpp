#include "Podcast.hpp"
#include "Podcaster.hpp"
#include "../lib/utils.hpp"

Podcast::Podcast() {

}

Podcast::Podcast(std::string nome, int codigo, std::string gen, int qtdTemp){
    this->setTipo(1);
    this->nome = nome;
    this->codigo = codigo;
    this->qtdTemporadas = qtdTemp;
    Midia::Genero temp;
    temp.setSigla(gen);
    this->setGenero(&temp);
}

void Podcast::addPodcaster(Produtor *p){
    this->podcasters.push_back((Podcaster *)p);
}

vector<Podcast::Podcaster *> Podcast::getPodcasters(){
    return this->podcasters;
}

void Podcast::wipePodcasters(){
    for(unsigned int i = 0; i<this->podcasters.size(); i++){
        try{
            Podcaster *p = (Podcaster *)this->podcasters[i];
            if(p != NULL){
                delete p;
                this->podcasters[i] = NULL;      
            }
        }
        catch(const std::exception& e){
            this->podcasters[i] = NULL;      
        }
    }
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
