#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print01(int value)
{
    cout << value << " ";
}

class Print02
{
public:
    void operator()(int value)
    {
        cout << value << " ";
    }
};

class Person048
{
public:
    int year;
    bool gender;
    Person048(int year, bool gender) :year(year), gender(gender) {};
};

void printPerson01(Person048 value)
{
    cout << value.year << "," << value.gender << " ";
}

// 算法主要由头文件algorithm、functional、numeric组成
// algorithm是所有STL头文件中最大的一个，含有比较、交换、遍历、复制、修改等
// numeric体积很小，只包含几个在序列上面进行简单数学运算的模板函数
// functional定义了一些模板类，用以声明函数对象
void main048()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // void for_each(iterator begin, iterator end, function);
    // 使用函数遍历
    for_each(v.begin(), v.end(), print01);
    cout << endl;
    // 使用仿函数遍历
    for_each(v.begin(), v.end(), Print02());
    cout << endl;
    // 遍历对象
    vector<Person048> v2;
    v2.push_back(Person048(1998, true));
    v2.push_back(Person048(1999, false));
    for_each(v2.begin(), v2.end(), printPerson01);
}
