#include<iostream>
using namespace std;

class Animal2
{
public:
    int year = 2020;
    static bool gender;
    void printYear()
    {
        cout << "Animal2.year:" << year << endl;
    }
    void printYear(int year)
    {
        cout << "Animal2.year:" << year << endl;
    }
    static void print()
    {
        cout << "Animal2.print()" << endl;
    }
};

bool Animal2::gender = true;

class Cat2 : public Animal2
{
public:
    int year = 2021;
    static bool gender;
    void printYear()
    {
        cout << "Cat2.year:" << year << endl;
    }
    static void print()
    {
        cout << "Cat2.print()" << endl;
    }
};

bool Cat2::gender = false;

void main018()
{
    Cat2 cat;
    // 同名属性或方法，子类访问，显示子类的值
    cout << "cat.year:" << cat.year << endl;
    // 如需访问父类，需要加上父类的名称
    cout << "cat.Animal2::year:" << cat.Animal2::year << endl;
    cat.printYear();
    cat.Animal2::printYear();
    // 子类会覆盖掉父类中所有的同名函数，所以此处需要加上父类名称
    cat.Animal2::printYear(1234);

    // 静态
    cout << "Cat2::gender:" << Cat2::gender << endl;
    // 通过Cat2来访问父类Animal2中的属性gender
    cout << "Cat2::Animal2::gender:" << Cat2::Animal2::gender << endl;
    cout << "Animal2::gender:" << Animal2::gender << endl;
    Cat2::print();
    Cat2::Animal2::print();
    Animal2::print();
}
