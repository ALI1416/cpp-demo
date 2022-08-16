#include<iostream>
using namespace std;

// C++允许重载的运算符
// 双目算术运算符  +(加)、-(减)、*(乘)、/(除)、%(模)
// 关系运算符      ==(等于)、!=(不等于)、<(小于)、>(大于)、<=(小于等于)、>=(大于等于)
// 逻辑运算符      ||(逻辑或)、&&(逻辑与)、!(逻辑非)
// 单目运算符      +(正)、-(负)、*(指针)、&(取址)
// 自增自减运算符  ++(自增)、--(自减)
// 位运算符        &(按位与)、|(按位或)、~(按位取反)、^(按位异或)、<<(左移)、>>(右移)
// 赋值运算符      =、+=、-=、*=、/=、%=、&=、|=、^=、<<=、>>=
// 空间申请与释放  new、delete、new[]、delete[]
// 其他运算符      ()(函数调用)、->(成员访问)、->*(成员指针访问)、,(逗号)、[](下标)
//
// 不能重载的运算符
// .(成员访问运算符)、.*(成员指针访问运算符)、::(域运算符)、sizeof(长度运算符)、?:(条件运算符）

class Person10
{
public:
    // 身高
    int height;
    // 体重
    int weight;

    Person10() {}
    Person10(int height, int weight) :height(height), weight(weight) {}

    // 重载运算符+
    Person10 operator+(Person10& p)
    {
        Person10 t;
        t.height = this->height + p.height;
        t.weight = this->weight + p.weight;
        return t;
    }
};

// 全局函数重载运算符-
Person10 operator-(Person10& p1, Person10& p2)
{
    Person10 t;
    t.height = p1.height - p2.height;
    t.weight = p1.weight - p2.weight;
    return t;
}

void main011()
{
    Person10 p1(174, 63);
    Person10 p2(180, 70);
    // 等同于
    // Person10 p3 = p1.operator+(p2);
    Person10 p3 = p1 + p2;
    cout << "p1身高：" << p1.height << "，体重：" << p1.weight << endl;
    cout << "p2身高：" << p2.height << "，体重：" << p2.weight << endl;
    cout << "p3=p1+p2身高：" << p3.height << "，体重：" << p3.weight << endl;
    // 等同于
    // Person10 p4 = operator-(p2, p1);
    Person10 p4 = p2 - p1;
    cout << "p4=p2-p1身高：" << p4.height << "，体重：" << p4.weight << endl;
}
