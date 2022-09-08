#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 打印
void print(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

// vector数据结构和普通数组类似，称为单端数组
// 区别：vector数组的静态空间，是可以动态扩展的：找到更大的内存空间，把原数据拷贝进新空间，释放原空间
void main()
{
    /* 构造 */
    // 无参(默认)
    // vector<T>();
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    print(v1);
    // 区间
    // 将v[begin,v.end)区间内的元素拷贝给自己
    // vector<T>(iterator v.begin(), iterator v.end());
    vector<int> v2(v1.begin(),v1.end());
    print(v2);
    // n个元素
    // vector<T>(int n, int value);
    vector<int> v3(10,1);
    print(v3);
    // 拷贝
    // vector<T>(const vector<T>& v);
    vector<int> v4(v3);
    print(v4);

    /* 赋值 */
    // 


}
