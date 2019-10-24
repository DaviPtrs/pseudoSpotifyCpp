#include "Album.hpp"
#include "Artista.hpp"
#include <string>
#include <iostream>

using namespace std;

Artista::Artista() {
    cout << "Artista generico criado!" << endl;
}


Artista::Artista(std::string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    this->tipo = 'A';
    cout << "Artista " << codigo << " criado!" << endl;
}

std::vector<Album *> Artista::getAlbums(){
    return this->albums;
}

void Artista::addAlbum(Album * album){
    this->albums.push_back(album);
}