//
//  iter.hpp
//  bless
//
//  Created by Anton Hryb on 13.05.2021.
//

#include "cathedra.hpp"
#pragma once

//#ifndef iter_hpp
//#define iter_hpp
//
//#include <stdio.h>
//#include "cathedra.hpp"
//#endif /* iter_hpp */


class iter{
protected:
    Cathedra* i; //указатель на елемент
public:
    explicit iter(Cathedra* i1 = 0); //конструктор с параметром
    iter(const iter& x); //конструктор копирования
    
    //метод для получения элемента
    Cathedra get_i();
    
    //перегруженные операторы
    iter operator=(const iter& x);
    Cathedra& operator*();
    iter& operator++ ();
    iter& operator-- ();
    iter& operator++ (int);
    iter& operator-- (int);
    iter operator-(int n);
    iter operator+(int n);

    bool operator!=(const iter& x);
    bool operator==(const iter& x);
    friend int operator-(const iter& x, const iter& y){ return x.i - y.i; }
};
