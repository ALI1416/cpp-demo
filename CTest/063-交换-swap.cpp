#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print063(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

void main063()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int> v2;
    for (int i = 0; i < 6; i++)
    {
        v2.push_back(i+10);
    }
    print063(v);
    print063(v2);
    // void swap(container c1, container c2);
    swap(v, v2);
    print063(v);
    print063(v2);
}
