#include<iostream>
using namespace std;

class Person2
{
public:
    string name;
    // 把年龄的数据，创建到堆区
    int* year;

    Person2(string name, int year)
    {
        this->name = name;
        // 在堆区创建
        this->year = new int(year);
        cout << this << " 全参构造函数" << endl;
    }
    Person2(const Person2& p)
    {
        // 浅拷贝：简单赋值拷贝操作
        // 深拷贝：在堆区重新申请空间，进行拷贝
        name = p.name;
        // 进行深拷贝，如果不进行深拷贝，会重复释放堆区内存，会报错
        year = new int(*p.year);
        cout << this << " 拷贝构造函数" << endl;
    }
    ~Person2()
    {
        // 释放堆区内存
        if (year != NULL)
        {
            delete year;
            year = NULL;
        }
        cout << this << " 析构函数" << endl;
    }
};

void main005()
{
     Person2 p1("ck", 1998);
     cout << "p1:姓名：" << p1.name << "，出生年：" << *p1.year << endl;
     Person2 p2(p1);
     cout << "p2:姓名：" << p2.name << "，出生年：" << *p2.year << endl;
}
