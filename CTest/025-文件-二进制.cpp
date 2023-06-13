#include<iostream>
#include<fstream>
using namespace std;

class Person25
{
public:
    // string会出现问题
    char name[32];
    int year;
    bool gender;
};

void main025()
{
    Person25 p = { "阿狸",1998,true };
    // 写文件
    ofstream ofs;
    ofs.open("/2.txt", ios::out | ios::binary);
    // 参数(对象引用,对象大小)
    ofs.write((const char*)&p, sizeof(Person25));
    ofs.close();

    // 读文件
    ifstream ifs;
    ifs.open("/2.txt", ios::in | ios::binary);
    if (ifs.is_open())
    {
        Person25 p2;
        ifs.read((char*)&p2, sizeof(Person25));
        cout << "姓名：" << p2.name << "，性别：" << (p2.gender == true ? "男" : "女") << "，出生年：" << p2.year << endl;
    }
    ifs.close();
}
