#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h> 
#include <typeinfo>
#include <cstdio>
#include <cctype>
#include <tuple>
#include <vector>
#include <algorithm>
#include "utils.hpp"
#include "PlataformaDigital.hpp"
#include "Podcaster.hpp"
#include "Podcast.hpp"
#include "Artista.hpp"
#include "Midia.hpp"

enum Indx{
    CODIGO=0,
    NOME=1,
    TIPO=2,
    PRODUTORES=3,
    DURACAO=4,
    GENERO=5,
    TEMPORADA=6,
    ALBUM=7,
    CODALBUM=8,
    ANOPUB=9
};

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
    string s;
    insert_sort(this->assinantes, assinante);
    s.append("Assinante \"");
    s.append(assinante->getNome());
    s.append("\" inserido!\n");

    cout << s;
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
    cout << "Produtor \"";
    cout << produtor->getNome(); 
    cout << "\" inserido!\n";
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
        getline(infile, data[ANOPUB]);
        data[GENERO] = convertSiglaGenero(data[GENERO]);

        if(data[CODIGO].compare("") == 0){
            break;
        }

        if(data[TIPO].compare("P") == 0){ //Tipo // Podcast
            Podcast *obj = fillPodcast(data);
            inserirProduto((Podcast *)obj);
        }else if(data[TIPO].compare("M") == 0){ //Musica 
            Musica *obj = fillMusica(data);
            vector <int>artistasIds = extractIntsFromString(data[PRODUTORES]);  
            Album *b = NULL;            
            int codigoAlbum = -1;
            int flag = 0;

            if(!data[CODALBUM].empty()){ //se nao for vazia, entao tem album
                try{
                    codigoAlbum = stoi(data[CODALBUM]);
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
                    ((Artista *)p)->addAlbum(b);
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
        codigo = stoi(data[CODALBUM]);
        ano = stoi(data[ANOPUB]);
        duracao = convertDuracao(data[DURACAO]);
    }catch(const std::exception& e){
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    }
    
    Album *obj = new Album(data[ALBUM],codigo,duracao,ano,0);

    return obj;
}

Musica *PlataformaDigital::fillMusica(std::string data[]){
    float duracao;
    int codigo, ano;
    try{
        codigo = stoi(data[CODIGO]);
        ano = stoi(data[ANOPUB]);
        duracao = convertDuracao(data[DURACAO]);
    }catch(const std::exception& e){
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    } 
    Musica *obj = new Musica(data[NOME],codigo,data[GENERO],duracao,ano);

    //Adiciona o genero
    Midia::Genero *gen = this->searchGenero(data[GENERO]);
    obj->setGenero(gen);
    gen->addMidia(obj);

    return obj;
}

Podcast *PlataformaDigital::fillPodcast(std::string data[]){
    Podcast *obj = new Podcast(data[NOME], stoi(data[CODIGO]), data[GENERO], stoi(data[TEMPORADA]));
    obj->setDuracao(convertDuracao(data[DURACAO])); //Seta a duracao em segundos

    try{    
        obj->setAnoLancamento(stoi(data[ANOPUB]));
    }
    catch(const std::exception& e){
        cerr << "Inconsistências na entrada" << endl;
        exit(1);
    }
    

    Midia::Genero *gen = this->searchGenero(data[GENERO]);
    obj->setGenero(gen);
    gen->addMidia(obj);
    
    vector <int>podcasterIds = extractIntsFromString(data[PRODUTORES]);

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

void PlataformaDigital::wipeAll(){
    for(Assinante *x : this->assinantes){
        delete x;
        x = NULL;
    }

    for(Produtor *x : this->listaProdutor){            
        if(x->getTipo() == 'A'){
            Artista *y = (Artista *)x;
            delete y;
        }else{
            Podcaster *y = (Podcaster *)x;
            delete y;
        }
        x = NULL;
    }
    for(Album *x : this->albunsCadastrados){
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
        }
        y = NULL;
    }
}

Album *PlataformaDigital::searchMusicAlbum(Artista * prod, Musica *obj){
    for(Album *a: prod->getAlbums()){
        if(a->isMusicIn(obj)){
            return a;
        }
    }
    return NULL;
}

void PlataformaDigital::backupUsers(){
    cout << "Usuários:" << endl;
    for(Produtor *user: this->listaProdutor){
        cout << user->getId() << ";" << user->getNome() << endl;
    }
    for(Assinante *user: this->assinantes){
        cout << user->getId() << ";" << user->getNome() << endl;
    }
}

void PlataformaDigital::backupMidias(){
    cout << "Midias:" << endl;
    // cout << "";
    for(Produtor *prod: this->listaProdutor){
        for(Midia *midia: prod->getProdutosDesenvolvidos()){
            cout << midia->getNome() << ";";
            cout << midia->getTipo() << ";";
            cout << prod->getNome() << ";";
            cout << midia->getGenero()->getNome() << ";";
            if(midia->getTipo() == 'P'){
                cout << ((Podcast *)midia)->getQtdTemporadas() << ";";
                cout << ";";
            }else{
                cout << ";";
                Album *album = this->searchMusicAlbum((Artista *)prod, (Musica *)midia);
                if(album != NULL){
                    cout << album->getId() << ";";
                }else{
                    cout << ";";
                }
            }
            cout << midia->getAnoLancamento() << endl;;
        }
    }
}

void PlataformaDigital::backup(){
    this->backupUsers();
    this->backupMidias();
}

// void horasConsumidas(){}

void PlataformaDigital::horasConsumidas(){
    //<HC>
    float hc = 0;
    for(Assinante *user : this->assinantes){
        for(Midia * midia: user->getFavoritos()){
            hc += midia->getDuracao();
        }
    }
    hc = hc/60;
    cout << hc << " horas" << endl;
}

void PlataformaDigital::topGenero(){
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
    cout << max->getNome() << " - " << max->getMinsGen() << " minutos" << endl;
}

void PlataformaDigital::midiasPorGenero()
{
    for(Midia::Genero *genero : this->listaGeneros)
    {
        cout << genero->getNome() << ";" << genero->getQtdMidia() << endl;
    }
}

void PlataformaDigital::midiasPorProdutores()
{
    for(Produtor *produtor : this->listaProdutor)
    {
        cout << produtor->getNome();
        cout << ";";
        vector <Midia *> midias = produtor->getProdutosDesenvolvidos();
        sort(midias.begin(), midias.end(), &MidiaSortNome);
        for(Midia *midia: midias){
            cout << midia->getNome();
            if(midia != midias[midias.size()-1]){
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void PlataformaDigital::favList(){
    for(Assinante * user: this->assinantes){
        for(int i = 0; i<2; i++){
            for(Midia * midia: user->getFavoritos()){
                if((i == 0) && (midia->getTipo() == 'P')){
                    cout << user->getId() << ";";
                    cout << "Podcast;" << midia->getId() << ";";
                    cout << midia->getGenero()->getNome() << ";";
                    cout << midia->getDuracao() << endl;
                }else if((i == 1) && (midia->getTipo() == 'M')){
                    cout << user->getId() << ";";
                    cout << "Musica;" << midia->getId() << ";";
                    cout << midia->getGenero()->getNome() << ";";
                    cout << midia->getDuracao() << endl;
                }
            }
        }
    }
}

void PlataformaDigital::top10Artistas()
{
   vector<Produtor *> produtor;
   vector<Midia *> midias;
   vector<tuple<Produtor *, int>> produtorNFavoritos;
   tuple <Produtor*, int> aux;
   int favsProdutor = 0;
   for(Produtor *artista: this->listaProdutor)
   {
       midias = artista->getProdutosDesenvolvidos();
       for(Midia *midia: midias)
       {
           favsProdutor += midia->getFavs();  // numero de midias favoritadas do produtor
       }
        aux = make_tuple(artista, favsProdutor);
        produtorNFavoritos.push_back(aux);
   }

    sort(produtorNFavoritos.begin(), produtorNFavoritos.end(), TupleLess<1>());

    int tam = produtorNFavoritos.size();
    if(tam >= 10){
        tam = 10;
    }
    for(int i = 0; i<tam; i++)
    {
        Produtor *p = get<0>(produtorNFavoritos[i]);
        int nFav = get<1>(produtorNFavoritos[i]);
        cout << p->getNome() << ";" << nFav << endl;
    }
}


void PlataformaDigital::top10Midias()
{
    vector<tuple<Midia*, int>> top10Midia;
    tuple <Midia*, int> aux;
    for(Midia* midia : this->produtosCadastrados)
    {
        if(midia->getTipo() == 'M')
        {
            aux = make_tuple(midia, midia->getFavs());
            top10Midia.push_back(aux);
        }

    }
    sort(top10Midia.begin(), top10Midia.end(), TupleLess<1>());
    int tam = top10Midia.size();
    if(tam >= 10)
        tam = 10;

    for(int i = 0; i<tam; i++)
    {
        Midia *m = get<0>(top10Midia[i]);
        int nFav = get<1>(top10Midia[i]);
        cout << m->getNome() << ";" << m->getGenero()->getNome() << ";" << nFav << endl;
    }
}
