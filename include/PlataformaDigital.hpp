#pragma once
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include "Produtor.hpp"
#include <vector>

class PlataformaDigital {
    private:
        std::string nome;
        std::vector<Assinante *> assinantes;
        std::vector<Midia*> produtosCadastrados;
        std::vector<Midia::Genero*> listaGeneros;
        std::vector<Produtor*> listaProdutor;
    public:
        PlataformaDigital();
        PlataformaDigital(std::string _nome);
        void imprimeProdutos(std::string genero);
        void imprimeAssinantes();
        void inserirAssinante(Assinante *);
        Assinante *removerAssinante(std::string nome);
        int inserirProduto(Midia *novoProduto, std::vector<Produtor*> listaProdutor);
        int selecionaAssinante();
        void inserirAssinante(); //q parada eh essa veio
        void imprimeNoArquivo(std::ofstream &outfile);
        void carregaArquivoUsuario(std::ifstream &infline);
        void carregaArquivoMidia(std::ifstream &infline);
        void carregaArquivoFavoritos(std::ifstream &infline);
        void carregaArquivoGenero(std::ifstream &infline);
        void exportarBiblioteca();
        void gerarRelatorios();

        std::string getNome();
        std::vector<Midia *> getProdutosCadastrados();
        std::vector<Assinante *> getAssinantes();
};
