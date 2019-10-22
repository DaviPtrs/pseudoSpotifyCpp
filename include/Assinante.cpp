#include <iostream>
#include "Assinante.hpp"

using std::Assinante

Assinante();
Assinante(std::string _nome);
void imprimeFavoritos();
void inserirFavorito(Midia* favorito);
void removerFavorito();
std::vector <Midia*> getFavoritos();
void imprimeNoArquivo(std::ofstream &outfile);
void carregaArquivo(std::ifstream &infline);
