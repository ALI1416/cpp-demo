#include<iostream>
using namespace std;

// 多态
// 静态多态：函数重载、运算符重载
//          函数地址早绑定->编译阶段确定函数地址
// 动态多态：子类、虚函数
//          函数地址晚绑定->运行阶段确定函数地址
class Animal22
{
public:
    void speak()
    {
        cout << "动物在说话" << endl;
    }
    // 虚函数
    virtual void speak2()
    {
        cout << "动物在说话2" << endl;
    }
};

class Cat22 : public Animal22
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
    // 重写虚函数
    virtual void speak2()
    {
        cout << "小猫在说话2" << endl;
    }
};

// 在编译阶段已绑定函数地址，无论如何调用，都输出Animal22的内容
void doSpeak(Animal22& animal)
{
    animal.speak();
}

// 动态多态
// 子类继承父类，重写父类的虚函数
void doSpeak2(Animal22& animal)
{
    animal.speak2();
}

void main021()
{
    Cat22 cat;
    doSpeak(cat);
    doSpeak2(cat);
    cout << "sizeof(Cat22):" << sizeof(Cat22) << endl;
    // cl /d1 reportSingleClassLayoutCat22 "021-多态-虚函数.cpp"
    //class Cat22     size(4):
    //        +---
    // 0      | +--- (base class Animal22)
    // 0      | | {vfptr} virtual funcation pointer 虚函数指针，占用4字节，指向vftable
    //        | +---
    //        +---
    //Cat22::$vftable@: virtual funcation table 虚函数表
    //        | &Cat22_meta
    //        |  0
    // 0      | &Cat22::speak2 Cat22重写的虚函数speak2
    //Cat22::speak2 this adjustor: 0
}
