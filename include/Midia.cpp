#include "Midia.hpp"

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