#include "Podcaster.hpp"

Podcaster::Podcaster() {}

Podcaster::Podcaster(std::string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    cout << "Podcaster " << codigo << " criado!" << endl;
}
