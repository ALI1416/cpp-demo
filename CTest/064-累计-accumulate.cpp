#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void main064()
{
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
    }
    // T accumulate(iterator start, iterator end, T initValue);
    int total = accumulate(v.begin(), v.end(), 0);
    cout << total << endl;
}
