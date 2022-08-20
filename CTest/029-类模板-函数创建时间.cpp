#include<iostream>
using namespace std;

class Temp1
{
public:
    void print1()
    {
        cout << "Temp1" << endl;
    }
};

class Temp2
{
public:
    void print2()
    {
        cout << "Temp2" << endl;
    }
};

template<class T>
class Person29
{
public:

    T obj;

    void fun1()
    {
        // 类模板中才函数，在调用时，才生成
        obj.print1();
    }
    void fun2()
    {
        obj.print2();
    }
};

void main029()
{
    Person29<Temp1> p;
    p.fun1();
    // Temp1类中没有print2方法，编译时不会出错，但是运行会报错
    // p.fun2();

}
