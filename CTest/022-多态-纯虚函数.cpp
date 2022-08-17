#include<iostream>
using namespace std;

// 含有纯虚函数的类，也叫抽象类
class Animal23
{
public:
    // 纯虚函数，必须有一个子类实现方法
    virtual void speak() = 0;
};

class Cat23 : public Animal23
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

void main022()
{
    Animal23* animal = new Cat23;
    animal->speak();
    delete animal;
}
