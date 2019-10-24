#include "Musica.hpp"

Musica::Musica() {}

Musica::Musica(std::string nome, int codigo, std::string gen, float duracao, int ano){
    this->setTipo('M');
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = ano;
    Midia::Genero temp; //cria um objeto genero temporário
    temp.setSigla(gen);
    this->setGenero(&temp);
}