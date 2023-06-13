#include<iostream>
using namespace std;

// 声明
template<class NameType, class YearType>
class Person35;

// 全局友元函数-类外实现
template<class NameType, class YearType>
void print2(Person35<NameType, YearType> p)
{
    cout << "全局友元函数-类外实现-姓名：" << p.name << "，出生年：" << p.year << endl;
}

template<class NameType, class YearType>
class Person35
{
private:
    NameType name;
    YearType year;
public:
    Person35(NameType name, YearType year) :name(name), year(year) {}

    // 全局友元函数-类内实现
    friend void print(Person35<NameType, YearType> p)
    {
        cout << "全局友元函数-类内实现-姓名：" << p.name << "，出生年：" << p.year << endl;
    }

    // 全局友元函数-类内声明
    // 需要加上空参数列表，声明它是模板函数
    friend void print2<>(Person35<NameType, YearType> p);

};

void main034()
{
    Person35<string, int> p("ck", 1998);
    print(p);
    print2(p);
}
