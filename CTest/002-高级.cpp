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

    /* 异常捕获 */

    /* 字符串异常 */
    try
    {
        // 抛出字符串异常
        throw "字符串异常";
    }
    // 捕获字符串异常
    catch (const char* c)
    {
        cout << "error：" << c << endl;
    }
    // 捕获所有异常
    catch (...)
    {
        cout << "unknown error" << endl;
    }

    /* 标准C++异常 */
    // exception    所有标准异常类的父类
    //      bad_alloc       分配内存错误(new)
    //      bad_cast        动态类型转换错误
    //      bad_exception   这是个特殊的异常，如果函数的异常抛出列表里声明了bad_exception异常，当函数内部抛出了异常抛出列表中没有的异常，这是调用的unexpected函数中若抛出异常，不论什么类型，都会被替换为bad_exception类型
    //      bad_typeid      使用typeid操作符，操作一个NULL指针，而该指针是带有虚函数的类，这时抛出bad_typeid异常
    //      logic_error     逻辑错误，可以在运行前检测的错误
    //          domain_error        参数的值域错误，主要用在数学函数中。例如使用一个负值调用只能操作非负数的函数
    //          invalid_argument    参数不合适。在标准库中，当利用string对象构造bitset时，而string中的字符不是’0’或’1’的时候，抛出该异常
    //          length_error        试图生成一个超出该类型最大长度的对象时，例如vector的resize操作
    //          out_of_range        超出有效范围
    //      runtime_error   运行时错误，仅在运行时才可以检测的错误
    //          overflow_error      算术计算上溢
    //          underflow_error     算术计算下溢
    //          range_error         计算结果超出了有意义的值域范围
    try
    {
        // 抛出标准C++异常
        throw exception("标准C++异常");
    }
    catch (const exception& e)
    {
        cout << "error：" << e.what() << endl;
    }

    /* win32异常 */
    // 需要开启win32异常捕获，才能捕获到空指针、内存越界、除0异常等
    // 开启方法：`项目`->`属性`->`配置属性`->`C/C++`->`代码生成`->`启用C++异常`->`是，但有SEH异常(/EHa)`
    // 除0异常
    try
    {
        int eb = 0;
        int ea = 1 / eb;
    }
    // win32异常，只能用...才能捕获到
    catch (...)
    {
        cout << "unknown error" << endl;
    }
    // 空指针异常(无效)
    try
    {
        int* ec = NULL;
        //*ec = 1;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
    }
    // 内存越界异常(无效)
    try
    {
        int ed[2];
        //ed[2] = 1;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
    }

}
