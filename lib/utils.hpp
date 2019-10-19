#pragma once
#include <vector>
#include <bits/stdc++.h> 
template< typename T >
typename std::vector<T>::iterator 
   insert_sort( std::vector<T> & vec, T const& item )
{
    return vec.insert
        ( 
            upper_bound( vec.begin(), vec.end(), item ),
            item 
        );
}