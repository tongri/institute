//
//  institute.hpp
//  bless
//
//  Created by Anton Hryb on 13.05.2021.
//
#pragma once
#include "cathedra.hpp"
#include "iter.hpp"


class Institute: public Organisation{
protected:
    Cathedra* cathedras; //указатель на элемент массива кафедр
    int size = 0; //размер массива
public:
    Institute(string n_name, string n_phone, string n_address, int n_income, int n); //конструктор с параметром
    Institute();
    Institute(const Institute& a); //конструктор копирования
    
    //методы получения значений полей
    Cathedra* getCathedras();
    int getSize();
    
    //метод установки массива кафедр
    void setCathedras(Cathedra* n_cathedras, int n_size);
    
    void set_size(int n);
    
    void addCathedra();
    
    void setSize(int n_size);
    
    int count(); //метод подсчета общего числа студентов на всех кафедрах
    
    iter begin(); // метод для получения первого элемента в массиве
    iter end(); // метод для получения последнего элемента в массиве
    
    Institute& operator=(const Institute& a); //перегруженный оператор присваивания
    
    void print();
    
    friend ostream& operator<<(ostream& out, const Institute& cathedra); //перегруженный оператор вывода
    friend istream& operator>>(istream& in, Institute& cathedra); //перегруженный оператор ввода
    
};
