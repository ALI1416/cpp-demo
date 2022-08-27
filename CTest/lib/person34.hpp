#pragma once
#ifndef __PERSON34_H__
#define __PERSON34_H__

//声明
template<class NameType, class YearType>
class Person34
{
public:
    NameType name;
    YearType year;

    Person34(NameType name, YearType year);

    void print();
};

// 实现
template<class NameType, class YearType>
Person34<NameType, YearType>::Person34(NameType name, YearType year)
{
    this->name = name;
    this->year = year;
}

template<class NameType, class YearType>
void Person34<NameType, YearType>::print()
{
    cout << "姓名：" << name << "，出生年：" << year << endl;
}

#endif
