#include "utils.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
#include "Produtor.hpp"
#include "Midia.hpp"
#include <algorithm>
#include "colors.hpp"

using namespace std;

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
        inputError();
    }
    return result;
}

float convertDuracao(std::string origin){ //Le o formato de texto e retorna segundos
    std::vector <int> vec = extractIntsFromString(origin);
    if((vec.size() != 1) && (vec.size() != 2)){
        inputError();
    }
    if(vec.size() == 1){
        return (float)vec[0];
    }else if(vec.size() == 2){
        return (float)vec[0] + (float)vec[1]/100;
    }else{
        inputError();
    }
    return -1;
}


bool stringCompare(std::string s1, std::string s2)
{
    const collate<char>& col = use_facet<collate<char>>(locale());
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    const char* pb1 = s1.data();
    const char* pb2 = s2.data();
    return(col.compare(pb1, pb1 +s1.size(), pb2, pb2 + s2.size()) < 0);
}

bool MidiaSortNome(Midia *midia1, Midia *midia2)
{
    return stringCompare(midia1->getNome(), midia2->getNome());
   
}

void inputError(){
    cerr << RED("Inconsistências na entrada") << endl;
    exit(1);
}