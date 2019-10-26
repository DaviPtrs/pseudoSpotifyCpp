#include "Midia.hpp"
#include <string>
#include <iostream>

using namespace std;

int Midia::qtdProdutos = 0;

Midia::Midia() {
    this->tipo = -1;
    this->qtdProdutos++;
    this->favQtd = 0;
}

Midia::Genero::Genero() {}

Midia::Genero::Genero(string sigla, string nome)
{
    this->sigla = sigla;
    this->nome = nome;
}

string Midia::formataDuracao(){
    string result;
    int mins = 0, segs = 0;
    float swap = this->duracao;
    if(swap < 1){
        mins = 0;
    }else{
        mins = (int)swap;
        swap = swap - (float)mins;
    }
    segs = (int)((float)swap*60);

    if(mins != 0){
        result.append(to_string(mins));
        result.append(" Mins e ");
    }
    result.append(to_string(segs));
    result.append(" segs\n");
    
    return result;
}

void Midia::Genero::addMidia(Midia *m){
    this->midias.push_back(m);
}

int Midia::Genero::getQtdMidia(){
    return this->midias.size();
}

float Midia::Genero::getMinsGen(){
    float soma = 0;
    for(Midia *x: this->midias){
        soma += x->getDuracao();
    }
    return soma;
}

string Midia::Genero::getNome()
{
    return this->nome;
}

string Midia::Genero::getSigla()
{
    return this-> sigla;
}

char Midia::getTipo(){
    return this->tipo;
}

void Midia::setTipo(char t){
    this->tipo = t;
}

void Midia::Genero::setNome(string nome)
{
    this->nome = nome;
}

void Midia::Genero::setSigla(string sigla)
{
    this->sigla = sigla;
}

void Midia::setGenero(Midia::Genero* gen){
    this->genero = gen;
}

void Midia::setDuracao(float n){
    this->duracao = n;
}

void Midia::setAnoLancamento(int n){
    this->anoLancamento = n;
}

void Midia::imprimeQtdProdutos(){
    cout << "Quantidade de midias criadas: " << qtdProdutos << endl;
}

Midia::Genero* Midia::getGenero(){
    return this->genero;
}

string Midia::getNome(){
    return this->nome;
}

int Midia::getId(){
    return this->codigo;
}

float Midia::getDuracao(){
    return this->duracao;
}

int Midia::getAnoLancamento(){
    return this->anoLancamento;
}

void Midia::fav(){
    this->favQtd++;    
}

void Midia::unfav(){
    this->favQtd--;
}

int Midia::getFavs(){
    return this->favQtd;
}