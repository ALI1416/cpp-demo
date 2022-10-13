#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

void main053()
{
    set<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.insert(i);
    }
    // 只适用于有序序列
    // bool binary_search(iterator begin, iterator end, T value);
    bool b = binary_search(v.begin(), v.end(), 2);
    if (b)
    {
        cout << "找到元素！" << endl;
    }
    else
    {
        cout << "未找到元素！" <<  endl;
    }
    bool b2 = binary_search(v.begin(), v.end(), 12);
    if (b2)
    {
        cout << "找到元素！" << endl;
    }
    else
    {
        cout << "未找到元素！" <<  endl;
    }
}
