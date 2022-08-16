#include<iostream>
using namespace std;

class Person14
{
public:
    string name;
    int year;
    Person14(string name,int year) :name(name),year(year) {}

    // жиди==
    bool operator==(Person14& p)
    {
        return this->name == p.name && this->year == p.year;
    }
};

void main015()
{
    Person14 p1("ck", 1998);
    Person14 p2("kk", 1999);
    Person14 p3("kk", 1999);
    cout << "p1==p2:" << (p1 == p2) << endl;
    cout << "p2==p3:" << (p2 == p3) << endl;
}
