#include "Podcaster.hpp"
#include "colors.hpp"

Podcaster::Podcaster() {}

Podcaster::Podcaster(std::string _nome, int codigo){
    this->codigo = codigo;
    this->nome = _nome;
    this->tipo = 'P';
    cout << BLU("Podcaster ") << codigo << BLU(" criado!") << endl;
}
