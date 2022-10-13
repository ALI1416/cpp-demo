#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool greate5(int v)
{
    return v > 5;
}

void main051()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 条件查找，找到返回第一个对应的iterator，找不到返回end
    // iterator for_each(iterator begin, iterator end, function);
    vector<int>::iterator it1 = find_if(v.begin(), v.end(), greate5);
    if (it1 == v.end())
    {
        cout << "未找到元素！" << endl;
    }
    else
    {
        cout << "找到元素:" << *it1 << endl;
    }
}
