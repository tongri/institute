#include "cathedra.hpp"
#include <iostream>


Cathedra::Cathedra(): Organisation(){
    cout << "Конструктор Кафедры по умолчанию" << endl;
    cout << "Enter specialization of cathedra\n";
    cin >> specialization;
    
    cout << "Enter amount of bacaulors\n";
    cin >> people.bacaulors;
    
    cout << "Enter amount of specialists\n";
    cin >> people.specialists;
    
    cout << "Enter amount of magisters\n";
    cin >> people.magisters;
};

Cathedra::Cathedra(string n_name, string n_phone, string n_address, int n_income, string n_specialization,
         int n_bacaulors, int n_specialists, int n_magisters):
Organisation(n_name, n_phone, n_address, n_income), specialization(n_specialization){
    cout << "Конструктор Кафедры с параметрами" << endl;
    people.bacaulors = n_bacaulors;
    people.specialists = n_specialists;
    people.magisters = n_magisters;
};

Cathedra::Cathedra(const Cathedra& cathedra){
    cout << "Конструктор копирования Кафедры" << endl;
    name = cathedra.name;
    phone = cathedra.phone;
    address = cathedra.phone;
    income = cathedra.income;
    people.bacaulors = cathedra.people.bacaulors;
    people.specialists = cathedra.people.specialists;
    people.magisters = cathedra.people.magisters;
}

string Cathedra::get_specialization() {return specialization;}
void Cathedra::set_specialization(string n_specialization){specialization = n_specialization;}

int Cathedra::get_bacaulors() {return people.bacaulors;}
void Cathedra::set_bacaulors(int n_bacaulors){people.bacaulors = n_bacaulors;}

int Cathedra::get_specialists() {return people.specialists;}
void Cathedra::set_specialitst(int n_specialists){people.specialists = n_specialists;}

int Cathedra::get_magisters() {return people.magisters;}
void Cathedra::set_magisters(int n_magisters){people.magisters = n_magisters;}

void Cathedra::print(){
    cout << "It is cathedra with name " << name << " and spesialization " << specialization << endl;
};


ostream& operator<<(ostream& out, const Cathedra& cathedra){
    out << "Info about cathedra " << cathedra.name << ": " << endl;
    out << "Phone number " << cathedra.phone << endl;
    out << "Address " << cathedra.address << endl;
    out << "Spesizalization " << cathedra.specialization << endl;
    out << "Amount of bacaulors " << cathedra.people.bacaulors << ", of specialists "
    << cathedra.people.specialists << " and of magisters is " << cathedra.people.magisters << endl;
    return out;
};

istream& operator>>(istream& in, Cathedra& cathedra){
    cout << "Enter name of organisation" << endl;
    in >> cathedra.name;
    
    cout << "Enter its phone number" << endl;
    in >> cathedra.phone;
    
    cout << "Enter address" << endl;
    in >> cathedra.address;
    
    cout << "Enter specialization" << endl;
    in >> cathedra.specialization;
    
    cout << "Enter amount of bacaulors" << endl;
    in >> cathedra.people.bacaulors;
    
    cout << "Enter amount of specialists" << endl;
    in >> cathedra.people.specialists;
    
    cout << "Enter amount of magisters" << endl;
    in >> cathedra.people.magisters;
    
    return in;
};
