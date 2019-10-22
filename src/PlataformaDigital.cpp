#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h> 
#include <typeinfo>
#include <cstdio>
#include <cctype>
#include "utils.hpp"
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

void PlataformaDigital::imprimePodcasts(){
    cout << "=-=-=-=PODCASTS-=-=-=-=\n";
    for(Midia *x : this->produtosCadastrados){
        if(x->getTipo() == 'P'){
            cout << x->getId()<< ", "<< x->getNome() << endl;
        }
    }
    cout << "=-=-=-=PODCASTS-=-=-=-=\n";
}


void PlataformaDigital::imprimeMusicas(){
    cout << "=-=-=-=MUSICAS-=-=-=-=\n";
    for(Midia *x : this->produtosCadastrados){
        if(x->getTipo() == 'M'){
            cout << x->getId()<< ", "<< x->getNome() << endl;
        }
    }
    cout << "=-=-=-=MUSICAS-=-=-=-=\n";
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

void PlataformaDigital::imprimeListaGenero(){
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
    exit(1);
}

void PlataformaDigital::inserirProduto(Midia *novoProduto){
    insert_sort(this->produtosCadastrados, novoProduto);
    cout << "Produto id.:" << novoProduto->getId() << " \"" << novoProduto->getNome() << "\" inserido!\n";
}

void PlataformaDigital::inserirAlbum(Album *album){
    this->albunsCadastrados.push_back(album);
    cout << "Album id.:" << album->getId() << " \"" << album->getNome() << "\" inserido!\n";
}


void PlataformaDigital::carregaArquivoUsuario(std::ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro de I/O\n";
        exit(1);
    }

    string codigo;
    string tipo;
    string nome;
    int codigoNum;
    
    getline(infile, nome); //Ignorando a primeira linha
    while(!infile.eof()){ 
        getline(infile, codigo, ';');
        getline(infile, tipo, ';');
        getline(infile, nome);
        if(codigo.compare("") == 0){
            break;
        }
        try{
            codigoNum = stoi(codigo);
        }
        catch(const std::exception& e){
            cerr << "Erro de formatação" << endl;
            exit(1);
        }
        switch (tipo[0])
        {
        case 'U': //Usuario comum (Assinante)
            this->inserirAssinante(new Assinante(nome, codigoNum));
            break;
        case 'P': //Podcaster
            this->inserirProdutor(new Podcaster(nome, codigoNum));
            break;
        case 'A': //Podcaster
            this->inserirProdutor(new Artista(nome, codigoNum));
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

void PlataformaDigital::carregaArquivoFavoritos(std::ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro de I/O\n" ;
        exit(1);
    }

    string codigo;
    string favs;
    int codigoNum;
    vector<int> favsNum;
    getline(infile, codigo); //ignora primeira linha
    while(!infile.eof()){
        getline(infile, codigo, ';');
        getline(infile, favs);
        if(codigo.compare("") == 0){
            break;
        }
        try{
            codigoNum = stoi(codigo);
            favsNum = extractIntsFromString(favs);
        }catch(const std::exception& e){
            cerr << "Inconsistências na entrada" << endl;
            exit(1);
        }
        if(favsNum.size() != 0){
            Assinante *user = searchAssinante(codigoNum);
            for(int favId: favsNum){
                Midia *fav = searchMidia(favId);
                user->inserirFavorito(fav);
            }
        }
    }
    infile.close();
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
        }else if(data[2].compare("M") == 0){ //Musica 
            Musica *obj = fillMusica(data);
            vector <int>artistasIds = extractIntsFromString(data[3]);  
            Album *b = NULL;            
            int codigoAlbum = -1;
            int flag = 0;

            if(!data[8].empty()){ //se nao for vazia, entao tem album
                try{
                    codigoAlbum = stoi(data[8]);
                }catch(const std::exception& e){
                    cerr << "Inconsistências na entrada" << endl;
                    exit(1);
                }
                b = searchAlbum(codigoAlbum);
                if(b == NULL){
                    b = fillAlbum(data);
                    this->inserirAlbum(b);
                    flag = 1; // indica se o album acabou de ser criado
                }
            }
            
            //Adiciona o produtor
            for(int aId : artistasIds){
                Produtor *p = searchProdutor(aId);
                //se o album for novo, adiciona ao artista principal
                if((flag == 1) && (aId == artistasIds[0])){
                    b->setArtista((Artista *)p);
                }
                p->addProduto(obj);
            }
            if(b != NULL){
                b->addFaixa((Musica *) obj);
            }
            inserirProduto((Musica *)obj);


        }else{
            cerr << "Inconsistências na entrada" << endl;
            exit(1);
        }
    }
    infile.close();
}

Album *PlataformaDigital::fillAlbum(std::string data[]){
    int codigo, ano;
    float duracao;
    try{
        codigo = stoi(data[8]);
        ano = stoi(data[9]);
        duracao = convertDuracao(data[4]);
    }catch(const std::exception& e){
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    }
    
    Album *obj = new Album(data[7],codigo,duracao,ano,0);

    return obj;
}

Musica *PlataformaDigital::fillMusica(std::string data[]){
    float duracao;
    int codigo, ano;
    try{
        codigo = stoi(data[0]);
        ano = stoi(data[9]);
        duracao = convertDuracao(data[4]);
    }catch(const std::exception& e){
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    } 
    Musica *obj = new Musica(data[1],codigo,data[5],duracao,ano);

    //Adiciona o genero
    Midia::Genero *gen = this->searchGenero(data[5]);
    obj->setGenero(gen);

    return obj;
}

Podcast *PlataformaDigital::fillPodcast(std::string data[]){
    Podcast *obj = new Podcast(data[1], stoi(data[0]), data[5], stoi(data[6]));
    obj->setDuracao(convertDuracao(data[4])); //Seta a duracao em segundos

    try{    
        obj->setAnoLancamento(stoi(data[9]));
    }
    catch(const std::exception& e){
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    }
    

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

Album *PlataformaDigital::searchAlbum(int id){
    for(Album *a : this->albunsCadastrados){
        if(a->getId() == id){
            return a;
        }
    }
    return NULL;
}

Midia* PlataformaDigital::searchMidia(int id){
    for(Midia *x: this->produtosCadastrados){
        if(x->getId() == id){
            return x;
        }
    }
    cerr << "Inconsistências na entrada" << endl;
    exit(1);
    return NULL;
}

Assinante *PlataformaDigital::searchAssinante(int id){
    for(Assinante *x: this->assinantes){
        if(x->getId() == id){
            return x;
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
        if(y->getTipo() == 'P'){//se for podcast
            Podcast *x = (Podcast *)y;
            delete x;
        }else if((y->getTipo() == 'M')){//se for musica
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

void PlataformaDigital::estatisticas()
{
    //<HC>
    float hc = 0;
    for(Assinante *user : this->assinantes){
        for(Midia * midia: user->getFavoritos()){
            hc += midia->getDuracao();
        }
    }
    cout << hc << endl;

    Midia::Genero *max = NULL;
    int qtdMidias = 0;
    Midia::Genero *genero_teste = NULL;
    for(Assinante *user : this->assinantes)
    {
        for(Midia * midia: user->getFavoritos())
        {
            genero_teste = midia->getGenero();
            if(genero_teste->getQtdMidia() >= qtdMidias)
            {
                max = genero_teste;
                qtdMidias = genero_teste->getQtdMidia();
            }
        }
    }
    cout << max->getNome() << max->getMinsGen() << endl;
}