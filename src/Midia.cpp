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


Midia::Genero::Genero(std::string sigla, std::string nome)
{
    this->sigla = sigla;
    this->nome = nome;
}

std::string Midia::Genero::getNome()
{
    return this->nome;
}

std::string Midia::Genero::getSigla()
{
    return this-> sigla;
}

int Midia::getTipo(){
    return this->tipo;
}

void Midia::setTipo(int n){
    this->tipo = n;
}


void Midia::Genero::setNome(std::string nome)
{
    this->nome = nome;
}


void Midia::Genero::setSigla(std::string sigla)
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

// static void Midia::imprimeQtdProdutos(){

// }

Midia::Genero* Midia::getGenero(){
    return this->genero;
}

string Midia::getNome(){
    return this->nome;
}

int Midia::getId(){
    return this->codigo;
}

void Midia::fav(){
    this->favQtd++;
}
void Midia::unfav(){
    this->favQtd--;
}