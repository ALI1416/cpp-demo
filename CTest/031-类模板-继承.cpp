#include<iostream>
using namespace std;

template<class T>
class Base31
{
public:
    T t;
    void showType()
    {
        cout << "Base31类型T：" << typeid(T).name() << endl;
    }
};

// 子类继承类模板，需要指定数据类型
class Son31 :public Base31<int>
{
};

// 子类不指定数据类型，可以把子类也变成类模板
template<class T1, class T2>
class Son32 :public Base31<T1>
{
public:
    T2 t;
    void showType2()
    {
        cout << "Son33类型T2：" << typeid(T2).name() << endl;
    }
};

void main031()
{
    Son31 s1;
    s1.showType();
    Son32<bool, double> s2;
    s2.showType2();
    s2.showType();
}