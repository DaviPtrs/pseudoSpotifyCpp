#pragma once
#include "Produtor.hpp"

class Artista:public Produtor {
    class Album;
    private:
        std::vector<Album *> albums;
        //musicas tipo midia
    public:
        Artista();
        void imprimeNoArquivo(std::ofstream &outfile); 
        void addAlbum(Album * album);
        Album *retiraAlbum();
        std::vector<Album *> getAlbums();
};