#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print058(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
}

void main058()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);
    // ·´×ª
    // void reverse(iterator start, iterator end);
    reverse(v.begin(), v.end());
    print058(v);
}
