#include<iostream>
using namespace std;

class Person13
{
public:
    string name;
    int* year;

    Person13(string name, int year)
    {
        this->name = name;
        // 深拷贝
        this->year = new int(year);
    }

    // 编译器提供的第4个构造函数
    // 重载赋值运算符，但是浅拷贝
    // 此处替换成深拷贝
    // 返回*this是为了可以链式调用
    Person13& operator=(Person13& p)
    {
        name = p.name;
        // 深拷贝
        year = new int(*p.year);
        return *this;
    }

    ~Person13()
    {
        // 释放堆区内存
        if (year != NULL)
        {
            delete year;
            year = NULL;
        }
    }
};

void main014()
{
    Person13 p1("ck", 1998);
    Person13 p2("kk", 1999);
    Person13 p3("cc", 2000);
    cout << "p1:姓名：" << p1.name << "，出生年：" << *p1.year << endl;
    p1 = p2;
    cout << "p1:姓名：" << p1.name << "，出生年：" << *p1.year << endl;
    p1 = p2 = p3;
    cout << "p1:姓名：" << p1.name << "，出生年：" << *p1.year << endl;
}
