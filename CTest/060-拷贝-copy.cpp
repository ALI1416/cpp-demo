#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print060(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
}

void main060()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int> v2;
    v2.push_back(123);
    // 需要给目标容器提前分配空间
    v2.resize(v.size() + v2.size());
    // 目标容器数据会被从beginDest开始替换
    // void copy(iterator start, iterator end, iterator startDest);
    copy(v.begin(), v.end(), v2.begin() + 1);
    print060(v2);
}
