#pragma once

template <typename Cathedra>
class My_iterator //класс-итератор
{
    Cathedra* pn;
public:
    My_iterator(Cathedra* first);
    //операции для перепрыгивание на число елементов
    Cathedra& operator +(int n);
    Cathedra& operator-(int n);
    //операции для передвижения по контейнеру
    Cathedra& operator++(int);
    Cathedra& operator--(int);
    Cathedra& operator++();
    Cathedra& operator--();
    //операции равенства или не равенства
    bool operator !=(const My_iterator& it);
    bool operator ==(const My_iterator& it);
    Cathedra& operator*();//операция разыменования
};
