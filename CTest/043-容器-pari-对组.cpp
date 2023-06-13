#include<iostream>
using namespace std;

// 对组 成对的数据
void main043()
{
    /* 构造和获取 */
    // 构造
    // pair<T1,T2>();
    pair<string, int> ck("ChengKai", 1998);
    // pari<T1,T2> make_pair(const T1& t1, const T1& t1);
    pair<string, int> kk = make_pair("Kai", 2008);
    // 获取
    cout << "姓名：" << ck.first << "，出生年：" << ck.second << endl;
    cout << "姓名：" << kk.first << "，出生年：" << kk.second << endl;
}
