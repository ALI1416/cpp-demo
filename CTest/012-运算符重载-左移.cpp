#include<iostream>
using namespace std;

class Person11
{
    // 如果属性是私有的，需要加上友元声明
    friend ostream& operator<<(ostream& cout, Person11& p);

private:
    string name;
public:
    Person11(string name):name(name){}
    // 不能利用内部函数重载<<运算符，p.operator<<(cout)，简化为p << cout，因为cout在右侧
    //void Person11 operator<<(cout)
};

// 需要返回ostream& cout，才能进行链式调用
ostream& operator<<(ostream& cout, Person11& p)
{
    cout << p.name;
    return cout;
}

void main012()
{
    Person11 p("ck");
    cout << "姓名：" << p << endl;
}
