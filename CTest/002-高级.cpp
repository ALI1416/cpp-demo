#include<iostream>
#include"lib/fun.h"
using namespace std;

// 返回局部变量的引用
int& ref01()
{
    int a = 10;
    return a;
}

// 返回静态变量的引用
int& ref02()
{
    static int a = 20;
    return a;
}

// 常量引用
void print2(const int& s)
{
    // 值不可修改
    // s = 100;
    cout << "print：" << s << endl;
}

// 参数带默认值
void add(int a, int b = 2, int c = 3)
{
    cout << "add：" << a + b + c << endl;
}

// 声明和实现，只能有一个带默认值，要不然会报错
void add2(int a, int b = 2, int c = 3);

void add2(int a, int b, int c)
{
    cout << "add2：" << a + b + c << endl;
}

// 占位参数，必须传递，但是无用，也可以给定默认值
void add3(int a, int b, int c, int)
{
    cout << "add3：" << a + b + c << endl;
}

// 重载
void add4(int a, int b, int c)
{
    cout << "add4：" << a + b + c << endl;
}

void add4(int a, int b)
{
    cout << "add4：" << a + b << endl;
}

void main002()
{
    /* 创建基本类型 */
    // 创建对象
    int* p = new int(123);
    cout << "int：" << *p << endl;
    // 释放对象，使用delete
    delete p;

    /* 创建数组类型 */
    int* p2 = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p2[i] = i;
    }
    cout << "int[]：";
    for (int i = 0; i < 10; i++)
    {
        cout << p2[i] << "，";
    }
    cout << endl;
    // 释放数组对象，使用delete[]
    delete[] p2;

    /* 引用 */
    int a = 10;
    // 引用，相当于给变量起别名，他们都是指向同一个地址
    // 引用必须初始化，并且不可修改
    // 一个修改，其他的也会修改
    // 引用的本质是指针常量
    // `int& b = a;`会自动转为`int* const b = &a;`
    int& b = a;
    cout << a << endl;
    a = 20;
    cout << b << endl;
    // 内部发现变量b是引用类型，会自动转为`*b = 30;`
    b = 30;
    cout << a << endl;

    /* 参数引用 */
    int num1 = 1111, num2 = 22222;
    cout << "num1：" << num1 << "，num2：" << num2 << endl;
    // 引用传递，会改变原数据
    swap03(num1, num2);
    cout << "num1：" << num1 << "，num2：" << num2 << endl;

    /* 返回值引用 */
    // 函数运行结束后，局部变量会被释放掉
    int& a1 = ref01();
    // 第一次获取是正确的数值，被保留住了
    cout << a1 << endl;
    // 第二次获取是错误的，已被释放(x86)
    cout << a1 << endl;
    // 静态变量，程序运行结束后系统释放
    int& a2 = ref02();
    // 无论运行多少次，都是正常结果
    cout << a2 << endl;
    cout << a2 << endl;

    /* 常量引用 */
    int c = 666;
    print2(c);

    /* 函数默认值 */
    add(1, 2, 3);
    add(1, 2);
    add(1);
    add2(1, 2, 3);

    /* 占位参数 */
    add3(1, 2, 3, 4);

    /* 重载 */
    add4(1, 2);
    add4(1, 2, 3);
}
