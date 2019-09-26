#include "Produtor.hpp"
#pragma once

class Artista:public Produtor {
    class Album;
    private:
        vector<Album *> albums;
    public:
        Artista();
        void imprimeNoArquivo(ofstream &outfile); //Italico
        void carregaArquivo(ifstream &infline); //Italico
        void addAlbum(Album * album);
        Album *retiraAlbum();
        vector<Album *> getAlbums();
};