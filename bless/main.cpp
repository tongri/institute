#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Organisation{
protected:
    string name;
    string phone;
    string address;
    int income;

public:
    Organisation(){
        cout << "Enter name of organisation" << endl;
        cin >> name;
        
        cout << "Enter its phone number" << endl;
        cin >> phone;
        
        cout << "Enter address" << endl;
        cin >> address;
        
        cout << "Enter annualy income" << endl;
        cin >> income;
    }
    
    Organisation(string n_name, string n_phone, string n_address, int n_income):
    name(n_name), phone(n_phone), address(n_address), income(n_income){}
    
    Organisation(const Organisation &a):
    name(a.name), phone(a.phone), address(a.address), income(a.income){}
    
    string get_name() const {return name;}
    void set_name(string n_name){name = n_name;}
    
    string get_phone() const {return phone;}
    void set_phone(string n_phone) {phone = n_phone;}
    
    string get_address() const {return address;}
    void set_address(string n_address){address = n_address;}
    
    int get_income() const {return income;}
    void set_income(int n_income){income=n_income;}
    
    Organisation operator= (const Organisation& a){
        name = a.name;
        phone = a.phone;
        address = a.address;
        income = a.income;
        return *this;
    };
    
    Organisation operator()(string n_name, string n_phone, string n_address, int n_income) const {
        Organisation tmp(n_name, n_phone, n_address, income+n_income);
        return tmp;
    }
    
    friend ostream& operator<<(ostream& out, const Organisation& org);
    
    friend istream& operator>>(istream& in, Organisation& org);
    
    virtual void readType() {
        cout << name << endl;
    };
    
//    ~Organisation(){
//        cout << name << " organisation deleted successfully" << endl;
//    }
};

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
    Cathedra(): Organisation(){
        cout << "Enter specialization of cathedra\n";
        cin >> specialization;
        
        cout << "Enter amount of bacaulors\n";
        cin >> people.bacaulors;
        
        cout << "Enter amount of specialists\n";
        cin >> people.specialists;
        
        cout << "Enter amount of magisters\n";
        cin >> people.magisters;
    };
    
    Cathedra(string n_name, string n_phone, string n_address, int n_income, string n_specialization,
             int n_bacaulors, int n_specialists, int n_magisters):
    Organisation(n_name, n_phone, n_address, n_income), specialization(n_specialization){
        people.bacaulors = n_bacaulors;
        people.specialists = n_specialists;
        people.magisters = n_magisters;
    };
    
    Cathedra(const Cathedra& cathedra){
        name = cathedra.name;
        phone = cathedra.phone;
        address = cathedra.phone;
        income = cathedra.income;
        people.bacaulors = cathedra.people.bacaulors;
        people.specialists = cathedra.people.specialists;
        people.magisters = cathedra.people.magisters;
    }
    
    string get_specialization() const {return specialization;}
    void set_specialization(string n_specialization){specialization = n_specialization;}
    
    int get_bacaulors() const {return people.bacaulors;}
    void set_bacaulors(int n_bacaulors){people.bacaulors = n_bacaulors;}
    
    int get_specialists() const {return people.specialists;}
    void set_specialitst(int n_specialists){people.specialists = n_specialists;}
    
    int get_magisters() const {return people.magisters;}
    void set_magisters(int n_magisters){people.magisters = n_magisters;}
    
    friend ostream& operator<<(ostream& out, const Cathedra& cathedra);
    friend istream& operator>>(istream& in, Cathedra& cathedra);
    
    virtual void readType() override{
        cout << specialization << endl;
    }
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

class iter{
protected:
    Cathedra* i;
public:
    explicit iter(Cathedra* i1 = 0) : i(i1){};
    iter(const iter& x) : i(x.i){};
    iter& operator=(const iter& x) { i = x.i; return *this;}
    Cathedra& operator*() const { return *i; };
    iter& operator++ () { ++i; return *this; };
    iter& operator-- () { --i; return *this; };
    iter& operator++ (int) { i++; return *this; };
    iter& operator-- (int) { i--; return *this; };
    iter operator-(int n) { return iter(i - n); }
    iter operator+(int n) { return iter(i+n); }
    
    Cathedra get_i() const {return *i;}
    
    bool operator!=(const iter& x)const { return i != x.i; }
    friend int operator-(const iter& x, const iter& y){ return x.i - y.i; }
};

class Institute{
protected:
    Cathedra* cathedras;
    int size;
public:
    Institute(int n){
        size = n;
        cathedras = new Cathedra[size];
        for(iter i = begin(); i != end(); ++i){
            *i = cathedras[i - begin()];
        };
    };
    
    Institute(const Institute& a) {
        cathedras = new Cathedra[size = a.size];
        for (iter i = begin(); i != end(); ++i) *i = a.cathedras[i - begin()];
    };
    
    ~Institute() { delete[]cathedras; }
    
    Institute& operator=(const Institute& a){
        if (this != &a){
            delete[]cathedras; cathedras = new Cathedra[size = a.size];
            for (iter i = begin(); i != end(); ++i) *i = a.cathedras[i - begin()];}
                return *this;
    };
    
    int count(){
        int amount = 0;
        for(iter i = begin(); i != end(); i++){
            amount += cathedras[i-begin()].get_bacaulors();
            amount += cathedras[i-begin()].get_magisters();
            amount += cathedras[i-begin()].get_specialists();
        };
        return amount;
    };
    
    iter begin() { return iter(cathedras); }
    iter end() { return iter(cathedras + size); }
};


int main(){
    Institute i(2);
    cout << i.count() << endl;
}
