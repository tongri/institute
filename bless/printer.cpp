//
//  printer.cpp
//  bless
//
//  Created by Anton Hryb on 13.05.2021.
//

#include "printer.hpp"
#include "organisation.hpp"
#include <iostream>

using namespace std;

void Printer::print(Organisation* org){
    cout << "Вызов статического метода класса Printer" << endl;
    org->print();
    cout << endl;
    
}
