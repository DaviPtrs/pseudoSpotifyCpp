#include "PlataformaDigital.hpp"
#include <fstream>
#include <iostream>

void PlataformaDigital::carregaArquivoGenero(std::ifstream &infile)
{
    std::string sigla;
    std::string nome;
    while(!(infile.eof()))
    {
        getline(infile, sigla, ';');
        getline(infile, nome);
        this->listaGeneros.push_back(new Midia::Genero(sigla, nome));
        
    }

    this->listaGeneros.pop_back();  // gambiarra bonita, gambiarra formosa;

}


void PlataformaDigital::imprimeListaGenero()
{
    for(int i = 0; i < this->listaGeneros.size(); i++)
    {
        std::cout<<this->listaGeneros[i]->getSigla()<<';';
        std::cout<<this->listaGeneros[i]->getNome()<<std::endl;
       // std::cout<<"to com fome"<< i <<std::endl;
    }
}

PlataformaDigital::PlataformaDigital()
{

}

PlataformaDigital::PlataformaDigital(std::string meupaudeoculos)
{

}