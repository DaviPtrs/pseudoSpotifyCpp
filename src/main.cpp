#include "PlataformaDigital.hpp"
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
int main(){
    PlataformaDigital *soundcorno = new PlataformaDigital();
    ifstream file;
    file.open("tests/generos.csv");
    soundcorno->carregaArquivoGenero(file);
    // file.clear();
    // soundcorno->imprimeListaGenero();

    file.open("tests/usuarios.csv");
    soundcorno->carregaArquivoUsuario(file);
    soundcorno->imprimeAssinantes();
    return 0;
}