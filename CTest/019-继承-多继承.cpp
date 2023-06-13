#include<iostream>
using namespace std;

// 不建议使用多继承
class Base1
{
public:
    int a = 1;
    int b = 2;
};

class Base2
{
public:
    int a = 3;
    int c = 4;
};

// 继承多个父类，用逗号隔开
class Son : public Base1, public Base2
{
public:
    int a = 5;
    int b = 6;
    int d = 7;
};

void main019()
{
    Son s;
    // 占用28字节
    cout << "sizeof(s):" << sizeof(s) << endl;
    // 访问的是子类的属性
    cout << "s.a:" << s.a << endl;
    // 访问父类中的重名的属性，需要加作用域
    cout << "s.Base1::a:" << s.Base1::a << endl;
}
