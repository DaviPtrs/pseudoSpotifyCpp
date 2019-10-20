#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h> 
#include "../lib/utils.hpp"
#include "PlataformaDigital.hpp"
#include "Podcaster.hpp"
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

int convertDuracao(string origin){ //Le o formato de texto e retorna segundos
    char duracao[origin.length() + 1];
    strcpy(duracao, origin.c_str());
    int min, segs;
    sscanf(duracao, "%d,%d", &min, &segs);

    return (segs + (min * 60));
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

        if(data[2].compare("P") == 0){ //Tipo // Podcast
            Podcast *obj = new Podcast(data[1], stoi(data[0]), data[5], stoi(data[6]));
            obj->setDuracao(convertDuracao(data[4])); //Seta a duracao em segundos
            obj->setAnoLancamento(stoi(data[9]));

            Midia::Genero *gen = this->searchGenero(data[5]);
            obj->setGenero(gen);

            vector <int> podcasterIds = extractIntsFromString(data[3]);

            for(int i = 0; i<podcasterIds.size(); i++){
                Podcaster *p = searchPodcaster(podcasterIds[i]);
            // obj->addPodcaster((); //parei aqui
            }

        }else if(data[2].compare("M") == 0){ //Musica

        }else{
            cerr << "Tipo de midia " << data[2] << " invalido!" << endl;
        }
    }
    
    infile.close();
}

Midia::Genero *PlataformaDigital::searchGenero(string genero){
    for(unsigned int i = 0; i < this->listaGeneros.size(); i++){
        if(this->listaGeneros[i]->getSigla().compare(genero) == 0){
            return this->listaGeneros[i];
        }
    }
    cerr << "Genero nao localizado! Sigla: " << genero << endl;
    exit(1);
    return NULL;
}

Podcaster *PlataformaDigital::searchPodcaster(int id){
    for(unsigned int i = 0; i < this->listaProdutor.size(); i++){
        if(this->listaProdutor[i]->getId() == id){
            return (Podcaster *)this->listaProdutor[i];
        }
    }
    cerr << "Produtor nao localizado! Id: " << id << endl;
    exit(1);
    return NULL;
}

Produtor *PlataformaDigital::searchProdutor(int id){
    for(unsigned int i = 0; i < this->listaProdutor.size(); i++){
        if(this->listaProdutor[i]->getId() == id){
            return this->listaProdutor[i];
        }
    }
    cerr << "Produtor nao localizado! Id: " << id << endl;
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
