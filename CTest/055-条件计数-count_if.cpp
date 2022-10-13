#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool greate6(int v)
{
    return v > 6;
}

void main055()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 返回根据条件找到的个数
    // int count_if(iterator begin, iterator end, function);
    int n = count_if(v.begin(), v.end(), greate6);
    cout << "找到的个数：" << n << endl;
}
