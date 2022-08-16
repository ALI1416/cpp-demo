#include<iostream>
using namespace std;

class Person15
{
public:
    string name;
    int year;

    // 重载()
    void operator()()
    {
        cout << "姓名：" << name << "，出生年：" << year << endl;
    }
    // 重载()，带参
    void operator()(string s)
    {
        cout << s << endl;
    }
};

void main016()
{
    Person15 p;
    p.name = "ck";
    p.year = 1998;
    // 由于使用起来类似函数调用，所以也叫仿函数
    p();
    // 调用匿名函数对象
    Person15()("Hello, World !");
}
