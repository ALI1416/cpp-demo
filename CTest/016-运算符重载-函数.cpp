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

class MyAdd
{
public:
    // 有返回值
    int operator()(int a, int b)
    {
        return a + b;
    }
};

// 函数对象可以拥有自己的内部状态
class MyPrint
{
public:
    // 内部状态
    int count;

    MyPrint()
    {
        count = 0;
    }

    void operator()(string msg)
    {
        cout << msg << endl;
        count++;
    }
};

// 函数对象作为参数传递
void doPrint(MyPrint& myPrint, string msg)
{
    myPrint(msg);
}

void main016()
{
    Person15 p;
    p.name = "ck";
    p.year = 1998;
    // 由于使用起来类似函数调用，所以也叫仿函数
    p();
    // 调用匿名函数对象
    Person15()("Hello, World !");

    // 调用有返回值的函数对象
    MyAdd myAdd;
    cout << myAdd(2, 3) << endl;

    // 调用拥有自己的内部状态
    MyPrint myPrint;
    myPrint("Hello");
    myPrint("World");
    myPrint("Hi");
    myPrint("C++");
    cout << myPrint.count << endl;

    // 函数对象作为参数传递
    doPrint(myPrint, "Hello, World !");

}
