#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main052()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    // 找到返回第一个相邻元素的iterator，找不到返回end
    // iterator adjacent_find(iterator begin, iterator end);
    vector<int>::iterator it1 = adjacent_find(v.begin(), v.end());
    if (it1 == v.end())
    {
        cout << "未找到相邻元素！" << endl;
    }
    else
    {
        cout << "找到相邻元素:" << *it1 << endl;
    }
    vector<int> v2;
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    vector<int>::iterator it2 = adjacent_find(v2.begin(), v2.end());
    if (it2 == v2.end())
    {
        cout << "未找到相邻元素！" << endl;
    }
    else
    {
        cout << "找到相邻元素:" << *it2 << endl;
    }
}
