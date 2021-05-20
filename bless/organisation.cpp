#include "organisation.hpp"
#include <iostream>

using namespace std;

Organisation::Organisation(){
    cout << "Конструктор Организации по умолчанию" << endl;
    cout << "Enter name of organisation" << endl;
    cin >> name;
    
    cout << "Enter its phone number" << endl;
    cin >> phone;
    
    cout << "Enter address" << endl;
    cin >> address;
    
    cout << "Enter annualy income" << endl;
    cin >> income;
};


Organisation::Organisation(string n_name, string n_phone, string n_address, int n_income):
name(n_name), phone(n_phone), address(n_address), income(n_income){
    cout << "Конструктор Организации с параметрами" << endl;
};

Organisation::Organisation(const Organisation &a):
name(a.name), phone(a.phone), address(a.address), income(a.income){
    cout << "Конструктор копирования Организации" << endl;
};


string Organisation::get_name(){return name;}
void Organisation::set_name(string n_name){name = n_name;}

string Organisation::get_phone() {return phone;}
void Organisation::set_phone(string n_phone) {this->phone = n_phone;}

string Organisation::get_address() {return address;}
void Organisation::set_address(string n_address){address = n_address;}

int Organisation::get_income() {return income;}
void Organisation::set_income(int n_income){income=n_income;}

Organisation Organisation:: operator= (const Organisation& a){
        name = a.name;
        phone = a.phone;
        address = a.address;
        income = a.income;
        return *this;
    };


Organisation Organisation:: operator()(string n_name, string n_phone, string n_address, int n_income) {
    Organisation tmp(n_name, n_phone, n_address, income+n_income);
    return tmp;
}

void Organisation::print() {
    cout << "It is organisation with name " << name << endl;
};

Organisation::~Organisation(){cout << name << " deleted successfully" << endl;}

ostream& operator<<(ostream& out, const Organisation& org){
    out << "You can contact organisation " << org.name << " with annual income " << org.income <<
    " via calling " << org.phone << " or to get to "
    << org.address << endl;
    return out;
};

istream& operator>>(istream& in, Organisation& org){
    cout << "Enter name of organisation" << endl;
    in >> org.name;
    
    cout << "Enter its phone number" << endl;
    in >> org.phone;
    
    cout << "Enter address" << endl;
    in >> org.address;
    return in;
};
