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
        void imprimePodcasts();
        void imprimeMusicas();
        void imprimeAssinantes();
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

        //Delete functions
        void wipeAll();

        //Output
        //principais
        void gerarRelatorios();
        void exportarBiblioteca();
        //auxiliares
        //estatisticas
        std::string estatisticas();
        std::string horasConsumidas();
        std::string topGenero();
        std::string midiasPorGenero();
        std::string top10Midias();
        std::string top10Produtores();
        //avulsos
        std::string midiasPorProdutores();
        std::string favList();
        //backup (exportar biblioteca)
        std::string backup();
        std::string backupUsers();
        std::string backupMidias();

};
