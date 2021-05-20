//
//  institute.cpp
//  bless
//
//  Created by Anton Hryb on 13.05.2021.
//

#include "institute.hpp"
#include <iostream>


Institute::Institute(string n_name, string n_phone, string n_address, int n_income, int n):
    Organisation(n_name, n_phone, n_address, n_income){
        cout << "Конструктор інститута з параметрами" << endl;
    size = n;
    cathedras = new Cathedra[size];
};

void Institute::set_size(int n){
    size = n;
    cathedras = new Cathedra[size];
}

Institute::Institute(const Institute& a) {
    cout << "Конструктор копіювання інститута" << endl;
    name = a.name;
    phone = a.phone;
    address = a.address;
    income = a.income;
    cathedras = new Cathedra[size = a.size];
    for (iter i = begin(); i != end(); ++i) *i = a.cathedras[i - begin()];
};

Institute::Institute(): Organisation(){
    cathedras = new Cathedra[size];
};

Cathedra* Institute::getCathedras(){return cathedras;}
int Institute::getSize(){return size;}

void Institute::setCathedras(Cathedra *n_cathedras, int n_size) {
    cathedras = n_cathedras;
    size = n_size;
}

void Institute::setSize(int n_size){
    size = n_size;
};

int Institute::count(){
    int amount = 0;
    for(iter i = begin(); i != end(); i++){
        amount += cathedras[i-begin()].get_bacaulors();
        amount += cathedras[i-begin()].get_magisters();
        amount += cathedras[i-begin()].get_specialists();
    };
    return amount;
};

iter Institute::begin() { return iter(cathedras); }
iter Institute::end() { return iter(cathedras + size); }

void Institute::print(){
    cout << "Institute with name " << name << " and " << size << " cathedras.";
};

ostream& operator<<(ostream& out, const Institute& institute){
    out << "Info about institute: " << institute.name << endl;
    out << "Its phone: " << institute.phone << endl;
    out << "Its address: " << institute.address << endl;
    out << "Its income: " << institute.income << endl;
    out << "Cathedras amount: " << institute.size << endl;
    return out;
};

istream& operator>>(istream& in, Institute& institute){
    cout << "Enter name: ";
    in >> institute.name;
    cout << "Enter phone: ";
    in >> institute.phone;
    return in;
}

Institute& Institute::operator=(const Institute& a){
    if (this != &a){
        delete[]cathedras; cathedras = new Cathedra[size = a.size];
        for (iter i = begin(); i != end(); ++i) *i = a.cathedras[i - begin()];}
            return *this;
};
