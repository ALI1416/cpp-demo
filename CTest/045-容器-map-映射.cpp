#include<iostream>
#include<map>
using namespace std;

// 打印
void print(map<int, int> m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        // 访问方式2
        cout << "key:" << (*it).first << ",value:" << (*it).second << "; ";
    }
    cout << endl;
}

// 自定义排序
class Desc2
{
public:
    // 降序仿函数
    bool operator()(const int& v1, const int& v2) const
    {
        return v1 > v2;
    }
};

void main045() {

    /* 构造 */
    // 无参(默认)
    // map<T1, T2>();
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(make_pair(2, 20));
    m1.insert(make_pair(3, 30));
    m1.insert(make_pair(4, 40));
    print(m1);
    // 拷贝
    // map<T1, T2>(const map<T1, T2>& m);
    map<int, int> m2(m1);
    print(m1);

    /* 赋值 */
    // map赋值给当前map
    // map& operator=(const map& s);
    map<int, int> m3 = m2;
    print(m3);

    /* 大小操作 */
    map<int, int> m4;
    // 判断栈是否为空
    // bool empty();
    // 返回栈的长度
    // int size();
    cout << "empty:" << m4.empty() << ",size:" << m4.size() << endl;
    m4.insert(make_pair(2, 20));
    m4.insert(make_pair(3, 30));
    m4.insert(make_pair(4, 40));
    cout << "empty:" << m4.empty() << ",size:" << m4.size() << endl;

    /* 存取 */
    map<int, int> m5;
    // 插入
    // pair<map<T1, T2>::iterator, bool> insert(pair<map<T1, T2>& value);
    // 插入方式1
    m5.insert(pair<int, int>(1, 10));
    // 插入方式2
    m5.insert(make_pair(2, 20));
    // 插入方式3(不建议)
    m5[3] = 30;
    m5.insert(make_pair(5, 50));
    m5.insert(make_pair(4, 40));
    // 访问方式1
    cout << m5[4] << endl;
    print(m5);
    // 删除迭代器指向元素
    // iterator erase(iterator pos);
    m5.erase(--m5.end());
    print(m5);
    // 删除迭代器start到end之间的元素
    // iterator erase(iterator start, iterator end);
    m5.erase(++m5.begin(), --m5.end());
    print(m5);
    // 删除指定key的元素
    // ? erase(T1);
    m5.erase(4);
    print(m5);
    // 清空容器
    // void clear();
    m5.clear();
    print(m5);

    /* 查找和统计 */
    map<int, int> m6;
    m6.insert(make_pair(4, 40));
    m6.insert(make_pair(2, 20));
    m6.insert(make_pair(5, 50));
    m6.insert(make_pair(1, 10));
    m6.insert(make_pair(3, 30));
    // 查找是否存在该值，存在返回迭代器，不存在返回s.end();
    // iterator find(T value);
    cout << "查找到的值:" << (*m6.find(2)).second << endl;
    cout << "是否查找到:" << (m6.find(0) != m6.end()) << endl;
    // 统计个数
    // int count(T value);
    cout << "个数:" << m6.count(2) << endl;
    cout << "个数:" << m6.count(0) << endl;

    /* 自定义排序 */
    map<int, int, Desc2> m7;
    m7.insert(make_pair(4, 40));
    m7.insert(make_pair(2, 20));
    m7.insert(make_pair(5, 50));
    m7.insert(make_pair(1, 10));
    m7.insert(make_pair(3, 30));
    for (map<int, int, Desc2>::const_iterator it = m7.begin(); it != m7.end(); it++)
    {
        cout << "key:" << (*it).first << ",value:" << (*it).second << "; ";
    }
    cout << endl;

}
