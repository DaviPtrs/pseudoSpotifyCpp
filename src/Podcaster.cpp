#include "Podcaster.hpp"

Podcaster::Podcaster() {
    cout << "Podcaster generico criado!" << endl;
}

Podcaster::Podcaster(std::string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    cout << "Podcaster " << codigo << "criado!" << endl;
}
