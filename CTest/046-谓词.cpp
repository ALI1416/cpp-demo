#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print046(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ",";
    }
    cout << endl;
}

// 比5大
class GreaterFive
{
public:
    bool operator()(int v)
    {
        return v > 5;
    }
};

// 降序
class Desc
{
public:
    bool operator()(const int& v1, const int& v2) const
    {
        return v1 > v2;
    }
};

// 返回bool类型的`仿函数`叫做`谓词`
// 如果operator()接受1个参数，叫一元谓词
// 如果operator()接受2个参数，叫二元谓词
void main046()
{
    /* 一元谓词 */
    vector<int> v;
    v.push_back(3);
    v.push_back(7);
    v.push_back(5);
    v.push_back(1);
    v.push_back(9);
    // 查找比5大的值
    // iterator find_if(iterator begin, iterator end, function)
    // GreaterFive()是匿名函数对象
    vector<int>::iterator vr = find_if(v.begin(), v.end(), GreaterFive());
    if (vr == v.end())
    {
        cout << "未找到！" << endl;
    }
    else
    {
        cout << "找到了比5大的数字为：" << *vr << endl;
    }

    /* 二元谓词 */
    print046(v);
    sort(v.begin(), v.end(), Desc());
    print046(v);

}
