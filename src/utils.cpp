#include "utils.hpp"
#include <iostream>
#include <vector>
#include <string>

std::string convertSiglaGenero(std::string origin){
    std::string str;
    for(char c : origin){
        if(c == ','){
            break;
        }else{
            str.push_back(c);
        }
    }
    return str;
}

std::vector<int>extractIntsFromString(std::string origin){
    std::vector <int> result;
    std::string temp;
    for(char c : origin){
        if(isdigit(c)){
            temp.push_back(c);
        }else if((c == ',') || (c == ' ')){
            if(temp != "")
                result.push_back(stoi(temp));
            temp.clear();
        }
    }
    try{
        if(temp != ""){
        result.push_back(stoi(temp));
        }
    }
    catch(const std::exception& e){
        std::cerr << "Inconsistências na entrada" << std::endl;
        exit(1);
    }
    return result;
}

float convertDuracao(std::string origin){ //Le o formato de texto e retorna segundos
    std::vector <int> vec = extractIntsFromString(origin);
    if((vec.size() != 1) && (vec.size() != 2)){
        std::cerr << "Inconsistências na entrada" << std::endl;
        exit(1);
    }
    if(vec.size() == 1){
        return (float)vec[0]/100;
    }else if(vec.size() == 2){
        return (float)vec[0] + (float)vec[1]/100;
    }else{
        std::cerr << "Inconsistências na entrada" << std::endl;
        exit(1);
    }
}