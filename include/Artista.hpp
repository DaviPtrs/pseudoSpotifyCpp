#pragma once
#include "Produtor.hpp"

class Album;
class Artista: public Produtor {
    private:
        std::vector<Album *> albums;
    public:
        Artista();
        Artista(std::string _nome, int codigo);

        //Printers
        // virtual void imprimeNoArquivo(std::ofstream &outfile); 

        //Add/remove
        void addAlbum(Album * album);

        //Getters
        std::vector<Album *> getAlbums();
};