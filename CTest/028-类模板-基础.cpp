#include<iostream>
using namespace std;

// 使用逗号分隔多个泛型，可以设置默认数据类型
template<class NameType, class YearType = int>
class Person28
{
public:
    NameType name;
    YearType year;

    Person28(NameType name, YearType year):name(name),year(year){}

    void print()
    {
        cout << "姓名：" << name << "，出生年：" << year << endl;
    }
};

void main028()
{
    // 类模板无法自动推导数据类型
    Person28<string, int> p("ck", 1998);
    p.print();

    // 使用默认数据类型
    Person28<string> p2("kk", 2008);
    p2.print();

}
