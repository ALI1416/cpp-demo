#include<iostream>
using namespace std;

// 手机类
class Phone
{
public:
    string name;
    Phone(string name) :name(name) {}
};

class Person3
{
public:
    string name;
    bool gender;
    int year;
    // 手机类
    Phone phone;

    // 普通初始化操作
    //Person3(string name, bool gender, int year)
    //{
    //    this->name = name;
    //    this->gender = gender;
    //    this->year = year;
    //    cout << this << " 全参构造函数" << endl;
    //}

    // 初始化列表
    Person3(string name, bool gender, int year, string phoneName) :name(name), gender(gender), year(year), phone(phoneName)
    {
        cout << "初始化列表" << endl;
    }
};

void main006()
{
    Person3 p1("ck", true, 1998, "iPhone 12 Pro Max");
    cout << "姓名：" << p1.name << "，性别：" << (p1.gender == true ? "男" : "女") << "，出生年：" << p1.year << "，手机：" << p1.phone.name << endl;
}
