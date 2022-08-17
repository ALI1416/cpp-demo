#include<iostream>
using namespace std;

// 菱形继承
//   动物
//  /   \
// 熊    猫
//  \   /
//   熊猫

// 动物
class Animal20
{
public:
    int year;
};

// 熊
class Bear20 : public Animal20
{
};

// 猫
class Cat20 : public Animal20
{
};

// 熊猫
class Panda20 : public Bear20, public Cat20
{
};


// 动物
class Animal21
{
public:
    int year;
};

// 熊
// Animal21为虚基类
class Bear21 : virtual public Animal21
{
};

// 猫
class Cat21 : virtual public Animal21
{
};
// 熊猫
class Panda21 : public Bear21, public Cat21
{
};

void main020()
{
    Panda20 p;
    // 由于继承于2个类，所以需要加作用域
    p.Bear20::year = 2020;
    p.Cat20::year = 2022;
    // cl /d1 reportSingleClassLayoutPanda20 "020-继承-虚继承.cpp"
    //class Panda20   size(8):
    //        +---
    // 0      | +--- (base class Bear20)
    // 0      | | +--- (base class Animal20)
    // 0      | | | year
    //        | | +---
    //        | +---
    // 4      | +--- (base class Cat20)
    // 4      | | +--- (base class Animal20)
    // 4      | | | year
    //        | | +---
    //        | +---
    //        +---
    // 占用了8个字节，Bear20占4个，Cat20占4个
    cout << "sizeof(p):" << sizeof(p) << endl;
    cout << "p.Bear20::year" << p.Bear20::year << endl;
    cout << "p.Cat20::year" << p.Cat20::year << endl;

    // 由于只需一份就可以，所以在子类上加上修饰符virtual，会变成虚继承
    Panda21 p2;
    p2.Bear21::year = 2023;
    p2.Cat21::year = 2025;
    // 由于是虚属性，只有一份，所以可以直接赋值，不用带上作用域
    p2.year = 2027;
    // cl /d1 reportSingleClassLayoutPanda21 "020-继承-虚继承.cpp"
    //class Panda21   size(12):
    //        +---
    // 0      | +--- (base class Bear21)
    // 0      | | {vbptr} virtual base pointer 虚基指针，指向虚基表(vbtable)，占用4字节
    //        | +--- 虚基表查找$vbtable@Bear21，看到偏移量为8，0+8=8，指向8号地址，即year属性
    // 4      | +--- (base class Cat21)
    // 4      | | {vbptr} 虚基指针，占用4字节
    //        | +--- 虚基表查找$vbtable@Cat21，看到偏移量为4，4+4=8，指向8号地址，即year属性
    //        +---
    //        +--- (virtual base Animal21)
    // 8      | year int类型，占用4字节
    //        +---
    // 虚基表 virtual base table
    //Panda21::$vbtable@Bear21@:
    // 0      | 0
    // 1      | 8 (Panda21d(Bear21+0)Animal21)
    //Panda21::$vbtable@Cat21@:
    // 0      | 0
    // 1      | 4 (Panda21d(Cat21+0)Animal21))
    //vbi:       class  offset o.vbptr  o.vbte fVtorDispe
    //        Animal21       8       0       4 0
    cout << "sizeof(p2):" << sizeof(p2) << endl;
    cout << "p2.Bear21::year" << p2.Bear21::year << endl;
    cout << "p2.Cat21::year" << p2.Cat21::year << endl;
    cout << "p2.year" << p2.year << endl;
}
