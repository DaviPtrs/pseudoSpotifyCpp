#include "PlataformaDigital.hpp"
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include <vector>
#include <fstream>
#include <iostream>
// #include<stdio.h>
// #include<ctype.h>
// #include<stdlib.h>
#include <unistd.h>

using namespace std;

class Paths{
    public:
        string Users;
        string Gens;
        string Favs;
        string Tracks;
};

Paths getPaths(int argc, char **argv){
    if(argc != 9){
        cout << "CERTIFIQUE-SE DE QUE TODAS AS FLAGS ESTÃO SENDO PASSADAS!\n";
        if(argc == 1){
            cout << "INSTRUÇÕES DE USO: \n -g : Path do arquivo de gêneros \n -u : Path do arquivo de usuários b \n -m: Path do arquivo de mídias \n -f: Path do arquivo de favoritos \n";
        }
        exit(1);
    }

    Paths x;
    int opt;
    while ((opt = getopt(argc,argv,"g:u:m:f:")) != EOF){
        switch(opt){
            case 'g': 
                x.Gens = (string)optarg;
                break;
            case 'u': 
                x.Users = (string)optarg;
                break;
            case 'm': 
                x.Tracks = (string)optarg;
                break;
            case 'f': 
                x.Favs = (string)optarg;
                break;
            case '?': 
                cout << "INSTRUÇÕES DE USO: \n -g : Path do arquivo de gêneros \n -u : Path do arquivo de usuários b \n -m: Path do arquivo de mídias \n -f: Path do arquivo de favoritos \n";
                exit(1);
            default: 
                cout<<endl; 
                exit(1);
        }   
    }

    return x;
}

int main(int argc, char **argv){
    // Paths p = getPaths(argc, argv);

    PlataformaDigital *soundcorno = new PlataformaDigital();
    ifstream file;
    file.open("tests/generos.csv");
    // file.open(p.Gens);
    soundcorno->carregaArquivoGenero(file);
    // soundcorno->imprimeListaGenero();

    file.open("tests/usuarios.csv");
    // file.open(p.Users);
    soundcorno->carregaArquivoUsuario(file);
    // soundcorno->imprimeAssinantes();
    // soundcorno->imprimeProdutores();

    file.open("tests/midias.csv");
    // file.open(p.Tracks);
    soundcorno->carregaArquivoMidia(file);

    // Free na porra toda
    soundcorno->wipeAll();
    delete soundcorno;

    return 0;
}