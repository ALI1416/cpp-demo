#include<iostream>
using namespace std;

// 父类(基类)
// 动物类
class Animal
{
public:
    int year;
protected:
    string name;
private:
    bool gender;
public:
    Animal()
    {
        cout << "Animal构造" << endl;
    }
    ~Animal()
    {
        cout << "Animal析构" << endl;
    }
};

// 子类(派生类)
// 继承方式
// public       公共继承    public->public      protected->protected    private不可访问
// protected    保护继承    public->protected   protected->protected    private不可访问
// private      私有继承    public->private     protected->private      private不可访问
//

// 猫类
class Cat : public Animal
{
// 继承下来的属性
//public:
//    int year;
//protected:
//    string name;
public:
    // 构造顺序：父类->子类
    // 析构顺序：子类->父类
    Cat(int year)
    {
        cout << "Cat构造" << endl;
        this->year = year;
        name = "猫";
    }
    ~Cat()
    {
        cout << "Cat析构" << endl;
    }
    void print()
    {
        cout << "姓名：" << name << "，出生年：" << year << endl;
    }
};

// 狗类
class Dog : protected Animal
{
// 继承下来的属性
//protected:
//    int year;
//protected:
//    string name;
public:
    int a;
    Dog()
    {
        year = 2021;
        name = "狗";
    }
    void print()
    {
        cout << "姓名：" << name << "，出生年：" << year << endl;
    }
};

// 鼠类
class Rat : private Animal
{
// 继承下来的属性
//private:
//    int year;
//private:
//    string name;
public:
    Rat()
    {
        year = 2020;
        name = "鼠";
    }
    void print()
    {
        cout << "姓名：" << name << "，出生年：" << year << endl;
    }
};

void main017()
{
    Cat cat(2022);
    cat.print();
    cat.year = 2023;
    cat.print();
    Dog dog;
    dog.print();
    Rat rat;
    rat.print();

    // x86 28字节 x64 40字节
    cout << "sizeof(string):" << sizeof(string) << endl;
    cout << "sizeof(Animal):" << sizeof(Animal) << endl;
    // 父类中的非静态属性，也被子类继承了，但是被隐藏了，无法访问
    cout << "sizeof(Cat):" << sizeof(Cat) << endl;
    // 可以使用命令来查询 对象模型
    // cl /d1 reportSingleClassLayout类名 cpp文件名
    // 例如 cl /d1 reportSingleClassLayoutDog "017-继承-基础.cpp"
    // 显示如下
    //class Dog       size(36): 总共占用36字节，实际占用40字节(string少算4字节)
    //        +---
    // 0      | +--- (base class Animal) 继承父类Animal
    // 0      | | year 父类int属性占用4字节(4-0=4)
    // 4      | | ?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@ name 父类string属性占用24字节(28-4=24)，实际占用28字节(string少算4字节)
    //28      | | gender 父类bool属性占用4字节(32-28=4)
    //        | | <alignment member> (size=3) 总共3个属性
    //        | +---
    //32      | a 自己int属性占用4字节(36-32=4)
    //        +---
    cout << "sizeof(Dog):" << sizeof(Dog) << endl;
}
