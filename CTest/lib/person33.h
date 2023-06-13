#pragma once
#ifndef __PERSON33_H__
#define __PERSON33_H__

//声明
template<class NameType, class YearType>
class Person33
{
public:
    NameType name;
    YearType year;

    Person33(NameType name, YearType year);

    void print();
};

#endif
