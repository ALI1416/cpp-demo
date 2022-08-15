#include<iostream>
using namespace std;

class Person8
{
public:
    // 常属性，必须有默认值
    const string name ="ck";
    // mutable可变的，常方法可修改
    mutable bool gender;
    int year;

    void print()
    {
        cout << "姓名：" << name << "，性别：" << (gender == true ? "男" : "女") << "，出生年：" << year << endl;
    }

    // 常方法
    void print2() const
    {
        // 常方法只可修改mutable修饰发属性
        this->gender = true;
        cout << "性别：" << (gender == true ? "男" : "女") << endl;
    }

};

class Person9
{
public:
    mutable bool gender;

    void print()
    {
        cout << "性别：" << (gender == true ? "男" : "女") << endl;
    }

    void print2() const
    {
        cout << "性别：" << (gender == true ? "男" : "女") << endl;
    }
};

void main009()
{
    Person8 p;
    p.gender = false;
    p.year = 1998;
    p.print();
    p.print2();

    // 常对象，只能调用常方法
    // 注意：不能带有const属性
    const Person9 p2;
    p2.gender = false;
    p2.print2();
}
