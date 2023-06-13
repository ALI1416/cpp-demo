#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void main068()
{
    vector<int> v;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        v2.push_back(i + 5);
    }
    vector<int> v3;
    // 容量最大情况：后者不包含前者。最大值：前者容量
    v3.resize(v.size());
    // 返回目标元素的最后一个位置+1(两个集合必须是有序的)
    // iterator set_difference(iterator start, iterator end, iterator start2, iterator end2, iterator startDest);
    vector<int>::iterator itEnd = set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
    for (vector<int>::iterator it = v3.begin(); it != itEnd; it++)
    {
        cout << *it << ",";
    }
    cout << endl;
    vector<int> v4;
    v4.resize(v2.size());
    vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v.begin(), v.end(), v4.begin());
    for (vector<int>::iterator it = v4.begin(); it != itEnd2; it++)
    {
        cout << *it << ",";
    }
}
