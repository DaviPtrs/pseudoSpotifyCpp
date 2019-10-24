#pragma once
#include <vector>
#include <string>
#include <bits/stdc++.h> 
#include <tuple>
#include "Midia.hpp"

template <typename T> bool PComp(const T & a, const T & b)
{
   return *a < *b;
}
template< typename T >
typename std::vector<T>::iterator 
   insert_sort(std::vector<T> &vec, const T item )
{
    return vec.insert
        ( 
            std::upper_bound( vec.begin(), vec.end(), item, PComp<T>),
            item 
        );
}
template<int index> struct TupleLess
{
    template<typename Tuple>
    bool operator() (const Tuple & left, const Tuple& right) const
    {
        return std::get<index>(left) > std::get<index>(right);
    }
};


bool stringCompare(std::string s1, std::string s2);
bool MidiaSortNome(Midia*, Midia*);


std::string convertSiglaGenero(std::string origin);

std::vector <int> extractIntsFromString(std::string origin);

float convertDuracao(std::string origin);

class Produtor;

bool compareT_Produtor(const std::tuple<Produtor *, int> & a,const std::tuple<Produtor *, int> & b);

