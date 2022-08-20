#include<iostream>
using namespace std;

// int交换
void swapInt(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

// double交换
void swapDouble(double& a, double& b)
{
    double t = a;
    a = b;
    b = t;
}

// 声明模板template<typename或class 泛型名称>
// 一般函数使用typename，类使用class
// 通用交换
template<typename T>
void swapT(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

template<typename T>
void getT()
{
    // 使用typeid获取泛型类型
    cout << "泛型类型：" << typeid(T).name() << endl;
}

void main026()
{
    int a = 123;
    int b = 456;
    cout << "a:" << a << ",b:" << b << endl;
    swapInt(a, b);
    cout << "交换后：a:" << a << ",b:" << b << endl;

    double c = 1.23;
    double d = 4.56;
    cout << "c:" << c << ",d:" << d << endl;
    swapDouble(c, d);
    cout << "交换后：c:" << c << ",d:" << d << endl;

    // 使用模板
    double e = 1.23;
    double f = 4.56;
    cout << "e:" << e << ",f:" << f << endl;
    // 没有标明数据类型，自动推导
    swapT(e, f);
    cout << "交换后：e:" << e << ",f:" << f << endl;
    // 指明数据类型
    swapT<double>(e, f);
    cout << "交换后：e:" << e << ",f:" << f << endl;

    // 获取泛型类型
    getT<int>();
    getT<string>();
}
