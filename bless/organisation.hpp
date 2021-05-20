#pragma once
#include <string>
using namespace std;

class Organisation{
protected:
    string name;
    string phone;
    string address;
    int income;
public:
    Organisation(); //конструктор по умолчанию
    Organisation(string n_name, string n_phone, string n_address, int n_income); //конструктор с параметрами
    Organisation(const Organisation &a); //конструктор копирования
    
    //методы получения значения переменных
    string get_name();
    string get_phone();
    string get_address();
    int get_income();
    
    //методы установки значения переменных
    void set_name(string n_name);
    void set_phone(string n_phone);
    void set_address(string n_address);
    void set_income(int n_income);
    
    Organisation operator=(const Organisation& a); //перегрузка оператора присваивания
    
    Organisation operator()(string n_name, string n_phone, string n_address, int n_income); //оператор вызова объекта
    
    friend ostream& operator<<(ostream& out, const Organisation& org); //оператор вывода
    
    friend istream& operator>>(istream& in, Organisation& org); //оператор ввода
    
    virtual void print(); //метод вывода информации об объекте
    
    virtual ~Organisation(); //деструктор
};
