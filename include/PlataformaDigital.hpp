#pragma once
#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include <vector>

class PlataformaDigital {
    private:
        std::string nome;
        std::vector<Assinante *> assinantes;
        std::vector<Midia*> produtosCadastrados;
    public:
        PlataformaDigital();
        PlataformaDigital(std::string _nome);
        void imprimeProdutos(std::string genero);
        void imprimeAssinantes();
        void inserirAssinante(Assinante *);
        Assinante *removerAssinante(std::string nome);
        int inserirProduto(Midia *novoProduto, std::string nomeProdutor);
        int selecionaAssinante();
        void inserirProdutoAssinante(); //q parada eh essa veio
        void imprimeNoArquivo(std::ofstream &outfile);
        void carregaArquivo(std::ifstream &infline);
        void exportarBiblioteca();
        void gerarRelatorios();

        std::string getNome();
        std::vector<Midia *> getProdutosCadastrados();
        std::vector<Assinante *> getAssinantes();
};
