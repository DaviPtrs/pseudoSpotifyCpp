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
#include "colors.hpp"

using namespace std;

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

void checkFile(fstream &file){
    if(!file.is_open()){
        cerr << RED("Erro de I/O") << endl;
        exit(1);
    }
}

string formatFloat(float n){
    stringstream ss;
    ss << fixed << setprecision(2) << n;
    string out = ss.str();
    string::iterator it = find(out.begin(), out.end(),'.');
    out.replace(it, it+1, ",");

    return out;
}

PlataformaDigital::PlataformaDigital() {
    cout << GRN("Plataforma Digital generica criada!\n");
}

PlataformaDigital::PlataformaDigital(string _nome) {
    this->nome = _nome;
    cout << GRN("Objeto PlataformaDigital (") << _nome << GRN(") criado!\n");
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
    s.append(CYN("Assinante \""));
    s.append(assinante->getNome());
    s.append(CYN("\" inserido!\n"));

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
    inputError();
}

void PlataformaDigital::inserirProdutor(Produtor *produtor){
    insert_sort(this->listaProdutor, produtor);
    cout << YEL("Produtor \"");
    cout << produtor->getNome(); 
    cout << YEL("\" inserido!\n");
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
    inputError();
}

void PlataformaDigital::inserirProduto(Midia *novoProduto){
    insert_sort(this->produtosCadastrados, novoProduto);
    cout << YEL("Produto id.:") << novoProduto->getId() << YEL(" \"") << novoProduto->getNome() << YEL("\" inserido!\n");
}

void PlataformaDigital::inserirAlbum(Album *album){
    this->albunsCadastrados.push_back(album);
    cout << GRN("Album id.:") << album->getId() << GRN(" \"") << album->getNome() << GRN("\" inserido!\n");
}

void PlataformaDigital::carregaArquivoUsuario(std::ifstream &infile){
    checkFile((fstream &)infile);

    string codigo;
    string tipo;
    string nome;
    int codigoNum = -1;
    
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
            inputError();
        }
        switch (tipo[0])
        {
        case 'U': //Usuario comum (Assinante)
            this->inserirAssinante(new Assinante(nome, codigoNum));
            break;
        case 'P': //Podcaster
            this->inserirProdutor(new Podcaster(nome, codigoNum));
            break;
        case 'A': //Artista
            this->inserirProdutor(new Artista(nome, codigoNum));
            break;
        default:
            inputError();
        }
    }
    infile.close();
}

void PlataformaDigital::carregaArquivoGenero(ifstream &infile){
    checkFile((fstream &)infile);

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
    checkFile((fstream &)infile);

    string codigo;
    string favs;
    int codigoNum = -1;
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
            inputError();
        }
        if(favsNum.size() != 0){
            Assinante *user = searchAssinante(codigoNum);
            for(int favId: favsNum){
                Midia *fav = searchMidia(favId);
                if(!user->favExists(fav)){
                    user->inserirFavorito(fav);
                }
            }
        }
    }
    infile.close();
}

void PlataformaDigital::carregaArquivoMidia(ifstream &infile){
    checkFile((fstream &)infile);

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
            inserirProduto((Midia *)obj);
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
                    inputError();
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
            inserirProduto((Midia *)obj);
        }else{
            inputError();
        }
    }
    infile.close();
}

Album *PlataformaDigital::fillAlbum(std::string data[]){
    int codigo = -1, ano = -1;
    float duracao = -1;
    try{
        codigo = stoi(data[CODALBUM]);
        ano = stoi(data[ANOPUB]);
        duracao = convertDuracao(data[DURACAO]);
    }catch(const std::exception& e){
        inputError();
    }
    
    Album *obj = new Album(data[ALBUM],codigo,duracao,ano,0);
    return obj;
}

Musica *PlataformaDigital::fillMusica(std::string data[]){
    int codigo = -1, ano = -1;
    float duracao = -1;
    try{
        codigo = stoi(data[CODIGO]);
        ano = stoi(data[ANOPUB]);
        duracao = convertDuracao(data[DURACAO]);
    }catch(const std::exception& e){
        inputError();
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
        inputError();
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
    inputError();
    return NULL;
}

Produtor *PlataformaDigital::searchProdutor(int id){
    for(Produtor *p : this->listaProdutor){
        if(p->getId() == id){
            return p;
        }
    }
    inputError();
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
    inputError();
    return NULL;
}

Assinante *PlataformaDigital::searchAssinante(int id){
    for(Assinante *x: this->assinantes){
        if(x->getId() == id){
            return x;
        }
    }
    inputError();
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

void PlataformaDigital::gerarRelatorios(){
    ofstream file;
    file.open("output/estatisticas.txt", ios::out);
    checkFile((fstream &)file);
    file << estatisticas();
    file.close();

    file.open("output/produtores.csv", ios::out);
    checkFile((fstream &)file);
    file << "<nome do produtor>;<nomes das mídias>" << endl;
    file << midiasPorProdutores();
    file.close();

    file.open("output/favoritos.csv", ios::out);
    checkFile((fstream &)file);
    file << "<código do assinante>;<tipo>;<código da mídia>;<gênero>;<duração>" << endl;
    file << favList();
    file.close();
}


void PlataformaDigital::exportarBiblioteca(){
    ofstream file;
    file.open("output/backup.txt", ios::out);
    checkFile((fstream &)file);
    file << backup();
    file.close();
}

string PlataformaDigital::backupUsers(){
    string out;
    out.append("Usuários:\n");
    for(Produtor *user: this->listaProdutor){
        out.append(to_string(user->getId()));
        out.append(";");
        out.append(user->getNome());
        out.append("\n");
    }
    for(Assinante *user: this->assinantes){
        out.append(to_string(user->getId()));
        out.append(";");
        out.append(user->getNome());
        out.append("\n");
    }
    return out;
}

string PlataformaDigital::backupMidias(){
    string out;
    out.append("Midias:\n");
    for(Produtor *prod: this->listaProdutor){
        for(Midia *midia: prod->getProdutosDesenvolvidos()){
            out.append(midia->getNome());
            out.append(";");
            out.push_back(midia->getTipo());
            out.append(";");
            out.append(prod->getNome());
            out.append(";");
            out.append(midia->getGenero()->getNome());
            out.append(";");
            if(midia->getTipo() == 'P'){
                out.append(to_string(((Podcast *)midia)->getQtdTemporadas()));
                out.append(";;");
            }else{
                out.append(";");
                Album *album = this->searchMusicAlbum((Artista *)prod, (Musica *)midia);
                if(album != NULL){
                    out.append(to_string(album->getId()));
                    out.append(";");
                }else{
                    out.append(";");
                }
            }
            out.append(to_string(midia->getAnoLancamento()));
            out.append("\n");
        }
    }
    return out;
}

string PlataformaDigital::backup(){
    string out;
    out.append(this->backupUsers());
    out.append("\n");
    out.append(this->backupMidias());
    return out;
}

string PlataformaDigital::estatisticas(){
    string out;
    out.append("Horas Consumidas: ");
    out.append(horasConsumidas());
    out.push_back('\n');
    out.append("Genero mais ouvido: ");
    out.append(topGenero());
    out.push_back('\n');
    out.append("Midias por Genero:\n");
    out.append(midiasPorGenero());
    out.push_back('\n');
    out.append("Top 10 Midias:\n");
    out.append(top10Midias());
    out.push_back('\n');
    out.append("Top 10 Produtores:\n");
    out.append(top10Produtores());;
    return out;
}

string PlataformaDigital::horasConsumidas(){
    float hc = (float)0;
    for(Assinante *user : this->assinantes){
        for(Midia * midia: user->getFavoritos()){
            hc += midia->getDuracao();
        }
    }
    string out;
    out.append(formatFloat((float)hc));
    out.append(" minutos\n");
    return out;
}

string PlataformaDigital::topGenero(){
    Midia::Genero *max = NULL;
    Midia::Genero *genero_teste = NULL;
    int qtdFavs = 0;
    vector<tuple<Midia::Genero *, int>> generoFavs;
    int i;

    for(Midia::Genero *obj: this->listaGeneros){
        generoFavs.push_back(make_tuple(obj, 0));
    }

    for(Midia* midia: this->produtosCadastrados){
        i = searchIndexGenero(midia->getGenero());
        get<1>(generoFavs[i]) += midia->getFavs();
    }

    for(auto obj: generoFavs){
        genero_teste = get<0>(obj);
        if(get<1>(obj) > qtdFavs){
            max = genero_teste;
            qtdFavs = get<1>(obj);
        }
    }

    string out;
    out.append(max->getNome());
    out.append(" - ");
    out.append(formatFloat(max->getMinsGen()));
    out.append(" minutos\n");
    return out;
}

int PlataformaDigital::searchIndexGenero(Midia::Genero *obj){
    int tam = this->listaGeneros.size();
    for(int i = 0; i<tam; i++){
        if(this->listaGeneros[i]->getSigla().compare(obj->getSigla()) == 0){
            return i;
        }
    }
    return -1;
}

string PlataformaDigital::midiasPorGenero()
{
    string out;
    for(Midia::Genero *genero : this->listaGeneros)
    {
        out.append(genero->getNome());
        out.append(";");
        out.append(to_string(genero->getQtdMidia()));
        out.append("\n");
    }
    return out;
}

string PlataformaDigital::midiasPorProdutores()
{
    string out;
    for(Produtor *produtor : this->listaProdutor)
    {
        out.append(produtor->getNome());
        out.append(";");
        vector <Midia *> midias = produtor->getProdutosDesenvolvidos();
        sort(midias.begin(), midias.end(), &MidiaSortNome);
        for(Midia *midia: midias){
            out.append(midia->getNome());
            if(midia != midias[midias.size()-1]){
                out.append(", ");
            }
        }
        out.append("\n");
    }
    return out;
}

string PlataformaDigital::favList(){
    string out;
    
    for(Assinante * user: this->assinantes){
        for(int i = 0; i<2; i++){
            for(Midia * midia: user->getFavoritos()){
                if((i == 0) && (midia->getTipo() == 'P')){
                    out.append(to_string(user->getId()));
                    out.append(";");
                    out.append("Podcast;");
                    out.append(to_string(midia->getId()));
                    out.append(";");
                    out.append(midia->getGenero()->getNome());
                    out.append(";");
                    out.append(formatFloat(midia->getDuracao()));
                    out.append("\n");
                }else if((i == 1) && (midia->getTipo() == 'M')){
                    out.append(to_string(user->getId()));
                    out.append(";");
                    out.append("Musica;");
                    out.append(to_string(midia->getId()));
                    out.append(";");
                    out.append(midia->getGenero()->getNome());
                    out.append(";");
                    out.append(formatFloat(midia->getDuracao()));
                    out.append("\n");
                }
            }
        }
    }
    return out;
}

string PlataformaDigital::top10Produtores()
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
        favsProdutor = 0;
   }

    sort(produtorNFavoritos.begin(), produtorNFavoritos.end(), TupleLess<1>());

    int tam = produtorNFavoritos.size();
    if(tam >= 10){
        tam = 10;
    }
    string out;
    for(int i = 0; i<tam; i++)
    {
        Produtor *p = get<0>(produtorNFavoritos[i]);
        int nFav = get<1>(produtorNFavoritos[i]);
        out.append(p->getNome());
        out.append(";");
        out.append(to_string(nFav));
        out.append("\n");
    }
    return out;
}


string PlataformaDigital::top10Midias()
{
    vector<tuple<Midia*, int>> top10Midia;
    tuple <Midia*, int> aux;
    for(Midia* midia : this->produtosCadastrados)
    {
        aux = make_tuple(midia, midia->getFavs());
        top10Midia.push_back(aux);
    }
    sort(top10Midia.begin(), top10Midia.end(), TupleLess<1>());
    int tam = top10Midia.size();
    if(tam >= 10)
        tam = 10;

    string out;
    for(int i = 0; i<tam; i++)
    {
        Midia *m = get<0>(top10Midia[i]);
        int nFav = get<1>(top10Midia[i]);
        out.append(m->getNome());
        out.append(";");
        out.append(m->getGenero()->getNome());
        out.append(";");
        out.append(to_string(nFav));
        out.append("\n");
    }
    return out;
}
