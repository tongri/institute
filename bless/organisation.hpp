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
    
    Organisation(){}
    
    Organisation(string n_name, string n_phone, string n_address, int n_income);
    
    Organisation(const Organisation &a);
    
    string get_name();
    void set_name(string n_name);
    
    string get_phone();
    void set_phone(string n_phone);
    
    string get_address();
    void set_address(string n_address);
    
    int get_income();
    void set_income(int n_income);
    
    Organisation operator= (const Organisation& a);
    
    Organisation operator()(string n_name, string n_phone, string n_address, int n_income);
    
    friend ostream& operator<<(ostream& out, const Organisation& org);
    
    friend istream& operator>>(istream& in, Organisation& org);
    
    virtual void readType();
    
    ~Organisation();
};
