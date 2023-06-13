#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Person050
{
public:
    int year;
    bool gender;
    Person050(int year, bool gender) :year(year), gender(gender) {};
    // 重载==，比较Person050类型
    bool operator==(const Person050& p)
    {
        return this->year == p.year && this->gender == p.gender;
    }
};

void main050()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 找到返回对应iterator，找不到返回end
    // iterator for_each(iterator begin, iterator end, T value);
    vector<int>::iterator it1 = find(v.begin(), v.end(), 2);
    if (it1 == v.end())
    {
        cout << "未找到元素！" << endl;
    }
    else
    {
        cout << "找到元素:" << *it1 << endl;
    }
    vector<int>::iterator it2 = find(v.begin(), v.end(), 12);
    if (it2 == v.end())
    {
        cout << "未找到元素！" << endl;
    }
    else
    {
        cout << "找到元素:" << *it2 << endl;
    }
    // 查找对象
    vector<Person050> v2;
    v2.push_back(Person050(1998, true));
    v2.push_back(Person050(1999, false));
    v2.push_back(Person050(2000, false));
    v2.push_back(Person050(2001, false));
    vector<Person050>::iterator it3 = find(v2.begin(), v2.end(), Person050(2000, false));
    cout << "找到元素:" << it3->year << "," << it3->gender << endl;
}
