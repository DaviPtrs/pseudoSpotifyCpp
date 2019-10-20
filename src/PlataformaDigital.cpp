#include <iostream>
#include <fstream>
#include "../lib/utils.hpp"
#include "PlataformaDigital.hpp"

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
        cout << this->assinantes[i]->getNome() << endl;
    }
    cout << "=-=-=-=ASSINANTES-=-=-=-=\n";
}

// void insert_sort(std::vector<Assinante *> *vec, Assinante *item){
//     int fim = vec->size() -1;
//     int pos = -1;
//     if(fim == -1){
//         pos = 0;
//     }else{
//         for (int i = fim; i<=0; i--){
//             if(*item > (*(*vec)[i])){
//                 pos = i+1;
//                 break;
//             }
//         }
//         if(fim == -1){
//             pos = 0;
//         }
//     }
//     vec->insert(vec->begin() + pos, item);
// }

void PlataformaDigital::inserirAssinante(Assinante * assinante){
    insert_sort(this->assinantes, assinante);
    cout << "Assinante \"" << assinante->getNome() << "\" inserido!\n";
}

Assinante * PlataformaDigital::removerAssinante(string nome){
    vector<Assinante *> *vet = &this->assinantes;
    int tam = vet->size();

    for(int i = 0; i<tam; i++){
        Assinante *obj = (*vet)[i]; //Nao sei se isso funciona
        if(!obj->getNome().compare(nome)){
            vet->erase(vet->begin() + i);
            cout << "Assinante \"" << obj->getNome() << "\" removido!\n";
            return obj;
        }
    }
    return NULL;
}

void PlataformaDigital::inserirProdutor(Produtor *produtor){
    insert_sort(this->listaProdutor, produtor);
    cout << "Produtor \"" << produtor->getNome() << "\" inserido!\n";
}

Produtor *PlataformaDigital::removerProdutor(int id){

}

void PlataformaDigital::carregaArquivoUsuario(std::ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro ao abrir arquivo de usuarios\n" ;
        exit(1);
    }

    std::string codigo;
    std::string tipo;
    std::string nome;

    getline(infile, nome); //Ignorando a primeira linha
    while(!infile.eof()){ 
        getline(infile, codigo, ';');
        getline(infile, tipo, ';');
        
        getline(infile, nome);
        switch (tipo[0])
        {
        case 'U': //Usuario comum (Assinante)
            this->inserirAssinante(new Assinante(nome, stoi(codigo)));
            break;
        case 'A' || 'P': //Produtor
            if(tipo[0] == 'A'){ //Artista

            }else{ //Podcaster

            }
            break;
        default:
            cerr << "Tipo de usuario \'" << tipo << "\' indefinido (id.:" << codigo << ")\n";
            break;
        }
    }
    // Midia::Genero *last = this->listaGeneros[this->listaGeneros.size() -1];
    // this->listaGeneros.pop_back();
    // delete last;
}

void PlataformaDigital::carregaArquivoGenero(std::ifstream &infile){
    if(!infile.is_open()){
        cerr << "Erro ao abrir arquivo de generos\n" ;
        exit(1);
    }

    std::string sigla;
    std::string nome;

    getline(infile, sigla); //Ignorando a primeira linha
    while(!infile.eof()){ 
        getline(infile, sigla, ';');
        getline(infile, nome, infile.widen('\n'));
        this->listaGeneros.push_back(new Midia::Genero(sigla, nome));
    }
    Midia::Genero *last = this->listaGeneros[this->listaGeneros.size() -1];
    this->listaGeneros.pop_back();
    infile.close();
    delete last;
}

void PlataformaDigital::imprimeListaGenero()
{
    for(unsigned int i = 0; i < this->listaGeneros.size(); i++){
        std::cout<<this->listaGeneros[i]->getSigla()<<';';
        std::cout<<this->listaGeneros[i]->getNome()<<std::endl;
    }
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
