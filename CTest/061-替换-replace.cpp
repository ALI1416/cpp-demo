#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print061(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
}

void main061()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(2);
    // void replace(iterator start, iterator end, T oldValue, T newValue);
    replace(v.begin(), v.end(), 2, 200);
    print061(v);
}
