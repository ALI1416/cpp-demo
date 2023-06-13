#include<iostream>
using namespace std;

class Person
{
private:
    // 姓名
    // 可以给定默认值
    string name = "";
    // 性别
    bool gender = true;
    // 出生年
    int year = 2000;

public:
    /* 构造函数 */
    // 如果没有手动添加构造函数，系统会默认添加3个构造函数
    // 1.无参构造函数，方法体为空
    // 2.无参析构函数，方法体为空
    // 3.拷贝构造函数，方法体拷贝所有属性
    // 如果用户定义了有参构造函数，系统不再提供无参构造函数，但是会提供拷贝构造函数
    // 如果用户定义了拷贝构造函数，系统不再提参其他构造函数
    // 无参构造函数
    Person()
    {
        cout << this << " 无参构造函数" << endl;
    }
    // 含参构造函数
    Person(string name)
    {
        this->name = name;
        cout << this << " 含参构造函数" << endl;
    }
    Person(bool gender)
    {
        this->gender = gender;
        cout << this << " 含参构造函数" << endl;
    }
    // 全参构造函数
    Person(string name, bool gender, int year)
    {
        this->name = name;
        this->gender = gender;
        this->year = year;
        cout << this << " 全参构造函数" << endl;
    }
    // 拷贝构造函数
    // 使用const引用，防止修改、节省内存
    Person(const Person& p)
    {
        name = p.name;
        gender = p.gender;
        year = p.year;
        cout << this << " 拷贝构造函数" << endl;
    }
    /* 析构函数 */
    // 在类名前加上~，对象销毁前，自动调用
    ~Person()
    {
        cout << this << " 析构函数" << endl;
    }
    void print()
    {
        cout << "姓名：" << name << "，性别：" << (gender == true ? "男" : "女") << "，出生年：" << year << endl;
    }
};

void main004()
{
    /* 调用方式 */
    // 1、括号法
    // 无参构造函数(注意：不可加括号，否则会被识别为函数声明)
    Person p1;
    // 含参构造函数
    Person p2("ck");
    // 全参构造函数
    Person p3("ck", true, 1998);
    // 拷贝构造函数
    Person p4(p3);
    p4.print();

    // 2、显示法
    Person p5 = Person();
    Person p6 = Person("kk");
    Person p7 = Person("kk", false, 2008);
    Person p8 = Person(p7);
    // 匿名函数，执行结束，立即回收
    Person("cc");
    p8.print();
    // 匿名函数不能使用拷贝构造函数
    // 例如Person(p8)会解析成Person p8，运行会出现重定义错误
    // Person(p8);

    // 3、隐式转换法
    // 会自动探测类型
    Person p9 = false;
    Person p10 = p9;
    p10.print();
}
