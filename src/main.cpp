#include "PlataformaDigital.hpp"
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
    PlataformaDigital *plataforma = new PlataformaDigital();
    ifstream file;
    file.open("tests/generos.csv");
    if(!(file.is_open()))
    {
        cout << "Erro ao abrir arquivo\n" ;
        return 0;
    }
    plataforma->carregaArquivoGenero(file);
    plataforma->imprimeListaGenero();
    return 0;

}