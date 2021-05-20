#pragma once
#include <string>
#include "organisation.hpp"

class Cathedra: public Organisation{
private:
    string specialization;
    struct certain_amount{
        int bacaulors;
        int specialists;
        int magisters;
    };
    certain_amount people;
public:
    Cathedra(); //конструктор по умолчанию
    Cathedra(string n_name, string n_phone, string n_address, int n_income, string n_specialization,
             int n_bacaulors, int n_specialists, int n_magisters); //конструктор с параметрами
    Cathedra(const Cathedra& cathedra); //конструктор копирования

    //методы получения значения переменных
    string get_specialization();
    int get_bacaulors();
    int get_specialists();
    int get_magisters();
    
    //методы установки значения переменных
    void set_specialization(string n_specialization);
    void set_bacaulors(int n_bacaulors);
    void set_specialitst(int n_specialists);
    void set_magisters(int n_magisters);
    
    friend ostream& operator<<(ostream& out, const Cathedra& cathedra); //перегруженный оператор вывода
    friend istream& operator>>(istream& in, Cathedra& cathedra); //перегруженный оператор ввода
    
    void print(); //метод вывода информации об объекте
    
};
