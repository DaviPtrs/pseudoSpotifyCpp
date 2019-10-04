#include "PlataformaDigital.hpp"

void PlataformaDigital::carregaArquivoGenero(std::ifstream &infline)
{
    std::string sigla;
    std::string nome;
    while(!infile.eof())
    {
        getline(infile, sigla, ';');
        getline(infile, nome);
        this->ListaGeneros.push_back(new Midia::Genero(sigla, nome));
    }

}
