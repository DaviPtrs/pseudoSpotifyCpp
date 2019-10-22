#include "PlataformaDigital.hpp"
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
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


void columnChecker(std::ifstream &infile, char tipo){
    string line;
    while(!infile.eof()){
        int n = 0;
        getline(infile, line);
        if(!line.compare("")){
            break;
        }
        for(char c : line){
            if(c == ';'){
                n++;
            }
        }
        switch (tipo){
            case 'g':
                if(n != 1){
                    cout << "Erro de formatação" << endl;
                    cout << "Arquivo de generos" << endl;
                    cout << ">> " << line << endl;
                    exit(1);
                }
                break;
            case 'f':
                if(n != 1){
                    cout << "Erro de formatação" << endl;
                    cout << "Arquivo de favoritos" << endl;
                    cout << ">> " << line << endl;
                    exit(1);
                }
                break;
            case 'm':
                if(n != 9){
                    cout << "Erro de formatação" << endl;
                    cout << "Arquivo de midias" << endl;
                    cout << ">> " << line << endl;
                    exit(1);
                }
                break;
            case 'u':
                if(n != 2){
                    cout << "Erro de formatação" << endl;
                    cout << "Arquivo de usuários" << endl;
                    cout << ">> " << line << endl;
                    exit(1);
                }
                break;
        }
    }
    infile.clear();
    infile.seekg(0);
}

int main(int argc, char **argv){
    // Paths p = getPaths(argc, argv);

    PlataformaDigital *soundcorno = new PlataformaDigital();
    ifstream file;
    // // file.open(p.Gens);
    file.open("tests/set2/generos.csv");
    columnChecker(file, 'g');
    soundcorno->carregaArquivoGenero(file);
    // soundcorno->imprimeListaGenero();


    file.open("tests/set2/usuarios.csv");
    // file.open(p.Users);
    columnChecker(file, 'u');
    soundcorno->carregaArquivoUsuario(file);
    // soundcorno->imprimeAssinantes();
    // soundcorno->imprimeProdutores();

    file.open("tests/set2/midias.csv");
    // file.open(p.Tracks);
    columnChecker(file, 'm');
    soundcorno->carregaArquivoMidia(file);
    // soundcorno->imprimeMusicas();
    // soundcorno->imprimePodcasts();

    file.open("tests/set2/favoritos.csv");
    // file.open(p.Tracks);
    columnChecker(file, 'f');
    soundcorno->carregaArquivoFavoritos(file);
    soundcorno->estatisticas();

    // Free na porra toda
    soundcorno->wipeAll();
    delete soundcorno;

    return 0;
}