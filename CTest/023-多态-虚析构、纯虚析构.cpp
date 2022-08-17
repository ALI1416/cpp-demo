#include<iostream>
using namespace std;

class Animal24
{
public:
    // 加上virtual修饰符，虚析构
    // 可以解决父类释放时，子类不释放的问题
    //virtual ~Animal24()
    //{
    //    cout << "Animal24虚析构" << endl;
    //}

    // 存虚析构，必须实现
    virtual ~Animal24() = 0;

    virtual void speak() = 0;
};

// 实现存虚析构
Animal24::~Animal24()
{
    cout << "Animal24纯虚析构" << endl;
}

class Cat24 : public Animal24
{
public:
    string* name;

    Cat24(string name)
    {
        this->name = new string(name);
    }

    ~Cat24()
    {
        if (name != NULL)
        {
            cout << "Cat24析构" << endl;
            delete name;
            name = NULL;
        }
    }

    void speak()
    {
        cout << "小猫[" << *name << "]在说话" << endl;
    }
};

void main()
{
    Animal24* animal = new Cat24("喵喵");
    animal->speak();
    delete animal;
}
