#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool greate7(int v)
{
    return v > 7;
}

void print062(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
}

void main062()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // void replace_if(iterator start, iterator end, function, T newValue);
    replace_if(v.begin(), v.end(), greate7, 200);
    print062(v);
}
