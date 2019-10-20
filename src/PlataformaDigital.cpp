#include <iostream>
#include <fstream>
#include "../lib/utils.hpp"
#include "PlataformaDigital.hpp"
#include "Podcaster.hpp"
#include "Artista.hpp"

using namespace std;



PlataformaDigital::PlataformaDigital() {
    cout << "Objeto PlataformaDigital criado!\n";
}

PlataformaDigital::PlataformaDigital(string _nome) {
    this->nome = _nome;
    cout << "Objeto PlataformaDigital (" << _nome <<") criado!\n";
}
void PlataformaDigital::imprimeAssinantes(){
    int tam = this->assinantes.size();
    cout << "=-=-=-=ASSINANTES-=-=-=-=\n";
    for(int i = 0; i<tam; i++){
        cout << this->assinantes[i]->getId()<< ", "<< this->assinantes[i]->getNome() << endl;
    }
    cout << "=-=-=-=ASSINANTES-=-=-=-=\n";
}

void PlataformaDigital::imprimeProdutores(){
    int tam = this->listaProdutor.size();
    cout << "=-=-=-=PRODUTORES-=-=-=-=\n";
    for(int i = 0; i<tam; i++){
        cout << this->listaProdutor[i]->getId()<< ", "<< this->listaProdutor[i]->getNome() << endl;
    }
    cout << "=-=-=-=PRODUTORES-=-=-=-=\n";
}

void PlataformaDigital::imprimeListaGenero()
{
    for(unsigned int i = 0; i < this->listaGeneros.size(); i++){
        cout<<this->listaGeneros[i]->getSigla()<<';';
        cout<<this->listaGeneros[i]->getNome()<<endl;
    }
}

void PlataformaDigital::inserirAssinante(Assinante * assinante){
    insert_sort(this->assinantes, assinante);
    cout << "Assinante \"" << assinante->getNome() << "\" inserido!\n";
}

Assinante * PlataformaDigital::removerAssinante(Assinante *obj){
    vector<Assinante *> *vet = &this->assinantes;
    int tam = vet->size();

    for(int i = 0; i<tam; i++){
        Assinante *temp = (*vet)[i]; //Nao sei se isso funciona
        if(*temp == *obj){
            vet->erase(vet->begin() + i);
            cout << "Assinante \"" << obj->getNome() << "\" removido!\n";
            return obj;
        }
    }
    cerr << "Assinante (id.:" << obj->getId() << ") nao encontrado!" << endl;
    return NULL;
}

void PlataformaDigital::inserirProdutor(Produtor *produtor){
    insert_sort(this->listaProdutor, produtor);
    cout << "Produtor \"" << produtor->getNome() << "\" inserido!\n";
}


void PlataformaDigital::carregaArquivoUsuario(std::ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro ao abrir arquivo de usuarios\n" ;
        exit(1);
    }

    string codigo;
    string tipo;
    string nome;

    getline(infile, nome); //Ignorando a primeira linha
    while(!infile.eof()){ 
        getline(infile, codigo, ';');
        getline(infile, tipo, ';');
        getline(infile, nome);
        if(codigo.compare("") == 0){
            break;
        }
        switch (tipo[0])
        {
        case 'U': //Usuario comum (Assinante)
            this->inserirAssinante(new Assinante(nome, stoi(codigo)));
            break;
        case 'P': //Podcaster
            this->inserirProdutor(new Podcaster(nome, stoi(codigo)));
            break;
        case 'A': //Podcaster
            this->inserirProdutor(new Artista(nome, stoi(codigo)));
            break;
        default:
            cerr << "Tipo de usuario \'" << tipo << "\' indefinido (id.:" << codigo << ")\n";
            break;
        }
    }
    infile.close();
}

void PlataformaDigital::carregaArquivoGenero(ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro ao abrir arquivo de generos\n" ;
        exit(1);
    }

    string sigla;
    string nome;

    getline(infile, sigla); //Ignorando a primeira linha
    while(!infile.eof()){ 
        getline(infile, sigla, ';');
        getline(infile, nome, infile.widen('\n'));
        if(sigla.compare("") == 0){
            break;
        }
        this->listaGeneros.push_back(new Midia::Genero(sigla, nome));
    }
    
    infile.close();
}

void PlataformaDigital::carregaArquivoMidia(ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro ao abrir arquivo de generos\n" ;
        exit(1);
    }

    string data[10];
    getline(infile, data[0]); //Ignorando a primeira linha
    while(!infile.eof()){
        for(int i = 0; i<9; i++){
            getline(infile, data[i], ';');
        }
        getline(infile, data[9]);
        if(data[0].compare("") == 0){
            break;
        }
        if(data[2].compare("M") == 0){ //Tipo // Musica

        }else if(data[2].compare("P") == 0){ //Podcast

        }else{
            cerr << "Tipo de midia " << data[2] << " invalido!" << endl;
        }
    }
    
    infile.close();
}

Midia::Genero *PlataformaDigital::searchGenero(std::string genero){
    for(unsigned int i = 0; i < this->listaGeneros.size(); i++){
        if(this->listaGeneros[i]->getSigla().compare(genero) == 0){
            return this->listaGeneros[i];
        }
    }
    cerr << "Genero nao localizado! Sigla: " << genero << endl;
    exit(1);
    return NULL;
}

string PlataformaDigital::getNome(){
    return this->nome;
}

vector<Midia *> PlataformaDigital::getProdutosCadastrados(){
    return this->produtosCadastrados;
}

vector<Assinante *> PlataformaDigital::getAssinantes(){
    return this->assinantes;
}
