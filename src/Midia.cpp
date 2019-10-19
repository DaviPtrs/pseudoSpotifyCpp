#include "Midia.hpp"

int Midia::qtdProdutos = 0;

Midia::Midia() {
    this->qtdProdutos++;
}

Midia::Midia(std::string nome, bool explicito, std::string genero) {
    this->qtdProdutos++;
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


void Midia::Genero::setNome(std::string nome)
{
    this->nome = nome;
}


void Midia::Genero::setSigla(std::string sigla)
{
    this->sigla = sigla;
}

// static void Midia::imprimeQtdProdutos(){

// }

Midia::Genero* Midia::getGenero(){
    
}

std::string Midia::getNome(){
    
}

bool Midia::isExplicit(){
    return this->explicito;
}