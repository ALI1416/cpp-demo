#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print057(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
}

void main057()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 100);
    }
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v2.push_back(i);
    }
    vector<int> v3;
    v3.push_back(123);
    v3.push_back(123);
    // 需要给目标容器提前分配空间
    v3.resize(v.size() + v2.size() + v3.size());
    // 合并2个有序容器到另一个容器中(容器内的元素必须是有序的，目标容器内容会被清空)
    // void merge(iterator start1, iterator end1, iterator start2, iterator end2, iterator startDest);
    merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
    print057(v3);
}
