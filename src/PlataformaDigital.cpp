#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h> 
#include <typeinfo>
#include "../lib/utils.hpp"
#include "PlataformaDigital.hpp"
#include "Podcaster.hpp"
#include "Podcast.hpp"
#include "Artista.hpp"

using namespace std;

PlataformaDigital::PlataformaDigital() {
    cout << "Plataforma Digital generica criada!\n";
}

PlataformaDigital::PlataformaDigital(string _nome) {
    this->nome = _nome;
    cout << "Objeto PlataformaDigital (" << _nome <<") criado!\n";
}
void PlataformaDigital::imprimeAssinantes(){
    cout << "=-=-=-=ASSINANTES-=-=-=-=\n";
    for(Assinante * x : this->assinantes){
        cout << x->getId()<< ", "<< x->getNome() << endl;
    }
    cout << "=-=-=-=ASSINANTES-=-=-=-=\n";
}

void PlataformaDigital::imprimeProdutores(){
    cout << "=-=-=-=PRODUTORES-=-=-=-=\n";
    for(Produtor * x : this->listaProdutor){
        cout << x->getId()<< ", "<< x->getNome() << endl;
    }
    cout << "=-=-=-=PRODUTORES-=-=-=-=\n";
}

void PlataformaDigital::imprimeListaGenero()
{
    for(Midia::Genero *g : this->listaGeneros){
        cout << g->getSigla() << ';';
        cout << g->getNome() << endl;
    }
}

void PlataformaDigital::inserirAssinante(Assinante * assinante){
    insert_sort(this->assinantes, assinante);
    cout << "Assinante \"" << assinante->getNome() << "\" inserido!\n";
}

void PlataformaDigital::removerAssinante(Assinante *obj){
    vector<Assinante *> *vet = &this->assinantes;
    int tam = vet->size();

    for(int i = 0; i<tam; i++){
        Assinante *temp = (*vet)[i];
        if(*temp == *obj){
            vet->erase(vet->begin() + i);
            cout << "Assinante \"" << obj->getNome() << "\" removido!\n";
        }
    }
    cerr << "Inconsistências na entrada" << endl;
}

void PlataformaDigital::inserirProdutor(Produtor *produtor){
    insert_sort(this->listaProdutor, produtor);
    cout << "Produtor \"" << produtor->getNome() << "\" inserido!\n";
}

void PlataformaDigital::removerProdutor(Produtor* produtor){
    vector<Produtor *> *vet = &this->listaProdutor;
    int tam = vet->size();

    for(int i = 0; i<tam; i++){
        Produtor *temp = (*vet)[i];
        if(*temp == *produtor){
            vet->erase(vet->begin() + i);
            cout << "Produtor \"" << produtor->getNome() << "\" removido!\n";
        }
    }
    cerr << "Inconsistências na entrada" << endl;
}

void PlataformaDigital::inserirProduto(Midia *novoProduto){
    insert_sort(this->produtosCadastrados, novoProduto);
    cout << "Produto id.:" << novoProduto->getId() << " \"" << novoProduto->getNome() << "\" inserido!\n";
}


void PlataformaDigital::carregaArquivoUsuario(std::ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro de I/O\n";
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
            cerr << "Inconsistências na entrada" << endl;
            break;
        }
    }
    infile.close();
}

void PlataformaDigital::carregaArquivoGenero(ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro de I/O\n" ;
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

string convertSiglaGenero(string origin){
    string str;
    for(char c : origin){
        if(c == ','){
            break;
        }else{
            str.push_back(c);
        }
    }
    return str;
}

vector <int> extractIntsFromString(string origin){
    stringstream ss;     
    vector <int> result;
  
    /* Storing the whole string into string stream */
    ss << origin; 
  
    /* Running loop till the end of the stream */
    string temp; 
    int found; 
    while (!ss.eof()) { 
  
        /* extracting word by word from stream */
        ss >> temp; 
  
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found){
            result.push_back(found);
        }  
        /* To save from space at the end of string */
        temp = ""; 
    } 
    return result;
}

int convertDuracao(string origin){ //Le o formato de texto e retorna segundos
    vector <int> vec = extractIntsFromString(origin);
    if(vec.size() == 1){
        return vec[0];
    }else if(vec.size() == 2){
        return vec[1] + (vec[0] * 60);
    }else{
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    }
}

void PlataformaDigital::carregaArquivoMidia(ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro de I/O\n" ;
        exit(1);
    }

    string data[10];
    getline(infile, data[0]); //Ignorando a primeira linha
    while(!infile.eof()){
        for(int i = 0; i<9; i++){
            getline(infile, data[i], ';');
        }
        getline(infile, data[9]);
        data[5] = convertSiglaGenero(data[5]);

        if(data[0].compare("") == 0){
            break;
        }

        if(data[2].compare("P") == 0){ //Tipo // Podcast
            Podcast *obj = fillPodcast(data);
            inserirProduto((Podcast *)obj);
        }else if(data[2].compare("M") == 0){ //Musica //PAREI AQUI

        }else{
            cerr << "Inconsistências na entrada" << endl;
        }
    }
    
    infile.close();
}

Podcast *PlataformaDigital::fillPodcast(std::string data[]){
    Podcast *obj = new Podcast(data[1], stoi(data[0]), data[5], stoi(data[6]));
    obj->setDuracao(convertDuracao(data[4])); //Seta a duracao em segundos
    obj->setAnoLancamento(stoi(data[9]));

    Midia::Genero *gen = this->searchGenero(data[5]);
    obj->setGenero(gen);

    vector <int>podcasterIds = extractIntsFromString(data[3]);

    for(int pId : podcasterIds){
        Produtor *p = searchProdutor(pId);
        p->addProduto(obj);
        obj->addPodcaster(p);
    }

    return obj;
}

Midia::Genero *PlataformaDigital::searchGenero(string genero){
    for(Midia::Genero *g : this->listaGeneros){
        if(g->getSigla().compare(genero) == 0){
            return g;
        }
    }
    cerr << "Inconsistências na entrada" << endl;
    exit(1);
    return NULL;
}

Produtor *PlataformaDigital::searchProdutor(int id){
    for(Produtor *p : this->listaProdutor){
        if(p->getId() == id){
            return p;
        }
    }
    cerr << "Inconsistências na entrada" << endl;
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

void PlataformaDigital::wipeAll(){
    for(Assinante *x : this->assinantes){
        delete x;
        x = NULL;
    }

    for(Produtor *x : this->listaProdutor){
        delete x;
        x = NULL;
    }

    for(Midia::Genero *x : this->listaGeneros){
        delete x;
        x = NULL;
    }

    for(Midia *y : this->produtosCadastrados){
        if(y->getTipo() == 1){//se for podcast
            Podcast *x = (Podcast *)y;
            delete x;
        }else if((y->getTipo() == 0)){//se for musica
            Musica *x = (Musica *)y;
            delete x;
        }else{
            delete y;
        }
        y = NULL;
    }

    for(Album *x : this->albunsCadastrados){
        delete x;
        x = NULL;
    }
}
