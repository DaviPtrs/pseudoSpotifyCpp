#include "PlataformaDigital.hpp"
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include <vector>
#include <fstream>
#include <iostream>
int main()
{
    PlataformaDigital *plataforma = new PlataformaDigital();
    std::ifstream file;
    file.open("include/testes/generos.csv");
    if(!(file.is_open()))
    {
        return 0;
    }
    plataforma->carregaArquivoGenero(file);
    plataforma->imprimeListaGenero();
    return 0;

}