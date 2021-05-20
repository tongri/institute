//
//  iter.cpp
//  bless
//
//  Created by Anton Hryb on 13.05.2021.
//

#include "iter.hpp"


iter::iter(Cathedra* i1) : i(i1){};
iter::iter(const iter& x) : i(x.i){};
iter iter:: operator=(const iter& x) { i = x.i; return *this;}
Cathedra& iter::operator*() { return *i; };
iter& iter::operator++ () { ++i; return *this; };
iter& iter::operator-- () { --i; return *this; };
iter& iter::operator++ (int) { i++; return *this; };
iter& iter::operator-- (int) { i--; return *this; };
iter iter::operator-(int n) { return iter(i - n); }
iter iter::operator+(int n) { return iter(i+n); }

bool iter::operator!=(const iter& x) { return i != x.i; }
bool iter::operator==(const iter& x) { return i == x.i; }

Cathedra iter::get_i() {return *i;}
