#pragma once
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include "Album.hpp"
#include <vector>

class PlataformaDigital {
    private:
        std::string nome;
        std::vector<Assinante *> assinantes;
        std::vector<Midia*> produtosCadastrados;
        std::vector<Midia::Genero*> listaGeneros;
        std::vector<Produtor*> listaProdutor;
        std::vector<Album *> albunsCadastrados;
    public:
        PlataformaDigital();
        PlataformaDigital(std::string _nome);

        //Printers
        void imprimeProdutos(std::string genero);
        void imprimeAssinantes();
        void imprimeNoArquivo(std::ofstream &outfile);
        void imprimeListaGenero();
        void imprimeProdutores();

        //Insert/Remove
        void inserirAssinante(Assinante *);
        Assinante *removerAssinante(Assinante *);
        void inserirProdutor(Produtor* produtor);
        Produtor *removerProdutor(int id);
        int inserirProduto(Midia *novoProduto, std::vector<Produtor*> listaProdutor);
        void inserirAlbum(Album *album);

        //Load data
        void carregaArquivoUsuario(std::ifstream &infile);
        void carregaArquivoMidia(std::ifstream &infile);
        void carregaArquivoFavoritos(std::ifstream &infile);
        void carregaArquivoGenero(std::ifstream &infile);

        //Getters
        std::string getNome();
        std::vector<Midia *> getProdutosCadastrados();
        std::vector<Assinante *> getAssinantes();
        Midia::Genero *searchGenero(std::string genero);
        Produtor *searchProdutor(int id);
        Podcaster *searchPodcaster(int id);

        //Output
        void exportarBiblioteca();
        void gerarRelatorios();

};
