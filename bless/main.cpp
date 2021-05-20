#include <iostream>
#include <cstring>
#include <vector>
#include "cathedra.hpp"
#include "institute.hpp"
#include "printer.hpp"
#include "iter.hpp"

using namespace std;


int main(){
    cout << "Welcome to my Program" << endl;
    cout << "First create an institute\n" << endl;
    Institute institute = Institute();
    cout << "Here is a list of possible actions to perform with corresponding numbers (enter 0 if you want to get back)" << endl;
    while(true){
        cout << "1 - Institute read, update, delete actions\n" << "2 - Cathedra actions\n" << "3 - demonstrate polimorfism cluster (developer function only, but firstly create cathedra)" << endl;
        int action = -1;
        cin >> action;
        if(action == 0)
            return 0;
        switch(action){
            case 1:{
                cout << "1 - Get info about institute\n" << "2 - Edit institute\n" << "3 - Delete institute\n";
                int inst_action;
                cin >> inst_action;
                switch(inst_action){
                    case 1:{
                        cout << institute;
                        cout << "Amount of students is " << institute.count() << endl;
                        break;
                    }
                    case 2:{
                        cout << "1 - edit name, 2 - edit address, 3 - edit income, 4 - edit phone number\n";
                        cin >> action;
                        cout << "Enter new value: ";
                        switch(action){
                            case 1:{
                                string name;
                                cin >> name;
                                institute.set_name(name);
                                break;
                            }
                            case 2:{
                                string address;
                                cin >> address;
                                institute.set_address(address);
                                break;
                            }
                            case 3:{
                                int income;
                                cin >> income;
                                institute.set_income(income);
                                break;
                            }
                            case 4:{
                                string number;
                                cin >> number;
                                institute.set_phone(number);
                                break;
                            }
                        }
                        break;
                    }
                    case 3:{
                        return 0;
                    };
                    default:{
                        break;
                    }
                }
                break;
            }
            case 2:{
                cout << "1 - create cathedras, 2 - Find cathedra by name" << endl;
                cin >> action;
                switch(action){
                    case 1:{
                        cout << "How much cathedras would u like to create?\n";
                        int n;
                        cin >> n;
                        institute.set_size(n);
                        break;
                    }
                    case 2:{
                        if(!institute.getSize()){
                            cout << "There are no cathedras in institute! Please add and come back:)\n";
                            break;
                        }
                        cout << "Enter cathedras name\n";
                        string name;
                        cin >> name;
                        bool flag = false;
                        iter a = institute.begin();
                        Cathedra *temp = &institute.getCathedras()[a - institute.begin()];
                        for(iter i = institute.begin(); i != institute.end(); ++i){
                            if(institute.getCathedras()[i - institute.begin()].get_name() == name){
                                temp = &institute.getCathedras()[i - institute.begin()];
                                flag = true;
                                break;
                            }
                        }
                        if(!flag){
                            cout << "No corresponding cathedra" << endl;
                            break;
                        }
                        cout << "1 - change name, 2 - change specialization, 3 - get info about it, 4 - delete\n";
                        cin >> action;
                        switch(action){
                            case 1:{
                                cout << "Enter new one: ";
                                cin >> name;
                                temp->set_name(name);
                                break;
                            }
                            case 2:{
                                cout << "Enter new one: ";
                                cin >> name;
                                temp->set_specialization(name);
                                break;
                            }
                            case 3:{
                                cout << *temp;
                                break;
                            }
                            case 4:{
                                delete temp;
                                institute.setSize(institute.getSize() - 1);
                                break;
                            };
                            default:{
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            case 3:{
                if(!institute.getSize()){
                    cout << "Please add some cathedra firstly\n";
                    break;
                };
                cout << "Would u like to call polimorf method of institute or of cathedra(1 - institute, 2 - cathedra)\n";
                int chose;
                cin >> chose;
                switch(chose){
                    case 1:{
                        Institute* inst = &institute;
                        Printer::print(inst);
                        break;
                    }
                    case 2:{
                        Cathedra* cath = &institute.getCathedras()[0];
                        Printer::print(cath);
                        break;
                    }
                    default:{
                        break;
                    }
                }
                break;
            }
            default:
                break;
        }
    }
}

//    Organisation org = Organisation();
//    Organisation orgParams = Organisation("HPI", "+380747474", "Sumskaya", 100);
//    Organisation orgCopy = Organisation(orgParams);
//
//    cout << "Enter new cathedra" << endl;
//    Cathedra cathedra = Cathedra();
//    Cathedra* ptr = &cathedra;
//    Organisation* new_org = ptr;
//
//    Printer::print(new_org);
//
//    Cathedra cathedraParams = Cathedra("KNT", "943759473", "Nure", 10000, "computer science", 100, 20, 40);
//    Cathedra cathedraCopy = Cathedra(cathedraParams);
//
//    cout << "cathedraParams name is " << cathedraParams.get_name() << endl;
//    cout << "setting new name to KiberBezpeka" << endl;
//    cathedraParams.set_name("KiberBezpeka");
//    cout << "now it's name is " << cathedraParams.get_name() << endl;
//    cout << "Organisation income is " << org.get_income() << endl;
//
//    cout << "Lets renew cathedra " << cathedraParams.get_name() << endl;
//    cin >> cathedraParams;
//    cout << "cout of cathedra " << cathedraParams.get_name() << "ч is " << cathedraParams << endl;
//    cout << "cout of org is " << org << endl;
//
//    int n;
//    cout << "How many cathedras would you like to create for institute?" << endl;
//    cin >> n;
//
//    Institute i("nure", "sndfk", "sklfkdmf", 500, n);
//
//    cout << "amount of cathedras in institute " << i.get_name() << " is " << i.getSize() << endl;
//    cout << i.count() << endl;
    
