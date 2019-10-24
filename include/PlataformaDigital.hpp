#pragma once
#include <string>
#include "Assinante.hpp"
#include "Podcast.hpp"
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
        void imprimePodcasts();
        void imprimeMusicas();
        void imprimeAssinantes();
        void imprimeNoArquivo(std::ofstream &outfile);
        void imprimeListaGenero();
        void imprimeProdutores();

        //Insert/Remove
        void inserirAssinante(Assinante *);
        void removerAssinante(Assinante *);
        void inserirProdutor(Produtor* produtor);
        void removerProdutor(Produtor* produtor);
        void inserirProduto(Midia *novoProduto);
        void inserirAlbum(Album *album);

        //Load data
        void carregaArquivoUsuario(std::ifstream &infile);
        void carregaArquivoMidia(std::ifstream &infile);
        void carregaArquivoFavoritos(std::ifstream &infile);
        void carregaArquivoGenero(std::ifstream &infile);
        Podcast *fillPodcast(std::string data[]);
        Musica *fillMusica(std::string data[]);
        Album *fillAlbum(std::string data[]);

        //Getters
        Midia::Genero *searchGenero(std::string genero);
        Assinante *searchAssinante(int id);
        Produtor *searchProdutor(int id);
        Album *searchAlbum(int id);
        Midia *searchMidia(int id);
        Album *searchMusicAlbum(Artista *, Musica *);

        //delete functions
        void wipeAll();

        //Output
        void exportarBiblioteca();
        void backup();
        void backupUsers();
        void backupMidias();
        void estatisticas();
        void horasConsumidas();
        void midiasPorGenero();
        void midiasPorProdutores();
        void favList();
        void topGenero();
        void gerarRelatorios();
        void top10Artistas();
        void top10Midias();

};
