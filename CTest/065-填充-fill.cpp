#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void print065(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
}

void main065()
{
    vector<int> v;
    v.resize(10);
    // T fill(iterator start, iterator end, T value);
    fill(v.begin(), v.end(), 123);
    print065(v);
}
