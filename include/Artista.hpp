#pragma once
#include "Produtor.hpp"

class Artista: public Produtor {
    class Album;
    private:
        std::vector<Album *> albums;
    public:
        Artista();
        Artista(std::string _nome, int codigo);

        //Printers
        // virtual void imprimeNoArquivo(std::ofstream &outfile); 

        //Add/remove
        void addAlbum(Album * album);
        Album *retiraAlbum();

        //Getters
        std::vector<Album *> getAlbums();
};