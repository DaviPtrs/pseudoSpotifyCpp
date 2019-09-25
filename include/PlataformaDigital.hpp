#include <string>
#include "Assinante.hpp"
#include "Midia.hpp"
#include <vector>
#pragma once

using namespace std;

class PlataformaDigital {
    private:
        string nome;
        vector<Assinante *> assinantes;
        vector<Midia*> produtosCadastrados;
    public:
        PlataformaDigital();
        PlataformaDigital(string _nome);
        void imprimeProdutos(string genero);
        void imprimeAssinantes();
        void inserirAssinante();
        void removerAssinante();
        int inserirProduto(Midia *novoProduto, string nomeProdutor);
        int selecionaAssinante();
        void inserirProdutoAssinante();
        vector<Midia *> getProdutosCadastrados();
        vector<Assinante *> getAssinantes();
        void imprimeNoArquivo(ofstream &outfile);
        void carregaArquivo(ifstream &infline);
        void exportarBiblioteca();
        void gerarRelatorios();
};
