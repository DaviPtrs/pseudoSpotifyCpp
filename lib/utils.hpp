#pragma once
#include <vector>
#include <bits/stdc++.h> 
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