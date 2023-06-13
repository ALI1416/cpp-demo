#include<iostream>
using namespace std;

int addInt(int a, int b)
{
    return a + b;
}

template<typename T>
T addT(T a, T b)
{
    return a + b;
}

void printAdd(int a, int b)
{
    cout << "普通函数printAdd:" << a + b << endl;
}

template<typename T>
void printAdd(T a, T b)
{
    cout << "函数模板printAdd:" << a + b << endl;
}

template<typename T>
void printAdd(T a, T b, T c)
{
    cout << "函数模板printAdd:" << a + b + c << endl;
}

void main027()
{
    int a = 123;
    int b = 456;
    // ASCII:97
    char c = 'a';
    // ASCII:98
    char d = 'b';
    int e = 789;
    // 普通函数调用时，会发生类型隐式转换
    cout << "a+b=" << addInt(a, c) << endl;
    // 模板不会，需要指定数据类型
    cout << "a+b=" << addT<int>(a, c) << endl;

    // 如果普通函数与函数模板同名，会默认调用普通函数
    printAdd(a, b);
    // 如果要强制调用函数模板，需要加上空参数列表
    printAdd<>(a, b);

    // 如果函数模板能产生更好的匹配，优先调用函数模板
    // 如果调用普通函数，需要进行2次隐式转换
    printAdd(c, d);

    // 模板函数重载
    printAdd(a, b, e);
}
