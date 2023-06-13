#include<iostream>
using namespace std;

class Person4
{
public:
    // 静态属性
    // 1.所有对象共享一份数据
    // 2.编译阶段分配内存
    // 3.类内声明，类外初始化
    static string name;

    // 静态方法，所有对象共享一个函数
    static void print()
    {
        // 静态方法只能访问静态属性
        cout << "静态方法：姓名：" << name << endl;
    }
};

// 静态属性，类外初始化(必须)
string Person4::name = "ck";

class Person5
{
};

class Person6
{
    int year;
};

void main007() {
    /* 访问静态属性 */
    // 1.通过对象访问
    Person4 p1;
    cout << "姓名：" << p1.name << endl;
    // 2.通过类名访问
    p1.name = "kk";
    cout << "姓名：" << Person4::name << endl;

    /* 访问静态方法 */
    // 1.通过对象访问
    Person4 p2;
    p2.print();
    // 2.通过类名访问
    Person4::print();

    /* 空间占用情况 */
    // 不含任何属性和方法的类，占用1个字节
    Person5 p3;
    cout << "Person5：占用字节数：" << sizeof(p3) << endl;
    // 非空属性的类，占用所有非静态属性占用的空间
    Person6 p4;
    cout << "Person6：占用字节数：" << sizeof(p4) << endl;
    // 类占用字节数：只计算非空属性占用的空间，如果没有，则占用1个字节
    Person4 p5;
    cout << "Person4：占用字节数：" << sizeof(p5) << endl;
}
