#include<iostream>
using namespace std;

class Person7
{
private:
    string name;
    bool gender;
    int year;
public:
    Person7 setName(string name)
    {
        this->name = name;
        // 返回*this可以进行链式调用
        return *this;
    }
    Person7 setGender(bool gender)
    {
        this->gender = gender;
        return *this;
    }
    Person7 setYear(int year)
    {
        this->year = year;
        return *this;
    }
    void print()
    {
        cout << "姓名：" << name << "，性别：" << (gender == true ? "男" : "女") << "，出生年：" << year << endl;
    }
};

void main()
{
    Person7 p;
    // 进行链式调用
    p.setName("ck").setGender(true).setYear(1998);
    p.print();
}
