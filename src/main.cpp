#include "PlataformaDigital.hpp"
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include "colors.hpp"
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
        cout << RED("CERTIFIQUE-SE DE QUE TODAS AS FLAGS ESTÃO SENDO PASSADAS!\n");
        if(argc == 1){
            cout << GRN("INSTRUÇÕES DE USO: \n -g : Path do arquivo de gêneros \n -u : Path do arquivo de usuários \n -m: Path do arquivo de mídias \n -f: Path do arquivo de favoritos \n");
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
                cout << GRN("INSTRUÇÕES DE USO: \n -g : Path do arquivo de gêneros \n -u : Path do arquivo de usuários \n -m: Path do arquivo de mídias \n -f: Path do arquivo de favoritos \n");
                exit(1);
            default: 
                cout<<endl; 
                exit(1);
        }   
    }
    return x;
}

//Checa se todos os arquivos estão com a quantidade correta de colunas 
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
                    cout << RED("Erro de formatação") << endl;
                    cout << GRN("Arquivo de generos") << endl;
                    cout << BLU(">> ") << line << endl;
                    exit(1);
                }
                break;
            case 'f':
                if(n != 1){
                    cout << RED("Erro de formatação") << endl;
                    cout << GRN("Arquivo de favoritos") << endl;
                    cout << BLU(">> ") << line << endl;
                    exit(1);
                }
                break;
            case 'm':
                if(n != 9){
                    cout << RED("Erro de formatação") << endl;
                    cout << GRN("Arquivo de midias") << endl;
                    cout << BLU(">> ") << line << endl;
                    exit(1);
                }
                break;
            case 'u':
                if(n != 2){
                    cout << RED("Erro de formatação") << endl;
                    cout << GRN("Arquivo de usuários") << endl;
                    cout << BLU(">> ") << line << endl;
                    exit(1);
                }
                break;
        }
    }
    infile.clear();
    infile.seekg(0);
}

int main(int argc, char **argv){
    Paths p = getPaths(argc, argv);

    PlataformaDigital *soundcorno = new PlataformaDigital("SOUNDCORNO");
    ifstream file;
    file.open(p.Gens);
    columnChecker(file, 'g');
    soundcorno->carregaArquivoGenero(file);

    file.open(p.Users);
    columnChecker(file, 'u');
    soundcorno->carregaArquivoUsuario(file);

    file.open(p.Tracks);
    columnChecker(file, 'm');
    soundcorno->carregaArquivoMidia(file);

    file.open(p.Favs);
    columnChecker(file, 'f');
    soundcorno->carregaArquivoFavoritos(file);

    //Relatorios e saidas    
    soundcorno->exportarBiblioteca();
    soundcorno->gerarRelatorios();
    
    // Free na p**** toda
    soundcorno->wipeAll();
    delete soundcorno;
    return 0;
}