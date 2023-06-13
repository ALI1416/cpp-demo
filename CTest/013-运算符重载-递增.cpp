#include<iostream>
using namespace std;

class Person12
{
public:
    int year;

    // 前置++(先++再返回)
    // 返回*this，才能进行链式调用
    Person12& operator++()
    {
        year++;
        return *this;
    }

    // 后置++(先返回再++)
    // 需要加一个占位符，代表后置
    Person12 operator++(int)
    {
        // 先记录下原始结果
        Person12 p =*this;
        // 递增
        year++;
        // 返回原始结果
        return p;
    }
};

ostream& operator<<(ostream& cout, Person12 p)
{
    cout << p.year;
    return cout;
}

void main013()
{
    Person12 p;
    p.year = 1998;
    cout << "原始出生年：" << p << endl;
    cout << "出生年++p：" << ++p << endl;
    cout << "出生年++p后：" << p << endl;
    cout << "出生年p++：" << p++ << endl;
    cout << "出生年p++后：" << p << endl;
}
