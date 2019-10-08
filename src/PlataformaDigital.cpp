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


void PlataformaDigital::imprimeProdutos(string genero){
    
}

void PlataformaDigital::imprimeAssinantes(){
    int tam = this->assinantes.size;
    cout << "=-=-=-=ASSINANTES-=-=-=-=\n";
    for(int i = 0; i<tam; i++){
        cout << this->assinantes[i]->getNome() << endl;
    }
    cout << "=-=-=-=ASSINANTES-=-=-=-=\n";
}

void PlataformaDigital::inserirAssinante(Assinante * assinante){
    insert_sort(this->assinantes, assinante);
    cout << "Assinante \"" << assinante->getNome() << "\" inserido!\n";
}

Assinante * PlataformaDigital::removerAssinante(string nome){
    vector<Assinante *> vet = this->assinantes;
    int tam = vet.size;

    for(int i = 0; i<tam; i++){
        Assinante *obj = vet[i]; //Nao sei se isso funciona
        if(!obj->getNome().compare(nome)){
            vet.erase(vet.begin() + i);
            cout << "Assinante \"" << obj->getNome() << "\" removido!\n";
            return obj;
        }
    }
    return NULL;
}

int PlataformaDigital::inserirProduto(Midia *novoProduto, string nomeProdutor){
    
}

void PlataformaDigital::imprimeNoArquivo(ofstream &outfile){

}

void PlataformaDigital::carregaArquivoUsuario(std::ifstream &infile){

}

void PlataformaDigital::carregaArquivoMidia(std::ifstream &infile){

}

void PlataformaDigital::carregaArquivoFavoritos(std::ifstream &infile){

}

void PlataformaDigital::carregaArquivoGenero(std::ifstream &infile)
{
    std::string sigla;
    std::string nome;
    while(!(infile.eof()))
    {
        getline(infile, sigla, ';');
        getline(infile, nome);
        this->listaGeneros.push_back(new Midia::Genero(sigla, nome));
        
    }

    this->listaGeneros.pop_back();  // gambiarra bonita, gambiarra formosa
}

void PlataformaDigital::exportarBiblioteca(){

}

void PlataformaDigital::gerarRelatorios(){

}

void PlataformaDigital::imprimeListaGenero()
{
    for(int i = 0; i < this->listaGeneros.size(); i++)
    {
        std::cout<<this->listaGeneros[i]->getSigla()<<';';
        std::cout<<this->listaGeneros[i]->getNome()<<std::endl;
       // std::cout<<"to com fome"<< i <<std::endl;
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
